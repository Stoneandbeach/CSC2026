#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include "algorithms/ex1.1_algorithms.hpp"
#include "parameters.hpp"


TEST_CASE("Exercise 1.1 - Complexity") {

    std::cout << "n = " << N << std::endl << std::endl;

#ifdef BENCH6
    BENCHMARK_ADVANCED("Algorithm 6")(Catch::Benchmark::Chronometer timer) {
        
        // Setup code
        std::vector<int> v(N);
        for (int &element : v) {
            element = rand() % 100000 - 40000;
        }

        // Benchmarking
        timer.measure([&]() {
            std::vector<int> v_copy = v;
            return algorithm_6(v_copy);
        });
        
    };
#endif

#ifdef BENCH7
    BENCHMARK_ADVANCED("Algorithm 7")(Catch::Benchmark::Chronometer timer) {
        
        // Setup code
        std::vector<int> v(N);
        for (int i = 0; i < v.size(); i++) {
            v[i] = i;
        }
        int target = -1;

        // Benchmarking
        timer.measure([&] {
            return algorithm_7(v, target);
        });
        
    };
#endif

#ifdef BENCH8
    BENCHMARK_ADVANCED("Algorithm 8")(Catch::Benchmark::Chronometer timer) {
        
        // Setup code
        std::vector<std::vector<int>> a(N, std::vector<int>(N));
        std::vector<std::vector<int>> b(N, std::vector<int>(N));
        for (std::vector<int> &row : a) {
            for (int &number : row) {
                number = rand() % N;
            }
        }

        for (std::vector<int> &row : b) {
            for (int &number : row) {
                number = rand() % N;
            }
        }

        // Benchmarking
        timer.measure([&] {
            return algorithm_8(a, b);
        });
        
    };
#endif

#ifdef BENCH9
    BENCHMARK_ADVANCED("Algorithm 9")(Catch::Benchmark::Chronometer timer) {
        
        // Setup code
        std::vector<int> v(N);
        for (int &element : v) {
            element = rand() % 10000 - 5000;
        }

        // Benchmarking
        timer.measure([&]() {
            std::vector<int> v_copy = v;
            return algorithm_9(v_copy);
        });
    };
#endif

#ifdef BENCH10
    BENCHMARK_ADVANCED("Algorithm 10")(Catch::Benchmark::Chronometer timer) {
        
        // Setup code
        std::vector<int> u(N);
        for (int &element : u) {
            element = rand() % 1000 - 5000;
        }

        std::vector<int> v(N);
        for (int &element : v) {
            element = rand() % 1000 - 5000;
        }

        // Benchmarking
        timer.measure([&]() {
            return algorithm_10(u, v);
        });
    };
#endif

}
