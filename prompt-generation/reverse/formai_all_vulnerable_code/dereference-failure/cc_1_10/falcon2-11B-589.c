//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
    char title[100];
    int rating;
    struct movie *next;
} Movie;

Movie *head = NULL;

void insertMovie(Movie *movie) {
    if (head == NULL) {
        head = movie;
    } else {
        Movie *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = movie;
    }
}

void displayMovies() {
    Movie *current = head;
    while (current!= NULL) {
        printf("Title: %s\n", current->title);
        printf("Rating: %d\n", current->rating);
        printf("Next: ");
        if (current->next == NULL) {
            printf("NULL\n");
        } else {
            printf("%s\n", current->next->title);
        }
        current = current->next;
    }
}

int main() {
    Movie *movie1 = (Movie *)malloc(sizeof(Movie));
    movie1->title[0] = 'A';
    movie1->title[1] = '\0';
    movie1->rating = 5;
    movie1->next = NULL;
    insertMovie(movie1);

    Movie *movie2 = (Movie *)malloc(sizeof(Movie));
    movie2->title[0] = 'B';
    movie2->title[1] = '\0';
    movie2->rating = 4;
    movie2->next = NULL;
    insertMovie(movie2);

    Movie *movie3 = (Movie *)malloc(sizeof(Movie));
    movie3->title[0] = 'C';
    movie3->title[1] = '\0';
    movie3->rating = 3;
    movie3->next = NULL;
    insertMovie(movie3);

    Movie *movie4 = (Movie *)malloc(sizeof(Movie));
    movie4->title[0] = 'D';
    movie4->title[1] = '\0';
    movie4->rating = 2;
    movie4->next = NULL;
    insertMovie(movie4);

    Movie *movie5 = (Movie *)malloc(sizeof(Movie));
    movie5->title[0] = 'E';
    movie5->title[1] = '\0';
    movie5->rating = 1;
    movie5->next = NULL;
    insertMovie(movie5);

    Movie *movie6 = (Movie *)malloc(sizeof(Movie));
    movie6->title[0] = 'F';
    movie6->title[1] = '\0';
    movie6->rating = 0;
    movie6->next = NULL;
    insertMovie(movie6);

    displayMovies();

    return 0;
}