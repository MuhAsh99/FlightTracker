//
// Created by Muhammad Ashraf on 3/31/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHTZ2_H
#define INC_22S_FLIGHT_PLANNER_FLIGHTZ2_H

#include "DSString.h"
#include "DSLinkedList.h"
//#include "City.h"
#pragma once

class Flightz2 {


public:

    Flightz2() = default;
    void setStart(DSString d);
    DSString getStart();
    void setDest(DSString d);
    DSString getDest();
    void setTime(int d);
    int getTime();
    void setCost(int d);
    int getCost();
    void setAirline(DSString d);
    DSString getAirline();


    //bool request(char c);
    //calculate best routes
    //iterative backtracking
    //takes the output of that and returns isPossible & list
    //if the list of routes has a length of 0, then it's not possible

private:

    DSString airline;
    DSString start;
    DSString destination;
    int time;
    int cost;
    char ordering; //either t or c
    bool isPossible;
    DSLinkedList<Flightz2>myList;
    //some way of keeping track of best sechedule

};


#endif //INC_22S_FLIGHT_PLANNER_FLIGHTZ2_H
