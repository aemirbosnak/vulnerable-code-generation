//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    int rating;
    char review[100];
} Movie;

Movie createMovie(char title[], int rating, char review[]) {
    Movie movie;
    strcpy(movie.title, title);
    movie.rating = rating;
    strcpy(movie.review, review);
    return movie;
}

void printMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Rating: %d\n", movie.rating);
    printf("Review: %s\n", movie.review);
}

void addMovie(Movie movies[], int size, int index, char title[], int rating, char review[]) {
    if (index >= size) {
        size++;
        movies = realloc(movies, sizeof(Movie) * size);
    }
    movies[index] = createMovie(title, rating, review);
}

void sortMoviesByRating(Movie movies[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (movies[j].rating > movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }
}

void printMovies(Movie movies[], int size) {
    for (int i = 0; i < size; i++) {
        printMovie(movies[i]);
    }
}

int main() {
    Movie movies[5];
    int size = 0;
    char title[50] = "The Shawshank Redemption";
    int rating = 9;
    char review[100] = "A truly inspiring story of hope and redemption.";
    addMovie(movies, size, size, title, rating, review);
    size++;

    char title2[50] = "The Godfather";
    int rating2 = 8;
    char review2[100] = "A classic tale of power and corruption.";
    addMovie(movies, size, size - 1, title2, rating2, review2);
    size++;

    char title3[50] = "Pulp Fiction";
    int rating3 = 7;
    char review3[100] = "A stylish and entertaining crime drama.";
    addMovie(movies, size, size - 2, title3, rating3, review3);
    size++;

    char title4[50] = "The Dark Knight";
    int rating4 = 6;
    char review4[100] = "A thrilling superhero movie with great performances.";
    addMovie(movies, size, size - 3, title4, rating4, review4);
    size++;

    char title5[50] = "Inception";
    int rating5 = 5;
    char review5[100] = "A mind-bending sci-fi thriller with stunning visuals.";
    addMovie(movies, size, size - 4, title5, rating5, review5);
    size++;

    sortMoviesByRating(movies, size);
    printMovies(movies, size);

    return 0;
}