//
//  utils.hpp
//  RSA
//
//  Created by Anna Starovoyt on 3/25/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <chrono>

#endif /* utils_hpp */

#include "numbers.hpp"

using namespace std::chrono;

namespace NUtils {
    class TAlgorithms {
    public:
        NNumber::TNumber getInverse (NNumber::TNumber, NNumber::TNumber);
        NNumber::TNumber phi(NNumber::TNumber);
        bool MillerRabin(NNumber::TNumber, int);
    };
    
    class TRandom {
    public:
        NNumber::TNumber generateRandNumber(size_t);
        NNumber::TNumber generateRandNumberWithLimit(NNumber::TNumber, NNumber::TNumber);
        
    protected:
        size_t i;
        size_t seed;
        
        int rand() {
            size_t m = 1065353216;
            size_t k = 1664525;
            size_t b = 1013904223;
            seed = (k * seed + b) % m;
            i++;
            if (i % 11 == 0) TRandom::srand();
            return int(seed % 2);
        };
        
        void srand() {
            time_point<system_clock> now = system_clock::now();
            auto duration = now.time_since_epoch();
            long long millis = duration_cast<milliseconds>(duration).count();
            seed = static_cast<int>(millis % 1000);
        };
    };
}
