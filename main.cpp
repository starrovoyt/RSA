//
//  main.cpp
//  RSA
//
//  Created by Anna Starovoyt on 3/24/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//

#include <iostream>
#include <vector>
#include "RSA.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
//    vector<int> b;
//    b.push_back(1);
//    b.push_back(1);
//    b.push_back(1);

    NNumber::TNumber n1(a);
//    NNumber::TNumber n2(b);

//    NUtils::TAlgorithms algs;
//    bool res = algs.MillerRabin(n1, 15);
//    cout << res;

    NRSA::TRSA rsa;
    rsa.makeRSA();
    NNumber::TNumber code = rsa.code(a);
    for (int i = 0; i < code.value.size(); i++) {
        cout << code.value[i];
    }
    cout << endl;
    NNumber::TNumber res = rsa.decode(code);

    for (int i = 0; i < res.value.size(); i++) {
        cout << res.value[i];
    }
    cout << endl;
    return 0;
}
