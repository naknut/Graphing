//
//  main.cpp
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-05.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#include <iostream>
#include <string>
#include "Path.h"
#include "Node.h"
#include "Djikas.h"

vector<shared_ptr<Node>> nodes;

shared_ptr<Node> getNodeWithName(string name) {
    for(auto node : nodes) {
        if(node->getName() == name)
            return node;
    }
    return nullptr;
}

void addNodeAndPaths(string labelA, string labelB, int weight) {
    shared_ptr<Node> a = getNodeWithName(labelA);
    shared_ptr<Node> b = getNodeWithName(labelB);
    
    if(!a) {
        a = shared_ptr<Node>(new Node(labelA));
        nodes.push_back(a);
    }
    if(!b) {
        b = shared_ptr<Node>(new Node(labelB));
        nodes.push_back(b);
    }
    new Path(a, b, weight);
}

int main(int argc, const char * argv[]) {
    if((argc - 1) % 3 != 0) {
        return -1;
    }
    
    int i = 1;
    do {
        addNodeAndPaths(argv[i], argv[i + 2], stoi(argv[i + 1]));
        i += 3;
    } while(i < argc);
    
    for (auto node : nodes) {
        for(auto path : node->getPaths()) {
            cout << node->getName() << " " << path->getWeight() << " ";
            if(path->getA() == node.get()) {
                cout << path->getB()->getName() << "\n";
            } else {
                cout << path->getA()->getName() << "\n";
            }
        }
    }
    
    auto djikas = shared_ptr<Djikas>(new Djikas(nodes));
    auto front = nodes.front();
    auto back = nodes.back();
    cout << front->getName() << djikas->shortestPath(front.get(), back.get()) << back->getName();
    
    return 0;
}
