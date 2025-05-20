//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *random_word(char **words, int count) {
    int random_index = rand() % count;
    return words[random_index];
}

void print_random_conspiracy() {
    char *adjectives[] = {"sinister", "diabolical", "devious", "nefarious", "malevolent", "malicious", "wicked", "evil", "dark", "ominous"};
    char *nouns[] = {"agenda", "plot", "conspiracy", "scheme", "plan", "machination", "design", "ploy", "plotting"};
    char *verbs[] = {"manipulate", "control", "dominate", "influence", "direct", "command", "govern", "orchestrate", "guide"};

    int adj_count = sizeof(adjectives) / sizeof(char *);
    int noun_count = sizeof(nouns) / sizeof(char *);
    int verb_count = sizeof(verbs) / sizeof(char *);

    char *adjective = random_word(adjectives, adj_count);
    char *noun = random_word(nouns, noun_count);
    char *verb = random_word(verbs, verb_count);

    int random_number = rand() % 100 + 1;
    char *number_str = malloc(4 * sizeof(char));
    sprintf(number_str, "%d", random_number);

    char *conspiracy = malloc(100 * sizeof(char));
    strcpy(conspiracy, "The ");
    strcat(conspiracy, adjective);
    strcat(conspiracy, " ");
    strcat(conspiracy, noun);
    strcat(conspiracy, " to ");
    strcat(conspiracy, verb);
    strcat(conspiracy, " the world is ");
    strcat(conspiracy, number_str);
    strcat(conspiracy, "% true!");

    printf("%s\n", conspiracy);
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        print_random_conspiracy();
    }

    return 0;
}