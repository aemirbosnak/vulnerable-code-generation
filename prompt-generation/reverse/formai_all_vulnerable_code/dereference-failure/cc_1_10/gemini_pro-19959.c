//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie {
    char *title;
    int year;
    double rating;
} movie;

typedef struct node {
    movie *movie;
    struct node *next;
} node;

node *head = NULL;

void add_movie(char *title, int year, double rating) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->movie = (movie *)malloc(sizeof(movie));
    new_node->movie->title = (char *)malloc(strlen(title) + 1);
    strcpy(new_node->movie->title, title);
    new_node->movie->year = year;
    new_node->movie->rating = rating;
    new_node->next = head;
    head = new_node;
}

void print_movies() {
    node *current = head;
    while (current != NULL) {
        printf("%s (%d): %.1f\n", current->movie->title, current->movie->year, current->movie->rating);
        current = current->next;
    }
}

void sort_movies_by_rating() {
    node *current = head;
    node *next;
    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            if (current->movie->rating < next->movie->rating) {
                movie *temp = current->movie;
                current->movie = next->movie;
                next->movie = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

int main() {
    add_movie("The Shawshank Redemption", 1994, 9.2);
    add_movie("The Godfather", 1972, 9.1);
    add_movie("The Dark Knight", 2008, 9.0);
    add_movie("12 Angry Men", 1957, 8.9);
    add_movie("Schindler's List", 1993, 8.9);

    print_movies();

    sort_movies_by_rating();

    printf("\nSorted movies by rating:\n");
    print_movies();

    return 0;
}