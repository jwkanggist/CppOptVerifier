//
//  main.cpp
//  cppOpt
//
//  Created by jwkangmacpro on 2017. 6. 5..
//  Copyright © 2017년 jwkangmacpro. All rights reserved.
//
#include "gtest/gtest.h"

#include "cppOptVerifier.h"

TEST(inlineFuncTest,RunTimeTest1)
{
    CppOptVerifier* test1 = new CppOptVerifier();
    
    const int in1 = 1;
    const int in2 = 1;
    int out = 0;
    
    long int numCallList[] = {100, 1000,  10000, 1000000, 10000000};
    long numOfFunCall = 0;
    time_t startTime_ms = 0;
    time_t endTTime_ms = 0;
    double runtime_sec= 0.0;
    
    const int ListLen = 5;
    for (int n = 0 ; n < ListLen ; n++)
    {
        
        numOfFunCall = numCallList[n];
        LOGD("NumOfFunCall = %ld",numOfFunCall);
        
        /* For inline function */
        startTime_ms = clock();
        for (int t = 0 ; t < numOfFunCall; t++)
        {
            out = test1->scalarAdd_Inline(in1, in2);// N times call of inline func.
        }
        endTTime_ms = clock();
        
        runtime_sec = (double)(endTTime_ms - startTime_ms)/CLOCKS_PER_SEC*1000.0;// measure runtime of inline
        LOGD("[RunTimeCheck]")
        LOGD("-- Inline function: %f sec",runtime_sec);
        
        /* For normal function */
        startTime_ms = clock();
        for (int t = 0 ; t < numOfFunCall; t++)
        {
            out = test1->scalarAdd(in1, in2);// N times call of normal func.
        }
        endTTime_ms = clock();
        
        runtime_sec = (double)(endTTime_ms - startTime_ms)/CLOCKS_PER_SEC*1000.0;// measure runtime of normal
        LOGD("-- Normal function: %f sec",runtime_sec);
    }
    
    if (test1 != nullptr)
    {
        delete test1;
        test1 = nullptr;
    }
}
//
//TEST(inlineFuncTest,RunTimeTest2)
//{
//
//    CppOptVerifier* test1 = new CppOptVerifier();
//
//    /* INPUT DATA CONFIG */
//    const int vecLen = 10;
//    int* vecIn1 = new int[vecLen];
//    int* vecIn2 = new int[vecLen];
//    int vecOut[vecLen] = {0};
//
//    for (int n = 0 ; n < vecLen ;n ++)
//    {
//        vecIn1[n] = n;
//        vecIn2[n] = n;
//    }
//    
//    LOGD("Input vector length = %d",vecLen);
//    
//    long int numCallList[] = {100, 1000,  10000, 1000000, 10000000};
//    long numOfFunCall = 0;
//    time_t startTime_ms = 0;
//    time_t endTTime_ms = 0;
//    double runtime_sec= 0.0;
//    
//    const int ListLen = 5;
//    for (int n = 0 ; n < ListLen ; n++)
//    {
//        
//        numOfFunCall = numCallList[n];
//        LOGD("NumOfFunCall = %ld",numOfFunCall);
//        
//        /* For inline function */
//        startTime_ms = clock();
//        for (int t = 0 ; t < numOfFunCall; t++)
//        {
//            test1->vectorAdd_Inline(vecIn1,vecIn2,vecLen,vecOut);
//        }
//        endTTime_ms = clock();
//        
//        runtime_sec = (double)(endTTime_ms - startTime_ms)/CLOCKS_PER_SEC*1000.0;
//        LOGD("[RunTimeCheck]")
//        LOGD("-- Inline function: %f sec",runtime_sec);
//        
//        /* For normal function */
//        startTime_ms = clock();
//        for (int t = 0 ; t < numOfFunCall; t++)
//        {
//            test1->vectorAdd(vecIn1,vecIn2,vecLen,vecOut);
//        }
//        endTTime_ms = clock();
//        
//        runtime_sec = (double)(endTTime_ms - startTime_ms)/CLOCKS_PER_SEC*1000.0;
//        LOGD("-- Normal function: %f sec",runtime_sec);
//    }
//    
//    if (test1 != nullptr)
//    {
//        delete test1;
//        test1 = nullptr;
//    }
//    
//    if (vecIn1 != nullptr)
//    {
//        delete [] vecIn1;
//        vecIn1 = nullptr;
//    }
//    
//    if (vecIn2  != nullptr)
//    {
//        delete [] vecIn2;
//        vecIn2 = nullptr;
//    }
//}

int main(int argc, char* argv[])
{
    printf("Successful Running in Google Test\n");
    
    printf("[----------------Google Test START---------------------]\n");
    
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
    
    return 0;
    
}
