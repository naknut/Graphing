//
//  Djikas.hpp
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-08.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#ifndef Djikas_hpp
#define Djikas_hpp

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Node;
class Path;

class Djikas {
private:
    vector<shared_ptr<Node>> graph;
    map<shared_ptr<Node>, int> nodeMap;
    const shared_ptr<Node> getNeighbor(const shared_ptr<Node> to, const Path* path);
    const shared_ptr<Node> getLowest();
    int calculateNeighbors(Node& node);
public:
    Djikas(vector<shared_ptr<Node>> graph);
    int shortestPath(const shared_ptr<Node> from, const shared_ptr<Node> to);
};

#endif /* Djikas_hpp */
