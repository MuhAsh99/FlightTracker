//
// Created by Muhammad Ashraf on 2/15/22.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H
#include "DSString.h"
#include "iostream"
template <typename T>

class DSVector{

public:

    DSVector();
    DSVector(const DSVector& arg);
    ~DSVector();
    DSVector<T>& operator= (const DSVector<T>& arg);
    T& push_back(const T& val);
    T& operator[] (const int num);
    void insert( int pos, const T value );
    void removeAt(const int pos);
    T& removeVal(const T& value);
    int find(const T& value);
    T& end(const T& value);
    int sizeOf();
    int findSomething(const T& value, int index);
    T& sortStuff();
    void insertionSort();

    friend std::ostream& operator<< (std::ostream& out, DSVector<T>& vec){
        /*
        for(int i = 0; i < vec.sizeOf(); i++){
            out<<vec[i]<< " ";
        }
        out<<std::endl;
         */

//        for(int i = 0; i < vec.sizeOf(); i++){
//            std::cout << vec[i] << " ";
//        }
//        std::cout << std::endl;
        return out;
    }


private:

    T * data;

    int size = 0;

    int capacity;

    void resize();


};


template <typename T>
DSVector<T>::DSVector(){

    capacity = 10;

    size = 0;

    data = new T[capacity];
}

template <typename T>
DSVector<T>::~DSVector(){
    delete[] data;
    size = 0;
    capacity = 0;
}
template <typename T>
DSVector<T>::DSVector(const DSVector<T>& arg){

    capacity = arg.capacity;

    size = arg.size;

    data = new T[capacity];

    for(int i = 0; i < size; i++){
        data[i] = arg.data[i];
    }

}
template <typename T>
DSVector<T>& DSVector<T>::operator=(const DSVector<T>& arg){
    if(&arg != this){

       // delete[]data;

        this->size = arg.size;

        this->capacity = arg.capacity;

        this->data = new T[this->capacity];

        for(int i = 0; i < size; i++){
            data[i] = arg.data[i];
        }

    }
    return *this;
}


template <typename T>
T& DSVector<T>::push_back(const T& val){

    if(size == capacity) {
        resize();
    }

    data[size] = val;

    size++;

    return data[size - 1];
}

template <typename T>
void DSVector<T>::resize(){
    T * temp = new T[capacity * 2];

    for(int i = 0; i < capacity; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
}


template <typename T>
T& DSVector<T>::operator[] (const int num){
    //return item at certain index
    return data[num];
}
template <typename T>
void DSVector<T>:: insert( int pos, const T value ) {
    T * temp = new T[size];
    for(int i = pos; i < size; i++) {
        temp[i] = data[i];
    } // start at index and then copy data into temp

    data[pos] = value; //data at index equals value passed in

    for(int i = pos; i < size; i++){
        data[i + 1] = temp[i];
    } // copy info from temp into data at one index higher
    delete[] temp;

    size++;

    if(size == capacity){
        resize();
    }

}


template <typename T>
void DSVector<T>::removeAt(const int pos){

    T * temp = new T[size];

    for(int i = 0; i < pos; i++){
       temp[i] =  data[i];
    }//copy info up until pos into temp


    for(int i = pos + 1; i < size; i++){
        temp[i - 1] = data[i];
    } // copy info from temp into data at one index lower
    delete[] data;

    data = temp;

    size--;



}

template <typename T>
T& DSVector<T>::removeVal(const T& value){

    for(int i = 0; i < size; i++){
        if(data[i] == value){
            removeAt(i);
            i--;
        } //remove at value and incase there is repeat i-- removes each instance of what to be removed
    } //copy info up until pos into temp


    return data;
}

template <typename T>
int DSVector<T>:: find(const T& value){
    for(int i = 0; i < size; i++){
        if(data[i] == value){
            return i;
        }

    }
    return -1; //if unable to find value, return -1 for error
}
template <typename T>
int DSVector<T>::findSomething(const T& value, int index){
    for(int i = index; i < size; i++){
        if(data[i] == value){
            return i;
        }

    }
    return -1; //if unable to find value, return -1 for error
}

template <typename T>
int DSVector<T>:: sizeOf(){
    return size;
}


template <typename T>
void DSVector<T>:: insertionSort()
{
    //this sorting algo was obtained from https://www.geeksforgeeks.org/insertion-sort/
    T key;
    int i, j;
    for (i = 1; i < size; i++)

    {
        key = data[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}








#endif //INC_21F_PA02_DSVECTOR_H
