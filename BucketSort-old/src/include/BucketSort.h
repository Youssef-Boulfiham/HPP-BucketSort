#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>
#include <string>
#include "Server.h"

using namespace std;


class BucketSort : public Server {
public:
    explicit BucketSort(string task);

    string taskName;
    vector<int> listSorted;
    vector<int> listUnsorted;
    int digitsNegativeCount;
    struct Buckets {
        vector<vector<int>> bucketsPositive;
        vector<vector<int>> bucketsNegative;
    };

    void run(vector<int> listUnsorted);

    Buckets distributionPass(vector<int> list, int digitsIndex, int digitsCount, bool negativesInValues);

    vector<int> gatheringPass(Buckets buckets);

    int getPositiveDigitsCount(const vector<int> &list);

    bool digitsNegativeCount(vector<int> list);

    friend ostream &operator<<(ostream &os, BucketSort &BucketSort);

};

#endif // BUCKET_SORT_H
