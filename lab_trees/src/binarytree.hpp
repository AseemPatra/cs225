/**
 * @file binarytree.hpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    Node* tmp1 = root->left;
    Node* tmp2 = root->right;
    mirrorHelper(root->left);
    mirrorHelper(root->right);
    root->left = tmp2;
    root->right = tmp1;
}
    template <typename T>
void BinaryTree<T>::mirrorHelper(Node* node) {
    if (node == NULL) {return;}
    Node* tmp1 = node->left;
    Node* tmp2 = node->right;
    mirrorHelper(node->left);
    mirrorHelper(node->right);
    node->left = tmp2;
    node->right = tmp1;
}
/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    std::stack<Node*> s;
    s.push(root->left);
    //Left side
    while (s.size() != 0) {
        if (s.top()->left != NULL) {
            s.push(s.top()->left);
            continue;
        }
        if (s.top()->right != NULL) {
            s.push(s.top()->right);
            continue;
        }
        int len = s.size();
        for (int index = 0; index < len; index++) {
            if (root->elem < s.top()->elem) {
                return false;
            }
            s.pop();
        }
    }
    //Right Side
    s.push(root->right);
    while (s.size() != 0) {
        if (s.top()->left != NULL) {
            s.push(s.top()->left);
            continue;
        }
        if (s.top()->right != NULL) {
            s.push(s.top()->right);
            continue;
        }
        int len = s.size();
        for (int index = 0; index < len; index++) {
            if (root->elem > s.top()->elem) {
                return false;
            }
            s.pop();
        }
    }
    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    T amount = recursiveLeftHelper(root->left, root->elem);
    if (amount > root->elem) {
        return false;
    }
    T amount2 = recursiveRightHelper(root->right, root->elem);
    if (amount2 < root->elem) {
        return false;
    }
    return true;
}

template <typename T>
T BinaryTree<T>::recursiveLeftHelper(Node* node, T data) const {
    if (node == NULL) {return data;}
    T amount = recursiveLeftHelper(node->left, data);
    if (amount > data) {
        return amount;
    }
    T amount2 = recursiveLeftHelper(node->right, data);
    if (amount2 > data) {
        return amount2;
    }
    return node->elem;
}

template <typename T>
T BinaryTree<T>::recursiveRightHelper(Node* node, T data) const {
    if (node == NULL) {return data;}
    T amount = recursiveRightHelper(node->left, data);
    if (amount < data) {
        return amount;
    }
    T amount2 = recursiveRightHelper(node->right, data);
    if (amount2 < data) {
        return amount2;
    }
    return node->elem;
}

