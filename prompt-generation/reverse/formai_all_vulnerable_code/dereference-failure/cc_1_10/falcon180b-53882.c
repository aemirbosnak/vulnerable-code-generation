//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 100

// Fortune struct to hold the fortunes
typedef struct {
    char* text;
    int length;
} Fortune;

// Function prototypes
Fortune* initFortunes();
void freeFortunes(Fortune* fortunes);
Fortune* getRandomFortune(Fortune* fortunes);

int main() {
    srand(time(NULL));

    Fortune* fortunes = initFortunes();

    while (1) {
        Fortune* fortune = getRandomFortune(fortunes);
        printf("%s\n", fortune->text);

        char choice;
        printf("Press 'y' to hear another fortune or any other key to exit: ");
        scanf(" %c", &choice);

        if (choice!= 'y') {
            break;
        }
    }

    freeFortunes(fortunes);
    return 0;
}

// Initialize the fortunes array with random fortunes
Fortune* initFortunes() {
    Fortune* fortunes = malloc(NUM_FORTUNES * sizeof(Fortune));

    for (int i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].text = malloc(100 * sizeof(char));
        fortunes[i].length = rand() % 100;
        for (int j = 0; j < fortunes[i].length; j++) {
            fortunes[i].text[j] = rand() % 26 + 'a';
        }
        fortunes[i].text[fortunes[i].length] = '\0';
    }

    return fortunes;
}

// Free the fortunes array
void freeFortunes(Fortune* fortunes) {
    for (int i = 0; i < NUM_FORTUNES; i++) {
        free(fortunes[i].text);
    }
    free(fortunes);
}

// Get a random fortune from the fortunes array
Fortune* getRandomFortune(Fortune* fortunes) {
    return &fortunes[rand() % NUM_FORTUNES];
}