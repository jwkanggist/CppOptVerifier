//
//  cppOptVerifier.cpp
//  cppOpt
//
//  Created by jwkangmacpro on 2017. 6. 5..
//  Copyright © 2017년 jwkangmacpro. All rights reserved.
//

#include "cppOptVerifier.h"

CppOptVerifier::CppOptVerifier(){}

CppOptVerifier::~CppOptVerifier(){}

int CppOptVerifier::scalarAdd(const int in1, const int in2)
{
    return in1 + in2;
    
}
void CppOptVerifier::vectorAdd(const int* vecIn1, const int* vecIn2, const int vecLen, int* vecOut)
{
    for (int n = 0 ; n < vecLen ; n++)
    {
        vecOut[n] =  vecIn1[n] + vecIn2[n];
    }
}
