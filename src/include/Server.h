#pragma  once
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

class Server {
public:
    std::string assignmentName;
    std::chrono::system_clock::time_point timeStart;
    std::chrono::system_clock::time_point timeCurrent;
    std::chrono::duration<long long, std::ratio<1, 1000000000>> timeDifference{};

    //! time
    // static std::string setTimeToString(std::chrono::system_clock::time_point timeToConvert);

    std::chrono::system_clock::time_point getTimeStart();

    std::chrono::system_clock::time_point getTimeCurrent();

    static std::string timeDifferenceToString(std::chrono::duration<long long,
            std::ratio<1, 1000000000>> timeDifference);

    static std::chrono::system_clock::time_point setTimeCurrent();

    //! list
    static std::vector<int> flattenListOfLists(const std::vector<std::vector<int>> &listOfLists);

    static std::string getListOfLists(const std::vector<std::vector<int>> &listOfLists);

    static std::string printList(const std::vector<int> &list);

    std::vector<int> getListSliced(std::vector<int> xs,
                                   int p,
                                   int q);

    std::vector<int> listReplaceIndexed(std::vector<int> xs,
                                        int p,
                                        int q,
                                        std::vector<int> ys);

    int getElementLowest(vector<int> list);

    int getElementHighest(vector<int> list);

    //! overige
    friend std::ostream &operator<<(std::ostream &os, Server &Server);

    explicit Server(const std::string &assignmentName);

    static std::string intToString(int value);

    static int stringToInt(char value);

    [[nodiscard]] std::string getName() const;

    int run(const std::string &taskName,
                   const std::vector<int> &listUnsorted);

};

#endif // SERVER_H
