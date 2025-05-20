//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Movie {
    char title[100];
    int rating;
    struct Movie* next;
} Movie;

void readMovies(Movie** head) {
    FILE* file = fopen("movies.txt", "r");
    char title[100];
    int rating;
    Movie* newMovie = NULL;
    Movie* current = *head;

    while (fscanf(file, "%s%d%*[^\n]", title, &rating) != EOF) {
        if (!(newMovie = (Movie*) malloc(sizeof(Movie)))) {
            printf("Memory error!\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newMovie->title, title);
        newMovie->rating = rating;
        newMovie->next = NULL;

        if (*head == NULL) {
            *head = newMovie;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newMovie;
        }
    }

    fclose(file);
}

void printMovies(Movie* head) {
    Movie* current = head;

    printf("Title\tRating\n");
    printf("---------------------\n");

    while (current != NULL) {
        printf("%s\t%d\n", current->title, current->rating);
        current = current->next;
    }
}

void findAverageRating(Movie* head) {
    int sum = 0;
    int count = 0;
    Movie* current = head;

    while (current != NULL) {
        sum += current->rating;
        count++;
        current = current->next;
    }

    printf("Average rating: %d\n", sum / count);
}

int main() {
    Movie* movies = NULL;

    readMovies(&movies);
    printMovies(movies);
    findAverageRating(movies);

    Movie* current = movies;

    while (current != NULL) {
        Movie* temp = current->next;
        free(current);
        current = temp;
    }

    return 0;
}