#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

// Basic parameter setup
#define SIZE 64 // size of the vector in bytes. If you make it bigger than 2 GB, you might break the code...
#define STEPS 1000000000 // 1 billion, number of steps of the timing loop

int main() {

    // Calculate the required vector length to get SIZE bytes
    const int length = SIZE / sizeof(int);
    std::vector<int> data(length);

    // Fill the vector with numbers from 0 to length
    for (int i = 0; i < length; i++) {
        data[i] = i;
    }

    // Fisher-Yates shuffle the array
    // This swaps each element i of the vector with some element j in [i, length - 1],
    // effectively producing a randomly shuffled vector.
    int temp;
    for (int i = 0; i < length; i++) {
        int j = i + rand() % (length - i);
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // Measure the time required to make STEPS number of pseudo-random vector accesses.
    auto start = std::chrono::high_resolution_clock::now();
    int sum = 0;
    int pseudorandom_index;
    for (long steps_taken = 0; steps_taken < STEPS; steps_taken++) {
        pseudorandom_index = data[steps_taken % length];
        sum += data[pseudorandom_index];
    }
    auto stop = std::chrono::high_resolution_clock::now();

    // Print out stats of the run
    std::cout << "Array size: " << data.size() * sizeof(int) << " bytes." << std::endl;
    std::cout << "Steps taken: " << STEPS << std::endl;
    
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << "Elapsed time: " << elapsed.count() / 1e9 << " s." << std::endl;
    
    float per_step = (float)elapsed.count() / STEPS;
    std::cout << "Per step: " << per_step << " ns." << std::endl;

    // Printing out the sum of all the vector accesses (even though the number is nonsense)
    // prevents the compiler from optimizing away the timing loop.
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
