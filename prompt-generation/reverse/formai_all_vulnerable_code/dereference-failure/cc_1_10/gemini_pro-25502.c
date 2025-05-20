//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data type for movie rating
typedef struct {
  float avgRating;
  int numRatings;
  int totalStars;
  int starDistributions[5]; // Distribution of ratings from 1 to 5 stars
} MovieRating;

// Initialize a movie rating with default values
MovieRating initMovieRating() {
  MovieRating rating;
  rating.avgRating = 0.0;
  rating.numRatings = 0;
  rating.totalStars = 0;
  for (int i = 0; i < 5; i++) {
    rating.starDistributions[i] = 0;
  }
  return rating;
}

// Add a new rating to a movie rating
void addRating(MovieRating *rating, int stars) {
  if (stars < 1 || stars > 5) {
    printf("Invalid rating: %d\n", stars);
    return;
  }

  rating->numRatings++;
  rating->totalStars += stars;
  rating->starDistributions[stars - 1]++;

  rating->avgRating = (float)rating->totalStars / rating->numRatings;
}

// Print the movie rating summary
void printRating(MovieRating rating) {
  printf("Average rating: %.2f\n", rating.avgRating);
  printf("Number of ratings: %d\n", rating.numRatings);
  for (int i = 0; i < 5; i++) {
    printf("%d stars: %d\n", i + 1, rating.starDistributions[i]);
  }
}

// Get a random rating between 1 and 5
int getRandomRating() {
  return rand() % 5 + 1;
}

// Generate a list of random movie ratings
MovieRating *generateRatings(int numRatings) {
  MovieRating *ratings = malloc(sizeof(MovieRating) * numRatings);
  for (int i = 0; i < numRatings; i++) {
    ratings[i] = initMovieRating();
    for (int j = 0; j < 10; j++) {
      addRating(&ratings[i], getRandomRating());
    }
  }
  return ratings;
}

// Find the movie with the highest average rating
MovieRating findHighestRatedMovie(MovieRating *ratings, int numRatings) {
  MovieRating highestRated = ratings[0];
  for (int i = 1; i < numRatings; i++) {
    if (ratings[i].avgRating > highestRated.avgRating) {
      highestRated = ratings[i];
    }
  }
  return highestRated;
}

// Main function
int main() {
  // Generate a list of 100 random movie ratings
  MovieRating *ratings = generateRatings(100);

  // Find the movie with the highest average rating
  MovieRating highestRated = findHighestRatedMovie(ratings, 100);

  // Print the summary of the highest rated movie
  printf("Highest Rated Movie:\n");
  printRating(highestRated);

  // Free the allocated memory
  free(ratings);

  return 0;
}