//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_NAMES 20
#define MAX_VERBS 20
#define MAX_NOUNS 20
#define MAX_ADVERBS 20

typedef struct {
    char *name;
    char *verb;
    char *noun;
    char *adverb;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACY_LENGTH];

void generate_conspiracy(int length) {
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        conspiracies[i].name = malloc(MAX_NAMES * sizeof(char));
        conspiracies[i].verb = malloc(MAX_VERBS * sizeof(char));
        conspiracies[i].noun = malloc(MAX_NOUNS * sizeof(char));
        conspiracies[i].adverb = malloc(MAX_ADVERBS * sizeof(char));

        strcpy(conspiracies[i].name, "They");
        strcpy(conspiracies[i].verb, "are");
        strcpy(conspiracies[i].noun, "hiding");
        strcpy(conspiracies[i].adverb, "secretly");
    }
}

void print_conspiracy(int length) {
    for (int i = 0; i < length; i++) {
        printf("%s %s %s %s\n", conspiracies[i].name, conspiracies[i].verb, conspiracies[i].noun, conspiracies[i].adverb);
    }
}

int main() {
    int length;

    printf("Enter the length of the conspiracy theory: ");
    scanf("%d", &length);

    generate_conspiracy(length);
    print_conspiracy(length);

    return 0;
}