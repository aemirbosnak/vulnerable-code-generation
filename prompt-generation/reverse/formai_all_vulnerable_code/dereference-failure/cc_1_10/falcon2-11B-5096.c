//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    // Check command line arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <inputfile> <outputfile> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *input_file, *output_file;
    char *delimiter = argv[3];

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_file);
        return 1;
    }

    char buffer[BUFSIZE];
    while (fgets(buffer, sizeof(buffer), input_file)) {
        char *token;
        int count = 0;

        token = strtok(buffer, delimiter);
        while (token!= NULL) {
            fprintf(output_file, "%s", token);
            token = strtok(NULL, delimiter);
            count++;
        }

        fprintf(output_file, "\n");
        if (count > 0) {
            fprintf(output_file, "%d\n", count);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}