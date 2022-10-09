/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    Node* y = t->left;
    t->right = y->left;
    y->left = t;
    y->height += 1;
    t->height -= 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    Node* y = t->right;
    t->left = y->right;
    y->right = t;
    y->height += 1;
    t->height -= 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    int bfactor = std::abs(subtree->right->height - subtree->left->height);
    if (bfactor <= 1) {
        return;
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if (subtree == NULL) {
        Node* newnode = new Node(key, value);
        subtree = newnode;
    } else {
        if (key == subtree->key) {
            return;
        }
        if (key < subtree->key) {
            insert(subtree->left, key, value);
        }
        if (key > subtree->key) {
            insert(subtree->right, key, value);
        }
    }
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL) {return;}
    
    if (key > subtree->key) {
        remove(subtree->right, key);
        return;
    }
    
    if (key < subtree->key) {
        remove(subtree->left, key);
        return;
    }

    if (subtree->right == NULL && subtree->left == NULL) {
        delete subtree;
        subtree = NULL;
        return;
    }

    if (subtree->right == NULL && subtree->left != NULL) {
        Node* tmp = subtree;
        subtree = subtree->left;
        delete tmp;
        return;
    }

    if (subtree->right != NULL && subtree->left == NULL) {
        Node* tmp = subtree;
        subtree = subtree->right;
        delete tmp;
        return;
    }

    if (subtree->right != NULL && subtree->left != NULL) {
        Node* empty;
        Node* tmp = subtree->left;
        if (tmp == NULL) {
            empty = NULL;
            subtree->key = empty->key;
            remove(subtree->left, empty->key);
            return;
        }
        while (tmp->right != NULL) {
            tmp = tmp->right;
        }
        empty = tmp;
        subtree->key = empty->key;
        remove(subtree->left, empty->key);
        return;
    }

    //if (subtree == NULL)
      //  return;

    //if (key < subtree->key) {
        // your code here
    //} else if (key > subtree->key) {
        // your code here
    //} else {
      //  if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
        //} else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
        //} else {
            /* one-child remove */
            // your code here
        //}
        // your code here
    //}
}
