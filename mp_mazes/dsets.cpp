/* Your code here! */
#include "dsets.h"


//Creates n unconnected root nodes at the end of the vector.
void DisjointSets::addelements(int num) {
    for(int i = 0; i < num; i++) {
        set.push_back(-1);
    }
}

//This function should compress paths and works as described in lecture.
int DisjointSets::find(int elem) {
    if(set[elem] < 0) {
        return elem;
    }
    int overheating = find(set[elem]);
    set[elem] = overheating;
    return overheating;

}

/*
This function should be implemented as union-by-size.

That is, when you setunion two disjoint sets, the smaller (in terms of number of nodes) should point at the larger. This function works as described in lecture, except that you should not assume that the arguments to setunion are roots of existing uptrees.

Your setunion function SHOULD find the roots of its arguments before combining the trees. If the two sets are the same size, make the tree containing the second argument point to the tree containing the first. (Note that normally we could break this tie arbitrarily, but in this case we want to control things for grading.)
*/
void DisjointSets::setunion(int a, int b) {
    if(find(a) == find(b)) {
        return;
    }
    int x = find(a);
    int y = find(b);
    if(set[x] > set[y]) {
        set[y] = set[x] + set[y];
        set[x] = y;
    }
    else {
        set[x] = set[x] + set[y];
        set[y] = x;
    }
}
//This function should return the number of nodes in the up-tree containing the element.
int DisjointSets::size(int elem) {
    int x = find(elem);
    return -1 * set[x];
}

