//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for movies and reviews
typedef struct Movie {
    char *title;
    int year;
    char *genre;
    float rating;
    struct Review *reviews;
} Movie;

typedef struct Review {
    char *author;
    char *text;
    int rating;
    struct Review *next;
} Review;

// Function to create a new movie
Movie *create_movie(char *title, int year, char *genre, float rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->year = year;
    movie->genre = strdup(genre);
    movie->rating = rating;
    movie->reviews = NULL;
    return movie;
}

// Function to add a new review to a movie
void add_review(Movie *movie, char *author, char *text, int rating) {
    Review *review = malloc(sizeof(Review));
    review->author = strdup(author);
    review->text = strdup(text);
    review->rating = rating;
    review->next = movie->reviews;
    movie->reviews = review;
}

// Function to print the details of a movie
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Year: %d\n", movie->year);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %.1f\n", movie->rating);
    printf("Reviews:\n");
    Review *review = movie->reviews;
    while (review != NULL) {
        printf("  %s - %s - %d\n", review->author, review->text, review->rating);
        review = review->next;
    }
}

// Function to free the memory allocated for a movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie->genre);
    Review *review = movie->reviews;
    while (review != NULL) {
        Review *next = review->next;
        free(review->author);
        free(review->text);
        free(review);
        review = next;
    }
    free(movie);
}

// Main function
int main() {
    // Create a movie
    Movie *movie = create_movie("The Shawshank Redemption", 1994, "Drama", 9.3);

    // Add some reviews to the movie
    add_review(movie, "John Doe", "This is the best movie I've ever seen!", 10);
    add_review(movie, "Jane Doe", "I really enjoyed this movie.", 8);
    add_review(movie, "Bob Smith", "This movie was okay.", 6);

    // Print the details of the movie
    print_movie(movie);

    // Free the memory allocated for the movie
    free_movie(movie);

    return 0;
}