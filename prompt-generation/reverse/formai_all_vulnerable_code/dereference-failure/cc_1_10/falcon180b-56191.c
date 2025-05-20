//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 1000
#define MAX_LENGTH 100

struct conspiracy {
    char* text;
    int length;
};

void generate_conspiracy(struct conspiracy* c) {
    const char* nouns[] = {"government", "aliens", "illuminati", "freemasons", "big pharma", "deep state", "elites", "corporations"};
    const char* verbs[] = {"controls", "manipulates", "suppresses", "conceals", "conspires", "dominates", "enslaves", "oppresses"};
    const char* adjectives[] = {"secret", "hidden", "sinister", "shadowy", "malevolent", "nefarious", "covert", "clandestine"};

    srand(time(NULL));
    int noun_index = rand() % sizeof(nouns) / sizeof(nouns[0]);
    int verb_index = rand() % sizeof(verbs) / sizeof(verbs[0]);
    int adjective_index = rand() % sizeof(adjectives) / sizeof(adjectives[0]);

    int length = rand() % MAX_LENGTH + 1;
    char* text = malloc(length + 1);

    sprintf(text, "The %s %s is %sly %s the world through %s means.", nouns[noun_index], verbs[verb_index], adjectives[adjective_index], nouns[noun_index], verbs[verb_index]);

    c->text = text;
    c->length = length;
}

void print_conspiracy(const struct conspiracy* c) {
    printf("%s\n", c->text);
}

int main() {
    struct conspiracy conspiracies[MAX_CONSPIRACIES];

    int num_conspiracies = rand() % MAX_CONSPIRACIES + 1;

    for (int i = 0; i < num_conspiracies; i++) {
        generate_conspiracy(&conspiracies[i]);
    }

    for (int i = 0; i < num_conspiracies; i++) {
        print_conspiracy(&conspiracies[i]);
    }

    return 0;
}