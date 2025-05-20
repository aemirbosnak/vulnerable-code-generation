//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 100

typedef struct {
    char movie_name[50];
    int num_ratings;
    int total_rating;
} movie_t;

void read_movie_ratings(movie_t *movies, int num_movies) {
    int i;
    FILE *fp;
    char filename[50];

    for (i = 0; i < num_movies; i++) {
        sprintf(filename, "movie_%d.txt", i + 1);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: could not open file %s\n", filename);
            exit(1);
        }

        movies[i].num_ratings = 0;
        movies[i].total_rating = 0;

        while (fscanf(fp, "%s %d", movies[i].movie_name, &movies[i].total_rating) == 2) {
            movies[i].num_ratings++;
        }

        fclose(fp);
    }
}

void print_movie_ratings(movie_t *movies, int num_movies) {
    int i;

    for (i = 0; i < num_movies; i++) {
        printf("Movie %d: %s\n", i + 1, movies[i].movie_name);
        printf("  Total rating: %d\n", movies[i].total_rating);
        printf("  Number of ratings: %d\n\n", movies[i].num_ratings);
    }
}

int main(int argc, char *argv[]) {
    movie_t movies[MAX_RATINGS];
    int num_movies;

    if (argc!= 2) {
        printf("Usage: %s num_movies\n", argv[0]);
        exit(1);
    }

    num_movies = atoi(argv[1]);

    if (num_movies > MAX_RATINGS) {
        printf("Error: num_movies must be less than or equal to %d\n", MAX_RATINGS);
        exit(1);
    }

    read_movie_ratings(movies, num_movies);
    print_movie_ratings(movies, num_movies);

    return 0;
}