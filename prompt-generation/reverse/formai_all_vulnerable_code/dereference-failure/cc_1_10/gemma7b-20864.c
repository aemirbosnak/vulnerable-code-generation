//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[256];
    int year;
    float rating;
    char genre[256];
    struct Movie* next;
};

struct Movie* insertMovie(struct Movie* head, char* title, int year, float rating, char* genre) {
    struct Movie* newMovie = malloc(sizeof(struct Movie));
    strcpy(newMovie->title, title);
    newMovie->year = year;
    newMovie->rating = rating;
    strcpy(newMovie->genre, genre);
    newMovie->next = NULL;

    if (head == NULL) {
        head = newMovie;
    } else {
        struct Movie* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newMovie;
    }

    return head;
}

void printMovies(struct Movie* head) {
    struct Movie* temp = head;
    while (temp) {
        printf("%s (%d) - %.1f, %s\n", temp->title, temp->year, temp->rating, temp->genre);
        temp = temp->next;
    }
}

int main() {
    struct Movie* head = NULL;

    insertMovie(head, "The Shawshank Redemption", 1994, 9.3, "Drama");
    insertMovie(head, "The Godfather", 1972, 9.2, "Drama");
    insertMovie(head, "The Dark Knight", 2008, 8.8, "Action");
    insertMovie(head, "The Matrix Reloaded", 2003, 8.6, "Action");

    printMovies(head);

    return 0;
}