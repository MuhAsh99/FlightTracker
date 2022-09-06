//
// Created by MARK FONTENOT on 9/14/21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "DSLinkedList.h"
#include "NodeEastern.h"
#include "DSStack.h"
#include "DSString.h"


TEST_CASE("DSString", "[DSString]"){


    SECTION("substring"){
        DSString myString("Hello");
        DSString shortStr("Hel");
        REQUIRE(strcmp(myString.substring(0,3).c_str(),shortStr.c_str()) == 0);
        myString = "1347&%@&&$(@>?<}@&@_";
        shortStr = "7&%@";
        REQUIRE(strcmp(myString.substring(3,4).c_str(),shortStr.c_str()) == 0);
        myString = "I LOVE CODING";
        shortStr = "VE CO";
        REQUIRE(strcmp(myString.substring(4,5).c_str(), shortStr.c_str()) == 0);
    }

    SECTION("getLength"){
        DSString myString = "Hello";
        REQUIRE(myString.getLength() == 5);
        myString = "Spider-man";
        REQUIRE(!(myString.getLength() == 9));
        myString = "";
        REQUIRE(myString.getLength() == 0);
        myString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_-?><.,"":;~`|\"";
        REQUIRE(myString.getLength() == 59);

    }

    SECTION("DSString(const char * d)"){
        char*data = "wassup";
        DSString temp(data);
        REQUIRE(strcmp(temp.c_str(),"wassup") == 0);
        data = nullptr;
        DSString temp2(data);
        REQUIRE(temp2.c_str() == nullptr);
        data = "";
        DSString thirdString(data);
        DSString tempp(thirdString);
        REQUIRE(strcmp(tempp.c_str(), "") == 0);

    }

    SECTION("DSString(const DSString & d)"){
        char * data = "wassup";
        DSString firstString(data);
        DSString temp(firstString);
        REQUIRE(strcmp(temp.c_str(),"wassup") == 0);
        data = nullptr;
        DSString secondString(data);
        DSString tem(secondString);
        REQUIRE(tem.c_str() == nullptr);
        data = "";
        DSString thirdString(data);
        DSString tempp(thirdString);
        REQUIRE(strcmp(tempp.c_str(), "") == 0);

    }

    SECTION("operator= (const char* d)"){
        char * data = "wassup";
        DSString firstString = data;
        REQUIRE(strcmp(firstString.c_str(), "wassup") == 0);
        char * data2 = "0";
        DSString secString = data2;
        REQUIRE(strcmp(secString.c_str(), "0") == 0);
        char * data3 = "@^%$*&@><?|{}@*(#";
        DSString thirdString = data3;
        REQUIRE(strcmp(thirdString.c_str(),"@^%$*&@><?|{}@*(#") == 0);

    }

    SECTION("operator= (const DSString &d"){
        char * data = "wassup";
        DSString firstString = data;
        DSString secString = firstString;
        REQUIRE(strcmp(secString.c_str(), "wassup") == 0);
        char * data2 = "0";
        DSString thirdString = data2;
        REQUIRE(strcmp(thirdString.c_str(), "0") == 0);
        char * data3 = "@^%$*&@><?|{}@*(#";
        DSString fourthString = data3;
        REQUIRE(strcmp(fourthString.c_str(),"@^%$*&@><?|{}@*(#") == 0);

    }

    SECTION("operator== (const char*data)"){
        char * data = "wassup";
        DSString firstString = data;
        DSString secString = "wassup";
        REQUIRE(firstString == secString);
        DSString thirdString = "Wassup";
        REQUIRE(!(firstString == thirdString));
        data = "I LOVE CODING";
        firstString = data;
        secString = "I LOVE CODING";
        REQUIRE(firstString == secString);
    }

    SECTION("operator== (const DSString&) const"){
        char * data = "wassup";
        DSString firstString = data;
        DSString secString = "wassup";
        REQUIRE(firstString == secString);
        DSString thirdString = "Wassup";
        REQUIRE(!(firstString == thirdString));
        data = "I LOVE CODING";
        firstString = data;
        secString = "I LOVE CODING";
        REQUIRE(firstString == secString);
    }

    SECTION("bool operator> (const DSString&) const"){
        char * data = "wassup";
        DSString firstString = data;
        DSString thirdString = "hello";
        REQUIRE((firstString > thirdString));
        REQUIRE(!(thirdString > firstString));
        thirdString = "hello";
        REQUIRE(!(thirdString > firstString));
    }

    SECTION("operator> (const char* ptr)"){
        char * data = "wassup";
        DSString firstString = data;
        DSString secString = "hello";
        REQUIRE(firstString > secString);
        REQUIRE(!(secString > firstString));
        secString = "hello";
        REQUIRE(!(secString > firstString));
    }

    SECTION("operator< (const char*)"){
        char * data = "wassup";
        DSString firstString = data;
        DSString secString = "hello";
        REQUIRE(secString < firstString);
        REQUIRE(!(firstString < secString));
        secString = "hello";
        REQUIRE(!(firstString < secString));

    }

    SECTION("operator< (const DSString&) const"){
        char * data = "wassup";
        DSString firstString = data;
        DSString secString = "hello";
        REQUIRE(secString < firstString);
        REQUIRE(!(firstString < secString));
        secString = "hello";
        REQUIRE(!(firstString < secString));
    }

    SECTION("char& operator[] (const int)"){
        char * data = "ligma";
        DSString firstString = data;
        REQUIRE(firstString[2] == 'g');
        firstString[3] = 'b';
        REQUIRE(firstString == "ligba");
        char * red = "Power Rangers";
        firstString = red;
        firstString[14] = '\0';
        REQUIRE(firstString == "Power Rangers");
    }

//    SECTION("operator+ (const DSString&)"){
//        char * data = "hello";
//        DSString firstString = data;
//        DSString secondString = "world";
//        REQUIRE(firstString + secondString == "helloworld");
//    }

    SECTION("toInt(DSString &d"){
        char * data = "9";
        DSString string = data;
        int x = string.toInt();
        REQUIRE(x == 9);
    }

}
