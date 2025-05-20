//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 50
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_GENRE_LEN 50
#define MAX_RATING 5
#define MAX_RATING_LEN 10
#define MAX_REVIEW_LEN 200

typedef struct {
    char title[MAX_TITLE_LEN + 1];
    char director[MAX_DIRECTOR_LEN + 1];
    char actor[MAX_ACTOR_LEN + 1];
    char genre[MAX_GENRE_LEN + 1];
    char rating[MAX_RATING_LEN + 1];
    char review[MAX_REVIEW_LEN + 1];
} Movie;

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].actor);
        scanf("%s", movies[i].genre);
        scanf("%s", movies[i].rating);
        scanf("%s", movies[i].review);
    }

    int num_rated_movies = 0;
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].rating[0]!= '\0') {
            num_rated_movies++;
        }
    }

    if (num_rated_movies == 0) {
        printf("No movies rated.\n");
    } else {
        printf("Top rated movies:\n");
        for (int i = 0; i < num_movies; i++) {
            if (movies[i].rating[0]!= '\0') {
                printf("%s\n", movies[i].title);
            }
        }
    }

    return 0;
}