//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CONSPIRACIES 100

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    char theory[100];
    int plausibility;
} Conspiracy;

void generate_conspiracy(Conspiracy* conspiracy) {
    const char* nouns[] = {"aliens", "government", "lizard people", "secret society", "illuminati", "big pharma", "deep state", "corporations", "elites", "reptilians"};
    const char* verbs[] = {"controls", "manipulates", "suppresses", "conspires", "dominates", "enslaves", "brainwashes", "monitors", "influences", "orchestrates"};
    const char* prepositions[] = {"of", "in", "by", "through", "with", "for", "over", "under", "behind", "within"};
    const char* articles[] = {"the", "a", "an"};

    srand(time(NULL));
    int noun_index = rand() % 10;
    int verb_index = rand() % 10;
    int preposition_index = rand() % 10;
    int article_index = rand() % 3;

    sprintf(conspiracy->theory, "%s %s %s %s %s %s %s", articles[article_index], nouns[noun_index], prepositions[preposition_index], verbs[verb_index], articles[article_index], nouns[noun_index], prepositions[preposition_index]);
}

int main() {
    Player players[MAX_PLAYERS];
    Conspiracy conspiracies[MAX_CONSPIRACIES];

    int num_players = 0;
    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int num_conspiracies = 0;
    printf("Enter number of conspiracies to generate (up to %d): ", MAX_CONSPIRACIES);
    scanf("%d", &num_conspiracies);

    for (int i = 0; i < num_conspiracies; i++) {
        generate_conspiracy(&conspiracies[i]);
        printf("%s: %s\n", players[i%num_players].name, conspiracies[i].theory);
    }

    return 0;
}