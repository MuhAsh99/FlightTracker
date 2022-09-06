//
// Created by Muhammad Ashraf on 3/31/22.
//

#ifndef INC_22S_FLIGHT_PLANNER_FLIGHTZ3_H
#define INC_22S_FLIGHT_PLANNER_FLIGHTZ3_H
#include "DSString.h"
#include "DSLinkedList.h"

class Flightz3{

public:

    Flightz3() = default;
    void setReqStart(DSString d);
    DSString& getReqStart();
    void setReqDest(DSString d);
    DSString& getReqDest();
    bool tOrc(DSString c);
    bool getTime();

private:
    DSString startReq;
    DSString destinationReq;
    bool isTime;
};

#endif //INC_22S_FLIGHT_PLANNER_FLIGHTZ3_H
