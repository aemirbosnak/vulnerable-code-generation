//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

typedef struct {
    char *word;
    char *translation;
} alien_language_t;

alien_language_t translate_alien_language(char *word) {
    alien_language_t translation = { 0 };
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            translation.word = (char *)malloc(MAX_LEN * sizeof(char));
            if (translation.word == NULL) {
                fprintf(stderr, "Error: Out of memory\n");
                exit(EXIT_FAILURE);
            }
            int j = 0;
            for (int k = i + 1; k < len; k++) {
                if (islower(word[k]) && toupper(word[k])!= word[i]) {
                    translation.translation = (char *)malloc(MAX_LEN * sizeof(char));
                    if (translation.translation == NULL) {
                        fprintf(stderr, "Error: Out of memory\n");
                        exit(EXIT_FAILURE);
                    }
                    strcpy(translation.translation, "");
                    strcat(translation.translation, word + j);
                    strcat(translation.translation, word + k);
                    strcat(translation.translation, " ");
                    j = k;
                }
            }
            strcat(translation.translation, word + j);
            free(translation.word);
            return translation;
        }
    }
    return translation;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <word>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *word = argv[1];
    alien_language_t translation = translate_alien_language(word);
    printf("Translation: %s\n", translation.translation);
    free(translation.word);
    free(translation.translation);
    return EXIT_SUCCESS;
}