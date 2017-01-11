//
//  Node.cpp
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-05.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#include "Node.h"
#include "Path.h"

int Node::getPathPosition(Path* path) {
    for(auto i = 0; i < paths.size(); i++)
        if(paths.at(i) == path)
            return i;
    return -1;
}

Node::Node(const string name) {
    this->name = name;
}

const vector<Path*> Node::getPaths() const {
    return paths;
}

const string Node::getName() const {
    return name;
}

void Node::addPath(Path* path) {
    if(paths.empty() || paths.back()->getWeight() <= path->getWeight()) {
        paths.push_back(path);
    } else {
        for(auto i = 0; i < paths.size(); i++) {
            if(paths.at(i)->getWeight() >= path->getWeight()) {
                paths.insert(paths.begin() + i, path);
                break;
            }
        }
    }
}

void Node::removePath(Path* path) {
    auto index = getPathPosition(path);
    if(index != -1) {
        paths.erase(paths.begin() + index);
    }
}
