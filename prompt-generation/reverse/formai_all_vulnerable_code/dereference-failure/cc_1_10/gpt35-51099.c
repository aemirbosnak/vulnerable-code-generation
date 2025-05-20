//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define TAB_SIZE 4

char* read_file(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char* buffer = (char*)malloc(sizeof(char) * MAX_LENGTH);
    if (buffer == NULL) {
        fprintf(stderr, "Error: unable to allocate memory\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    size_t length = fread(buffer, sizeof(char), MAX_LENGTH, fp);
    buffer[length] = '\0';

    fclose(fp);
    return buffer;
}

char* beautify_html(char* html)
{
    size_t length = strlen(html);
    char* output = (char*)malloc(sizeof(char) * (length * 2));
    if (output == NULL) {
        fprintf(stderr, "Error: unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    int indent = 0;
    int in_tag = 0;
    int in_quote = 0;

    for (int i = 0, j = 0; i < length; i++) {
        if (html[i] == '<' && !in_quote) {
            in_tag = 1;
            output[j++] = html[i];

            if (html[i + 1] != '/' && html[i + 1] != '!' && html[i + 1] != '?' && html[i + 1] != '\n') {
                output[j++] = '\n';
                for (int k = 0; k < indent; k++) {
                    for (int l = 0; l < TAB_SIZE; l++) {
                        output[j++] = ' ';
                    }
                }
                indent++;
            }
        } else if (html[i] == '>') {
            in_tag = 0;
            output[j++] = html[i];

            if (html[i - 1] != '/' && html[i - 1] != '\n') {
                output[j++] = '\n';
                for (int k = 0; k < indent - 1; k++) {
                    for (int l = 0; l < TAB_SIZE; l++) {
                        output[j++] = ' ';
                    }
                }
            }
        } else if (html[i] == '"' || html[i] == '\'') {
            in_quote = in_quote ? 0 : 1;
            output[j++] = html[i];
        } else {
            output[j++] = html[i];
        }
    }

    return output;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* filename = argv[1];
    char* html = read_file(filename);
    char* beautified_html = beautify_html(html);

    printf("%s", beautified_html);

    free(html);
    free(beautified_html);

    return EXIT_SUCCESS;
}