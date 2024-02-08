#include "include/BucketSort.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cmath>
#include <functional>

using namespace std;

BucketSort::BucketSort(std::string taskName) : Server("inherit") {
    Server server = Server("inheritance");
    this->taskName = taskName;
//    this->digitsDutch = {"eenheden", "tientallen", "honderdtallen"};
//    this->boolDutch = {"negatief", "positief"};

};


std::ostream &operator<<(std::ostream &os, BucketSort &BucketSort) {
    os;
//    << BucketSort.printList(BucketSort.listUnsorted)
//       << ", " << BucketSort.printList(BucketSort.listSorted)
//       << std::endl;
    return os;
}


BucketSort::Buckets BucketSort::distributionPass(std::vector<int> list,
                                                 int digitsIndex, int digitsCount,
                                                 bool negativesInValues) {
    //
    //
    std::vector<std::vector<int>> bucketsPositive(10);
    std::vector<std::vector<int>> bucketsNegative(10);
    //     positive
    if (negativesInValues) {
        for (int i = 0; i < list.size(); i++) {
            int value = list[i];
//            TODO::
        }
    }
    Buckets buckets;
//    buckets.bucketsRight = bucketsPositive;
//    buckets.bucketsLeft = bucketsNegative;
    return buckets;
}

//std::vector<int> BucketSort::gatheringPass(BucketSort::Buckets buckets) {
//    std::vector<int> list;
//    for (const auto &bucketRight: buckets.bucketsRight) {
//        list.insert(list.end(), bucketRight.begin(), bucketRight.end());
//    }
//
//    for (const auto &bucketLeft: buckets.bucketsLeft) {
//        list.insert(list.end(), bucketLeft.begin(), bucketLeft.end());
//    }
//    return list;
//}

int BucketSort::getPositiveDigitsCount(const std::vector<int> &list) {
    int maxVal = INT_MIN;
    for (int i: list) {
        maxVal = std::max(abs(maxVal), i);
    }
    int digitsCount = 0;
    while (maxVal > INT_MAX) {
        maxVal /= 10;
        digitsCount++;
    }
    return digitsCount;
}

bool BucketSort::getNegativesInValues(std::vector<int> list) {
    for (int value: list) {
        if (value < 0) {
            return false;
        }
    }
    return true;
}

void BucketSort::run(std::vector<int> list) {
    this->listUnsorted = list;
    int digitsCount = this->getPositiveDigitsCount(list);
    bool negativesInValues = this->getNegativesInValues(list);
    //
    std::cout
            << printList(list);
//            << ", " << this->digitsDutch[digitsCount - 1]
//            << ", " << this->boolDutch[negativesInValues];
    //
    for (int digitsIndex = 0; digitsIndex < digitsCount; digitsIndex++) {
        cout
                << "i=" << pow(10, digitsIndex+1);
//        Buckets buckets = this->distributionPass(list, digitsIndex, digitsCount, negativesInValues);
//        list = this->gatheringPass(buckets);
    }
    std::cout << std::endl;
}


