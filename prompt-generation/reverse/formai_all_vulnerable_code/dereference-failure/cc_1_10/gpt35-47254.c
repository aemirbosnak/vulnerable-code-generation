//FormAI DATASET v1.0 Category: Image compression ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define CHUNK_SIZE 4096

// function to compress image
void compress_image(FILE *src_file, FILE *dst_file) {

    // initialize variables
    unsigned char chunk[CHUNK_SIZE];
    size_t bytes_read;

    // loop through the file and read chunks
    while ((bytes_read = fread(chunk, sizeof(unsigned char), CHUNK_SIZE, src_file)) > 0) {

        // variable to hold compressed chunk
        unsigned char compressed_chunk[CHUNK_SIZE];

        // loop through input chunk, compressing as we go
        size_t compressed_i = 0;
        for (size_t i = 0; i < bytes_read; i++) {

            // if a run of same bytes is detected, emit a compression instruction
            size_t run_start = i;
            while (i + 1 < bytes_read && chunk[i+1] == chunk[run_start]) {
                i++;
            }

            // the run length is the different between i and run_start
            size_t run_length = i - run_start + 1;

            // if the run is more than a single byte, encode it
            if (run_length > 1) {
                compressed_chunk[compressed_i++] = 0;
                compressed_chunk[compressed_i++] = run_length;
                compressed_chunk[compressed_i++] = chunk[run_start];
            }
            else {
                compressed_chunk[compressed_i++] = chunk[run_start];
            }

        }

        // write this chunk to the destination file
        fwrite(compressed_chunk, sizeof(unsigned char), compressed_i, dst_file);

    }

}

int main(int argc, char **argv) {

    // check that we have the right arguments
    if (argc != 3) {
        fprintf(stderr, "usage: image_compression <source_file> <destination_file>\n");
        return EXIT_FAILURE;
    }

    // attempt to open both files
    FILE *src_file = fopen(argv[1], "rb");
    if (!src_file) {
        fprintf(stderr, "unable to open source file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    FILE *dst_file = fopen(argv[2], "wb");
    if (!dst_file) {
        fprintf(stderr, "unable to open destination file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // compress the image
    compress_image(src_file, dst_file);

    // close the files
    fclose(src_file);
    fclose(dst_file);

    return EXIT_SUCCESS;
}