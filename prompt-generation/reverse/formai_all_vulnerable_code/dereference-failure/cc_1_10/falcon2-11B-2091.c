//Falcon2-11B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

void countWords(const char* filename, const char* output_filename) {
    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_filename);
        fclose(input_file);
        return;
    }

    char word[MAX_WORD_LEN];
    int count[256] = {0};

    while (fgets(word, MAX_WORD_LEN, input_file)) {
        char* word_copy = strdup(word);
        int i = 0;
        while (word_copy[i]!= '\0') {
            if (isalpha(word_copy[i])) {
                count[tolower(word_copy[i])]++;
            }
            i++;
        }
        free(word_copy);
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            fprintf(output_file, "%c: %d\n", i, count[i]);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    const char* input_filename = "input.txt";
    const char* output_filename = "output.txt";

    countWords(input_filename, output_filename);

    return 0;
}