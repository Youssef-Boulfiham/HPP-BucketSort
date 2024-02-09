#include "include/BucketSort.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cmath>
#include <functional>

using namespace std;

BucketSort::BucketSort(std::string taskName, vector<int> listInput) : Server("inheritance")
{
    Server server = Server("inheritance");
    this->taskName = taskName;
    this->listInput = listInput;
};

void BucketSort::setDigitsCounts(const std::vector<int> &listTemp)
{
    int digitsMax = listTemp[0];
    for (int i : listTemp)
    {
        digitsMax = max(abs(digitsMax), i);
    }
    // cout << "digitsMax=" << digitsMax << endl;

    if (digitsMax >= 0)
    {
        digitsMax = to_string(digitsMax).length();
    }
    else
    {
        digitsMax = to_string(digitsMax).length() - 1;
    }
    // cout << "digitsMax=" << digitsMax << endl;
    DigitsCounts = digitsMax;
}

void BucketSort::getDistributionPass(vector<int> listTemp, int digitsIndex)
{
    buckets = bucketsEmpty;
    for (int j = 0; j < listTemp.size(); j++)
    {
        // bereken waarde op digit-positie
        int valueAtDigitsIndex = (listTemp[j] / static_cast<int>(pow(10, digitsIndex))) % 10;
        // bereken indexpositie
        int bucketsIndex = valueAtDigitsIndex + 9;
        // plaats in bucketPP
        buckets[bucketsIndex].push_back(listTemp[j]);
    }
}

void BucketSort::gatheringPass(vector<vector<int>> buckets)
{
    listTemp = flattenListOfLists(buckets);
}

void BucketSort::run()
{
    listTemp = listInput;
    // cout << this->getStringOfList(listTemp) << endl;
    // tel het aantal positieve en negatieve getallen
    setDigitsCounts(listTemp);
    for (int i = 0; i < this->DigitsCounts; i++)
    {
        getDistributionPass(listTemp, i);
        gatheringPass(buckets);
    }
        listOutput = listTemp;
        // cout << getStringOfList(listTemp) << endl;

}

string BucketSort::gettMessageToParentClass()
{
    return "taskName=" + taskName + "\ninput=" + getStringOfMiddleIntsOfList(listInput, 10) + "\noutput=" + getStringOfMiddleIntsOfList(listOutput, 10);
}

std::ostream &operator<<(std::ostream &os, BucketSort &BucketSort)
{
    os <<
    "taskName=" << BucketSort.taskName <<
    "\ninput=" << BucketSort.getStringOfMiddleIntsOfList(BucketSort.listInput, 10) <<
    "\noutput=" << BucketSort.getStringOfMiddleIntsOfList(BucketSort.listOutput, 10) << endl;
    return os;
}