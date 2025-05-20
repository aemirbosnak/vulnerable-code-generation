//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie {
    char title[50];
    char director[50];
    char genre[50];
    char actors[100];
    int length;
    int rating;
} Movie;

int main() {
    int numMovies;
    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    Movie movies[numMovies];

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie %d information:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Genre: ");
        scanf("%s", movies[i].genre);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Length (in minutes): ");
        scanf("%d", &movies[i].length);
        printf("Rating (out of 10): ");
        scanf("%d", &movies[i].rating);
    }

    printf("\nMovie Ratings:\n");

    for (int i = 0; i < numMovies; i++) {
        printf("\nMovie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Genre: %s\n", movies[i].genre);
        printf("Actors: %s\n", movies[i].actors);
        printf("Length: %d minutes\n", movies[i].length);
        printf("Rating: %d out of 10\n\n", movies[i].rating);
    }

    return 0;
}