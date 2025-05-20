//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct MovieRating
{
    char title[50];
    int year;
    float rating;
    char genre[20];
    struct MovieRating* next;
};

typedef struct MovieRating MovieRating;

void insertMovie(MovieRating** head, char* title, int year, float rating, char* genre)
{
    MovieRating* newNode = (MovieRating*)malloc(sizeof(MovieRating));

    strcpy(newNode->title, title);
    newNode->year = year;
    newNode->rating = rating;
    strcpy(newNode->genre, genre);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void printMovies(MovieRating* head)
{
    while (head)
    {
        printf("%s (%d) - %.1f - %s\n", head->title, head->year, head->rating, head->genre);
        head = head->next;
    }
}

int main()
{
    MovieRating* head = NULL;

    insertMovie(&head, "The Shawshank Redemption", 1994, 9.3, "Drama");
    insertMovie(&head, "The Godfather Part II", 1974, 9.2, "Drama");
    insertMovie(&head, "The Dark Knight Rises", 2008, 8.0, "Action");

    printMovies(head);

    return 0;
}