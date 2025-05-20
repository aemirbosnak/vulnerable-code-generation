//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int MAX_STR_LEN = 100;

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random conspiracy theory
char* generate_conspiracy_theory() {
    char* conspiracy_theory = (char*)malloc(sizeof(char) * MAX_STR_LEN);
    char* components[] = {"the Illuminati", "the government", "big pharma", "aliens", "the lizard people", "the deep state", "the Freemasons", "the New World Order", "corporations", "the CIA", "the FBI"};

    // Choose random components for the conspiracy theory
    int n_components = rand_range(1, 5);
    strcpy(conspiracy_theory, "The real reason for ");

    for (int i = 0; i < n_components; i++) {
        int rand_idx = rand_range(0, 10);
        strcat(conspiracy_theory, components[rand_idx]);

        if (i == n_components - 1) {
            strcat(conspiracy_theory, " ");
        } else if (i == n_components - 2) {
            strcat(conspiracy_theory, ", and ");
        } else {
            strcat(conspiracy_theory, ", ");
        }
    }

    strcat(conspiracy_theory, "is because ");

    // Choose random explanation for the conspiracy theory
    char* explanations[] = {"they want to enslave humanity", "they want to take over the world", "they want to profit off of our suffering", "they want to use us as test subjects", "they want to hide the truth from us", "they want to control our minds", "they want to create a new world order", "they want to start a war"};

    int rand_explanation_idx = rand_range(0, 7);
    strcat(conspiracy_theory, explanations[rand_explanation_idx]);
    strcat(conspiracy_theory, ".");

    return conspiracy_theory;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while (1) {
        printf("\nPress enter to generate a new conspiracy theory or type 'exit' to quit.\n");
        char input[MAX_STR_LEN];
        fgets(input, MAX_STR_LEN, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        
        char* conspiracy_theory = generate_conspiracy_theory();
        printf("\n%s\n", conspiracy_theory);
        free(conspiracy_theory);
    }

    return 0;
}