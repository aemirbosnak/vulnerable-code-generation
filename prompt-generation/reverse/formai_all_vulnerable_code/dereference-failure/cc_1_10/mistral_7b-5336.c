//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_KEYWORDS 10
#define MAX_THEORY_LENGTH 200

char *keywords[NUM_KEYWORDS] = {
    "New World Order",
    "Illuminati",
    "Reptilians",
    "Deep State",
    "Moon Landing Hoax",
    "Chemtrails",
    "5G Conspiracy",
    "False Flag Operations",
    "AI Takeover",
    "Alien Invasion"
};

char *conspiracy_theory(void) {
    int length = 0;
    char *theory = malloc(MAX_THEORY_LENGTH * sizeof(char));

    strcpy(theory, "Have you heard about the latest conspiracy theory? ");

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int index = rand() % NUM_KEYWORDS;
        int len = strlen(keywords[index]);
        strcat(theory, keywords[index]);
        strcat(theory, " ");
        if (i < 4) {
            strcat(theory, "and ");
            length += len + 3;
        }
    }

    strcat(theory, "are");
    strcat(theory, "\n");
    strcat(theory, "According to some, ");

    int last_index = rand() % NUM_KEYWORDS;
    int last_len = strlen(keywords[last_index]);
    strcat(theory, keywords[last_index]);
    strcat(theory, " ");

    int remaining_length = MAX_THEORY_LENGTH - (length + last_len + 26);

    if (remaining_length > 0) {
        char random_letter;
        for (int j = 0; j < remaining_length; j++) {
            random_letter = rand() % 26 + 'a';
            strcat(theory, &random_letter);
        }
    }

    free(theory);
    return theory;
}

int main() {
    printf("%s\n", conspiracy_theory());
    return 0;
}