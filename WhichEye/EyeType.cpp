//
//  EyeType.cpp
//  WhichEye
//
//  Created by Rafal Kitta on 18/04/2017.
//  Copyright © 2017 Rafal Kitta. All rights reserved.
//

#include <iostream>
#include "EyeType.hpp"

std::ostream& operator<<(std::ostream& os, EyeType eyeType) {
    return os << static_cast<char>(eyeType);
}
