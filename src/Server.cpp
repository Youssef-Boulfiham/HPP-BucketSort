#include <iomanip> // for std::setw() and std::setfill()
#include <string>
#include "include/BucketSort.h"

#include "include/Server.h"

using namespace std;

Server::Server(const string &assignmentName)
{
    this->assignmentName = assignmentName;
    this->digitsDutch = {"eenheden", "tientallen", "honderdtallen"};
    this->boolDutch = {"negatief", "positief"};
}

//! time
std::chrono::system_clock::time_point Server::getTimeCurrent()
{
    return std::chrono::system_clock::now();
}

std::chrono::system_clock::time_point Server::getTimeStart()
{
    return this->timeStart;
}

// std::chrono::system_clock::time_point Server::getTimeCurrent() {
// return this->timeCurrent;
// }

std::string Server::timeDifferenceToString(
    std::chrono::duration<long long int, std::ratio<1, 1000000000>> timeDifference)
{
    auto nanoseconds = timeDifference.count();
    long long milliseconds = nanoseconds / 1000000;
    nanoseconds %= 1000000;
    long long seconds = milliseconds / 1000;
    milliseconds %= 1000;
    long long minutes = seconds / 60;
    seconds %= 60;
    long long hours = minutes / 60;
    minutes %= 60;
    long long days = hours / 24;
    hours %= 24;
    std::stringstream oss;
    if (days > 0)
    {
        oss << days << " dagen, ";
    }
    if (hours > 0 || days > 0)
    {
        oss << hours << " uren, ";
    }
    if (minutes > 0 || hours > 0 || days > 0)
    {
        oss << minutes << " minuten, ";
    }
    oss << seconds << " seconden, ";
    oss << std::setfill('0') << std::setw(3) << milliseconds << ",";
    oss << std::setfill('0') << std::setw(3) << nanoseconds / 1000000 << ",";
    oss << std::setfill('0') << std::setw(3) << (nanoseconds / 1000) % 1000;
    oss << " milisecondes";
    return oss.str();
}

//! list
std::string Server::getStringOfListOfInts(const std::vector<int> &list)
{
    std::ostringstream os;
    os << "{";
    for (int i = 0; i < list.size(); i++)
    {
        os << list[i];
        if (i != list.size() - 1)
        {
            os << ",";
        }
    }
    os << "}";
    return os.str();
}

static string getStringOfRandomIntsOfList(const std::vector<int> &list, int counts)
{
    std::ostringstream os;
    os << "{";
    if (list.empty() || counts <= 0)
    {
        os << "}";
        return os.str();
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, list.size() - 1);

    for (int i = 0; i < counts; i++)
    {
        int index = dis(gen);
        os << list[index];
        if (i != counts - 1)
        {
            os << ",";
        }
    }

    os << "}";
    return os.str();
}

string Server::getStringOfMiddleIntsOfList(const vector<int> &list, int counts)
{
    ostringstream os;

    int size = list.size();
    if (size == 0 || counts <= 0)
    {
        return "{}";
    }

    int start = (size - counts) / 2;
    int end = start + counts;
    os << "{";
    for (int i = start; i < end && i < size; ++i)
    {
        os << list[i];
        if (i != end - 1 && i != size - 1)
        {
            os << ",";
        }
    }
    os << "}";

    return os.str();
}

std::string Server::getStringOfListOfListsOfInts(const std::vector<std::vector<int>> &listOfLists)
{
    std::ostringstream os;
    if (listOfLists.size() == 1 && listOfLists[0].empty())
    {
        os << "{{}}";
    }
    else
    {
        os << "{";
        for (const auto &list : listOfLists)
        {
            if (list.empty())
            {
                os << "{}";
            }
            else
            {
                os << "{";
                for (int i = 0; i < list.size(); i++)
                {
                    os << list[i];
                    if (i != list.size() - 1)
                    {
                        os << ",";
                    }
                }
                os << "}";
            }
        }
        os << "}";
    }
    return os.str();
}

std::vector<int> Server::flattenListOfLists(const std::vector<std::vector<int>> &listOfLists)
{
    std::vector<int> list;
    for (const auto &listInList : listOfLists)
    {
        for (const auto &integer : listInList)
        {
            list.push_back(integer);
        }
    }
    return list;
}

std::vector<int> Server::listReplaceIndexed(std::vector<int> xs,
                                            int p,
                                            int q,
                                            std::vector<int> ys)
{
    xs.erase(xs.begin() + p, xs.begin() + q);
    xs.insert(xs.begin() + p, ys.begin(), ys.end());
    return xs;
}

int Server::getElementLowest(vector<int> list)
{
    /*
     achterhaal laagste getal in de lijst.
     */
    int elementLowest = INT_MAX;
    for (int element : list)
    {
        if (element < elementLowest)
        {
            elementLowest = element;
        }
    }
    return elementLowest;
}

std::vector<int> Server::getListSliced(std::vector<int> xs, int p, int q)
{
    vector<int> xsSliced = std::vector<int>(xs.begin() + p, xs.begin() + q);
    return xsSliced;
}

int Server::getElementHighest(vector<int> list)
{
    /*
     achterhaal laagste getal in de lijst.
     */
    int elementLowest = INT_MIN;
    for (int element : list)
    {
        if (element < elementLowest)
        {
            elementLowest = element;
        }
    }
    return elementLowest;
}

//! overige
int Server::stringToInt(char value)
{
    return value - '0';
}

std::string Server::intToString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string Server::getName() const { return this->assignmentName; }

int Server::run(const std::string &taskName,
                const std::vector<int> &listInput)
{
    BucketSort bucketSort = BucketSort(taskName, listInput);
    timeStart = getTimeCurrent();
    bucketSort.run();
    messageOfChildClass = bucketSort.gettMessageToParentClass();
    return 0;
}

std::ostream &operator<<(std::ostream &os, Server &Server)
{
    //    std::this_thread::sleep_for(std::chrono::seconds(2));
    // std::string verschil = Server.timeDifferenceToString(Server.setTimeCurrent() - Server.getTimeStart());
    // os << endl << "Server " << Server.getName() << std::endl;
    //    << "START TIME " << Server.setTimeToString(Server.getTimeStart()) << std::endl
    //    << "END TIME " << verschil;

    // cout << timeDifferenceToString(getTimeCurrent() - timeStart) << endl;

    os <<
    Server.messageOfChildClass << endl <<
    "duration=" << Server.timeDifferenceToString(Server.getTimeCurrent() - Server.timeStart) << endl;
    return os;
}