//
//  Djikas.cpp
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-08.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#include "Djikas.h"
#include "Path.h"
#include "Node.h"

const Node* Djikas::getNeighbor(const Node* node, const Path* path) {
    if(path->getA() == node) {
        return path->getB();
    }
    return path->getA();
}

const Node* Djikas::getLowest() {
    typedef pair<const Node*, int> MapPair;
    struct Compare
    {
        bool operator()(const MapPair& left, const MapPair& right) const
        {
            return left.second < right.second;
        }
    };
    MapPair min = *min_element(nodeMap.begin(), nodeMap.end(), Compare());
    return min.first;
}

Djikas::Djikas(vector<shared_ptr<Node>> graph) : graph(graph) {
    for(auto node : graph) {
        nodeMap[node.get()] = numeric_limits<int>::max();
    }
}

int Djikas::shortestPath(const Node* from, const Node* to) {
    if(from == to) {
        return nodeMap[from];
    }
    for (auto path : from->getPaths()) {
        auto neighbor = getNeighbor(from, path);
        if(nodeMap.find(neighbor) != nodeMap.end() && nodeMap[neighbor] > path->getWeight()) {
            nodeMap[neighbor] = path->getWeight();
        }
    }
    nodeMap.erase(from);
    return shortestPath(getLowest(), to);
}
