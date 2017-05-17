//
//  EyeType.hpp
//  WhichEye
//
//  Created by Rafal Kitta on 17/04/2017.
//  Copyright © 2017 Rafal Kitta. All rights reserved.
//

#ifndef EyeType_hpp
#define EyeType_hpp

enum class EyeType: char {
    
    left = 'l',
    right = 'r',
    unspecified = 'u'
};
    
std::ostream& operator<<(std::ostream& os, EyeType eyeType);

#endif /* EyeType_hpp */
