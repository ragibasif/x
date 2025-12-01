/*
 * File: main.h
 * Author: Ragib Asif
 * Email: ragibasif@tuta.io
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 */

#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define PROGRAM_NAME    "Program Name"
#define PROGRAM_VERSION "1.0.0"
#define PROGRAM_AUTHOR  "Ragib Asif (ragibasif@tuta.io)"

// Version: Major.Minor.Patch (1 byte each: MMMM MMMM | NNNN NNNN | PPPP PPPP)
#define PROGRAM_VERSION_MAJOR 1
#define PROGRAM_VERSION_MINOR 0
#define PROGRAM_VERSION_PATCH 0

#define PROGRAM_VERSION_NUM                                                    \
    ( ( PROGRAM_VERSION_MAJOR << 16 ) | ( PROGRAM_VERSION_MINOR << 8 ) |       \
      PROGRAM_VERSION_PATCH )

// Bit masking macros to extract version components
#define VERSION_GET_MAJOR( v ) ( ( v >> 16 ) & 0xFF )
#define VERSION_GET_MINOR( v ) ( ( v >> 8 ) & 0xFF )
#define VERSION_GET_PATCH( v ) ( v & 0xFF )

// Debug macro - disabled by default, can be enabled with -DDEBUG=1
#ifndef DEBUG
#define DEBUG 0
#endif

// Kibibyte: 1 KiB = 1024 bytes
// Mebibyte: 1 MiB = 1048576 bytes
// Gibibyte: 1 GiB = 1073741824 bytes
// Tebibyte: 1 TiB = 1099511627776 bytes
// Pebibyte: 1 PiB = 1125899906842620 bytes
#define KiB( n ) ( n * 1024 )             
#define MiB( n ) ( n * 1048576 )          
#define GiB( n ) ( n * 1073741824 )       
#define TiB( n ) ( n * 1099511627776 )    
#define PiB( n ) ( n * 1125899906842620 ) 

#define clamp( n, lower, upper ) min( max( ( x ), ( lower ) ), ( upper ) )
#define bit( n )                 ( 1 << ( n ) )

// TODO
extern long long gcd( const long long m, const long long n );

// TODO
extern long long lcm( const long long m, const long long n );

// Euclidean Modulo
// mathematically, modulo is always non-negative
// % -> remainder operator in C
// % -> already behaves like Euclidean modulo for unsigned integers
extern long long euclidean_modulo( const long long a, const long long b ) ;

#ifdef __cplusplus
}
#endif

#endif // MAIN_H
