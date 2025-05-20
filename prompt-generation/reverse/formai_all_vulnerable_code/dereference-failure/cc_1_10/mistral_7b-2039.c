//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 100
#define MAX_CHARS 50

typedef struct {
    char word[MAX_CHARS];
    int meaning;
} Dictionary;

void load_dictionary(Dictionary dictionary[], const char *filename) {
    FILE *file = fopen(filename, "r");
    int i = 0;
    char line[MAX_CHARS][MAX_CHARS];
    char *token;

    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fgets(line[i], MAX_CHARS, file) != NULL) {
        token = strtok(line[i], " \t\n");
        strcpy(dictionary[i].word, token);
        token = strtok(NULL, " \t\n");
        dictionary[i].meaning = atoi(token);
        i++;
    }

    fclose(file);
}

int translate(Dictionary dictionary[], const char *alien_word) {
    int i;
    int result = -1;

    for (i = 0; i < 100 && strcmp(dictionary[i].word, alien_word) != 0; i++);

    if (i < 100) {
        result = dictionary[i].meaning;
    }

    return result;
}

int main() {
    Dictionary dictionary[MAX_WORDS];
    char alien_word[MAX_CHARS];
    int translation;

    load_dictionary(dictionary, "dictionary.txt");

    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    translation = translate(dictionary, alien_word);

    if (translation != -1) {
        printf("The meaning of the alien word \"%s\" is: %d\n", alien_word, translation);
    } else {
        printf("Sorry, we don't have a translation for that alien word.\n");
    }

    return 0;
}