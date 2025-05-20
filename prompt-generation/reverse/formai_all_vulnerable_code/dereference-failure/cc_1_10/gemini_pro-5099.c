//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct _Fate {
    char *fate;
    struct _Fate *next;
};

struct _Fate fateStack = {0};

bool pushFate(char *fate) {
    struct _Fate *newFate = malloc(sizeof(struct _Fate));
    if (!newFate) return false;
    newFate->fate = fate;
    newFate->next = fateStack.next;
    fateStack.next = newFate;
    return true;
}

char *popFate() {
    if (!fateStack.next) return NULL;
    struct _Fate *topFate = fateStack.next;
    fateStack.next = topFate->next;
    char *fate = topFate->fate;
    free(topFate);
    return fate;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Define a list of possible fortunes
    char *fortunes[] = {
        "Your future is as bright as the sun.",
        "You will find success in all your endeavors.",
        "A great fortune awaits you.",
        "You will soon meet the love of your life.",
        "You will travel to faraway lands.",
        "You will win a large sum of money.",
        "You will have a long and happy life.",
        "You will make a positive impact on the world.",
        "You will achieve your goals.",
        "You will be surrounded by loving friends and family.",
    };

    // Push all fortunes onto the stack
    for (int i = 0; i < sizeof(fortunes) / sizeof(char *); i++) {
        if (!pushFate(fortunes[i])) {
            fprintf(stderr, "Error: Unable to allocate memory for fortune.\n");
            return EXIT_FAILURE;
        }
    }

    // Get a random fortune from the stack
    char *fate = popFate();
    if (!fate) {
        fprintf(stderr, "Error: Unable to retrieve fortune.\n");
        return EXIT_FAILURE;
    }

    // Print the fortune
    printf("Your fortune: %s\n", fate);

    return EXIT_SUCCESS;
}