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
  ListNode* curr = head_;
  while (curr != NULL) {
    ListNode* tmp = curr->next;
    delete curr;
    curr = tmp;
  }
  delete curr;
  head_ = NULL;
  tail_ = NULL;
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
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;
  if (head_ != NULL) {
    head_ -> prev = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  head_ = newNode;
  length_++;

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
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = NULL;
  newNode -> prev = tail_;
  if (tail_ != NULL) {
    tail_ -> next = newNode;
  }
  if (head_ == NULL) {
    head_ = newNode;
  }
  tail_ = newNode;
  length_++;
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
  ListNode * curr = start;
  if (splitPoint == 0 || start == NULL) {
    return curr;
  }
  int i = 0;
  while (i != splitPoint) {
    if (curr == NULL) {
      break;
    }
    curr = curr->next;
    i++;
  }

  if (curr != NULL) {
    curr->prev->next = NULL;
    curr->prev = NULL;
  }
   
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
    if (length_ < 3) {return;}
    int minDex = 0;
    bool flag = true;
    ListNode* curr = head_;
    while (flag) {
      if (curr == NULL) {break;}
      if (length_ - minDex > 2) {
        ListNode* first = curr;
        ListNode* second = first->next;
        ListNode* third = second->next;
        ListNode* before = curr->prev;
        if (curr == head_) {head_ = second;}
        if (third == tail_) {tail_ = first;}
        if (before != NULL) {
          before->next = second;
        }
        curr = third->next;
        
        first->next = curr;
        first->prev = third;

        third->next = first;
        third->prev = second;

        second->next = third;
        second->prev = before;

        if (curr != NULL) {
          curr->prev = first;
        }
      } else {
        flag = false;
      }
      minDex += 3;
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

  //Initialize edge nodes and starting node
  ListNode* curr = startPoint;
  ListNode* prior = curr->prev;
  ListNode* after = endPoint->next;

  ListNode* ahead = curr->next;

  curr->next = after;
  curr->prev = ahead;

  curr = ahead;

  //Switching wire connections are we traverse
  while (curr != endPoint) {
    ahead = curr->next;
    ListNode* pre = curr->prev;
    curr->next = pre;
    curr->prev = ahead;
    curr = ahead;
    if (curr == endPoint) {break;}
  }

  //Pluggin in the front
  endPoint->next = endPoint->prev;
  endPoint->prev = prior;

  //Connecting the edges, either by the head/tail or the earlier nodes
  if (head_ != startPoint) {
    prior->next = curr;
  } else {
    head_ = endPoint;
  }
  if (tail_ != endPoint) {
    after->prev = startPoint;
  } else {
    tail_ = startPoint;
  }
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
  ListNode* start = head_;
  ListNode* curr = start;
  while (start != NULL) {
    curr = start;
    for (int index = 0; index < n - 1; index++) {
      if (curr == tail_) {
        reverse(start, curr);
        return;
      }
      curr = curr->next;
    }
    reverse(start, curr);
    start = start->next;
  }
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
  ListNode* start;
  if (second->data < first->data) {
    start = second;
    second = second->next;
  } else {
    start = first;
    first = first->next;
  }

  bool fin = true;
  if (first == NULL || second == NULL) {
    fin = false;
  }

  ListNode* end = start;
  while (fin) {

    if (second->data < first->data || second->data == first->data) {
      second->prev = end;
      end->next = second;
      second = second->next;
      end = end->next;
      if (first == NULL || second == NULL) {
        fin = false;
      }
      continue;
    } else {
      first->prev = end;
      end->next = first;
      first = first->next;
      end = end->next;
      if (first == NULL || second == NULL) {
        fin = false;
      }
      continue;
    }
  }
  if (first == NULL) {
    second->prev = end;
    end->next = second;
  } else {
    first->prev = end;
    end->next = first;
  }
  return start;
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
  ListNode* print = start;
  while (print != NULL) {
    print = print->next;
  }
  if (chainLength == 1) {return start;}
  if (chainLength == 2) {
    ListNode* sec = start->next;
    start->next = NULL;
    return merge(mergesort(start, 1), mergesort(sec, 1));
  }

  ListNode* first = start;
  int half = chainLength / 2;
  for (int index = 0; index < half; index++) {
    first = first->next;
  }
  first->prev->next = NULL;
  first->prev = NULL;

  ListNode* sort1 = mergesort(start, half);
  ListNode* sort2 = mergesort(first, chainLength - half);
  return merge(sort1, sort2);
}
