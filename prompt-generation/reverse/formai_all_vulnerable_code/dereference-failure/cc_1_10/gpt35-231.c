//FormAI DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void error(char *msg) {
    printf("Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

char *read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) error("Cannot open file");

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(sizeof(char) * (size + 1));
    if (!buffer) error("Cannot allocate buffer");

    fread(buffer, 1, size, file);
    fclose(file);

    buffer[size] = '\0';
    return buffer;
}

void write_file(char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) error("Cannot open file");

    fputs(content, file);
    fclose(file);
}

void beautify_html(char *filename) {
    char *input = read_file(filename);
    char *output = (char *) malloc(sizeof(char) * 2 * strlen(input));
    if (!output) error("Cannot allocate output buffer");

    int indent = 0;
    int in_tag = 0;
    int in_comment = 0;
    int i = 0, j = 0;
    while (input[i]) {
        if (in_comment) {
            if (input[i] == '-' && input[i+1] == '-' && input[i+2] == '>') {
                in_comment = 0;
                i += 3;
            } else {
                i++;
            }
        } else if (in_tag) {
            output[j++] = input[i++];
            if (input[i-1] == '>') {
                in_tag = 0;
                if (output[j-2] == '/') {
                    indent--;
                    output[j-2] = '\n';
                    for (int k = 0; k < indent; k++) output[j++] = '\t';
                }
                output[j++] = '\n';
                for (int k = 0; k < indent; k++) output[j++] = '\t';
            }
        } else {
            if (input[i] == '<') {
                in_tag = 1;
                output[j++] = input[i++];
                if (input[i] == '!') {
                    in_comment = 1;
                } else if (input[i] == '/') {
                    indent--;
                } else {
                    indent++;
                }
                output[j++] = '\n';
                for (int k = 0; k < indent; k++) output[j++] = '\t';
            } else {
                output[j++] = input[i++];
            }
        }
    }
    output[j] = '\0';

    write_file(filename, output);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    beautify_html(argv[1]);
    printf("HTML beautified!\n");
    return EXIT_SUCCESS;
}