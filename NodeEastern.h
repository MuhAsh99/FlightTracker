//
// Created by Muhammad Ashraf on 3/24/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_NODEEASTERN_H
#define INC_22S_FLIGHT_PLANNER_NODEEASTERN_H

template <typename T>
class NodeEastern{

public:

    NodeEastern();
    ~NodeEastern();
    NodeEastern(const NodeEastern& arg);
    NodeEastern<T>& operator=(const NodeEastern<T>& arg);
    T& getData();
    void setData(T d);
    NodeEastern<T> * getNext();
    void setNext(NodeEastern<T> * n);
    NodeEastern<T> * getPrev();
    void setPrev(NodeEastern<T> * p);

private:

    T data;

    NodeEastern<T> * next;

    NodeEastern<T> * prev;
};

template <typename T>
NodeEastern<T>::NodeEastern(){
    next = nullptr;
    prev = nullptr;
}

template <typename T>
NodeEastern<T>::~NodeEastern(){


}

template <typename T>
NodeEastern<T>::NodeEastern(const NodeEastern<T> &arg) {


    data = arg.data;
//
//    for(int i = 0; i < size; i++){
//        head[i] = arg.head[i];
//        back[i] = arg.back[i];

    next = arg.next;
  //  next = arg.next;


    prev = arg.prev;
   // prev = arg.prev;

}

template <typename T>
NodeEastern<T>& NodeEastern<T>::operator=(const NodeEastern<T> &arg) {


        this->data = arg.data;

        this->next = arg.next;

        this->prev = arg.prev;

        return *this;
}


template <typename T>
void NodeEastern<T>::setData(T d) {

    data = d;
}

template <typename T>
T& NodeEastern<T>::getData() {
    return data;
}

template <typename T>
void NodeEastern<T>::setNext(NodeEastern<T> * n) {

    next = n;
}

template <typename T>
NodeEastern<T>* NodeEastern<T>::getNext(){
    return next;
}

template <typename T>
void NodeEastern<T>::setPrev(NodeEastern<T> * p) {

    prev = p;
}

template <typename T>
NodeEastern<T>* NodeEastern<T>::getPrev(){
    return prev;
}


#endif //INC_22S_FLIGHT_PLANNER_NODEEASTERN_H
