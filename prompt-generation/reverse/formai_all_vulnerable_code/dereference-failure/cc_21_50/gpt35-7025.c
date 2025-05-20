//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char* argv[])
{
    char* input_file = NULL;
    char* output_file = NULL;
    FILE* in_fp = NULL;
    FILE* out_fp = NULL;
    char line[MAX_LINE_LEN];
    int indent = 0;
    int i;

    // Parse command line arguments
    if (argc < 2 || argc > 4) {
        printf("Usage: %s input_file [output_file] [indent_size]\n", argv[0]);
        return 1;
    }
    input_file = argv[1];
    if (argc >= 3) {
        output_file = argv[2];
    }
    if (argc == 4) {
        indent = atoi(argv[3]);
    }

    // Open input file
    in_fp = fopen(input_file, "r");
    if (in_fp == NULL) {
        printf("Error opening input file %s\n", input_file);
        return 1;
    }

    // Open output file or use stdout
    if (output_file == NULL) {
        out_fp = stdout;
    } else {
        out_fp = fopen(output_file, "w");
        if (out_fp == NULL) {
            printf("Error opening output file %s\n", output_file);
            fclose(in_fp);
            return 1;
        }
    }

    // Read input file line by line and beautify
    while (fgets(line, MAX_LINE_LEN, in_fp)) {
        // Strip leading and trailing whitespace
        char* trimmed = strdup(line);
        for (i = 0; i < strlen(trimmed); i++) {
            if (trimmed[i] == '\r' || trimmed[i] == '\n' || trimmed[i] == '\t' || trimmed[i] == ' ') {
                trimmed[i] = '\0';
            } else {
                break;
            }
        }
        int len = strlen(trimmed) - 1;
        for (i = len; i >= 0; i--) {
            if (trimmed[i] == '\r' || trimmed[i] == '\n' || trimmed[i] == '\t' || trimmed[i] == ' ') {
                trimmed[i] = '\0';
            } else {
                break;
            }
        }
        len = strlen(trimmed);
        if (len == 0) {
            // Empty line, do nothing
        } else if (trimmed[0] == '<' && trimmed[len-1] == '>') {
            // Tag
            if (trimmed[1] == '/') {
                indent--;
            }
            for (i = 0; i < indent; i++) {
                fprintf(out_fp, " ");
            }
            fprintf(out_fp, "%s\n", trimmed);
            if (trimmed[1] != '/') {
                indent++;
            }
        } else {
            // Text
            for (i = 0; i < indent; i++) {
                fprintf(out_fp, " ");
            }
            fprintf(out_fp, "%s\n", trimmed);
        }

        free(trimmed);
    }

    // Cleanup
    fclose(in_fp);
    if (out_fp != stdout) {
        fclose(out_fp);
    }

    return 0;
}