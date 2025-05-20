//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    WordTranslation translations[MAX_WORDS];
    int num_translations = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (num_translations >= MAX_WORDS) {
                printf("Too many words in input file.\n");
                fclose(input_file);
                fclose(output_file);
                return 1;
            }

            WordTranslation *translation = &translations[num_translations];
            strcpy(translation->word, word);

            char *cat_word = strcat(word, "s");
            char *cat_translation = strcat("meows", cat_word);

            strcpy(translation->translation, cat_translation);

            num_translations++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);
    fclose(output_file);

    output_file = fopen(argv[2], "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < num_translations; i++) {
        fprintf(output_file, "%s -> %s\n", translations[i].word, translations[i].translation);
    }

    fclose(output_file);

    return 0;
}