//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

const unsigned int MAX_MOVIES = 100;

struct movie {
    char *title;
    int rating;
    int year;
    int is_watched;
};

struct movie_node {
    struct movie movie;
    struct movie_node *next;
};

struct movie_list {
    struct movie_node *head;
    int size;
};

void add_movie(struct movie_list *list, const char *title, int rating, int year, int is_watched) {
    struct movie_node *new_node = malloc(sizeof(struct movie_node));
    if (new_node == NULL) {
        fprintf(stderr, "Error allocating memory for new movie node.\n");
        exit(1);
    }

    new_node->movie.title = strdup(title);
    new_node->movie.rating = rating;
    new_node->movie.year = year;
    new_node->movie.is_watched = is_watched;

    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void print_movies(const struct movie_list *list) {
    struct movie_node *node = list->head;
    while (node != NULL) {
        printf("%s (%d, %d) %s\n", node->movie.title, node->movie.rating, node->movie.year, node->movie.is_watched ? "watched" : "unwatched");
        node = node->next;
    }
}

void free_movies(struct movie_list *list) {
    struct movie_node *node = list->head;
    while (node != NULL) {
        struct movie_node *next = node->next;
        free(node->movie.title);
        free(node);
        node = next;
    }

    list->head = NULL;
    list->size = 0;
}

int main() {
    struct movie_list movies;
    movies.head = NULL;
    movies.size = 0;

    add_movie(&movies, "The Matrix", 9, 1999, 1);
    add_movie(&movies, "Blade Runner", 8, 1982, 1);
    add_movie(&movies, "Akira", 8, 1988, 0);
    add_movie(&movies, "Ghost in the Shell", 8, 1995, 0);
    add_movie(&movies, "Neon Genesis Evangelion", 8, 1995, 0);

    print_movies(&movies);

    free_movies(&movies);

    return 0;
}