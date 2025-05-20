//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char* name;
    char* description;
} conspiracy_t;

conspiracy_t conspiracies[MAX_CONSPIRACIES];

void generate_conspiracy(int index) {
    char* nouns[] = {"government", "aliens", "illuminati", "corporations", "secret societies", "religious institutions"};
    char* verbs[] = {"control", "manipulate", "hide", "suppress", "influence", "monitor"};
    char* objects[] = {"information", "people", "events", "resources", "technology", "history"};

    char* name = malloc(MAX_WORD_LENGTH * sizeof(char));
    char* description = malloc(MAX_WORD_LENGTH * sizeof(char));

    strcpy(name, nouns[rand() % sizeof(nouns) / sizeof(nouns[0])]);
    strcat(name, " ");
    strcat(name, verbs[rand() % sizeof(verbs) / sizeof(verbs[0])]);
    strcat(name, " ");
    strcat(name, objects[rand() % sizeof(objects) / sizeof(objects[0])]);

    strcpy(description, "The ");
    strcat(description, name);
    strcat(description, " conspiracy theory suggests that ");

    int description_length = strlen(description);
    for (int i = description_length; i < MAX_WORD_LENGTH; i++) {
        char random_letter = rand() % 26 + 'a';
        strcat(description, &random_letter);
    }

    conspiracies[index].name = name;
    conspiracies[index].description = description;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy(i);
    }

    int choice;
    do {
        printf("Enter a number between 1 and %d:\n", MAX_CONSPIRACIES);
        scanf("%d", &choice);
        choice--;
    } while (choice < 0 || choice >= MAX_CONSPIRACIES);

    printf("Conspiracy theory #%d:\n", choice + 1);
    printf("Name: %s\n", conspiracies[choice].name);
    printf("Description: %s\n", conspiracies[choice].description);

    return 0;
}