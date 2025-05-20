//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

char *translate_word(char *word) {
    char *result = malloc(strlen(word) + 1);
    strcpy(result, word);
    char *ptr = result;

    while (*ptr) {
        if (*ptr == 'a' || *ptr == 'A') {
            *ptr = 'o';
        } else if (*ptr == 'e' || *ptr == 'E') {
            *ptr = 'i';
        } else if (*ptr == 'i' || *ptr == 'I') {
            *ptr = 'a';
        } else if (*ptr == 'o' || *ptr == 'O') {
            *ptr = 'u';
        } else if (*ptr == 'u' || *ptr == 'U') {
            *ptr = 'a';
        }
        ptr++;
    }

    return result;
}

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char *translated_line;

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        translated_line = translate_word(line);
        fprintf(output_file, "%s", translated_line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}