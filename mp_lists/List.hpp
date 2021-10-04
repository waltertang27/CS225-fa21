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
  if(length_ == 0) {
    head_ = NULL;
    tail_ = NULL;
  }
  else {
    ListNode *cur;
    ListNode *temp;
    cur = head_;
    while(cur != NULL) {
      temp = cur->next;
      delete cur;
      cur = temp;
    }
    head_ = NULL;
    tail_ = NULL;
    cur = NULL;
    temp = NULL;
    length_ = 0;
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
  
  if(splitPoint >= length_) {
    return start;
  }

  if(splitPoint == 0) {
    return start;
  }
  

  ListNode * curr = start;

  for (int i = 0; i < splitPoint; i++) {
    if(curr->next == NULL) {
      return start;
    }
    curr = curr->next;
    
  }
  if(curr != NULL) {
    curr->prev->next = NULL;
    curr->prev = NULL;
    tail_ = curr->prev;
    return curr;
  }
  return start;

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
    //std::cout<<temp->data;
    temp2->next = temp->next;
    temp2->prev = temp;
    temp->next = temp2;
    //std::cout<<temp2->next->prev->data;
    //if(temp2->next != NULL) {
      //temp2->next->prev = temp2;
      //std::cout<<"hello";
      //std::cout<<temp2->data;
    //}
    //std::cout<<temp2->next->data;
    //std::cout<<temp2_->next->data;
    //temp->next = temp2;
    //temp2->prev = temp;
    //head_ = temp2->next;
    //temp = temp->next;
    count--;
    temp2->next = temp2->next->next;

    //std::cout<<temp->data;
    ListNode *n = temp2->next->prev;

    ListNode *n2 = n;

    //std::cout <<head_->data;
    //return;
    while(count != 0) {
      n2 = n2->next->next;
      //std::cout<<n->next->data;
      //std::cout<<n2->data;
      //std::cout<<n->prev;
      //n->prev->next = n->next;
      //n2->next = n;
      //n->prev->next = n->next->next;
      
      //n->prev = n2;
      //n2->next = n;
      n->next = n2->next;
      n->prev = n2;
      n2->next = n;
      if(n->next != NULL) {
        //n->next->prev = n;
        n = n->next;
        n2 = n;
        std::cout<<"goes here";
      }
      //std::cout<<temp->next->next->data;
      count--;
    }
    if(n->next == NULL) {
      tail_ = n;
    }
    //std::cout << tail_ ->data;
    //n->next = NULL;
  }
    
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  if(head_ == NULL) {
    return;
  }
  if(length_ == 0) {
    return;
  }
  if(tail_ == NULL) {
    return;
  }
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
  //edge cases
  if(startPoint == NULL || endPoint == NULL || startPoint == endPoint) {
    return;
  }
  //if(startPoint == endPoint) {
  //  return;
  //}
 ListNode *cur = startPoint;
 ListNode *precur = startPoint->prev;
 ListNode *nextcur = endPoint->next;
 while(cur != nextcur) {
   ListNode *temp = cur->prev;
   cur->prev = cur->next;
   cur->next = temp;
   cur = cur->prev;
 }
 //std::cout<<"h1";
 if(precur == NULL) {
   endPoint->prev = NULL;
 }
 else {
  ListNode *temp = precur;
  temp->next = endPoint;
  endPoint->prev = temp;
  
 }
 //std::cout<<"h2";
 if(nextcur == NULL) {
   startPoint->next = NULL;
 }
 else {
  ListNode *temp = nextcur;
  temp->prev = startPoint;
  startPoint->next = temp;
 }
 std::swap(startPoint, endPoint);

  //ListNode *temp = startPoint;
  //startPoint = endPoint;
  //endPoint = temp;

 if(head_== endPoint) {
   head_ = startPoint;
 }
 if(tail_ == startPoint) {
   tail_ = endPoint;
 }

 //std::cout<<"h3";
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
  if(n <= 1) {
    return;
  }
  if(head_ == NULL || length_ == 0) {
    return;
  }
  if(n >= length_) {
    reverse(head_, tail_);
    return;
  }

  ListNode *cur = head_;
  ListNode *temp = head_;
  while(temp != NULL) {
    for(int i = 1; i < n; i++) {
      if(temp->next != NULL) {
        temp = temp->next;
      }
      else {
        reverse(cur, tail_);
        return;
      }
    } 
     //std::cout<<"test1";
     reverse(cur, temp);
     //std::cout<<"test2";
     //if(temp->next == NULL) {
     //  return;
     //}
     cur = temp->next;
     temp = cur;
     //std::cout<<"test3";
     if(temp == NULL) {
     //std::cout<<"hiyaaa";
     }
  }
  //std::cout<<"why am i segfaulting?";
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

  //edge cases
  if(first == NULL) {
    if(second == NULL) {
      return NULL;
    }
    else {
      return second;
    }
  }
  if(second == NULL) {
    return first;
  }

  ListNode *cur;
  if(first->data < second->data) {
    cur = first;
    first = first->next;
  }
  else {
    cur = second;
    second = second->next;
  }
  ListNode *temp = cur;
  while(first != NULL && second != NULL) {
    if(first->data < second->data) {
      first->prev = temp;
      temp->next = first;
      first = first->next;
    }
    else {
      second->prev = temp;
      temp->next = second;
      second = second->next;
    }
    if(temp->next != NULL) {
      temp = temp->next;
    }
  }
  //check the end nodes
  if(first == NULL) {
    if(second == NULL) {
      return cur;
    }
    else {
      second->prev = temp;
      temp->next = second;
      temp = temp->next;
      second = second->next;
    }
  }
  if(second == NULL) {
    if(first != NULL) {
      first->prev = temp;
      temp->next = first;
      temp = temp->next;
      first = first->next;
    }
  }
   return cur;
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
  
  //edge cases
  if(chainLength == 0 || chainLength == 1) {
    return start;
  }
  ListNode *list1, *list2;
  ListNode *temp = split(start, chainLength / 2);
  list2 = mergesort(temp, chainLength - chainLength / 2);
  list1 = mergesort(start, chainLength / 2);
  return merge(list1, list2);
}
