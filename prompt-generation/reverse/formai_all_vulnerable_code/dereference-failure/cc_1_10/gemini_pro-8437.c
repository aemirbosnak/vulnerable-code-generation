//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MIN_RATING 1
#define MAX_RATING 5

struct Movie {
    char *title;
    int rating;
};

struct MovieDatabase {
    struct Movie *movies;
    int num_movies;
};

struct MovieDatabase *create_movie_database() {
    struct MovieDatabase *database = malloc(sizeof(struct MovieDatabase));
    if (database == NULL) {
        return NULL;
    }

    database->movies = NULL;
    database->num_movies = 0;

    return database;
}

void destroy_movie_database(struct MovieDatabase *database) {
    if (database == NULL) {
        return;
    }

    for (int i = 0; i < database->num_movies; i++) {
        free(database->movies[i].title);
    }

    free(database->movies);
    free(database);
}

int add_movie(struct MovieDatabase *database, char *title, int rating) {
    if (database == NULL || title == NULL || rating < MIN_RATING || rating > MAX_RATING) {
        return -1;
    }

    struct Movie *new_movie = malloc(sizeof(struct Movie));
    if (new_movie == NULL) {
        return -1;
    }

    new_movie->title = strdup(title);
    if (new_movie->title == NULL) {
        free(new_movie);
        return -1;
    }

    new_movie->rating = rating;

    database->movies = realloc(database->movies, (database->num_movies + 1) * sizeof(struct Movie));
    if (database->movies == NULL) {
        free(new_movie->title);
        free(new_movie);
        return -1;
    }

    database->movies[database->num_movies] = *new_movie;
    database->num_movies++;

    return 0;
}

int get_movie_rating(struct MovieDatabase *database, char *title) {
    if (database == NULL || title == NULL) {
        return -1;
    }

    for (int i = 0; i < database->num_movies; i++) {
        if (strcmp(database->movies[i].title, title) == 0) {
            return database->movies[i].rating;
        }
    }

    return -1;
}

int main() {
    struct MovieDatabase *database = create_movie_database();
    if (database == NULL) {
        printf("Error creating movie database.\n");
        return EXIT_FAILURE;
    }

    int num_movies;
    printf("How many movies would you like to add? ");
    scanf("%d", &num_movies);

    for (int i = 0; i < num_movies; i++) {
        char title[100];
        int rating;
        printf("Enter the title of movie %d: ", i + 1);
        scanf(" %s", title);
        printf("Enter the rating of movie %d (1-5): ", i + 1);
        scanf(" %d", &rating);

        int result = add_movie(database, title, rating);
        if (result != 0) {
            printf("Error adding movie %s.\n", title);
        }
    }

    char movie_title[100];
    printf("Enter the title of the movie you want to get the rating for: ");
    scanf(" %s", movie_title);

    int rating = get_movie_rating(database, movie_title);
    if (rating == -1) {
        printf("Movie %s not found.\n", movie_title);
    } else {
        printf("The rating of movie %s is %d.\n", movie_title, rating);
    }

    destroy_movie_database(database);

    return EXIT_SUCCESS;
}