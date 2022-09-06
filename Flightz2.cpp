//
// Created by Muhammad Ashraf on 3/31/22.
//

#include "Flightz2.h"


void Flightz2::setStart(DSString d) {
    start = d;
}

DSString Flightz2::getStart() {
    return start;
}

void Flightz2::setDest(DSString d) {
    destination = d;
}

DSString Flightz2::getDest() {
    return destination;
}

void Flightz2::setCost(int d) {
    cost = d;
}

int Flightz2::getCost() {
    return cost;
}

void Flightz2::setTime(int d) {
    time = d;
}

int Flightz2::getTime() {
    return time;
}

void Flightz2::setAirline(DSString d) {
    airline = d;
}

DSString Flightz2::getAirline() {
    return airline;
}

//bool Flightz::request(char c) {
//   bool b = false;
//    if(c == 'T'){
//
//    }
//}