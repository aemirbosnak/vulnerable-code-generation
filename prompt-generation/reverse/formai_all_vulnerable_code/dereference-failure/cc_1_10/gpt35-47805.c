//FormAI DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABSIZE 4

char* read_file(const char* filename) {
    FILE* fp;
    char* buffer;
    long size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    buffer = (char*)malloc((size + 1) * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    fread(buffer, size, 1, fp);
    fclose(fp);

    buffer[size] = '\0';
    return buffer;
}

void write_file(const char* filename, const char* content) {
    FILE* fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot write to file.");
        exit(EXIT_FAILURE);
    }

    fputs(content, fp);
    fclose(fp);
}

char* beautify_html(char* input) {
    int indent = 0;
    int len = strlen(input);
    char* output = (char*)malloc((len + 1) * sizeof(char));
    if (output == NULL) {
        printf("Error: Memory allocation failed.");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int j = 0;
    while (i < len) {
        if (input[i] == '<') {
            output[j++] = input[i++];
            if (input[i] == '/') {
                indent -= TABSIZE;
                output[j++] = input[i++];
            }
            else {
                output[j++] = '\n';
                for (int k = 0; k < indent; k++) {
                    output[j++] = ' ';
                }
                indent += TABSIZE;
                while (input[i] != '>') {
                    output[j++] = input[i++];
                }
                output[j++] = '>';
                i++;
            }
        }
        else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error: Usage - %s [inputfile] [outputfile].", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* input = read_file(argv[1]);
    char* output = beautify_html(input);
    write_file(argv[2], output);

    free(input);
    free(output);

    return EXIT_SUCCESS;
}