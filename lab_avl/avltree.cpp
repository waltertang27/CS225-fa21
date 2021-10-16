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
void AVLTree<K, V>::newHeight(Node *& subtree) {
    int h1 = heightOrNeg1(subtree->left);
    int h2 = heightOrNeg1(subtree->right);
    if(h1 > h2) {
        subtree->height = h1 + 1;
    }
    else if (h2 > h1) {
        subtree->height = h2 + 1;
    }
    else {
        subtree->height = h1 + 1;
    }

}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    Node* root_right_child = t->right;
    t->right = root_right_child->left;
    root_right_child->left = t;
    //rebalance(t);
    newHeight(t);
    t = root_right_child;
    newHeight(t);
    //rebalance(t);
    // your code here
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
    // your code here
    Node *pivot = t->left;
    t->left = pivot->right;
    pivot->right = t;
    newHeight(t);
    t = pivot;
    newHeight(t);
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
    // your code here
    int leftHeight = heightOrNeg1(subtree->left);
    int rightHeight = heightOrNeg1(subtree->right);
    if(rightHeight - leftHeight == -2) {
        if(heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left) == -1) {
            rotateRight(subtree);
        }
        else {
            rotateLeftRight(subtree);
        }
    }
        else if(rightHeight - leftHeight == 2) {
            if(heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left) == 1) {
                rotateLeft(subtree);
            }
            else {
                rotateRightLeft(subtree);
            }
        }
    newHeight(subtree);
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL) {
        Node *newNode = new Node(key, value);
        subtree = newNode;
    }
    /*
    if(subtree->key < key) {
        if(subtree->left == NULL) {
            Node *newNode = new Node(key, value);
            subtree->left = newNode;
            //newNode->height = subtree->height + 1;
        }
        else {
            insert(subtree->left, key, value);
        }
    }
        else if(subtree->key > key) {
            if(subtree->right == NULL) {
                Node *newNode = new Node(key, value);
                subtree->right = newNode;
                //newNode->height = subtree->height + 1;
            }
            else {
                insert(subtree->right, key, value);
            }
        
    }
    newHeight(subtree);\
    */
   else if(subtree->key < key) {
       insert(subtree->right, key, value);
       rebalance(subtree);
   }
   else if(subtree->key > key) {
       insert(subtree->left, key, value);
       rebalance(subtree);
   }
   else if(subtree->key == key) {
       subtree->value = value;
       return;
   }
   newHeight(subtree);

}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
            return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node *node = subtree->left;
            while(node->right != NULL) {
                node = node->right;
            }
            swap(node, subtree);
            remove(subtree->left, key);
        } else {
            /* one-child remove */
            // your code here
            Node *node;
            if(subtree->right == NULL) {
                node = subtree->left;
            }
            if(subtree->left == NULL) {
                node = subtree->right;
            }
            *subtree = *node;
            delete node;
            node = NULL;
        }
        // your code here

    }
        newHeight(subtree);
        rebalance(subtree);
}
