//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct {
    char *text;
    int length;
} fortune_t;

void generate_fortunes(fortune_t fortunes[], int count) {
    char *adjectives[] = {"happy", "lucky", "successful", "prosperous", "fortunate", "joyful", "bright", "cheerful", "colorful", "delightful"};
    char *nouns[] = {"life", "love", "future", "destiny", "path", "journey", "career", "health", "wealth", "relationships"};
    char *verbs[] = {"will be", "is going to be", "shall be", "must be", "can be", "could be", "should be", "might be", "would be", "has to be"};

    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        fortunes[i].text = malloc(50 * sizeof(char));
        fortunes[i].length = 0;

        int adjective_index = rand() % 10;
        int noun_index = rand() % 10;
        int verb_index = rand() % 10;

        strcat(fortunes[i].text, adjectives[adjective_index]);
        strcat(fortunes[i].text, " ");
        strcat(fortunes[i].text, nouns[noun_index]);
        strcat(fortunes[i].text, " ");
        strcat(fortunes[i].text, verbs[verb_index]);
        strcat(fortunes[i].text, ".");

        fortunes[i].length = strlen(fortunes[i].text);
    }
}

void print_fortune(fortune_t fortune) {
    printf("%s\n", fortune.text);
}

int main() {
    fortune_t fortunes[MAX_FORTUNES];
    generate_fortunes(fortunes, MAX_FORTUNES);

    int choice;
    do {
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("How many fortunes would you like to hear? ");
        scanf("%d", &choice);
    } while (choice <= 0 || choice > MAX_FORTUNES);

    for (int i = 0; i < choice; i++) {
        print_fortune(fortunes[i]);
    }

    return 0;
}