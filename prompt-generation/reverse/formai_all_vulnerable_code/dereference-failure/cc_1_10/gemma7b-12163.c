//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MovieRating
{
    char title[50];
    int year;
    float rating;
    char genre[50];
    struct MovieRating* next;
} MovieRating;

MovieRating* insertMovie(MovieRating* head, char* title, int year, float rating, char* genre)
{
    MovieRating* newMovie = malloc(sizeof(MovieRating));
    strcpy(newMovie->title, title);
    newMovie->year = year;
    newMovie->rating = rating;
    strcpy(newMovie->genre, genre);
    newMovie->next = NULL;

    if (head == NULL)
    {
        head = newMovie;
    }
    else
    {
        head->next = newMovie;
    }

    return head;
}

void printMovie(MovieRating* head)
{
    while (head)
    {
        printf("%s (%d) - %.1f stars, %s\n", head->title, head->year, head->rating, head->genre);
        head = head->next;
    }
}

int main()
{
    MovieRating* head = NULL;

    insertMovie(head, "The Shawshank Redemption", 1994, 9.3, "Drama");
    insertMovie(head, "The Godfather", 1972, 9.2, "Drama");
    insertMovie(head, "The Dark Knight Rises", 2008, 8.8, "Action");
    insertMovie(head, "The Matrix Reloaded", 2003, 8.6, "Science Fiction");

    printMovie(head);

    return 0;
}