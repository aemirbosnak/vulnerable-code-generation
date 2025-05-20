//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>

// struct to hold movie information
typedef struct {
    char title[50];
    char director[50];
    double rating;
} movie;

// function to get movie details from user
void getMovieDetails(movie *m) {
    printf("Enter movie title: ");
    scanf("%s", m->title);
    printf("Enter director name: ");
    scanf("%s", m->director);
    printf("Enter movie rating out of 10: ");
    scanf("%lf", &m->rating);
}

// function to display movie details
void displayMovie(movie m) {
    printf("Title: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Rating: %0.1f/10\n\n", m.rating);
}

// function to sort an array of movies by rating
void sortMoviesByRating(movie list[], int size) {
    int i, j;
    movie temp;
    
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (list[j].rating > list[i].rating) {
                temp = list[j];
                list[j] = list[i];
                list[i] = temp;
            }
        }
    }
}

int main() {
    int numMovies, i;
    printf("Welcome to the unique C Movie Rating System!\n\n");
    printf("Please enter the number of movies you want to rate: ");
    scanf("%d", &numMovies);
    printf("\n");
    movie movieList[numMovies];
    
    for (i = 0; i < numMovies; i++) {
        printf("Movie %d:\n", i+1);
        getMovieDetails(&movieList[i]);
    }
    
    sortMoviesByRating(movieList, numMovies);
    
    printf("Here are the movies you have rated, sorted by rating:\n\n");
    for (i = 0; i < numMovies; i++) {
        displayMovie(movieList[i]);
    }
    
    return 0;
}