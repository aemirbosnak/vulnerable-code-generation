//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_REVIEWS 100
#define REVIEW_LENGTH 256

typedef struct {
    char name[REVIEW_LENGTH];
    char review[REVIEW_LENGTH];
    bool isPositive;
} Review;

void processReview(Review* review) {
    int i;
    int sum = 0;

    // Calculate Shannon score based on the number of positive and negative words
    for (i = 0; i < strlen(review->review); i++) {
        if (isalpha(review->review[i])) {
            sum += (isupper(review->review[i]) ? 1 : -1);
        }
    }

    // Determine if the review is positive or negative based on the Shannon score
    if (sum > 0) {
        review->isPositive = true;
    } else {
        review->isPositive = false;
    }
}

int main() {
    Review reviews[MAX_REVIEWS];
    int numReviews = 0;
    char line[REVIEW_LENGTH];

    while (fgets(line, REVIEW_LENGTH, stdin) != NULL) {
        if (numReviews >= MAX_REVIEWS) {
            printf("Maximum number of reviews reached. Exiting...\n");
            break;
        }

        strcpy(reviews[numReviews].name, strtok(line, ": "));
        strcpy(reviews[numReviews].review, strtok(NULL, "\n"));
        processReview(&reviews[numReviews]);
        numReviews++;
    }

    // Calculate the total number of positive and negative reviews
    int numPositiveReviews = 0;
    int numNegativeReviews = 0;
    for (int i = 0; i < numReviews; i++) {
        if (reviews[i].isPositive) {
            numPositiveReviews++;
        } else {
            numNegativeReviews++;
        }
    }

    // Determine the overall movie rating using binary arithmetic
    int totalPositiveBits = numPositiveReviews * 1;
    int totalNegativeBits = numNegativeReviews * 1;
    int rating = totalPositiveBits ^ totalNegativeBits;

    // Print the movie rating
    printf("Movie rating: %d\n", rating);

    return 0;
}