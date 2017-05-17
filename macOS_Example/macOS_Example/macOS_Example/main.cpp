//
//  main.cpp
//  macOS_Example
//
//  Created by Rafal Kitta on 17/04/2017.
//  Copyright © 2017 Rafal Kitta. All rights reserved.
//

#include <WhichEye/WhichEye.hpp>
#include <iostream>
#include "anyoption.h"


int main(int argc, char * argv[]) {
    
    AnyOption *opt = new AnyOption();
    opt->addUsage( "" );
    opt->addUsage( "Usage: " );
    opt->addUsage( "$ whichEye [--help][--verbose][--info] <image_file_path>" );
    opt->addUsage( "" );
    opt->addUsage( " -h  --help  		Prints this help " );
    opt->addUsage( " -i  --info         Prints brightest region info " );
    opt->addUsage( " -v  --verbose  	Prints more debuggig information " );
    opt->addUsage( "" );
    
    opt->setFlag( "help", 'h' );
    opt->setFlag( "info", 'i' );
    opt->setFlag( "verbose", 'v'  );
    
    opt->processCommandArgs( argc, argv );
    
    if( ! opt->hasOptions()) { /* print usage if no options */
        opt->printUsage();
        delete opt;
        return -1;
    }
    
    if( opt->getFlag( "help" ) || opt->getFlag( 'h' ) )
        opt->printUsage();
    
    bool infoFlag = false;
    if ( opt->getFlag( 'i' ) || opt->getFlag( "info" ) )
        infoFlag = true;
    
    bool verboseFlaf = false;
    if ( opt->getFlag( 'v' ) || opt->getFlag( "verbose" ) )
        verboseFlaf = true;

    
    if ( opt->getArgc() == 1 ) {
        WhichEye whichEye = WhichEye( opt->getArgv( 0 ), verboseFlaf );
        if ( verboseFlaf ) {
            std::cout << "Start analyzing image..." << std::endl;
        }
        whichEye.anylize();
        if ( verboseFlaf ) {
            std::cout << "End analyzing image." << std::endl;
        }
        
        if ( infoFlag ) {
            /// print all obtained info
            std::cout << "======================" << std::endl;
            std::cout << "Image anylize summary:" << std::endl;
            std::cout << "  Eye type            : " << whichEye.longNameEyeType() << std::endl;
            std::cout << "  Optic nerve location: " << whichEye.location << std::endl;
            std::cout << "======================" << std::endl;
            
        } else {
            /// print just eye type
            std::cout << whichEye.eyeType << std::endl;
        }
    
    } else {
        if (verboseFlaf) {
            std::cout << "Wrong arguments count. Expected one argument with path to image file." << std::endl;
        }
        return -1;
    }
    
    
    
//    for( int i = 0 ; i < opt->getArgc() ; i++ ){
//        cout << "arg = " <<  opt->getArgv( i ) << endl ;
//    }
    
    delete opt;
    
    
//    if ( argc != 2 ) {
//        std::cerr << "Usage: " << argv[0] << " <Image_Path>" << std::endl;
//        return -1;
//    }
    

    return 0;
}
