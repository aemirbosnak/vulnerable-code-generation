//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[256];
    int year;
    double rating;
    char genre[256];
    struct Movie* next;
};

struct Movie* insertMovie(struct Movie* head, char* title, int year, double rating, char* genre) {
    struct Movie* newNode = (struct Movie*)malloc(sizeof(struct Movie));
    strcpy(newNode->title, title);
    newNode->year = year;
    newNode->rating = rating;
    strcpy(newNode->genre, genre);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Movie* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printMovies(struct Movie* head) {
    struct Movie* temp = head;
    while (temp) {
        printf("%s (%d) - %.1lf (%.1s)\n", temp->title, temp->year, temp->rating, temp->genre);
        temp = temp->next;
    }
}

int main() {
    struct Movie* head = NULL;

    insertMovie(head, "The Shawshank Redemption", 1994, 9.3, "Drama");
    insertMovie(head, "The Godfather", 1972, 9.2, "Crime");
    insertMovie(head, "The Dark Knight Rises", 2008, 8.0, "Action");

    printMovies(head);

    return 0;
}