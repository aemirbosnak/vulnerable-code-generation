//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50

char *alien_words[] = {
    "Zorblatt", "Flibberjab", "Gronk", "Snarfle",
    "Ploink", "Zabble", "Quizzik", "Mungo",
    "Bozzle", "Frozzle", "Dazzik", "Wazzle",
    "Tazzle", "Pazzik", "Gazzle", "Jazzle"
};

int main(int argc, char *argv[]) {
    FILE *input_file;
    char input_string[MAX_WORD_SIZE];
    char *output_string;
    int i;

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", input_string)!= EOF) {
        output_string = strdup(input_string);

        for (i = 0; i < strlen(output_string); i++) {
            if (isalpha(output_string[i])) {
                output_string[i] = toupper(output_string[i]);
            }
        }

        if (strlen(output_string) > MAX_WORD_SIZE) {
            printf("Error: Word is too long.\n");
            exit(1);
        }

        int word_index = rand() % (sizeof(alien_words) / sizeof(char *));
        strcpy(output_string, alien_words[word_index]);

        printf("%s -> %s\n", input_string, output_string);
    }

    fclose(input_file);
    return 0;
}