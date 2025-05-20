//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Get the user's input
char *get_rating(void);

// Print the movie rating
void print_rating(char *rating);

int main(void)
{
    // Get the user's input
    char *rating = get_rating();

    // Print the movie rating
    print_rating(rating);

    // Free the allocated memory
    free(rating);

    return 0;
}

// Get the user's input
char *get_rating(void)
{
    // Allocate memory for the rating
    char *rating = malloc(10);

    // Get the user's input
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%s", rating);

    // Return the rating
    return rating;
}

// Print the movie rating
void print_rating(char *rating)
{
    // Print the rating
    switch (*rating)
    {
        case 'G':
            printf("The movie is rated G.\n");
            break;
        case 'P':
            printf("The movie is rated PG.\n");
            break;
        case 't':
            printf("The movie is rated PG13.\n");
            break;
        case 'R':
            printf("The movie is rated R.\n");
            break;
        case 'N':
            printf("The movie is rated NC17.\n");
            break;
        default:
            printf("Invalid rating.\n");
            break;
    }
}