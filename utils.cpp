//
//  utils.cpp
//  RSA
//
//  Created by Anna Starovoyt on 3/25/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#include "utils.hpp"

namespace NUtils {
    NNumber::TNumber TRandom::generateRandNumber(size_t len) {
        vector<int> res;
        res.push_back(1);
        for (size_t i = 1; i < len-1; i++) {
            res.push_back(rand());
        }
        res.push_back(1);
        return NNumber::TNumber(res);
    };
    
    // [a, b)
    NNumber::TNumber TRandom::generateRandNumberWithLimit(NNumber::TNumber a, NNumber::TNumber b) {
        NNumber::TNumber res = generateRandNumber(b.value.size() + 1);
        return a + (res % (b - a));
    };
    
    NNumber::TNumber TAlgorithms::phi(NNumber::TNumber n) {
        vector<int> two_v(1, 1);
        two_v.push_back(0);
        NNumber::TNumber two_n(two_v);

        vector<int> one_v(1, 1);
        NNumber::TNumber one_n(one_v);
        
        vector<int> zero_v(1, 0);
        NNumber::TNumber zero_n(zero_v);

        NNumber::TNumber result = n;
        for (NNumber::TNumber i = two_n; NNumber::TNumber::compare(i * i, n) <= 0; i = i + one_n)
            if (NNumber::TNumber::compare(n % i, zero_n) == 0) {
                while (NNumber::TNumber::compare(n % i, zero_n) == 0)
                    n = n / i;
                result = result - (result / i);
            }
        if (NNumber::TNumber::compare(n, one_v) > 0)
            result = result - (result / n);
        return result;
    }
    
    NNumber::TNumber TAlgorithms::getInverse(NNumber::TNumber a, NNumber::TNumber m) {
        vector<int> one_v(1, 1);
        NNumber::TNumber one_n(one_v);
        
        NNumber::TNumber diff = phi(m) - one_n;
        NNumber::TNumber deg = a ^ (diff);
        NNumber::TNumber res = deg % m;

        return res;
    };
    
    bool TAlgorithms::MillerRabin(NNumber::TNumber n, int k) {
        vector<int> zero_v(1, 0);
        NNumber::TNumber zero_n(zero_v);
        
        vector<int> one_v(1, 1);
        NNumber::TNumber one_n(one_v);
        
        vector<int> two_v(1, 1);
        two_v.push_back(0);
        NNumber::TNumber two_n(two_v);
        
        vector<int> three_v(1, 1);
        three_v.push_back(1);
        NNumber::TNumber three_n(three_v);
        
        if (NNumber::TNumber::compare(n, two_n) == 0 || NNumber::TNumber::compare(n, three_n) == 0)
            return true;
        
//        NNumber::TNumber t = n - one_n;
//        NNumber::TNumber ost = zero_n;

//        int s = 0;

//        while (NNumber::TNumber::compare(t % two_n, zero_n) == 0) {
//            ost = t % two_n;
//            t = t / two_n;
//            if (NNumber::TNumber::compare(ost, zero_n) == 0) {
//                s++;
//            }
//            else break;
//        }

        NUtils::TRandom rnd;
        for (int i = 0; i < k; i++) {
            NNumber::TNumber a = rnd.generateRandNumberWithLimit(two_n, n - one_n);
            NNumber::TNumber deg = (a ^ (n - one_n));
            NNumber::TNumber x = deg % n;
            if (NNumber::TNumber::compare(x, one_n) == 0) {
                continue;
            }
            return false;
        }
        return true;
        
//        for (int j = 1; j < k + 1; j++) {
//            NUtils::TRandom rnd;
//            NNumber::TNumber a = rnd.generateRandNumberWithLimit(one_n, n - one_n);
//            NNumber::TNumber b = n - one_n;
//            NNumber::TNumber d = one_n;
//            for (long long i = b.value.size(); i >= 0; i--) {
//                NNumber::TNumber x = d;
//                d = (d * d) % n;
//                if (NNumber::TNumber::compare(d, one_n) == 0 &&
//                    (NNumber::TNumber::compare(x, one_n) != 0) &&
//                    (NNumber::TNumber::compare(x, n - one_n) != 0))
//                    return false;
//                if (b.value[i] == 1) {
//                    d = (d * a) % n;
//                    if (NNumber::TNumber::compare(d, one_n) > 0 && NNumber::TNumber::compare(d, one_n) < 0)
//                        return false;
//                    return true;
//                }
//            }
//        }
//        return true;
    };
};
