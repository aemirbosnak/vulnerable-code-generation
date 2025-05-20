//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random number between min and max (inclusive)
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Print a welcome message
void welcome() {
    printf("Welcome to the Grateful Game!\n");
    printf("In this game, you will be presented with a series of choices.\n");
    printf("Make your choices wisely, and you may just find yourself on the path to gratitude.\n");
}

// Print a gratitude prompt
void gratitude_prompt() {
    printf("\nWhat are you grateful for today?\n");
    printf("(Enter your response or type 'quit' to exit.)\n");
}

// Get the user's input
char *get_input() {
    char *input = NULL;
    size_t len = 0;
    getline(&input, &len, stdin);
    return input;
}

// Process the user's input
void process_input(char *input) {
    if (strcmp(input, "quit\n") == 0) {
        printf("Thank you for playing the Grateful Game!\n");
        exit(0);
    }

    // Trim whitespace from the input
    char *trimmed_input = strtok(input, " \n");

    // Print the user's gratitude
    printf("I am grateful for %s.\n", trimmed_input);

    // Generate a random gratitude quote
    int quote_index = random_range(0, 4);
    char *quotes[] = {
        "Gratitude is the key to happiness.",
        "Gratitude turns what we have into enough.",
        "Gratitude is the seed of abundance.",
        "Gratitude makes the world a more beautiful place.",
        "Gratitude is the best attitude."
    };

    printf("Here is a gratitude quote for you: %s\n", quotes[quote_index]);
}

// Main game loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Welcome the user
    welcome();

    // Loop until the user quits
    while (1) {
        // Print the gratitude prompt
        gratitude_prompt();

        // Get the user's input
        char *input = get_input();

        // Process the user's input
        process_input(input);
    }

    return 0;
}