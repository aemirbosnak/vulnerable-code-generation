//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct movie {
    char title[100];
    char director[100];
    int year;
    char genre[50];
    int duration;
    float rating;
};

struct critic {
    char name[100];
    float bias;
    float consistency;
};

int main() {
    int num_movies, num_critics, num_ratings;
    scanf("%d %d %d", &num_movies, &num_critics, &num_ratings);

    struct movie movies[num_movies];
    struct critic critics[num_critics];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s %s %d %s %d", movies[i].title, movies[i].director, &movies[i].year, movies[i].genre, &movies[i].duration);
        movies[i].rating = 0;
    }

    for (int i = 0; i < num_critics; i++) {
        scanf("%s %f %f", critics[i].name, &critics[i].bias, &critics[i].consistency);
    }

    for (int i = 0; i < num_ratings; i++) {
        char critic_name[100];
        int movie_index;
        float rating;
        scanf("%s %d %f", critic_name, &movie_index, &rating);

        for (int j = 0; j < num_critics; j++) {
            if (strcmp(critic_name, critics[j].name) == 0) {
                movies[movie_index - 1].rating += rating * (1 + critics[j].bias);
                break;
            }
        }
    }

    for (int i = 0; i < num_movies; i++) {
        movies[i].rating /= num_critics;
        printf("%s (%d) - %.2f/10\n", movies[i].title, movies[i].year, movies[i].rating);
    }

    return 0;
}