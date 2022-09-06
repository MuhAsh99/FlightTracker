//
// Created by Muhammad Ashraf on 3/29/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_CITY_H
#define INC_22S_FLIGHT_PLANNER_CITY_H

#include <fstream>
#include "Flightz2.h"
#include "Flightz3.h"
#include "AdjList.h"
#include "NodeEastern.h"
#include "DSStack.h"
#include "DSString.h"
//#include "DSLinkedList.h"

class City{

public:

    City();

    void openFile(char ** file);

    void openFile2(char ** file);

    void print(char ** file);

    void bestResults();

    int bestT_C(DSLinkedList<DSLinkedList<DSString>> everyPath);

    //DSVector<DStack<flights>> iterativeBacktracking(const DSAdjacencyList& list, start, end);

    void iterativeBacktracking();
  //  friend std::ostream& operator<< (std::ostream&, const City& c);


private:

    DSLinkedList<Flightz2> infoList;
    DSLinkedList<Flightz3> requestList;
    AdjList<DSString> adjacent;
    DSStack<DSString> paths;
   // char * data;

};

#endif //INC_22S_FLIGHT_PLANNER_CITY_H
