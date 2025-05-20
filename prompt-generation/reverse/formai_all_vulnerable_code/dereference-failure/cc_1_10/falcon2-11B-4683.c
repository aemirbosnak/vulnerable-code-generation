//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int movieId;
    int reviewerId;
    int rating;
} MovieReview;

double calculateAverageRating(MovieReview* reviews, int numReviews) {
    int totalRating = 0;
    int numReviewsWithRatings = 0;

    for (int i = 0; i < numReviews; i++) {
        if (reviews[i].rating!= -1) {
            totalRating += reviews[i].rating;
            numReviewsWithRatings++;
        }
    }

    if (numReviewsWithRatings == 0) {
        return 0.0;
    }

    return (double)totalRating / numReviewsWithRatings;
}

int main() {
    MovieReview* reviews = (MovieReview*)malloc(10 * sizeof(MovieReview));
    int numReviews = 5;

    // Populate reviews array with data
    reviews[0].movieId = 1;
    reviews[0].reviewerId = 1;
    reviews[0].rating = 4;

    reviews[1].movieId = 1;
    reviews[1].reviewerId = 2;
    reviews[1].rating = 3;

    reviews[2].movieId = 2;
    reviews[2].reviewerId = 3;
    reviews[2].rating = -1;

    reviews[3].movieId = 2;
    reviews[3].reviewerId = 4;
    reviews[3].rating = 5;

    reviews[4].movieId = 3;
    reviews[4].reviewerId = 5;
    reviews[4].rating = 2;

    // Calculate average rating
    double averageRating = calculateAverageRating(reviews, numReviews);

    // Print average rating
    printf("Average Rating: %f\n", averageRating);

    // Free allocated memory
    free(reviews);

    return 0;
}