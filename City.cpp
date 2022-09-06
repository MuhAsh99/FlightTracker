//
// Created by Muhammad Ashraf on 3/29/22.
//

#include "City.h"

City::City(){

}
void City::openFile(char **file) {

    std::ifstream myFile(file[1]);
    if(myFile.is_open()){
        std::cout<<"I love Daddy Fontenot"<<std::endl;
        char * buffer = new char[1000];
        myFile.getline(buffer, 1000);
        int num = atoi(buffer);
        //std::cout<<"hi"<<std::endl;
        for (int i = 0; i < num; i++){

            //stores 5 different items in the file

            myFile.getline(buffer, 1000, ' ');
            DSString startCity(buffer);
            myFile.getline(buffer, 1000, ' ');
            DSString destCity(buffer);
            myFile.getline(buffer, 1000, ' ');
            DSString cost(buffer);
            myFile.getline(buffer, 1000, ' ');
            DSString time(buffer);
            myFile.getline(buffer, 1000, '\n');
            DSString airline(buffer);

           // std::cout<<startCity<<std::endl;
            //call addflight with first two inputs of each line
            adjacent.addFlight(startCity, destCity);


           //want to push back info from 1st input file into private list
            Flightz2 myFlight;

            myFlight.setStart(startCity);


            myFlight.setDest(destCity);


            int numCost = cost.toInt();
            myFlight.setCost(numCost);


            int numTime = time.toInt();
            myFlight.setTime(numTime);


            myFlight.setAirline(airline);
            infoList.push_back(myFlight);


            //create flight object that contains all 5 things, maybe vector


        }//end while
        myFile.close();
        openFile2(file);
    }//end if

}

void City::openFile2(char **file) {
    std::ifstream myFile2(file[2]);
    if (myFile2.is_open()) {
        std::cout << "I love Daddy Fontenot" << std::endl;
        char * buffer = new char[1000];
        myFile2.getline(buffer, 1000);

        while (!myFile2.eof()) {
            char * buffer = new char[1000];
            myFile2.getline(buffer, 1000, ' ');
            DSString sReq(buffer);
            myFile2.getline(buffer, 1000, ' ');
            DSString dReq(buffer);
            myFile2.getline(buffer, 1000);
            DSString choice(buffer);

            //info from second file
            Flightz3 myFlightReq;

            myFlightReq.setReqStart(sReq);

            myFlightReq.setReqDest(dReq);

            myFlightReq.tOrc(choice);
            requestList.push_back(myFlightReq);





        }//end while

        myFile2.close();
        iterativeBacktracking();
        print(file);
    }

}

void City::print(char **file) {

    std::ofstream bestFlightsAvailableByMuhammadAshrafYoureWelcome(file[3]);

    bestFlightsAvailableByMuhammadAshrafYoureWelcome<<"hello"<<std::endl;

    bestFlightsAvailableByMuhammadAshrafYoureWelcome.close();

}//END PRINT

void City::iterativeBacktracking() {
    //create stack of DSString

    //create list of paths
    //loop through flight plans
    adjacent.resetIterator();


   for(int i = 0; i < requestList.getSize(); i++){
       DSLinkedList<DSLinkedList<DSString>> everyPath;
        paths.push(requestList[i].getReqStart());

       //goes until nothing left in the stack
        while(!paths.isEmpty()){

            //if reach end of plan
            //then add new plan
            if(paths.peak() == requestList[i].getReqDest()){
                everyPath.push_back(paths.listReturn());
                paths.pop();
            }

            //find row in adjlist where start city corresponds to top city in stack
            if(adjacent[paths.peak()].itIsBack()){  //checks every possibility
                adjacent[paths.peak()].setIteratorFront();     //inc iterator
                adjacent[paths.peak()].getNext();
                paths.pop();
            }else{
                DSString c = adjacent[paths.peak()].getIterator();
                if(paths.listReturn().find(c)){
                    adjacent[paths.peak()].getNext();
                    //if curr city not already on path then add if
                }else{
                    adjacent[paths.peak()].getNext();
                    paths.push(c);
                }

            }



        }
       bestT_C(everyPath);

    }

}// THIS IS MY ITERATIVE BACKTRACKING FUNCTION. WHEN I RUN THE FUNCTION I GET STUCK IN AN INFINITE LOOP.
// I ORIGINALLY HAD A SEG FAULT, BUT I FIXED THE ISSUE. HOWEVER I WAS UNABLE TO GET RID OF THE INFINITE LOOP
// IF I WERE COMMENT OUT THE FUNCTION AND WHERE I CALL IT ON LINE 103, THERE WOULD BE NO INFINITE LOOP, BUT
// THE PROGRAM WOULD NOT HAVE MY ITERATIVE BACKTRACKING INCLUDED


int City::bestT_C(DSLinkedList<DSLinkedList<DSString>> everyPath) {


        //goes through 2D list
        for(int j = 0; j < everyPath.getSize(); j++){
            int totalCost = 0;
            int totalTime = 0;

            //assigns info at index of 2D list to city1
            DSString city1 = everyPath[j][0];

            for(int k = 1; k < everyPath[j].getSize(); k++){

                DSString city2 = everyPath[j][k];
                city1 = city2;  //prev dest is set to city1

                for(int m = 0; m < infoList.getSize(); m++){
                    if (infoList[m].getStart() == city1 && infoList[m].getDest() == city2) {
                        totalTime += infoList[m].getTime();
                        totalCost += infoList[m].getCost();
                        break;
                    }

                }
            }
        }

}//end bestT_C





