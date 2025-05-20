//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Define the maximum number of sides for a die.
#define MAX_SIDES 6

// Define the minimum number of sides for a die.
#define MIN_SIDES 1

// Define the maximum number of dice to roll.
#define MAX_DICE 10

// Define the minimum number of dice to roll.
#define MIN_DICE 1

// Define the maximum number of rolls to perform.
#define MAX_ROLLS 100

// Define the minimum number of rolls to perform.
#define MIN_ROLLS 1

// Define the minimum number of times a die needs to be rolled to get a certain score.
#define MIN_ATTEMPTS_PER_SCORE 1

// Function to roll a die with a given number of sides.
int roll_die(int sides) {
    if (sides < MIN_SIDES || sides > MAX_SIDES) {
        return -1;
    }
    return rand() % sides + 1;
}

// Function to roll a set of dice with a given number of sides.
int roll_dice(int num_dice, int sides) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += roll_die(sides);
    }
    return total;
}

// Function to roll a dice set and print the results.
void roll_and_print(int num_dice, int sides, int num_rolls) {
    if (num_dice < MIN_DICE || num_dice > MAX_DICE) {
        printf("Invalid number of dice.\n");
        return;
    }
    if (sides < MIN_SIDES || sides > MAX_SIDES) {
        printf("Invalid number of sides.\n");
        return;
    }
    if (num_rolls < MIN_ROLLS || num_rolls > MAX_ROLLS) {
        printf("Invalid number of rolls.\n");
        return;
    }
    for (int i = 0; i < num_rolls; i++) {
        printf("%d\n", roll_dice(num_dice, sides));
    }
}

// Function to get a random number between two values.
int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random dice set.
void generate_random_dice_set(int *num_dice, int *sides, int *num_rolls) {
    *num_dice = get_random_int(MIN_DICE, MAX_DICE);
    *sides = get_random_int(MIN_SIDES, MAX_SIDES);
    *num_rolls = get_random_int(MIN_ROLLS, MAX_ROLLS);
}

// Function to get a random score for a dice set.
int get_random_score(int num_dice, int sides) {
    int min_score = num_dice * MIN_ATTEMPTS_PER_SCORE;
    int max_score = num_dice * sides;
    return get_random_int(min_score, max_score);
}

// Function to roll a dice set and attempt to get a certain score.
void roll_and_attempt(int num_dice, int sides, int score) {
    int attempts = 0;
    int total = 0;
    while (total != score) {
        total = roll_dice(num_dice, sides);
        attempts++;
    }
    printf("It took %d attempts to get a score of %d with %d dice with %d sides.\n", attempts, score, num_dice, sides);
}

// Function to print a help message.
void print_help() {
    printf("Usage: dice_roller [options]\n");
    printf("Options:\n");
    printf("  -h, --help        Print this help message.\n");
    printf("  -n, --num-dice     The number of dice to roll.\n");
    printf("  -s, --sides        The number of sides on each die.\n");
    printf("  -r, --num-rolls    The number of times to roll the dice.\n");
    printf("  -g, --generate     Generate a random dice set.\n");
    printf("  -a, --attempt      Attempt to get a certain score with a dice set.\n");
}

// Main function.
int main(int argc, char *argv[]) {
    // Parse command-line arguments.
    int num_dice = MIN_DICE;
    int sides = MIN_SIDES;
    int num_rolls = MIN_ROLLS;
    int generate = 0;
    int attempt = 0;
    int score = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--num-dice") == 0) {
            if (i + 1 < argc) {
                num_dice = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--sides") == 0) {
            if (i + 1 < argc) {
                sides = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--num-rolls") == 0) {
            if (i + 1 < argc) {
                num_rolls = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--generate") == 0) {
            generate = 1;
        } else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--attempt") == 0) {
            if (i + 1 < argc) {
                score = atoi(argv[i + 1]);
                attempt = 1;
            }
        } else {
            printf("Invalid option: %s\n", argv[i]);
            print_help();
            return 1;
        }
    }
    // Initialize random number generator.
    srand(time(NULL));
    // Generate a random dice set if requested.
    if (generate) {
        generate_random_dice_set(&num_dice, &sides, &num_rolls);
    }
    // Roll the dice and print the results.
    if (!attempt) {
        roll_and_print(num_dice, sides, num_rolls);
    } else {
        roll_and_attempt(num_dice, sides, score);
    }
    return 0;
}