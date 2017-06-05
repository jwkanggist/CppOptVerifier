//
//  cppOptVerifier.h
//  cppOpt
//
//  Created by jwkangmacpro on 2017. 6. 5..
//  Copyright © 2017년 jwkangmacpro. All rights reserved.
//


#include "log.h"
#include <ctime>

#ifndef cppOptVerifier_h
#define cppOptVerifier_h


class CppOptVerifier
{
private:

    
public:
    CppOptVerifier();
    ~CppOptVerifier();
  
    // inline method example 1//
    int scalarAdd (const int in1, const int in2);
    
    inline int scalarAdd_Inline(const int in1, const int in2) 
    {
        return in1 + in2;
    }
    // inline method example 2//
    void        vectorAdd       (const int* vecIn1, const int* vecIn2, const int vecLen, int* vecOut);
    inline void vectorAdd_Inline(const int* vecIn1, const int* vecIn2, const int vecLen, int* vecOut) const
    {
//        LOGD("Call vectorAdd_Inline()")
        for (int n = 0 ; n < vecLen ; n++)
        {
            vecOut[n] =  vecIn1[n] + vecIn2[n];
        }
    }
    // ------------------------ //
    
};

#endif /* cppOptVerifier_h */
