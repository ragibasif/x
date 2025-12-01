/*
 * File: main.c
 * Author: Ragib Asif
 * Email: ragibasif@tuta.io
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#include "main.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>


#define BUFFER_SIZE 256

long long euclidean_modulo( const long long a, const long long b ) {
    assert( b != 0 );                          // b == 0 is Undefined Behavior
    if ( a == INT_MIN ) { assert( b != -1 ); } // UB because of overflow
    long long r = a % b;
    if ( r < 0 ) {
        // these two lines are the same: (b > 0 ? : -b) == abs(b)
        // r += ( b > 0 ? b : -b );
        r += labs( b );
    }
    return r;
}

static char *read_file( const char *filename ) {
    char *mode = "rb";
    FILE *file = fopen( filename, mode );
    assert( file != NULL ); // could not open file
    assert( strchr( filename, '.' ) !=
            NULL ); // input file requires an extension

    fseek( file, 0L, SEEK_END );
    size_t file_size = ftell( file );
    rewind( file );

    // NOTE: Remember to free this buffer
    char *buffer = malloc( sizeof *buffer * ( file_size + 1 ) );
    assert( buffer != NULL ); // check for successful allocation

    size_t bytes_read = fread( buffer, sizeof *buffer, file_size, file );
    assert( !( bytes_read < file_size ) ); // check file was read

    buffer[bytes_read] = '\0';

    fclose( file );

    return buffer;
}



int main( [[maybe_unused]]int argc, [[maybe_unused]]char **argv ) {

    fprintf( stdout, "Written by: %s\n\n", PROGRAM_AUTHOR );
    fprintf( stdout, "Program version: %u.%u.%u\n\n",
             VERSION_GET_MAJOR( PROGRAM_VERSION_NUM ),
             VERSION_GET_MINOR( PROGRAM_VERSION_NUM ),
             VERSION_GET_PATCH( PROGRAM_VERSION_NUM ) );

    return EXIT_SUCCESS;
}
