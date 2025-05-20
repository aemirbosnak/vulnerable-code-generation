//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to get user input for movie ratings
int getMovieRating(void) {
  int rating;
  printf("Enter your rating for the movie (1-5): ");
  scanf("%d", &rating);

  // Validate user input
  while (rating < 1 || rating > 5) {
    printf("Invalid rating. Please enter a rating between 1 and 5: ");
    scanf("%d", &rating);
  }

  return rating;
}

// Function to calculate the average movie rating
float calculateAverageRating(int ratings[], int numRatings) {
  float averageRating = 0.0;
  for (int i = 0; i < numRatings; i++) {
    averageRating += ratings[i];
  }
  averageRating /= numRatings;

  return averageRating;
}

// Function to display the movie ratings and average rating
void displayMovieRatings(int ratings[], int numRatings, float averageRating) {
  printf("\nMovie Ratings:\n");
  for (int i = 0; i < numRatings; i++) {
    printf("Movie %d: %d\n", i + 1, ratings[i]);
  }

  printf("\nAverage Rating: %.2f\n", averageRating);
}

int main() {
  // Get the number of movie ratings from the user
  int numRatings;
  printf("How many movie ratings do you want to enter? ");
  scanf("%d", &numRatings);

  // Create an array to store the movie ratings
  int ratings[numRatings];

  // Get the movie ratings from the user
  for (int i = 0; i < numRatings; i++) {
    ratings[i] = getMovieRating();
  }

  // Calculate the average movie rating
  float averageRating = calculateAverageRating(ratings, numRatings);

  // Display the movie ratings and average rating
  displayMovieRatings(ratings, numRatings, averageRating);

  return 0;
}