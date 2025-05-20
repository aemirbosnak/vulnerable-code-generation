//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor1[MAX_ACTOR_LENGTH];
    char actor2[MAX_ACTOR_LENGTH];
    char actor3[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main(void) {
    int numMovies;
    scanf("%d", &numMovies);

    Movie movies[numMovies];

    for (int i = 0; i < numMovies; i++) {
        printf("Enter movie title: ");
        scanf("%s", movies[i].title);

        printf("Enter director: ");
        scanf("%s", movies[i].director);

        printf("Enter actor 1: ");
        scanf("%s", movies[i].actor1);

        printf("Enter actor 2: ");
        scanf("%s", movies[i].actor2);

        printf("Enter actor 3: ");
        scanf("%s", movies[i].actor3);

        printf("Enter genre: ");
        scanf("%s", movies[i].genre);

        printf("Enter rating (0-5): ");
        scanf("%d", &movies[i].rating);

        printf("Enter review: ");
        fgets(movies[i].review, MAX_REVIEW_LENGTH, stdin);
    }

    return 0;
}