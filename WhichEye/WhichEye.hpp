//
//  WhichEye.hpp
//  WhichEye
//
//  Created by Rafal Kitta on 16/04/2017.
//  Copyright © 2017 Rafal Kitta. All rights reserved.
//

#ifndef WhichEye_hpp
#define WhichEye_hpp

//#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <string>

#include "EyeType.hpp"


class WhichEye {
    
public:
    
    std::string imagePath;
    
    cv::Point location;
    EyeType eyeType;
    
    WhichEye( std::string imagePath, bool verbose = false );
    
    void anylize();
    
    std::string longNameEyeType();
    
private:
    bool verbose;
    
};


#endif /* WhichEye_hpp */
