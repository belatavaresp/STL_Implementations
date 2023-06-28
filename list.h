#ifndef SIMPLYLIST_H
#define SIMPLYLIST_H

#include <iostream>
#include <assert.h>

template <typename T> class Node {
public:
    T data;
    Node<T>* next;
    Node(){
        next = nullptr;
    }
};

template <typename T> class List {
    private:
    Node<T>* head;
    Node<T>* tail;
    int _size;

    public:
    //constructor
    List(){
        head = tail = nullptr;
        _size = 0;
    }  

    //destructor
    ~List(){
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    //check if list is empty
    bool isEmpty(){
        if(head == nullptr && _size == 0){
            return true;
        }else{
            return false;
        }
    }

    //return size of list
    int getSize(){
        return _size;
    }

    //return element at top
    T getHead(){
        return head->data;
    }

    //return last element
    T getTail(){
        return tail->data;
    }

    //insert at beggining
    void insertHead(T data){
        Node<T>* newNode = new Node<T>();
        newNode->data = data;
        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = head;
        }

        _size++;
    }

    //remove first element
    void removeHead(){
        Node<T>* aux = head->next;
        delete head;
        head = aux;
        _size--;
    }

    //remove last element
    void removeTail(){
        if (head == nullptr)
        return;
  
        if (head->next == nullptr) {
            delete head;
            return;
        }
    
        // Find the second last node
        Node<T>* second_last = head;
        while (second_last->next->next != nullptr)
            second_last = second_last->next;
    
        // Delete last node
        delete (second_last->next);
    
        // Change next of second last
        second_last->next = NULL;

        _size--;
    }

    //insert at end
    void insertTail(T data){
        Node<T>* newNode = new Node<T>();
        newNode->data = data;
        newNode->next = nullptr;

       if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        _size++;

    }

    void print(){
        Node<T>* current = head;
        while(current != nullptr){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear(){
        ~List();
    }

    //returns element at index
    T get(int index){
        Node<T>* current = head;
  
        // the index of the
        // node we're currently
        // looking at
        int count = 0;
        while (current != nullptr) {
            if (count == index)
                return (current->data);
            count++;
            current = current->next;
        }
    
        /* if we get to this line,
        the caller was asking
        for a non-existent element
        so we assert fail */
        assert(0);
    }

    //returns index of a element if it is in the list
    int find(T data){
        Node<T>* current = head;
        int ind = 0;
        while(current != nullptr){
            if(current->data == data)
                return ind;
            ind++;
            current = current->next;
        }  
        return -1;
    }
};

#endif
