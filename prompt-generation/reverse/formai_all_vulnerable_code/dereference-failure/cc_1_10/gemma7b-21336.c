//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct MovieRating {
    char title[256];
    int rating;
    struct MovieRating* next;
} MovieRating;

MovieRating* CreateMovieRating(char* title, int rating) {
    MovieRating* newRating = malloc(sizeof(MovieRating));
    strcpy(newRating->title, title);
    newRating->rating = rating;
    newRating->next = NULL;
    return newRating;
}

void AddMovieRating(MovieRating* head, char* title, int rating) {
    MovieRating* newRating = CreateMovieRating(title, rating);
    if (head == NULL) {
        head = newRating;
    } else {
        MovieRating* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newRating;
    }
}

int GetMovieRating(MovieRating* head, char* title) {
    MovieRating* current = head;
    while (current) {
        if (strcmp(current->title, title) == 0) {
            return current->rating;
        }
        current = current->next;
    }
    return -1;
}

int main() {
    MovieRating* head = NULL;
    AddMovieRating(head, "The Shawshank Redemption", 9);
    AddMovieRating(head, "The Godfather", 8);
    AddMovieRating(head, "The Dark Knight Rises", 7);
    int rating = GetMovieRating(head, "The Shawshank Redemption");
    printf("Rating: %d\n", rating);

    return 0;
}