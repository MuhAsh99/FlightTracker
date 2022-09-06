//
// Created by Muhammad Ashraf on 3/31/22.
//

#include "Flightz3.h"

void Flightz3::setReqStart(DSString d) {
    startReq = d;
}

DSString& Flightz3::getReqStart() {
    return startReq;
}

void Flightz3::setReqDest(DSString d) {
    destinationReq = d;
}

DSString& Flightz3::getReqDest() {
    return destinationReq;
}

bool Flightz3::tOrc(DSString c) {
    if(c == "T"){
        isTime = true;
    }else{
        isTime = false;
    }
}

bool Flightz3::getTime() {
    return isTime;
}


