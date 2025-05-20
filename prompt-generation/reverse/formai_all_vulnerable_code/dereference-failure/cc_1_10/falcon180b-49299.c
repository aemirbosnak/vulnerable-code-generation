//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 100
#define MAX_THEORY_LENGTH 100

typedef struct {
    char *theory;
    int length;
} Theory;

Theory theories[MAX_THEORIES];
int num_theories = 0;

void generate_theory(Theory *theory) {
    const char *nouns[] = {"government", "corporations", "aliens", "illuminati", "reptilians", "deep state", "secret societies", "big pharma", "global elites", "new world order"};
    const char *verbs[] = {"controls", "manipulates", "suppresses", "conspires", "schemes", "plots", "orchestrates", "engineers", "fabricates", "manufactures"};
    const char *adjectives[] = {"false", "fake", "manufactured", "engineered", "orchestrated", "fabricated", "manipulated", "suppressed", "controlled", "hidden"};
    const char *prepositions[] = {"by", "with", "through", "for", "in", "on", "at", "from", "to", "into"};
    const char *articles[] = {"the", "a", "an"};

    srand(time(NULL));
    int noun_index = rand() % sizeof(nouns) / sizeof(nouns[0]);
    int verb_index = rand() % sizeof(verbs) / sizeof(verbs[0]);
    int adjective_index = rand() % sizeof(adjectives) / sizeof(adjectives[0]);
    int preposition_index = rand() % sizeof(prepositions) / sizeof(prepositions[0]);
    int article_index = rand() % sizeof(articles) / sizeof(articles[0]);

    int theory_length = rand() % MAX_THEORY_LENGTH + 1;
    theory->theory = malloc(theory_length + 1);
    theory->length = theory_length;

    strcpy(theory->theory, articles[article_index]);
    strcat(theory->theory, " ");
    strcat(theory->theory, nouns[noun_index]);
    strcat(theory->theory, " ");
    strcat(theory->theory, verbs[verb_index]);
    strcat(theory->theory, " ");
    strcat(theory->theory, adjectives[adjective_index]);
    strcat(theory->theory, " ");
    strcat(theory->theory, prepositions[preposition_index]);
    strcat(theory->theory, " ");
    strcat(theory->theory, articles[article_index]);
    strcat(theory->theory, " ");
    strcat(theory->theory, nouns[noun_index]);
    strcat(theory->theory, ".");

    num_theories++;
}

void print_theory(Theory *theory) {
    printf("%s\n", theory->theory);
}

int main() {
    int i;
    for (i = 0; i < MAX_THEORIES; i++) {
        generate_theory(&theories[i]);
    }

    printf("Number of theories generated: %d\n", num_theories);

    return 0;
}