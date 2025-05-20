//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50

typedef struct {
    char *name;
    char *description;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACIES];

void generate_conspiracy(int index) {
    char *words[MAX_WORDS];
    int num_words = 0;

    srand(time(NULL));

    while (num_words < MAX_WORDS) {
        int word_len = rand() % 10 + 1;
        char *word = malloc(word_len + 1);
        for (int i = 0; i < word_len; i++) {
            word[i] = 'a' + rand() % 26;
        }
        word[word_len] = '\0';
        words[num_words++] = word;
    }

    char *name = words[rand() % num_words];
    char *description = words[rand() % num_words];

    strcpy(conspiracies[index].name, name);
    strcpy(conspiracies[index].description, description);
}

int main() {
    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        generate_conspiracy(i);
    }

    int choice;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Please choose a conspiracy theory:\n");

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        printf("%d. %s - %s\n", i + 1, conspiracies[i].name, conspiracies[i].description);
    }

    scanf("%d", &choice);

    printf("You have chosen conspiracy theory #%d:\n", choice);
    printf("Name: %s\n", conspiracies[choice - 1].name);
    printf("Description: %s\n", conspiracies[choice - 1].description);

    return 0;
}