//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style C Movie Rating System

// Define the movie rating system constants
#define RATING_G     "G"
#define RATING_PG    "PG"
#define RATING_PG13  "PG-13"
#define RATING_R     "R"
#define RATING_NC17  "NC-17"

// Define the movie rating system structure
typedef struct {
    char *rating;
    int age_limit;
} MovieRating;

// Define the movie rating system array
MovieRating movie_ratings[] = {
    { RATING_G,     0 },
    { RATING_PG,    8 },
    { RATING_PG13, 13 },
    { RATING_R,     17 },
    { RATING_NC17,  18 }
};

// Define the number of movie ratings
#define NUM_RATINGS (sizeof(movie_ratings) / sizeof(MovieRating))

// Get the movie rating from the user
char *get_movie_rating(void) {
    char *rating;

    printf("Enter the movie rating (G, PG, PG-13, R, or NC-17): ");
    scanf("%s", rating);

    return rating;
}

// Get the user's age
int get_user_age(void) {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    return age;
}

// Check if the user is old enough to see the movie
int is_user_old_enough(char *rating, int age) {
    int i;

    for (i = 0; i < NUM_RATINGS; i++) {
        if (strcmp(rating, movie_ratings[i].rating) == 0) {
            return age >= movie_ratings[i].age_limit;
        }
    }

    return 0;
}

// Print the movie rating system
void print_movie_rating_system(void) {
    int i;

    printf("Movie Rating System:\n");
    for (i = 0; i < NUM_RATINGS; i++) {
        printf("  %s: %d\n", movie_ratings[i].rating, movie_ratings[i].age_limit);
    }
}

// Main function
int main(void) {
    char *rating;
    int age;

    // Get the movie rating from the user
    rating = get_movie_rating();

    // Get the user's age
    age = get_user_age();

    // Check if the user is old enough to see the movie
    if (is_user_old_enough(rating, age)) {
        printf("You are old enough to see the movie.\n");
    } else {
        printf("You are not old enough to see the movie.\n");
    }

    // Print the movie rating system
    print_movie_rating_system();

    return 0;
}