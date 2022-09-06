//
// Created by Muhammad Ashraf on 3/24/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSSTACK_H
#define INC_22S_FLIGHT_PLANNER_DSSTACK_H

#include "DSLinkedList.h"

template <typename T>
class DSStack{

public:
    DSStack();
    ~DSStack();
    DSStack(const DSStack& arg);
    DSStack<T>& operator=(const DSStack<T>& arg);
    void push(T& val);
    T& pop();
    T& peak();
    bool isEmpty();
    DSLinkedList<T>& listReturn();

private:

    DSLinkedList<T> myList;

};


template <typename T>
DSStack<T>::DSStack() {

}

template <typename T>
DSStack<T>::~DSStack() {

}

template <typename T>
DSStack<T>::DSStack(const DSStack<T> &arg) {

    myList = arg.myList;
}

template <typename T>
DSStack<T>& DSStack<T>::operator=(const DSStack<T> &arg){
    this->myList = arg.myList;
}

template <typename T>
T& DSStack<T>::peak() {
    //last item in link list and returns
    //return myList[myList.getSize()-1];
    return myList.getBack();
}

template <typename T>
T& DSStack<T>::pop(){
    //removes top and returns
    T temp = myList[myList.getSize()-1];
    myList.eraseBack(myList.getSize()-1);
    return temp;
}

template <typename T>
void DSStack<T>::push(T& val) {
    myList.push_back(val);
}

template <typename T>
bool DSStack<T>::isEmpty() {

    //returns if size is 0
    if(myList.getSize() == 0){
        return true;
    }else{
        return false;
    }
}

template <typename T>
DSLinkedList<T>& DSStack<T>::listReturn() {
    return myList;
}
#endif //INC_22S_FLIGHT_PLANNER_DSSTACK_H
