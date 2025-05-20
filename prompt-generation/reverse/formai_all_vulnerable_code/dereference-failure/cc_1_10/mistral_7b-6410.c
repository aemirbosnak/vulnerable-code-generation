//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Alien Struct
typedef struct Alien {
    char name[20];
    char symbol;
    int intelligence;
} Alien;

// Alien Database
Alien aliens[5] = {
    {"Zorkon", 'Z', 90},
    {"Xaxxon", 'X', 85},
    {"Quux", 'Q', 75},
    {"Plork", 'P', 65},
    {"Grax", 'G', 55}
};

// Function to translate human language to alien language
void translate(char *human, Alien *aliens, int num_aliens) {
    int i;
    int min_diff = 100;
    Alien *best_match = NULL;

    for (i = 0; i < num_aliens; i++) {
        int diff = abs(aliens[i].intelligence - atoi(human));
        if (diff < min_diff) {
            min_diff = diff;
            best_match = &aliens[i];
        }
    }

    printf("The alien %s understands the human '%s' and responds with the symbol '%c'\n", best_match->name, human, best_match->symbol);
}

// Main Function
int main(int argc, char *argv[]) {
    char input[100];

    if (argc != 2) {
        printf("Usage: %s <human_intelligence_level>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    translate(input, aliens, 5);

    return 0;
}