//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct MovieRating
{
    char title[50];
    int year;
    float rating;
    struct MovieRating* next;
} MovieRating;

MovieRating* createMovieRating(char* title, int year, float rating)
{
    MovieRating* newMovieRating = malloc(sizeof(MovieRating));
    strcpy(newMovieRating->title, title);
    newMovieRating->year = year;
    newMovieRating->rating = rating;
    newMovieRating->next = NULL;
    return newMovieRating;
}

void addMovieRating(MovieRating* head, char* title, int year, float rating)
{
    MovieRating* newMovieRating = createMovieRating(title, year, rating);
    if (head == NULL)
    {
        head = newMovieRating;
    }
    else
    {
        MovieRating* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newMovieRating;
    }
}

void printMovieRatings(MovieRating* head)
{
    MovieRating* temp = head;
    while (temp)
    {
        printf("%s (%d) - %.1f\n", temp->title, temp->year, temp->rating);
        temp = temp->next;
    }
}

int main()
{
    MovieRating* head = NULL;
    addMovieRating(head, "The Shawshank Redemption", 1994, 9.3);
    addMovieRating(head, "The Godfather", 1972, 9.2);
    addMovieRating(head, "The Dark Knight Rises", 2008, 8.5);
    printMovieRatings(head);
    return 0;
}