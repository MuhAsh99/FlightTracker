//
// Created by Muhammad Ashraf on 3/29/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_ADJLIST_H
#define INC_22S_FLIGHT_PLANNER_ADJLIST_H

#include "DSLinkedList.h"
#pragma once

template <typename T>

class AdjList{

public:

    AdjList();
    ~AdjList();
    AdjList(const AdjList& arg);
    AdjList<T>& operator=(const AdjList<T>& arg);
    void addFlight(T& start, T& dest);
    DSLinkedList<T>& getDestination(T& dest);
    void resetIterator();
    DSLinkedList<T>& operator[] (const T& val);


private:

    DSLinkedList<DSLinkedList<T>> graph;


};

template <typename T>
AdjList<T>::AdjList() {


}


 template <typename T>
 AdjList<T>::AdjList(const AdjList<T> &arg) {

     graph = arg.graph;

 }

 template <typename T>
 AdjList<T>& AdjList<T>::operator=(const AdjList<T> &arg){

     this->graph = arg.graph;

     return *this;
 }

 template <typename T>
 AdjList<T>::~AdjList(){

 }

 template <typename T>
 void AdjList<T>::addFlight(T& start, T& dest) {

     //search through city list and see if origin city
     //if orig there, add city
     //if not orig create new city and add both

    bool found = false;
     for(int i = 0; i < graph.getSize(); i++){
         if(graph[i][0] == start){
             found = true;
             graph[i].push_back(dest);
             break;
         }
     }
     if (!found) {
         DSLinkedList<T> temp;
         temp.push_back(start);
         temp.push_back(dest);
         graph.push_back(temp);
     }

     //does reverse of above to go from dest to start
     bool found2 = false;
     for(int i = 0; i < graph.getSize(); i++){
         if(graph[i][0] == dest){
             found2 = true;
             graph[i].push_back(start);
             break;
         }
     }
     if (!found2) {
         DSLinkedList<T> temp;
         temp.push_back(dest);
         temp.push_back(start);
         graph.push_back(temp);
     }

 }

 template <typename T>
 DSLinkedList<T>& AdjList<T>::getDestination(T& dest) {
     //returns row
     for(int i = 0; i < graph.getSize(); i++){
         if(graph[i][0] == dest){
             return graph[i];
         }

     }
     //empty list returned
     DSLinkedList<T> newList;

     return newList;

 }

 template <typename T>
 DSLinkedList<T>& AdjList<T>::operator[] (const T& val){

     for(int i = 0; i < graph.getSize(); i++){
         if(graph[i].getHead() == val){
             return graph[i];
         }
     }
     return graph[0];
 }

 template <typename T>
 void AdjList<T>::resetIterator() {
     for(int i = 0; i < graph.getSize(); i++){
         graph[i].setIteratorFront();
         graph[i].getNext();
     }
 }

#endif //INC_22S_FLIGHT_PLANNER_ADJLIST_H
