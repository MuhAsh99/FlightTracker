//
// Created by Muhammad Ashraf on 3/24/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H

#include "NodeEastern.h"

template <typename T>
class DSLinkedList{

public:

    DSLinkedList(); //done
    ~DSLinkedList(); //done
    DSLinkedList(const DSLinkedList& arg); //done
    DSLinkedList<T>& operator= (const DSLinkedList<T>& arg); //done
    void push_back(const T& val); //done
    void push_front(const T& val); //done
    T& operator[] (const int num);
    bool find(const T& value); //find
    int getSize(); //done
    void eraseAll(); //done
    //void erase(T);
   // void eraseAt(const int num); //done
    void insert( int pos, const T value ); //done
    void setIterator(const int num);
    void setIteratorFront(); //done
    void setIteratorBack(); //done
    T& getIterator(); //done
    T& getNext(); //done
    T& getPrev(); //done
    bool itIsBack();
    void insertionSort();
    T& getHead();
    T& getBack();
    void eraseBack(const int num);


private:

  int size;
  NodeEastern<T> * head;
  NodeEastern<T> * back;
  NodeEastern<T> * iterator;


};

template <typename T>
DSLinkedList<T>::DSLinkedList(){

    size = 0;

    head = nullptr;

    back = nullptr;

    iterator = nullptr;


}

template <typename T>
DSLinkedList<T>::~DSLinkedList() {

    void eraseAll();

}

template <typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T> &arg) {


    // check to make sure if head is nullptr
    if(arg.head == nullptr){
        head = nullptr;
        back = nullptr;
    }else{

        //create new node that copies dereferenced head
        head = new NodeEastern<T>(*arg.head);
        NodeEastern<T>* nodey = arg.head->getNext();
        NodeEastern<T>* nodeyBro = head;
        while(nodey != nullptr){
            nodeyBro->setNext(new NodeEastern<T>(*nodey));
            nodeyBro->getNext()->setPrev(nodeyBro);
            nodeyBro = nodeyBro->getNext();
            nodey = nodey->getNext();
        }
        back = nodeyBro;
    }


}

template <typename T>
DSLinkedList<T>& DSLinkedList<T>::operator=(const DSLinkedList<T> &arg) {

    this->size = arg.size;

    this->head = arg.head;

    this->back = arg.back;

    return *this;
}

template <typename T>
void DSLinkedList<T>::push_back(const T &val) {

    //create node
    NodeEastern<T>* newNode = new NodeEastern<T>;
    newNode->setData(val);
    //sets head to nullptr if nothing in node
    if(size == 0){
       head = newNode;
    }else{
        //back is set to next ptr
      back->setNext(newNode);
        //back ptr is then set to prev
      newNode->setPrev(back);
    }
    //gets rid of previous ptr to back and has it pointing to new node
    back = newNode;

    size = size + 1;

}

template <typename T>
void DSLinkedList<T>::push_front(const T &val) {
    //create node
    NodeEastern<T>* newNode = new NodeEastern<T>;
    newNode->setData(val);

    //sets head to nullptr if nothing in node
    if(size == 0){
        back = newNode;
    }else{
        //front is set to next ptr
        head->setPrev(newNode);
        //back ptr is then set to prev
        newNode->setNext(head);

    }

    //gets rid of previous ptr to back and has it pointing to new node
    head = newNode;

    size = size + 1;

}

template <typename T>
int DSLinkedList<T>::getSize() {
    return size;
}

template <typename T>
bool DSLinkedList<T>::find(const T &value) {

    iterator = head;

    for(int i = 0; i < size; i++){
        if(iterator->getData() == value){
            return true;
        }
        iterator = iterator->getNext();
    }

    return false;
}

template <typename T>
void DSLinkedList<T>::eraseAll() {

    while(size > 0){
        eraseBack(0);
    }
}


template <typename T>
void DSLinkedList<T>::insert(int pos, const T value) {

    NodeEastern<T>* newNode = new NodeEastern<T>;

    iterator = head;

    for(int i = 0; i < pos; i++){
        iterator = iterator->getNext();
    }

    //set value of node to passed in value
    newNode->setData(value);

    //sets next node to new node
    iterator->getPrev()->setNext(newNode);

    //sets prev node to new node
    iterator->getNext()->setPrev(newNode);

    //sets prev pointer of new node to prev
    newNode->setPrev(iterator->getPrev());

    //sets next pointer of new node to next
    newNode->setNext(iterator->getNext());

}

template <typename T>
T& DSLinkedList<T>::operator[] (const int num) {

    iterator = head;

    for(int i = 0; i < num; i++){
        iterator = iterator->getNext();
    }

    return iterator->getData();
}

template <typename T>
void DSLinkedList<T>::setIterator(const int num) {

    //IDK IF THIS WORKS, NEED TO DO CATCH TO TEST IT
    this[num];

}

template <typename T>
T& DSLinkedList<T>::getNext() {
    //increment the iterator
    iterator = iterator->getNext();
    return iterator->getData();
}

template <typename T>
T& DSLinkedList<T>::getPrev() {

    iterator = iterator->getPrev();
    return iterator;
}

template <typename T>
void DSLinkedList<T>::setIteratorFront() {
    iterator = head;
}

template <typename T>
void DSLinkedList<T>::setIteratorBack() {
    iterator = back;
}

template <typename T>
bool DSLinkedList<T>::itIsBack() {
    if(iterator == back){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
void DSLinkedList<T>:: insertionSort()
{
    //this sorting algo was obtained from https://www.geeksforgeeks.org/insertion-sort/
    T p;
    int i, j;
    for (i = 1; i < size; i++)

    {

        p = this[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && this[j] > p)
        {
            this[j + 1] = this[j];
            j = j - 1;
        }
        this[j + 1] = p;
    }
}

template <typename T>
T& DSLinkedList<T>::getIterator() {
    return iterator->getData();
}

template <typename T>
T& DSLinkedList<T>::getHead() {
    return head->getData();
}

template <typename T>
T& DSLinkedList<T>::getBack() {
    return head->getData();
}


template <typename T>
void DSLinkedList<T> :: eraseBack(const int num){
    back = back->getPrev();
    delete back->getNext();
    size--;
}



#endif //INC_22S_FLIGHT_PLANNER_DSLINKEDLIST_H
