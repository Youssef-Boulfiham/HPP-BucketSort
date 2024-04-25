#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>
#include <string>
#include "Server.h"

using namespace std;

// struct Buckets {
// vector<vector<int>> Positive{10};
// vector<vector<int>> Negative{10};
// };
// struct DigitsCounts {
// int positive = 0;
// int negative = 0;
// };

class BucketSort : public Server
{
public:
    explicit BucketSort(string task, vector<int> listInput);

    string taskName;
    vector<int> listInput;
    vector<int> listOutput;
    vector<int> listTemp;
    vector<vector<int>> bucketsEmpty{19};
    vector<vector<int>> buckets;

    int DigitsCounts;

    void setDigitsCounts(const vector<int> &listTemp);

    void getDistributionPass(vector<int> listTemp, int digitsIndex);

    void gatheringPass(vector<vector<int>> buckets);

    void run();
    
    string gettMessageToParentClass();
    friend ostream &operator<<(ostream &os, BucketSort &BucketSort);
};

#endif // BUCKET_SORT_H
