#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template <typename T> class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(){
        right = left = nullptr;
    }

    Node(T x) : data(x), left(nullptr), right(nullptr) {}

};

template <typename T> class binarySeachTree{
private:
    Node<T>* root;
    int size;

    void inOrderHelper(Node<T>* node) {
        if (node == nullptr) return;
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }

    void preOrderHelper(Node<T>* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }

    void postOrderHelper(Node<T>* node) {
        if (node == nullptr) return;
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->data << " ";
    }

    bool lookup(Node<T>* node, T val){
        if(node == nullptr){
            return false;
        }else{
            if(val == node->data){
                return true;
            }

            if(val > node->data){
                return lookup(node->right, val);
            }else{
                return lookup(node->left, val);
            }
        }
    }

    void deleteTree(Node<T>* node){
        if(node != nullptr){
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
	    }
    }

    int depth(Node<T>* node){
        if (node == nullptr)
        return 0;
        else {
            /* compute the depth of each subtree */
            int lDepth = depth(node->left);
            int rDepth = depth(node->right);
    
            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
public:
    binarySeachTree(){
        root = nullptr;
        size = 0;
    }

    ~binarySeachTree(){
        deleteTree(root);
    }

    void insert(T data) {
        if (root == nullptr) {
            root = new Node<T>(data);
            size++;
            return;
        }

        Node<T>* cur = root;
        while (true) {
            if (data < cur->data) {
                if (cur->left == nullptr) {
                    cur->left = new Node<T>(data);
                    size++;
                    return;
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = new Node<T>(data);
                    size++;
                    return;
                }
                cur = cur->right;
            }
        }
        size++;
    }

    void inOrder(){
        inOrderHelper(root);
        std::cout << std::endl;
    }

    void preOrder(){
        preOrderHelper(root);
        std::cout << std::endl;
    }

    void postOrder(){
        postOrderHelper(root);
        std::cout << std::endl;
    }

    int getSize(){
        return size;
    }

    bool lookup(T val){
	    return lookup(this->root, val);
    }

    int height(){
        return depth(root);
    }

};

#endif