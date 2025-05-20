//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <delimiter>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char delimiter = argv[3][0];

    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_fp);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    size_t token_len = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_fp)!= NULL) {
        token = strtok_r(line, &delimiter, &token_len);
        while (token!= NULL) {
            fprintf(output_fp, "%s\n", token);
            token = strtok_r(NULL, &delimiter, &token_len);
        }
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}