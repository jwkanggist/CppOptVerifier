#ifndef _LOG_H_
#define _LOG_H_

//
//  log.h

//
//  Created by Soonwon Ka on 2015. 6. 15.
//  Copyright (c) 2015³â Soundlly. All rights reserved.
//

/* ----------- Define OS TYPE or Simulator ---------- */
// __ANDROID__				// (1) Android OS
// __APPLE__				// (2) iOS
// __XCODE__			    // (3) XCODE Development
// __LINUX__            // (4) Linux developement
/* -------------------------------------------------- */

/* ----------------- (1) Android OS ----------------- */
#ifdef __ANDROID__
//#define DEBUG
#define RELEASE
// Data logging


#ifndef __JENKINSBUILD__
#include <android/log.h>
#endif

#define  LOG_TAG "JWKANG_DEV"

#if defined(RELEASE)
#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)
#define  LOGD(...)
#define  LOGV(...)
#define  LOGS(...)
#elif defined(DEBUG)
#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  LOGS(...)
#else // nothing
#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define  LOGS(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#endif
#endif
/* -------------------------------------------------- */

/* --------------------- (2) iOS -------------------- */
// iOS LOG macro ..
#ifdef __APPLE__
#ifndef __XCODE__
#include <stdio.h>
#include <iostream>
//void logi(std::string format, ...);
//void loge(std::string format, ...);
//void logv(std::string format, ...);
//void logw(std::string format, ...);
//void logd(std::string format, ...);
//#define  LOGE(...) loge(__VA_ARGS__)
//#define  LOGW(...) logw(__VA_ARGS__)
////#define  LOGI(...) logi(__VA_ARGS__)
////#define  LOGD(...) logd(__VA_ARGS__)
//#define  LOGI(...) logv(__VA_ARGS__)
//#define  LOGD(...) logv(__VA_ARGS__)
//#define  LOGV(...) logv(__VA_ARGS__)
//
#ifdef DEBUG
#define  LOGE(...) {printf("MEX_LOG_ERROR:       "); printf(__VA_ARGS__); printf("\n");}
#define  LOGW(...) {printf("MEX_LOG_WARN:        "); printf(__VA_ARGS__); printf("\n");}
#define  LOGI(...) {printf("MEX_LOG_INFO:        "); printf(__VA_ARGS__); printf("\n");}
#define  LOGD(...) {printf("MEX_LOG_DEBUG:       "); printf(__VA_ARGS__); printf("\n");}
#define  LOGV(...) {printf("MEX_LOG_VERBOSE:     "); printf(__VA_ARGS__); printf("\n");}
#else
#define  LOGE(...) {printf("MEX_LOG_ERROR:       "); printf(__VA_ARGS__); printf("\n");}
#define  LOGW(...) {printf("MEX_LOG_WARN:        "); printf(__VA_ARGS__); printf("\n");}
#define  LOGI(...) {printf("MEX_LOG_INFO:        "); printf(__VA_ARGS__); printf("\n");}
#define  LOGD(...)
#define  LOGV(...)
#endif

#endif
#endif
/* -------------------------------------------------- */

/* ----------------- (3) XCODE Development ----------------- */
#ifdef __XCODE__ // 15.06.09 SWKA - Log macro for Matlab-imported C++ Mex File
//#define MEX // MATLAB Simulator
#define UNIT_TEST
#define _DEBUG
#include <stdio.h>

#ifdef __JENKINSBUILD__
#include <iostream>
#endif


#ifdef _DEBUG
//#define _LOG_INFO   // Log level
//#define _LOG_SIGNAL // for Simulation Analysis
#define _LOG_DEBUG

#define  LOGE(...) {printf("MEX_LOG_ERROR:       "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_ERROR
#define  LOGW(...) {printf("MEX_LOG_WARN:        "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_WARNING
#define  LOGI(...) {printf("MEX_LOG_INFO:        "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_INFO
#define  LOGD(...) {printf("MEX_LOG_DEBUG:       "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_DEBUG
#ifndef _LOG_VERBOSE
#define  LOGV(...)
#else
#define  LOGV(...) {printf("MEX_LOG_VERBOSE:     "); printf(__VA_ARGS__); printf("\n");}
#endif // LOG_VERBOSE
#else
#define  LOGV(...)
#endif // LOG_DEBUG
#else
#define  LOGD(...)
#define  LOGV(...)
#endif // LOG_INFO
#else
#define  LOGI(...)
#define  LOGD(...)
#define  LOGV(...)
#endif // LOG_WARNING
#else
#define  LOGW(...)
#define  LOGI(...)
#define  LOGD(...)
#define  LOGV(...)
#endif // LOG_ERROR
#else
#define  LOGE(...)
#define  LOGW(...)
#define  LOGI(...)
#define  LOGD(...)
#define  LOGV(...)
#endif // _DEBUG

#ifdef _LOG_SIGNAL
#define  LOGS(...) {printf("MEX_LOG_SIGNAL:      "); printf(__VA_ARGS__); printf("\n");} // Signal Analysis
#else
#define  LOGS(...)
#endif

#else // _ANDROID, _IOS
#ifdef __APPLE__
#define  LOGS(...)
#endif
#endif
/* ----------------------- end ---------------------- */


/* ----------------- (4) Linux Development ----------------- */
#ifdef __LINUX__ // 2016.12.16 by jwkang

#define UNIT_TEST
#define _DEBUG
#include <stdio.h>
#include <iostream>


#ifdef _DEBUG
#define _LOG_INFO   // Log level
//#define _LOG_SIGNAL // for Simulation Analysis
//#define _LOG_DEBUG

#define  LOGE(...) {printf("MEX_LOG_ERROR:       "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_ERROR
#define  LOGW(...) {printf("MEX_LOG_WARN:        "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_WARNING
#define  LOGI(...) {printf("MEX_LOG_INFO:        "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_INFO
#define  LOGD(...) {printf("MEX_LOG_DEBUG:       "); printf(__VA_ARGS__); printf("\n");}
#ifndef _LOG_DEBUG
#ifndef _LOG_VERBOSE
#define  LOGV(...)
#else
#define  LOGV(...) {printf("MEX_LOG_VERBOSE:     "); printf(__VA_ARGS__); printf("\n");}
#endif // LOG_VERBOSE
#else
#define  LOGV(...)
#endif // LOG_DEBUG
#else
#define  LOGD(...)
#define  LOGV(...)
#endif // LOG_INFO
#else
#define  LOGI(...)
#define  LOGD(...)
#define  LOGV(...)
#endif // LOG_WARNING
#else
#define  LOGW(...)
#define  LOGI(...)
#define  LOGD(...)
#define  LOGV(...)
#endif // LOG_ERROR
#endif // _DEBUG

#ifdef _LOG_SIGNAL
#define  LOGS(...) {printf("MEX_LOG_SIGNAL:      "); printf(__VA_ARGS__); printf("\n");} // Signal Analysis
#else
#define  LOGS(...)
#endif

#else // _ANDROID, _IOS
#ifdef __APPLE__
#define  LOGS(...)
#endif
#endif
/* ----------------------- end ---------------------- */

#endif // _LOG_H_
