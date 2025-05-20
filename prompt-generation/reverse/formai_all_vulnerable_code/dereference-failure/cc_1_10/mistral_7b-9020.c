//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AlienLanguage {
    char *name;
    char **translations;
} AlienLanguage;

AlienLanguage *loadAlienLanguage(char *filename) {
    FILE *file = fopen(filename, "r");
    AlienLanguage *aliens = NULL;
    char line[1024];
    char *token;
    int numAliens = 0;

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        numAliens++;
        AlienLanguage *alien = (AlienLanguage *) malloc(sizeof(AlienLanguage));
        alien->name = strtok(line, ":");
        alien->translations = (char **) malloc(sizeof(char *) * 10);

        int i = 0;
        char *token = strtok(NULL, ":");
        while (token != NULL) {
            alien->translations[i] = strdup(token);
            token = strtok(NULL, ":");
            i++;
        }
        alien->translations[i] = NULL;

        if (aliens == NULL) {
            aliens = (AlienLanguage *) malloc(sizeof(AlienLanguage));
            aliens[0] = *alien;
        } else {
            AlienLanguage *last = aliens + numAliens - 1;
            last->translations = (char **) realloc(last->translations, sizeof(char *) * (numAliens + 1));
            last->translations[numAliens] = alien->translations;
        }
    }

    fclose(file);

    return aliens;
}

void translate(AlienLanguage *aliens, char *english) {
    int i;
    for (i = 0; aliens[i].name != NULL; i++) {
        int j;
        for (j = 0; aliens[i].translations[j] != NULL; j++) {
            if (strcmp(english, aliens[i].translations[j]) == 0) {
                printf("%s -> %s\n", english, aliens[i].name);
                return;
            }
        }
    }

    printf("%s -> Unknown\n", english);
}

int main() {
    AlienLanguage *aliens = loadAlienLanguage("aliens.txt");

    if (aliens == NULL) {
        printf("Error: Unable to load alien languages\n");
        return 1;
    }

    translate(aliens, "Hello");
    translate(aliens, "Kangaroo");
    translate(aliens, "Sauron");

    int i;
    for (i = 0; aliens[i].name != NULL; i++) {
        free(aliens[i].name);
        free(aliens[i].translations);
    }

    free(aliens);

    return 0;
}

// Example aliens.txt file content:
// Zorgon:Greetings:Hello:Salutations:Hello there:Hello greetings
// Kangaroo:Kangaroo:Hopper:Jumper:Jumpy:Pog:Kang:Kangaroo hopper
// Sauron:Dark Lord:Sauron:Mordor:Lord of the Rings:Ringwraith:Dark One