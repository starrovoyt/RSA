//
//  numbers.cpp
//  RSA
//
//  Created by Anna Starovoyt on 3/24/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#include "numbers.hpp"

namespace NNumber {
    int TNumber::compare(const TNumber& first, const TNumber& second) {
        if (first.value.size() > second.value.size()) {
            return 1;
        }
        else {
            if (first.value.size() < second.value.size()) {
                return -1;
            }
            else {
                for (long long i = first.value.size() - 1; i >= 0; i--) {
                    if (first.value[i] == second.value[i])
                        continue;
                    else {
                        if (first.value[i] > second.value[i]) {
                            return 1;
                        }
                        else {
                            return -1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    TNumber TNumber::operator + (const TNumber& v) {
        vector<int> res(max(value.size(), v.value.size()));
        fill(res.begin(), res.end(), 0);
        
        vector<int> a(value);
        reverse(a.begin(), a.end());
        vector<int> b(v.value);
        reverse(b.begin(), b.end());
        
        a.resize(res.size());
        b.resize(res.size());
        size_t size = res.size();
        
        for (size_t i = 0; i < size; i++) {
            int sum = a[i] + b[i] + res[i];
            if (sum > 1) {
                res[i] = sum % 2;
                if (i == res.size() - 1) {
                    res.push_back(1);
                }
                else {
                    res[i+1] = 1;
                }
            }
            else {
                res[i] = sum;
            }
        }
        reverse(res.begin(), res.end());
        return TNumber(res);
    };
    
    TNumber TNumber::operator - (const TNumber& v) {
        TNumber a = copy(*this);
        TNumber b = copy(v);

        if (compare(a, b) < 0) {
            a = copy(v);
            b = copy(*this);
        }
        
        vector<int> res(a.value.size());
        fill(res.begin(), res.end(), 0);
        
        reverse(a.value.begin(), a.value.end());
        reverse(b.value.begin(), b.value.end());
        
        b.value.resize(a.value.size());
        size_t size = res.size();
        
        for (size_t i = 0; i < size; i++) {
            int diff = a.value[i] - b.value[i] + res[i];
            if (diff < 0) {
                res[i] = 2 + diff;
                res[i+1] -= 1;
            }
            else {
                res[i] = diff;
            }
        }
        reverse(res.begin(), res.end());
        
        while (true && res.size() > 1) {
            if (res[0] == 0)
                res.erase(res.begin());
            else
                break;
        }
        return TNumber(res);
    };
    
    TNumber TNumber::operator * (const TNumber& v) {
        vector<int> a(value);
        vector<int> b(v.value);
        
        vector<int> tmp_res;
        tmp_res.push_back(0);
        TNumber res(tmp_res);
        
        for (long j = b.size() - 1; j >= 0; j--) {
            vector<int> tmp;
            for (long i = a.size() - 1; i >= 0; i--) {
                tmp.push_back(a[i] * b[j]);
            }
            reverse(tmp.begin(), tmp.end());
            tmp.resize(tmp.size() + b.size() - 1 - j);
            res = TNumber(tmp) + TNumber(res);
        }
        return TNumber(res);
    }
    
    TNumber TNumber::operator / (const TNumber& v) {
        TNumber b = copy(v);
//
//        vector<int> res_tmp;
//        res_tmp.push_back(0);
//        TNumber res(res_tmp);
//
//        while (compare(a, b) >= 0) {
//            a = a - b;
//            res = res + TNumber(vector<int>(1, 1));
//        };
//        return TNumber(res);
        
        NNumber::TNumber a_copy = copy(*this);
        int comp = NNumber::TNumber::compare(a_copy, b);

        if (comp == -1) {
            return NNumber::TNumber(vector<int>(1, 0));
        }

        if (comp == 0) {
            return NNumber::TNumber(vector<int>(1, 1));
        }

        NNumber::TNumber diff(vector<int>(1, 1));
        NNumber::TNumber diff_sum(vector<int>(1, 0));
        while ((a_copy.value.size() - b.value.size()) > 1) {
            diff = NNumber::TNumber(vector<int>(a_copy.value.size() - b.value.size(), 0));
            diff.value[0] = 1;
            diff_sum = diff_sum + diff;
            a_copy = a_copy - (b * diff);
        }

        while (NNumber::TNumber::compare(a_copy, b) > -1) {
            a_copy = a_copy - b;
            diff_sum = diff_sum + NNumber::TNumber(vector<int>(1, 1));
        }
        return diff_sum;
    }
    
    TNumber TNumber::operator % (const TNumber& v) {
        TNumber a = copy(*this);
        TNumber b = copy(v);
        
        TNumber div = a / b;
        return a - div * b;
    }

    TNumber TNumber::operator ^ (const TNumber& n) {
        vector<int> one_v(1, 1);
        TNumber one_n(one_v);
        
        vector<TNumber> cache;
        cache.push_back(copy(*this));
        
        for (size_t i = 1; i < n.value.size(); i++) {
            cache.push_back(cache[i-1] * cache[i-1]);
        }
        
        TNumber res(one_v);
        for (size_t i = 0; i < n.value.size(); i++) {
            if (n.value[i])
                res = res * cache[n.value.size() - i - 1];
        }
        return res;
    }
}
