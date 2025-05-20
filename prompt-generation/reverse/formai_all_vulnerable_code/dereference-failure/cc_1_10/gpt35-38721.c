//FormAI DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store movie information
typedef struct {
    char *title;
    int year;
    float rating;
} movie;

// Define a function to add a new movie to the rating system
void add_movie(movie *movies, int *num_movies, char *title, int year, float rating) {
    movies[*num_movies].title = malloc(strlen(title) + 1); // Allocate memory for movie title
    strcpy(movies[*num_movies].title, title); // Copy title string to newly allocated memory
    movies[*num_movies].year = year;
    movies[*num_movies].rating = rating;
    (*num_movies)++; // Increment the number of movies in the system
}

// Define a function to print the top rated movies in the rating system
void top_rated(movie *movies, int num_movies) {
    printf("Top Rated Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating >= 9.0) {
            printf("%s (%d) - %.1f\n", movies[i].title, movies[i].year, movies[i].rating);
        }
    }
}

// Define a function to print the most recent movies in the rating system
void most_recent(movie *movies, int num_movies) {
    printf("Most Recent Movies:\n");
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].year >= 2020) {
            printf("%s (%d) - %.1f\n", movies[i].title, movies[i].year, movies[i].rating);
        }
    }
}

int main() {
    // Initialize an array of movies with a capacity of 10
    movie my_movies[10];
    int num_movies = 0; // Initialize the number of movies to 0

    // Add some sample movies to the system
    add_movie(my_movies, &num_movies, "The Shawshank Redemption", 1994, 9.3);
    add_movie(my_movies, &num_movies, "The Godfather", 1972, 9.2);
    add_movie(my_movies, &num_movies, "The Dark Knight", 2008, 9.0);
    add_movie(my_movies, &num_movies, "12 Angry Men", 1957, 8.9);
    add_movie(my_movies, &num_movies, "Schindler's List", 1993, 8.9);

    // Print the top rated and most recent movies in the rating system
    top_rated(my_movies, num_movies);
    most_recent(my_movies, num_movies);

    // Free memory allocated for movie titles
    for (int i = 0; i < num_movies; i++) {
        free(my_movies[i].title);
    }

    return 0;
}