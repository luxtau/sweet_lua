//
// assert.cpp
// Copyright (c) 2008 - 2012 Charles Baker.  All rights reserved.
//

#include "stdafx.hpp"
#include "assert.hpp"
#include <sweet/build.hpp>
//#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include <nt/debug.hxx>
#include <nt/teb.hxx>
#include <iostream>

namespace sweet
{

namespace assert
{

/**
// Break in the debugger.
*/
void sweet_break()
{
    //DebugBreak();
  ntl::nt::dbg::bp();
}

/**
// If \e expression isn't true then print \e file, \e line, and 
// \e description to the debug console and stderr.
//
// @param expression
//  The expression that has failed the assertion.
//
// @param file
//  The source file that the failed assertion is in.
//
// @param line
//  The line number that the failed assertion is on.
*/
void sweet_assert( bool expression, const char* description, const char* file, int line )
{
    //int error = ::GetLastError();
  unsigned error = ntl::nt::teb::instance().LastErrorValue;

    if ( !expression )
    {
        char message [1024];
        _snprintf( message, sizeof(message), "%s(%i) : %s\n", file, line, description );
        message[sizeof(message) - 1] = 0;
        //::fputs( message, stderr );
        std::cerr << message << std::endl;
    }

    //::SetLastError( error );
    ntl::nt::teb::instance().LastErrorValue = error;
}

}

}
