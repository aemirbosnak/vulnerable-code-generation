//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ABDUCTION_SUCCESS 1
#define ALIEN_ABDUCTION_FAILURE 0

struct AlienTranslator {
    char *earth_word;
    char *alien_word;
};

void translate_earth_to_alien(struct AlienTranslator *translator, char *earth_phrase) {
    char *token, *phrase = strdup(earth_phrase);
    size_t length = strlen(earth_phrase) + 1;
    size_t capacity = length * 2;
    char *alien_phrase = malloc(capacity);
    int abduction_success = ALIEN_ABDUCTION_FAILURE;

    token = strtok(phrase, " ");

    while (token != NULL) {
        int i;
        for (i = 0; i < sizeof(translator)/sizeof(struct AlienTranslator); i++) {
            if (strcasecmp(token, translator[i].earth_word) == 0) {
                strcat(alien_phrase, translator[i].alien_word);
                strcat(alien_phrase, " ");
                abduction_success = ALIEN_ABDUCTION_SUCCESS;
                break;
            }
        }

        if (i == sizeof(translator)/sizeof(struct AlienTranslator) && abduction_success == ALIEN_ABDUCTION_FAILURE) {
            fprintf(stderr, "Unknown Earth term: %s\n", token);
            free(alien_phrase);
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " ");
    }

    printf("Alien Translation: %s\n", alien_phrase);
    free(alien_phrase);
}

int main() {
    struct AlienTranslator translator[] = {
        {"hello", "klaatu"},
        {"world", "baraH"},
        {"how", "l'qo'o"},
        {"are", "kaj"},
        {"you", "ni'u"},
        {"from", "lo'u"},
        {"earth", "zorq"},
        {"this", "thuq"},
        {"planet", "s'kzar"},
        {"is", "qax"},
        {"beautiful", "m'lana"},
        {NULL, NULL}
    };

    char input[100];
    printf("Earthling, please enter a phrase to translate: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    translate_earth_to_alien(translator, input);

    return EXIT_SUCCESS;
}