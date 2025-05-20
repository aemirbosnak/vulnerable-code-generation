//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Movie {
    char title[100];
    int rating;
    struct Movie* next;
} Movie;

Movie* head = NULL;

void addMovie(char* title, int rating) {
    Movie* newMovie = (Movie*) malloc(sizeof(Movie));
    strcpy(newMovie->title, title);
    newMovie->rating = rating;
    newMovie->next = head;
    head = newMovie;
}

void printMovies() {
    Movie* current = head;
    printf("---- C MOVIE RATING SYSTEM ----\n");
    while (current != NULL) {
        printf("%s: %d\n", current->title, current->rating);
        current = current->next;
    }
}

void updateRating(char* title, int newRating) {
    Movie* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            current->rating = newRating;
            break;
        }
        current = current->next;
    }
}

int main() {
    char title[100];
    int choice, rating;

    while (1) {
        printf("1. Add Movie\n");
        printf("2. Print Movies\n");
        printf("3. Update Rating\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating: ");
                scanf("%d", &rating);
                addMovie(title, rating);
                break;

            case 2:
                printMovies();
                break;

            case 3:
                printf("Enter movie title to update: ");
                scanf("%s", title);
                printf("Enter new movie rating: ");
                scanf("%d", &rating);
                updateRating(title, rating);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    free(head);
    return 0;
}