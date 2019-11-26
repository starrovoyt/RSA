//
//  RSA.cpp
//  RSA
//
//  Created by Anna Starovoyt on 3/25/19.
//  Copyright © 2019 Anna Starovoyt. All rights reserved.
//


#include "RSA.hpp"

namespace NRSA {
    NNumber::TNumber TRSA::code(NNumber::TNumber m) {
        return (m ^ e) % n;
    }
    
    NNumber::TNumber TRSA::decode(NNumber::TNumber c) {
        return (c ^ d) % n;
    }
}
