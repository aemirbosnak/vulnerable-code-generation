//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CONSPIRACIES 10
#define WORDS 5

typedef struct {
    char word[WORDS][20];
} conspiracy_t;

conspiracy_t *theories;

void initialize_conspiracies() {
    theories = (conspiracy_t *) malloc(sizeof(conspiracy_t));
    memset(theories, 0, sizeof(conspiracy_t));

    strcpy(theories->word[0], "The Moon is made of cheese.");
    strcpy(theories->word[1], "The government controls weather.");
    strcpy(theories->word[2], "Elvis is still alive.");
    strcpy(theories->word[3], "Reptilians rule the world.");
    strcpy(theories->word[4], "9/11 was an inside job.");

    strcpy(theories->word[5], "The Illuminati.");
    strcpy(theories->word[6], "Area 51.");
    strcpy(theories->word[7], "The Flat Earth Society.");
    strcpy(theories->word[8], "The New World Order.");
    strcpy(theories->word[9], "The Freemasons.");
}

void print_conspiracy() {
    int i, j;
    int length = strlen(theories->word[rand() % CONSPIRACIES]);
    for (i = 0; i < WORDS - length / 2; i++) {
        printf(" ");
    }
    printf("%s\n", theories->word[rand() % CONSPIRACIES]);
}

int main(void) {
    srand(time(NULL));
    initialize_conspiracies();

    for (int i = 0; i < 10; i++) {
        print_conspiracy();
    }

    free(theories);
    return 0;
}