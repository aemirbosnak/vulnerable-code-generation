//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// define meows
char *meows[] = {
    "meow",
    "purr",
    "hiss",
    "yowl",
    "mew",
    "snarl",
    "growl",
    "chirrup",
    "yelp",
    "scratch",
    "lick",
    "paw",
    "roar",
    "cry",
};

// define human words and their corresponding meows
typedef struct {
    char *eng;
    char *meow;
} word_pair;

word_pair words[] = {
    {"hello", "meow"},
    {"world", "purr"},
    {"goodbye", "hiss"},
    {"cat", "mew"},
    {"food", "chirrup"},
    {"water", "yelp"},
    {"scratch", "scratch"},
    {"love", "lick"},
    {"play", "paw"},
    {"who", "roar"},
    {"why", "cry"},
};

int main(void) {
    char input[256] = "";
    char *output = malloc(256);

    printf("Enter phrase: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\r\n")] = 0; // remove newline

    // loop through each word in input
    char *word = strtok(input, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
            if (strcasecmp(word, words[i].eng) == 0) {
                strcat(output, words[i].meow);
                strcat(output, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(output, meows[rand() % 14]);
            strcat(output, " ");
        }
        word = strtok(NULL, " ");
    }
    printf("%s\n", output);

    free(output);
    return 0;
}