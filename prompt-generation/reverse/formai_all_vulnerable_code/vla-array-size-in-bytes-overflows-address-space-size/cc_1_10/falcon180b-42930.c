//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_ACTORS 10
#define MAX_GENRES 5
#define MAX_GENRE_LENGTH 20
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS][MAX_ACTOR_LENGTH];
    char genres[MAX_GENRES][MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies;
    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &numMovies);

    Movie movies[numMovies];
    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);

        printf("Enter the director of movie %d: ", i+1);
        scanf("%s", movies[i].director);

        int numActors;
        printf("Enter the number of actors in movie %d: ", i+1);
        scanf("%d", &numActors);
        for (int j = 0; j < numActors; j++) {
            printf("Enter the name of actor %d in movie %d: ", j+1, i+1);
            scanf("%s", movies[i].actors[j]);
        }

        int numGenres;
        printf("Enter the number of genres for movie %d: ", i+1);
        scanf("%d", &numGenres);
        for (int j = 0; j < numGenres; j++) {
            printf("Enter the genre of movie %d: ", i+1);
            scanf("%s", movies[i].genres[j]);
        }

        printf("Enter the rating for movie %d (1 to 5): ", i+1);
        scanf("%d", &movies[i].rating);

        printf("Enter your review of movie %d (up to %d characters): ", i+1, MAX_REVIEW_LENGTH);
        fgets(movies[i].review, MAX_REVIEW_LENGTH, stdin);
    }

    printf("\nMovie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: ");
        for (int j = 0; j < MAX_ACTORS && movies[i].actors[j][0]!= '\0'; j++) {
            printf("%s ", movies[i].actors[j]);
        }
        printf("\n");
        printf("Genres: ");
        for (int j = 0; j < MAX_GENRES && movies[i].genres[j][0]!= '\0'; j++) {
            printf("%s ", movies[i].genres[j]);
        }
        printf("\n");
        printf("Rating: %d\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}