#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

/* A simple (and inefficient) function to compute the
arithmetic sum from 1 to the value of upper using a for loop.
*/
int arithmetic_sum(int upper) {
    volatile int sum = 0;
    for (int i = 1; i <= upper; i++) {
        sum += i;
    }
    return sum;
}

TEST_CASE("Benchmarking Basics") {

    BENCHMARK("Arithmetic sum 1 to 100") {
        return arithmetic_sum(100);
    };

    REQUIRE(arithmetic_sum(100) == 5050);
}
