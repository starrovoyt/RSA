//
//  numbers.hpp
//  RSA
//
//  Created by Anna Starovoyt on 3/24/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#ifndef numbers_hpp
#define numbers_hpp

#include <stdio.h>

#endif /* numbers_hpp */

#include <vector>
#include <cmath>

using namespace std;

namespace NNumber {
    class TNumber {
    public:
        vector<int> value;
        
        TNumber () {};
        
        long long its_int = 0;
        
        TNumber (const vector<int>& v) {
            value = v;
            its_int = getInt();
        }
        
        TNumber copy (const TNumber& n) {
            vector<int> new_val(n.value);
            return TNumber(new_val);
        }
        
        TNumber operator + (const TNumber&);
        TNumber operator - (const TNumber&);
        TNumber operator * (const TNumber&);
        TNumber operator / (const TNumber&);
        TNumber operator % (const TNumber&);
        TNumber operator ^ (const TNumber&);
        
        static int compare(const TNumber&, const TNumber&);
    private:
        long long getInt() {
            long long its_int = 0;
            for (size_t i = 0; i < value.size(); i++) {
                its_int += pow(2, i) * value[value.size() - i - 1];
            }
            return its_int;
        };
    };
}

