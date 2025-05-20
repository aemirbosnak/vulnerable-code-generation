//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

struct word {
    char *english;
    char *cat;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;

    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), dict_file)!= NULL) {
        char *english_word = strtok(line, " ");
        char *cat_word = strtok(NULL, " ");

        if (english_word == NULL || cat_word == NULL) {
            printf("Error: Invalid line in dictionary file.\n");
            return 1;
        }

        words[num_words].english = strdup(english_word);
        words[num_words].cat = strdup(cat_word);

        num_words++;
    }

    fclose(dict_file);

    char input[100];
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin);

    int input_len = strlen(input);
    char *token = strtok(input, " ");
    char output[input_len + 1];
    output[0] = '\0';

    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcat(output, words[i].cat);
                strcat(output, " ");
                break;
            }
        }

        if (i == num_words) {
            printf("Error: Unknown word '%s'.\n", token);
            return 1;
        }

        token = strtok(NULL, " ");
    }

    printf("Translation: %s\n", output);

    return 0;
}