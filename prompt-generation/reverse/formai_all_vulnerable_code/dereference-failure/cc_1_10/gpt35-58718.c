//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <string.h>

struct element {
    char symbol[3];
    int atomic_number;
    char name[20];
    float atomic_weight;
};

int main() {
    struct element table[118];
    int choice, score = 0;

    // populate the periodic table
    strcpy(table[0].symbol, "H");
    table[0].atomic_number = 1;
    strcpy(table[0].name, "Hydrogen");
    table[0].atomic_weight = 1.008;
    // add the rest of the period table ...

    // display menu options
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Choose an option:\n");
    printf("1. Guess element by symbol\n");
    printf("2. Guess element by name\n");
    printf("3. Guess element by atomic number\n");
    printf("4. Quit\n");
    scanf("%d", &choice);

    while (choice != 4) {
        int rand_index = rand()%118;
        struct element rand_element = table[rand_index];

        if (choice == 1) {
            // guess element by symbol
            char guess[3];
            scanf("%s", guess);
            if (strcmp(guess, rand_element.symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The answer was %s.\n", rand_element.symbol);
            }
        } else if (choice == 2) {
            // guess element by name
            char guess[20];
            scanf("%s", guess);
            if (strcmp(guess, rand_element.name) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The answer was %s.\n", rand_element.name);
            }
        } else if (choice == 3) {
            // guess element by atomic number
            int guess;
            scanf("%d", &guess);
            if (guess == rand_element.atomic_number) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The answer was %d.\n", rand_element.atomic_number);
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }

        // display score and menu options
        printf("Your score is %d.\n", score);
        printf("Choose an option:\n");
        printf("1. Guess element by symbol\n");
        printf("2. Guess element by name\n");
        printf("3. Guess element by atomic number\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
    }

    printf("Thanks for playing the Periodic Table Quiz! Your final score is %d.\n", score);
    return 0;
}