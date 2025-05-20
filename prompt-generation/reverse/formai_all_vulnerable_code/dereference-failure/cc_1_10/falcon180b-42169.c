//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 100

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory *generate_random_conspiracy_theory() {
    ConspiracyTheory *conspiracy_theory = malloc(sizeof(ConspiracyTheory));
    
    conspiracy_theory->name = (char *)malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    conspiracy_theory->description = (char *)malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    
    // Generate random name
    srand(time(NULL));
    int name_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    for (int i = 0; i < name_length; i++) {
        conspiracy_theory->name[i] = (char)('A' + rand() % 26);
    }
    conspiracy_theory->name[name_length] = '\0';
    
    // Generate random description
    int description_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    for (int i = 0; i < description_length; i++) {
        conspiracy_theory->description[i] = (char)('A' + rand() % 26);
    }
    conspiracy_theory->description[description_length] = '\0';
    
    return conspiracy_theory;
}

void print_conspiracy_theory(ConspiracyTheory *conspiracy_theory) {
    printf("Name: %s\n", conspiracy_theory->name);
    printf("Description: %s\n", conspiracy_theory->description);
}

int main() {
    ConspiracyTheory *conspiracy_theory = generate_random_conspiracy_theory();
    print_conspiracy_theory(conspiracy_theory);
    
    free(conspiracy_theory->name);
    free(conspiracy_theory->description);
    free(conspiracy_theory);
    
    return 0;
}