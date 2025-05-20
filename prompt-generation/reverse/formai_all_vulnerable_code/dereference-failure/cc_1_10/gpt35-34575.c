//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>

// Struct for movie rating data
typedef struct {
    char title[50];
    char genre[20];
    int year;
    float rating;
} movie;

int main() {
    int numMovies;
    printf("Welcome to the Movie Rating System!\n");
    printf("Please enter the number of movies you want to rate: ");
    scanf("%d", &numMovies);

    // Allocating memory for movies
    movie *movies = malloc(numMovies * sizeof(movie));

    // Getting data for each movie
    for (int i = 0; i < numMovies; i++) {
        printf("\nPlease enter the details for Movie #%d:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
    }

    // Displaying all movie ratings
    printf("\n\nHere are the ratings for all movies entered:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("\nMovie #%d\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %0.1f/10\n", movies[i].rating);
    }

    // Finding highest rated movie
    float highestRating = 0;
    int highestIndex = 0;
    for (int i = 0; i < numMovies; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            highestIndex = i;
        }
    }
    printf("\n\nThe highest rated movie is:\n");
    printf("Title: %s\n", movies[highestIndex].title);
    printf("Genre: %s\n", movies[highestIndex].genre);
    printf("Year: %d\n", movies[highestIndex].year);
    printf("Rating: %0.1f/10\n", movies[highestIndex].rating);

    // Finding average rating for all movies
    float totalRating = 0;
    for (int i = 0; i < numMovies; i++) {
        totalRating += movies[i].rating;
    }
    float averageRating = totalRating / numMovies;
    printf("\n\nThe average rating for all movies is: %0.1f/10\n", averageRating);

    // Freeing memory allocated for movies
    free(movies);

    return 0;
}