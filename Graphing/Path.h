//
//  Path.h
//  Graphing
//
//  Created by Marcus Isaksson on 2017-01-05.
//  Copyright © 2017 Naknut Industries. All rights reserved.
//

#ifndef Path_h
#define Path_h

using namespace std;

class Node;

class Path {
private:
    int weight;
    shared_ptr<Node> a;
    shared_ptr<Node> b;
public:
    Path(shared_ptr<Node> a, shared_ptr<Node> b, int weight);
    ~Path();
    int getWeight();
    const Node* getA() const;
    const Node* getB() const;
    Path operator<(const Path& other);
};

#endif /* Path_h */
