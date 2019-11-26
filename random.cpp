//
//  random.cpp
//  RSA
//
//  Created by Anna Starovoyt on 3/25/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#include "random.hpp"

namespace NRandom {
    NNumber::TNumber TRandom::generateRandNumber(size_t len) {
        vector<int> res;
        for (size_t i = 0; i < len; i++) {
            res.push_back(rand());
        }
        return NNumber::TNumber(res);
    }
}
