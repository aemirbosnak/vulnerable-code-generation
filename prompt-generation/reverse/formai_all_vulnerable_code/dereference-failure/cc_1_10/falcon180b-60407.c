//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 1000
#define MAX_WORDS 100
#define MAX_LINES 100

char text[MAX_CHARS];
char words[MAX_WORDS][MAX_CHARS];
int num_words;

void tokenize(char* line) {
    char* token = strtok(line, ",.?!:;\"'");
    while (token!= NULL) {
        strcpy(words[num_words], token);
        num_words++;
        token = strtok(NULL, ",.?!:;\"'");
    }
}

void classify_image(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int num_lines = 0;
    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, file)!= NULL) {
        num_lines++;
        tokenize(line);
    }

    fclose(file);

    int i, j;
    for (i = 0; i < num_lines; i++) {
        for (j = 0; j < num_words; j++) {
            if (strcmp(words[j], "cat") == 0 || strcmp(words[j], "dog") == 0) {
                printf("Line %d contains an image of a pet.\n", i+1);
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage:./program filename.txt\n");
        exit(1);
    }

    strcpy(text, argv[1]);
    classify_image(text);

    return 0;
}