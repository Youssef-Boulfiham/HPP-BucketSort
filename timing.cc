#include <random>    // random_device, mt19937, mersenne_engine
#include <algorithm> // generate
#include <chrono>    // Timing functions
#include <iostream>  // Printing results

using namespace std::chrono;

void sort(std::vector<int>& vec) {
    int n = vec.size();
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> ns = { 10, 100, 1000, 10000 };

    for (int n : ns) {
        // Generate a random vector to sort
        std::random_device rnd_device;
        std::mt19937 mersenne_engine {rnd_device()};
        std::uniform_int_distribution<int> dist {1, 1000};

        auto gen = [&dist, &mersenne_engine](){
                       return dist(mersenne_engine);
                   };

        std::vector<int> vec(n);

        generate(std::begin(vec), std::end(vec), gen);

        // Start timing
        steady_clock::time_point begin = steady_clock::now();

        // Do the thing!
        std::cout << vec[2] << " " << vec[1] << std::endl;
        sort(vec);

        // Stop timing
        steady_clock::time_point end = steady_clock::now();

        // Calculate and print time
        int time_ms = duration_cast<microseconds>(end - begin).count();

        std::cout << n << ", " << time_ms << std::endl;
    }

    return 0;
}
