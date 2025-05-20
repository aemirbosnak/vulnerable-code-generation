//FormAI DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main()
{
    // User-defined variables
    int num_pairs;
    printf("Enter the number of pairs you want to play with (minimum 5 and maximum 10): ");
    scanf("%d", &num_pairs);

    // Ensure num_pairs is between 5 and 10
    if (num_pairs < 5)
    {
        printf("Invalid input! Please enter a number greater than or equal to 5.\n");
        return 1;
    }
    else if (num_pairs > 10)
    {
        printf("Invalid input! Please enter a number less than or equal to 10.\n");
        return 1;
    }

    // Create an array of size num_pairs * 2 and fill it with numbers from 1 to num_pairs
    int *card_array = malloc(num_pairs * 2 * sizeof(int));
    for (int i = 0; i < num_pairs * 2; i += 2)
    {
        card_array[i] = i / 2 + 1;
        card_array[i + 1] = i / 2 + 1;
    }

    // Shuffle the array using a random number generator
    srand(time(NULL));
    shuffle(card_array, num_pairs * 2);

    // Initialize game variables
    int num_guesses = 0;
    int num_matches = 0;
    int *card_positions = malloc(num_pairs * 2 * sizeof(int));
    for (int i = 0; i < num_pairs * 2; i++)
    {
        card_positions[i] = 0; // 0 denotes card is face-down, 1 denotes card is face-up
    }

    // Start game loop
    while (num_matches < num_pairs)
    {
        // Print current state of game board
        printf("Current board state:\n");
        for (int i = 0; i < num_pairs * 2; i++)
        {
            if (card_positions[i] == 0) // card is face-down
            {
                printf("[ ] ");
            }
            else // card is face-up
            {
                printf("[%d] ", card_array[i]);
            }
        }
        printf("\n");

        // Get user guess
        int guess1, guess2;
        printf("Enter two card positions to check (separated by a space): ");
        scanf("%d %d", &guess1, &guess2);

        // Ensure user input is within valid range
        if (guess1 < 1 || guess1 > num_pairs * 2 || guess2 < 1 || guess2 > num_pairs * 2)
        {
            printf("Invalid input! Please enter card positions between 1 and %d.\n", num_pairs * 2);
            continue;
        }

        // Ensure user does not choose the same position twice
        if (guess1 == guess2)
        {
            printf("Invalid input! Please enter two different card positions.\n");
            continue;
        }

        // Check if user guesses match
        if (card_array[guess1 - 1] == card_array[guess2 - 1]) // user guesses match
        {
            printf("Congratulations, you found a match!\n");
            card_positions[guess1 - 1] = 1;
            card_positions[guess2 - 1] = 1;
            num_matches++;
        }
        else // user guesses do not match
        {
            printf("Sorry, your guesses did not match. Try again!\n");
            num_guesses++;
        }
    }

    // Print game summary
    printf("Congratulations, you won the game in %d guesses!\n", num_guesses);
    printf("Final board state:\n");
    for (int i = 0; i < num_pairs * 2; i++)
    {
        printf("[%d] ", card_array[i]);
    }
    printf("\n");

    // Free memory
    free(card_array);
    free(card_positions);

    return 0;
}