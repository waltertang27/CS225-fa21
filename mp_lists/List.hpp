/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */


template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    ListNode* head_ = NULL;
    ListNode* tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode *cur;
  ListNode *temp;
  if(head_ != NULL) {
    cur = head_->next;
    while(cur != NULL) {
      temp = cur->next;
      delete cur;
      cur = temp;
    }
    delete head_;
    //delete cur;
    //delete temp;
  }

}


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  /*ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;
  
  if (head_ != NULL) {
    head_ -> prev = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  

  length_++;
  */
  ListNode *n = new ListNode(ndata);
  if(length_ == 0) {
    head_= n;
    tail_ = n;
    length_++;
  }
  else {
    n->prev = NULL;
    n->next = head_;
    head_->prev = n;
    head_ = n;
    length_++;
  }

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode *n = new ListNode(ndata);
  if(length_ == 0) {
    head_ = n;
    tail_ = n;
    length_++;
  }
  else {
    n->next = NULL;
    tail_->next = n;
    n->prev = tail_;
    tail_ = n;
    length_++;

  }
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  if(start == NULL) {
    return start;
  }

  ListNode * curr = start;

  for (int i = 0; i < splitPoint; i++) {
    curr = curr->next;
  }
  curr->prev->next = NULL;
  curr->prev = NULL;
  
  return curr;

}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  
  int count = length_ / 3;
  if(length_ < 3) {
      return;
  }
  else {
    
    ListNode *temp = head_;
    //std::cout<<temp->data;
    ListNode *temp2 = head_;

    temp = temp->next->next;
    //std::cout<<temp->data;

    
    //temp2->next = temp->next;
    head_ = temp2->next;
    temp2->next = temp->next;
    temp2->prev = temp;
    temp->next = temp2;
    
    //std::cout<<temp2_->next->data;
    //temp->next = temp2;
    //temp2->prev = temp;
    //head_ = temp2->next;
    //temp = temp->next;
    count--;
    //std::cout<<temp->data;
    ListNode *n = temp2->next;
    ListNode *n2 = n;

    //std::cout <<head_->data;
    //return;
    while(count != 0) {
      n2 = n2->next->next;
      //std::cout<<n2->data;
      n->next = n2->next;
      n->prev = n2;
      n2->next = n;
      if(n->next != NULL) {
        n = n->next;
        n2 = n;
        std::cout<<"ok";
      }
      std::cout << n->data<<std::endl;
      std::cout << n2->next->data<<std::endl;
    }
    if(n->next == NULL) {
      std::cout<<"hallo";
      tail_ = n;
    }
    cout << tail_ ->data;
    //n->next = NULL;
  }
    
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  return NULL;
}
