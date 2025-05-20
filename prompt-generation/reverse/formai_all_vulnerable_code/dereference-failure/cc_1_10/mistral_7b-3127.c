//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie {
    char title[100];
    int year;
    float rating;
    struct Movie* next;
} Movie;

void addMovie(Movie** head, char* title, int year, float rating) {
    Movie* newMovie = (Movie*) malloc(sizeof(Movie));
    strcpy(newMovie->title, title);
    newMovie->year = year;
    newMovie->rating = rating;
    newMovie->next = *head;
    *head = newMovie;
}

void printMovieList(Movie* head) {
    Movie* current = head;
    while (current != NULL) {
        printf("%s (%d) - %.2f\n", current->title, current->year, current->rating);
        current = current->next;
    }
}

void calculateAverageRating(Movie* head) {
    Movie* current = head;
    float sum = 0;
    int count = 0;

    while (current != NULL) {
        sum += current->rating;
        count++;
        current = current->next;
    }

    printf("Average rating: %.2f\n", sum / count);
}

int main() {
    Movie* movieList = NULL;

    addMovie(&movieList, "The Shawshank Redemption", 1994, 9.3);
    addMovie(&movieList, "The Godfather", 1972, 9.2);
    addMovie(&movieList, "The Dark Knight", 2008, 9.0);
    addMovie(&movieList, "12 Angry Men", 1957, 8.9);
    addMovie(&movieList, "Schindler's List", 1993, 8.8);

    printf("Movie List:\n");
    printMovieList(movieList);

    printf("\nAverage Rating: ");
    calculateAverageRating(movieList);

    return 0;
}