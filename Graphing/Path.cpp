//
//  Path.cpp
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-05.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#include "Node.h"
#include "Path.h"

Path::Path(shared_ptr<Node> a, shared_ptr<Node> b, int weight) : a(a), b(b), weight(weight) {
    a->addPath(this);
    b->addPath(this);
}

Path::~Path() {
    a->removePath(this);
    b->removePath(this);
}

int Path::getWeight() {
    return weight;
}

const shared_ptr<Node> Path::getA() const {
    return a;
}

const shared_ptr<Node> Path::getB() const {
    return b;
}

Path Path::operator<(const Path &other) {
    if(weight < other.weight) {
        return *this;
    }
    return other;
}
