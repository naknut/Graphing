//
//  Node.h
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-05.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <vector>
#include <string>

using namespace std;

class Path;

class Node {
    friend class Path;
private:
    vector<Path*> paths;
    string name;
    int getPathPosition(Path* path);
    void addPath(Path* path);
    void removePath(Path* path);
public:
    Node(const string name);
    const vector<Path*> getPaths() const;
    const string getName() const;
};

#endif /* Node_h */
