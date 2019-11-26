//
//  RSA.hpp
//  RSA
//
//  Created by Anna Starovoyt on 3/25/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#ifndef RSA_hpp
#define RSA_hpp

#include <stdio.h>
#include "utils.hpp"
#endif /* RSA_hpp */

namespace NRSA {
    class TRSA {
    public:
        NNumber::TNumber e;
        NNumber::TNumber d;
        NNumber::TNumber n;
        
        void makeRSA() {
            NUtils::TRandom rnd;
            NUtils::TAlgorithms algs;
            
            int SIZE = 4;
            NNumber::TNumber p = rnd.generateRandNumber(SIZE);
            while (!algs.MillerRabin(p, 15)) {
                p = rnd.generateRandNumber(SIZE);
            }
            
            NNumber::TNumber q = rnd.generateRandNumber(SIZE);
            while (!algs.MillerRabin(q, 15)) {
                q = rnd.generateRandNumber(SIZE);
            }
            
            n = p * q;
            
            NNumber::TNumber one_n(vector<int>(1, 1));
            NNumber::TNumber phi = (p - one_n) * (q - one_n);
            
            NNumber::TNumber two_n(vector<int>{1,0});
            e = rnd.generateRandNumberWithLimit(two_n, phi);
            
            d = algs.getInverse(e, phi);
        };
        
        NNumber::TNumber code(NNumber::TNumber);
        NNumber::TNumber decode(NNumber::TNumber);
    };
}
