//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>

// Function to calculate the letter grade based on the average ratings
char calculateGrade(float averageRating) {
    if (averageRating >= 90.0) {
        return 'A';
    } else if (averageRating >= 80.0) {
        return 'B';
    } else if (averageRating >= 70.0) {
        return 'C';
    } else if (averageRating >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int numMovies;
    printf("Enter the number of movies to rate: ");
    scanf("%d", &numMovies);

    // Create an array to store the ratings for each movie
    float movieRatings[numMovies];

    // Loop through each movie and ask for a rating
    for (int i = 0; i < numMovies; i++) {
        printf("Enter the rating for movie %d (out of 10): ", i+1);
        scanf("%f", &movieRatings[i]);
    }

    // Calculate the average rating for all movies
    float totalRating = 0;
    for (int i = 0; i < numMovies; i++) {
        totalRating += movieRatings[i];
    }
    float averageRating = totalRating / numMovies;

    // Calculate the letter grade based on the average rating
    char letterGrade = calculateGrade(averageRating);

    // Output the results
    printf("Average rating for all movies: %.2f\n", averageRating);
    printf("Letter grade: %c\n", letterGrade);

    // Output the individual ratings for each movie
    printf("Individual ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Movie %d: %.2f\n", i+1, movieRatings[i]);
    }

    return 0;
}