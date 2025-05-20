//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate user input
int validate_input(char *input) {
    int valid = 1;
    while (*input) {
        if (!isdigit(*input) && *input!= '.') {
            valid = 0;
            break;
        }
        input++;
    }
    return valid;
}

// Function to calculate average rating
float calculate_average_rating(float ratings[], int num_ratings) {
    float sum = 0;
    for (int i = 0; i < num_ratings; i++) {
        sum += ratings[i];
    }
    return sum / num_ratings;
}

// Function to display movie ratings
void display_ratings(float ratings[], int num_ratings) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("%d. %.2f\n", i + 1, ratings[i]);
    }
}

// Function to get user rating
float get_user_rating(char *movie_title) {
    float rating = 0;
    printf("Enter your rating for %s (out of 10): ", movie_title);
    if (scanf("%f", &rating)!= 1 ||!validate_input((char*)&movie_title)) {
        printf("Invalid input. Please enter a valid rating (out of 10).\n");
        exit(1);
    }
    return rating;
}

// Function to add user rating to movie ratings
void add_user_rating(float ratings[], int num_ratings, float user_rating) {
    ratings[num_ratings] = user_rating;
    num_ratings++;
}

// Main function
int main() {
    int num_ratings = 0;
    float ratings[100] = {0};
    char movie_title[100];

    // Initialize ratings array with default values
    for (int i = 0; i < 100; i++) {
        ratings[i] = 0;
    }

    // Get user rating
    printf("Enter a movie title: ");
    scanf("%s", movie_title);
    float user_rating = get_user_rating(movie_title);

    // Add user rating to movie ratings
    add_user_rating(ratings, num_ratings, user_rating);

    // Display movie ratings
    display_ratings(ratings, num_ratings);

    // Calculate average rating
    float average_rating = calculate_average_rating(ratings, num_ratings);
    printf("\nAverage rating: %.2f\n", average_rating);

    return 0;
}