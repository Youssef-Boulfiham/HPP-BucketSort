#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cmath>
#include <functional>
#include "src/include/Server.h"

#include <iostream>

struct TestCase
{
        std::string task;
        std::vector<int> digits;
};

std::vector<TestCase>
    testCases = {
        {"sorteren van positieve eenheden",
         {5, 6, 9, 6, 1, 8, 2, 0, 5, 6}},
        {"sorteren van positieve eenheden en tientallen",
         {31, 59, 5, 71, 60, 63, 60, 71, 40, 69}},
        {"sorteren van positieve eenheden, tientallen en honderdtallen",
         {233, 8, 176, 54, 87, 471, 24, 122, 538, 684}},
        {"sorteren van negatieve eenheden",
         {-9, 0, -9, -2, -5, -9, 0, -1, -5, -9}},
        {"sorteren van negatieve eenheden en tientallen",
         {-61, -39, -9, -46, -68, -13, -68, -13, -61, -96}},
        {"sorteren van positieve en negatieve eenheden, tientallen en honderdtallen",
         {-720, -485, -1, -52, -89, -134, -206, -165, -887, -755}},
        {"sorteren van positieve en negatieve eenheden",
         {6, -5, 2, -4, -1, -1, 9, -9, 6, -2}},
        {"sorteren van positieve en negatiev§±e eenheden en tientallen",
         {66, 99, 54, -97, -2, 81, 32, 61, 78, 96}},
        {"sorteren positieve en negatieve eenheden, tientallen en honderdtallen",
         {720, -5, -291, 2, -89, -134, -206, 165, 887, -755}}};
// add testcase; puur negatieve getallen
// TODO: add big-data

int main()
{
        // Generate a random vector to sort
        std::random_device rnd_device;
        std::mt19937 mersenne_engine{rnd_device()};
        std::uniform_int_distribution<int> dist{1, 1000};

        auto gen = [&dist, &mersenne_engine]()
        {
                return dist(mersenne_engine);
        };

        int IntsInList = 10;
        for (int i = 1; i <= IntsInList; ++i)
        {
                int n = std::pow(10, i);
                std::vector<int> randomVec(n);
                generate(std::begin(randomVec), std::end(randomVec), gen);
                testCases.push_back({to_string(i), randomVec});
        }
        cout << "Start:" << endl;
        // init
        Server server = Server("Inleveropgave 1: Bucket Sort");
        int startIndex = 0;
        int endIndex = testCases.size()-1; // limit=12
        // run
        cout << server.assignmentName << ";" << endl;
        for (int i = startIndex; i <= endIndex; i++)
        {
                server.run(testCases[i].task, testCases[i].digits);
                // eval
                cout << server << endl;
        }

        cout << "END." << endl;
        return 0;
}
