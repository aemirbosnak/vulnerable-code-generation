//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#define ALIEN_LANGUAGE_VERSION "1.0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *input_file = NULL;
    char *output_file = NULL;
    FILE *input_fp = NULL;
    FILE *output_fp = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *translated_line = NULL;
    size_t translated_len = 0;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_file = argv[1];
    output_file = argv[2];

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return EXIT_FAILURE;
    }

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input_fp);
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, input_fp)) != -1) {
        translated_len = 0;
        for (i = 0; i < read; i++) {
            switch (line[i]) {
                case 'a':
                    translated_line[translated_len++] = 'z';
                    break;
                case 'b':
                    translated_line[translated_len++] = 'y';
                    break;
                case 'c':
                    translated_line[translated_len++] = 'x';
                    break;
                case 'd':
                    translated_line[translated_len++] = 'w';
                    break;
                case 'e':
                    translated_line[translated_len++] = 'v';
                    break;
                case 'f':
                    translated_line[translated_len++] = 'u';
                    break;
                case 'g':
                    translated_line[translated_len++] = 't';
                    break;
                case 'h':
                    translated_line[translated_len++] = 's';
                    break;
                case 'i':
                    translated_line[translated_len++] = 'r';
                    break;
                case 'j':
                    translated_line[translated_len++] = 'q';
                    break;
                case 'k':
                    translated_line[translated_len++] = 'p';
                    break;
                case 'l':
                    translated_line[translated_len++] = 'o';
                    break;
                case 'm':
                    translated_line[translated_len++] = 'n';
                    break;
                case 'n':
                    translated_line[translated_len++] = 'm';
                    break;
                case 'o':
                    translated_line[translated_len++] = 'l';
                    break;
                case 'p':
                    translated_line[translated_len++] = 'k';
                    break;
                case 'q':
                    translated_line[translated_len++] = 'j';
                    break;
                case 'r':
                    translated_line[translated_len++] = 'i';
                    break;
                case 's':
                    translated_line[translated_len++] = 'h';
                    break;
                case 't':
                    translated_line[translated_len++] = 'g';
                    break;
                case 'u':
                    translated_line[translated_len++] = 'f';
                    break;
                case 'v':
                    translated_line[translated_len++] = 'e';
                    break;
                case 'w':
                    translated_line[translated_len++] = 'd';
                    break;
                case 'x':
                    translated_line[translated_len++] = 'c';
                    break;
                case 'y':
                    translated_line[translated_len++] = 'b';
                    break;
                case 'z':
                    translated_line[translated_len++] = 'a';
                    break;
                default:
                    translated_line[translated_len++] = line[i];
                    break;
            }
        }
        translated_line[translated_len] = '\0';
        fprintf(output_fp, "%s", translated_line);
    }

    fclose(input_fp);
    fclose(output_fp);

    return EXIT_SUCCESS;
}