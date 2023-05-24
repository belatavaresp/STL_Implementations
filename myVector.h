#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>

template <typename T> class myVector{
    private:
    T* vec; //address
    int capacity; //total number of elements that fit the vector
    int size; //total numbers currently in the vector

    public:
    //constructor
    myVector(){
        vec = new T[1];
        capacity = 1;
        size = 0;
    }

    //destructor
    ~myVector(){
        delete [] vec;
    }

    //push elements into the vector
    void push(T data){
        //vector full
        if(capacity == size){
            T* temp = new T[2 * capacity];

            for(int i = 0; i < capacity; i++){
                temp[i] = vec[i];
            }

            delete [] vec;
            capacity *= 2;
            vec = temp;
        }

        vec[size] = data;
        size++;
    }

    //push element in specific index
    void push(T data, int index)
    {
        // if index is equal to capacity then this
        // function is same as push defined above
        if (index == capacity)
            push(data);
        else
            vec[index] = data;
    }

    //function to stract element at index
    T get(int index){
        //if index is in range
        if(index < size)
            return vec[index];
        
        assert(0);
    }

    //remove last element
    void pop(){
        size--;
    }

    //return current size of vector
    int getSize(){
         return size; 
    }

    //return full capacity of the vector
    int getCapacity(){
        return capacity;
    }

    //print elements in the vector
    void print(){
        for(int i = 0; i < size; i++){
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    int find(T data){
        for(int i = 0; i < size; i++){
            if(vec[i] == data)
                return i;
        }
        return -1;
    }

    // access element at index
    T& at(int index) {
        if (index >= 0 && index < size) {
            return vec[index];
        }
        else {
            throw std::out_of_range("Index out of range");
        }
    }
};

#endif