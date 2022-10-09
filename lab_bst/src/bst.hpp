/**
 * @file bst.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V BST<K, V>::find(const K& key)
{
    return find(root, key)->value;
}

template <class K, class V>
struct BST<K, V>::Node* & BST<K, V>::find(Node* & subtree, const K& key)
{    
    if (subtree != NULL) {
        if (subtree->key == key) {
            return subtree;
        }
        Node*& foundLeft = find(subtree->left, key);
        Node*& foundRight = find(subtree->right, key);
        if (key < subtree->key) {
            return foundLeft;
        }
        if (key > subtree->key) {
            return foundRight;
        }
    }
    return subtree;
}

template <class K, class V>
void BST<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void BST<K, V>::insert(Node*& subtree, const K& key, const V& value)
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
void BST<K, V>::swap(Node*& first, Node*& second)
{
    Node*& firstLoc = find(first->key);
    Node*& secondLoc = find(second->key);

    Node* fl = first->left;
    Node* fr = first->right;
    Node* sl = second->left;
    Node* sr = second->right;

    second->left = fl;
    second->right = fr;

    first->left = sl;
    first->right = sr;

    firstLoc = second;
    secondLoc = first;
}

template <class K, class V>
void BST<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void BST<K, V>::remove(Node*& subtree, const K& key)
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

}

template <class K, class V>
BST<K, V> listBuild(std::vector<std::pair<K, V>> inList){
    BST<K,V> tree;
    for (int index = 0; index < (int) inList.size(); index++) {
        K first = inList[index].first;
        V second = inList[index].second;
        tree.insert(first, second);
    }
    return tree;
}

template <class K, class V>
std::vector<int> allBuild(std::vector<std::pair<K, V>> inList){
    std::sort(inList.begin(), inList.end());
    BST<K, V> tree = listBuild(inList);
    std::vector<int> h;
    while (std::next_permutation(inList.begin(), inList.end())) {
        BST<K, V> add = listBuild(inList);
        h.push_back(add.height());
    }
    int max = h[0];
    for (int index = 0; index < (int) h.size(); index++) {
        if (h[index] > max) {
            max = h[index];
        }
    }
    int it = max;
    std::vector<int> build;
    while (it > -1) {
        build.push_back(0);
        it -= 1;
    }

    for (int index = 0; index < (int) h.size(); index++) {
        build[h[index]] += 1;
    }
    build[max] += 1;
    return build;
}