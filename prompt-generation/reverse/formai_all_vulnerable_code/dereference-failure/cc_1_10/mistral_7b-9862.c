//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    float rating;
    int year;
} Movie;

typedef struct Node {
    Movie movie;
    struct Node* next;
} Node;

Node* head = NULL;

void addMovie(char* title, float rating, int year) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    strcpy(newNode->movie.title, title);
    newNode->movie.rating = rating;
    newNode->movie.year = year;
    newNode->next = head;

    head = newNode;
}

void printList() {
    Node* current = head;

    printf("\nMovie List:\n");
    printf("------------------------\n");

    while (current != NULL) {
        printf("%s (%d) - %.2f\n", current->movie.title, current->movie.year, current->movie.rating);
        current = current->next;
    }

    printf("------------------------\n");
}

void searchMovie(char* title) {
    Node* current = head;

    int found = 0;

    printf("\nSearching for movie '%s'...\n", title);

    while (current != NULL && found == 0) {
        if (strcmp(current->movie.title, title) == 0) {
            printf("Movie '%s' (Year: %d, Rating: %.2f) found!\n", current->movie.title, current->movie.year, current->movie.rating);
            found = 1;
        } else {
            current = current->next;
        }
    }

    if (found == 0) {
        printf("Movie '%s' not found.\n", title);
    }
}

int main() {
    addMovie("The Shawshank Redemption", 9.3, 1994);
    addMovie("The Godfather", 9.2, 1972);
    addMovie("The Dark Knight", 9.0, 2008);
    addMovie("12 Angry Men", 8.9, 1957);
    addMovie("Schindler's List", 8.7, 1993);

    printList();

    searchMovie("The Godfather");

    return 0;
}