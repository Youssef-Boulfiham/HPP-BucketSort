#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
#include <random>


using namespace std;

class Server
{
public:
    string assignmentName;
    string messageOfChildClass;
    chrono::system_clock::time_point timeStart;
    chrono::system_clock::time_point timeCurrent;
    // plaatshouder voor berekende tijdverschillen
    chrono::duration<long long, ratio<1, 1000000000>> timeDifference{};
    vector<string> digitsDutch;
    vector<string> boolDutch;

    //    this->digitsDutch = {"eenheden", "tientallen", "honderdtallen"};
    //    this->boolDutch = {"negatief", "positief"};

    //! time
    // static string setTimeToString(chrono::system_clock::time_point timeToConvert);

    chrono::system_clock::time_point getTimeStart();

    chrono::system_clock::time_point getTimeCurrent();

    static string timeDifferenceToString(chrono::duration<long long,
                                                                    ratio<1, 1000000000>>
                                                  timeDifference);

    static chrono::system_clock::time_point setTimeCurrent();

    //! list
    static string getStringOfListOfInts(const vector<int> &list);
    static string getStringOfRandomIntsOfList(const vector<int> &list, int counts);
    static string getStringOfMiddleIntsOfList(const vector<int> &list, int counts);
    static string getStringOfListOfListsOfInts(const vector<vector<int>> &listOfLists);

    static vector<int> flattenListOfLists(const vector<vector<int>> &listOfLists);
    vector<int> getListSliced(vector<int> xs, int p, int q);
    vector<int> listReplaceIndexed(vector<int> xs, int p, int q, vector<int> ys);
    int getElementLowest(vector<int> list);
    int getElementHighest(vector<int> list);

    //! overige
    friend ostream &operator<<(ostream &os, Server &Server);

    explicit Server(const string &assignmentName);

    static string intToString(int value);

    static int stringToInt(char value);

    [[nodiscard]] string getName() const;

    int run(const string &taskName,
            const vector<int> &listUnsorted);
};

#endif // SERVER_H
