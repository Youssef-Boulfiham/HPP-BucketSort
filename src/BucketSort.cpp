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


BucketSort::Buckets BucketSort::distributionPass(std::vector<int> listUnsorted, int digitsIndex) {
    //
    std::vector<std::vector<int>> bucketsPositive(10);
    for (int i = 0; i < listUnsorted.size(); i++) {
        cout << listUnsorted[i] << ";" << endl;
        // plaats in buckets
        bucketsPositive[listUnsorted[i]].push_back(listUnsorted[i]);
    }
    

cout << getListOfLists(bucketsPositive) << endl;
    // std::vector<std::vector<int>> bucketsNegative(10);
    //     positive
    // if (negativesInValues) {
        // for (int i = 0; i < list.size(); i++) {
            // int value = list[i];
//            TODO::
        // }
    // }
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
    // niet getest op puur negative lijst
    int digitsCount = 0;
    int maxVal = INT_MIN;
    // bepaal hoogste waarde
    for (int i: list) {
        maxVal = max(abs(maxVal), i);
    }
    // bepaal aantlal digits
    while (maxVal > 1) {
        maxVal /= 10;
        digitsCount++;
    }
    return digitsCount;
}

// bool BucketSort::getNegativesInValues(std::vector<int> list) {
    // for (int value: list) {
        // if (value < 0) {
            // return false;
        // }
    // }
    // return true;
// }

void BucketSort::run(std::vector<int> listUnsorted) {
    // print input
    for (int i = 0; i < listUnsorted.size() -1; i++) {
        cout << listUnsorted[i] << ", ";
    } cout << listUnsorted[listUnsorted.size()-1] << endl;

    // bepaal aantal positieve getallen
    int digitsPositiveCount = this->getPositiveDigitsCount(listUnsorted);
    // bepaal aantal negatieve getallen
    // int digitsNegativeCount = this->getNegativeDigitsCount(listUnsorted);

    for (int i = 0; i < digitsPositiveCount ; i ++) {
        cout << "digitsPositiveCount=" << digitsPositiveCount << ", i=" << i <<endl;
        Buckets buckets = this->distributionPass(listUnsorted, i);

    }


    // for (int digitsIndex = 1; digitsIndex < digitsPositiveCount; digitsIndex++) {
        // cout << "digitsIndex=" << digitsIndex << ", digitsPositiveCount=" << digitsPositiveCount << endl;
        // Buckets buckets = this->distributionPass(listUnsorted, digitsIndex);
        // listUnsorted = this->gatheringPass(buckets);
    // }
    std::cout << std::endl;
}


