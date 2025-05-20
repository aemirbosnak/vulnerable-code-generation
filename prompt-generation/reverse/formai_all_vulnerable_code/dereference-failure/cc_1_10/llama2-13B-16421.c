//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRATITUDE_LEVELS 10
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *phrase;
    int level;
} gratitude_entry_t;

gratitude_entry_t gratitude_list[GRATITUDE_LEVELS];

void init_gratitude_list(void) {
    int i;

    for (i = 0; i < GRATITUDE_LEVELS; i++) {
        gratitude_list[i].phrase = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
        gratitude_list[i].level = i + 1;
    }
}

void add_gratitude(const char *phrase) {
    int i;

    for (i = 0; i < GRATITUDE_LEVELS; i++) {
        if (strlen(phrase) > MAX_SENTENCE_LENGTH) {
            break;
        }

        if (strcmp(phrase, gratitude_list[i].phrase) < 0) {
            break;
        }

        gratitude_list[i].level = i + 1;
        break;
    }

    if (i == GRATITUDE_LEVELS) {
        gratitude_list[i].phrase = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
        strcpy(gratitude_list[i].phrase, phrase);
        gratitude_list[i].level = i + 1;
    }
}

void print_gratitude_list(void) {
    int i;

    for (i = 0; i < GRATITUDE_LEVELS; i++) {
        printf("%d. %s (%d)\n", i + 1, gratitude_list[i].phrase, gratitude_list[i].level);
    }
}

int main(void) {
    init_gratitude_list();

    add_gratitude("Thank you so much!");
    add_gratitude("You're amazing!");
    add_gratitude("I'm so grateful for you!");
    add_gratitude("I can't thank you enough!");
    add_gratitude("You're the best!");
    add_gratitude("I'm so lucky to have you!");
    add_gratitude("You're incredible!");
    add_gratitude("I'm forever grateful!");

    print_gratitude_list();

    return 0;
}