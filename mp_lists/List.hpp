/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */


template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
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
  return List<T>::ListIterator(NULL);
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
  
 ListNode *temp = head_;
 int count = length_ / 3;
 if(count > 0) {
   head_ = head_->next;
   head_->prev = NULL;
 }
 for(int i = 0; i < count; i++) {
   if(temp->prev != NULL) {
     temp->prev->next = temp->next;
     temp->next->prev = temp->prev;
   }
   else {
     temp->next->prev = NULL;
   }
   if(temp->next->next->next == NULL) {
     temp->prev = temp->next->next;
     temp->prev->next = temp;
     temp->next = NULL;
   }
   else {
     temp->next = temp->next->next->next;
     temp->prev = temp->next->prev;
     temp->next->prev = temp;
     temp->prev->next = temp;
   }
   temp = temp->next;
 }
 if(temp == NULL) {
   tail_ = tail_->next;
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
 ListNode *temp;
 while(cur != nextcur) {
   temp = cur->prev;
   cur->prev = cur->next;
   cur->next = temp;
   cur = cur->prev;
 }
 //std::cout<<"h1";
 if(precur != NULL) {
   precur->next = endPoint;
   endPoint->prev = precur;
 }
 else {
   endPoint->prev = NULL;
 }
 //std::cout<<"h2";
 if(nextcur != NULL) {
   startPoint->next = nextcur;
   nextcur->prev = startPoint;
 }
 else {
   startPoint->next = NULL;
 }
 temp = startPoint;
 startPoint = endPoint;
 endPoint = temp;

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
