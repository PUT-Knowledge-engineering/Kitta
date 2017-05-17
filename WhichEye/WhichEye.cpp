//
//  WhichEye.cpp
//  WhichEye
//
//  Created by Rafal Kitta on 16/04/2017.
//  Copyright © 2017 Rafal Kitta. All rights reserved.
//

#include "WhichEye.hpp"
#include <iostream>

using namespace cv;

WhichEye::WhichEye(std::string imagePath, bool verbose) {
    this->imagePath = imagePath;
    this->location = Point();
    this->eyeType = EyeType::unspecified;
    this->verbose = verbose;
}

void WhichEye::anylize() {
    Mat image;

    image = imread( imagePath, 1 );
    
    if ( !image.data ) {
        if ( verbose ) {
            std::cout << "[Error] No image data" << std::endl;
        }
        return;
    }
    
    if ( verbose ) {
        std::cout << "Read image from file path: OK" << std::endl;
    }
    
    /// Convert image to gray
    Mat image_gray;
    cvtColor( image, image_gray, CV_BGR2GRAY );
    
    if ( verbose ) {
        std::cout << "Converted image to gray scale: OK" << std::endl;
    }
    
    /// Reduce the noise so we avoid false max/min regions detection
    GaussianBlur( image_gray, image_gray, Size( 21, 21 ), 2, 2 );
    
    if ( verbose ) {
        std::cout << "Added Gaussian blur with radius 21: OK" << std::endl;
    }
    
    /// find min and max color (black, white) regions locations
    double minValue, maxVal;
    Point minLoc, maxLoc;
    minMaxLoc( image_gray, &minValue, &maxVal, &minLoc, &maxLoc );
    
    if ( verbose ) {
        std::cout << "Determined brightest region (and its location) of the image: OK" << std::endl;
    }
    
    /// set location of the brightest region
    location = maxLoc;
    
    /// if max < middle x -> left, otherwise right
    if ( maxLoc.x <= image.cols / 2 ) {
        eyeType = EyeType::left;
        
    } else {
        eyeType = EyeType::right;
    }
    if ( verbose ) {
        std::cout << "Determined which eye it is: OK" << std::endl;
    }
}

std::string WhichEye::longNameEyeType() {
    switch(eyeType)
    {
        case EyeType::left:         return "left";
        case EyeType::right:        return "right";
        case EyeType::unspecified:  return "unsecified";
    }
}

