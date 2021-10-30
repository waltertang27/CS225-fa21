/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(Dim <= curDim || curDim < 0) {
      return false;
    }
    if(first[curDim] < second[curDim]) {
      return true;
    }
    if(first[curDim] == second[curDim]) {
      return first < second;
    }

    return false;
}

//find the distance between two points
template <int Dim>
double KDTree<Dim>::findDistance(const Point<Dim> &first, const Point<Dim> &second) const{
  double distance = 0;
  for(int i = 0; i < Dim; i++) {
      distance += (first[i] - second[i]) * (first[i]- second[i]);
  }
  //return sqrt(distance);
  return distance;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    double d1 = findDistance(target, potential);
    double d2 = findDistance(target, currentBest);
    if(d1 < d2) {
      return true;
    }
    if(d1 > d2) {
      return false;
    }
    else {
      return potential < currentBest;
    }

}

//used to delete nodes. Used in the destructor
template <int Dim>
void KDTree<Dim>::clear(KDTreeNode *subroot) {
  if(subroot == NULL) {
    return;
  }
  if(subroot->left != NULL) {
    clear(subroot->left);
  }
  if(subroot->right != NULL) {
    clear(subroot->right);
  }
  delete subroot;
  subroot = NULL;
}

//does a deep copy of another KDTreeNode. copies second into first
template <int Dim>
void KDTree<Dim>::copy(KDTreeNode *first, KDTreeNode *second) {
  if(second == NULL) {
    return;
  }
  first = new KDTreeNode();
  first->point = second->point;
  copy(first->left, second->left);
  copy(first->right, second->right);
}

template <int Dim>
void KDTree<Dim>::buildTree(vector<Point<Dim> > &points, int dim, unsigned left, unsigned right, KDTreeNode *&curRoot) {
  if(points.empty()) {
    return;
  }
  if(left < 0 || right < 0 || left > right) {
    return;
  }
  if(left >= points.size() || right >= points.size()) {
    return;
  }
  //if(left <= right) {
    int middle = (left + right) / 2;
  //}

  Point<Dim> temp = quickSelect(points, dim, left, right, middle);
  curRoot = new KDTreeNode(temp);
  size++;
  buildTree(points, (dim + 1) % Dim, left, middle -1, curRoot->left);
  buildTree(points, (dim + 1) % Dim, middle + 1, right, curRoot->right);
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim> >& newPoints)
{
    /**
     * @todo Implement this function!
     */
    if(newPoints.empty()) {
      size = 0; 
      root = NULL;
      return;
    }
    vector<Point<Dim> > points;
    points.assign(newPoints.begin(), newPoints.end());
    size = 0;
    buildTree(points, 0, 0, points.size() - 1, root);
    
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   copy(root, other->root);
   size = other->size;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  clear(root);
  copy(this->root, rhs.root);
  size = rhs.size();
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  clear(root);
}


template <int Dim>
unsigned KDTree<Dim>::partition(vector<Point<Dim> > &list, int dim, unsigned left, unsigned right, unsigned pivotIndex) {
    Point<Dim> pivot = list[pivotIndex];
    unsigned count = left;
    Point<Dim> temp = list[pivotIndex];
    list[pivotIndex] = list[right];
    list[right] = temp;
    for(unsigned i = left; i < right; i++) {
      if(smallerDimVal(list[i], pivot, dim)) {
        Point<Dim> temp2 = list[count];
        list[count] = list[i];
        list[i] = temp2;
        count++;
      }
    }
    Point<Dim> temp3 = list[count];
    list[count] = list[right];
    list[right] = temp3;
    return count;
}
template <int Dim>
Point<Dim> KDTree<Dim>::quickSelect(vector<Point<Dim> > &list, int dim, unsigned left, unsigned right, unsigned x) {
  if(left == right) {
    return list[left];
  }
  unsigned pivotIndex = (left + right) / 2;
  pivotIndex = partition(list, dim, left, right, pivotIndex);
  if(pivotIndex == x) {
    return list[x];
  }
  if(x > pivotIndex) {
    return quickSelect(list, dim, pivotIndex + 1, right, x);
  }
  else {
    return quickSelect(list, dim, left, pivotIndex - 1, x);
  }
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> &query, int dim, KDTreeNode *curRoot) const {
  if(curRoot == NULL) {
    return NULL;
  }
  if(curRoot->left == NULL && curRoot->right == NULL) {
     return curRoot->point;
  }
  Point<Dim> nearest = curRoot->point;
  Point<Dim> tempNearest = nearest;
  bool recurse = false;
  //recurse = smallerDimVal(query, curRoot->point, dim);
  //checks for left subtree
  if(smallerDimVal(query, nearest, dim)) {
    recurse = true;
    if(curRoot->left != NULL) {
      nearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->left);
    }
    else if(curRoot->right != NULL) {
      nearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
    }
  }
  //otherwise, go right
  else if (!smallerDimVal(query, nearest, dim)) {
    recurse = false;
    if(curRoot->right != NULL) {
      nearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
    }
    else if(curRoot->left != NULL) {
      nearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->left);
    }
 //   else {
 //     p = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
 //   }
      //recurse = false;
  }
  
 //else if(!smallerDimVal(query, curRoot->point, dim) && curRoot->right != NULL) {
 //  recurse = false;
 //  temp = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
 //}
  //if curRoot is closer
  if(shouldReplace(query, nearest, curRoot->point)) {
    nearest = curRoot->point;
  }

  double radius = findDistance(query, nearest);
  double splitDistance = (curRoot->point[dim] - query[dim]) * (curRoot->point[dim] - query[dim]);
  if(radius >= splitDistance) {
      if(recurse && curRoot->right != NULL) {
        tempNearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
        if(shouldReplace(query, nearest, tempNearest)) {
          nearest = tempNearest;
        }
      }
      else if(!recurse && curRoot->left != NULL) {
        tempNearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->left); 
        if(shouldReplace(query, nearest, tempNearest)) {
          nearest = tempNearest;
        }
      }
  }
  return nearest;
}


template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    
    return findNearestNeighbor(query, 0, root);

}

