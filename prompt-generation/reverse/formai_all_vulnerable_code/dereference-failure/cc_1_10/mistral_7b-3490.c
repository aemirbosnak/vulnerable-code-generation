//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define WORDS_IN_CONSPIRACY 5

typedef struct {
    char *conspiracy;
} Conspiracy;

Conspiracy theories[MAX_CONSPIRACIES];

void create_conspiracy(Conspiracy *conspiracy) {
    char *words[WORDS_IN_CONSPIRACY];

    words[0] = "Lizard People";
    words[1] = "Illuminati";
    words[2] = "New World Order";
    words[3] = "Moon Landing Hoax";
    words[4] = "Reptilian Elite";

    conspiracy->conspiracy = malloc(sizeof(char) * 100);

    int length = 0;

    int random_index = rand() % WORDS_IN_CONSPIRACY;

    strcpy(conspiracy->conspiracy, words[random_index]);

    length += strlen(words[random_index]) + 1;

    for (int i = 1; i < WORDS_IN_CONSPIRACY; i++) {
        random_index = rand() % WORDS_IN_CONSPIRACY;

        int word_length = strlen(words[random_index]);

        strcat(conspiracy->conspiracy, " ");
        strcat(conspiracy->conspiracy, words[random_index]);

        length += word_length + 1;
    }

    conspiracy->conspiracy[length] = '\0';
}

void print_conspiracy(Conspiracy conspiracy) {
    printf("Conspiracy Theory: %s\n", conspiracy.conspiracy);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        create_conspiracy(&theories[i]);
    }

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        print_conspiracy(theories[i]);
    }

    for (int i = 0; i < MAX_CONSPIRACIES; i++) {
        free(theories[i].conspiracy);
    }

    return 0;
}