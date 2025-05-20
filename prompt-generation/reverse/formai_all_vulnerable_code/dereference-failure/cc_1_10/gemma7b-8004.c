//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct MovieRating
{
    char title[50];
    int rating;
    struct MovieRating* next;
} MovieRating;

MovieRating* createMovieRating(char* title, int rating)
{
    MovieRating* newRating = (MovieRating*)malloc(sizeof(MovieRating));
    strcpy(newRating->title, title);
    newRating->rating = rating;
    newRating->next = NULL;
    return newRating;
}

void addMovieRating(MovieRating* head, char* title, int rating)
{
    MovieRating* newRating = createMovieRating(title, rating);
    if (head == NULL)
    {
        head = newRating;
    }
    else
    {
        MovieRating* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newRating;
    }
}

int main()
{
    MovieRating* head = NULL;
    addMovieRating(head, "The Shawshank Redemption", 9);
    addMovieRating(head, "The Godfather", 8);
    addMovieRating(head, "The Dark Knight", 8);
    addMovieRating(head, "The Lord of the Flies", 7);

    MovieRating* current = head;
    while (current)
    {
        printf("%s - Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    return 0;
}