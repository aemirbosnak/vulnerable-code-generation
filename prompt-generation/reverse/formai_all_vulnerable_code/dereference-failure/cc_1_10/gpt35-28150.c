//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent a movie */
struct movie {
    char title[100];
    int year;
    char director[100];
    int rating;
};

/* Function to prompt the user for a movie and return a movie struct */
struct movie get_movie() {
    struct movie m;
    printf("Enter movie title: ");
    scanf("%s", m.title);
    printf("Enter movie year: ");
    scanf("%d", &m.year);
    printf("Enter movie director: ");
    scanf("%s", m.director);
    printf("Enter movie rating (1-10): ");
    scanf("%d", &m.rating);
    return m;
}

/* Function to print a movie */
void print_movie(struct movie m) {
    printf("%s (%d) - Directed by %s - Rated %d/10\n", m.title, m.year, m.director, m.rating);
}

/* Define a rating system struct to represent the collection of movies and metadata */
struct rating_system {
    char name[100];
    struct movie* movies;
    int movie_count;
    int total_rating;
    float average_rating;
};

/* Function to initialize a new rating system */
struct rating_system init_rating_system(char* name) {
    struct rating_system r;
    r.movies = NULL;
    r.movie_count = 0;
    r.total_rating = 0;
    r.average_rating = 0;
    sprintf(r.name, "%s", name);
    return r;
}

/* Function to add a movie to a rating system */
void add_movie(struct rating_system* r, struct movie m) {
    /* increase the size of the movies array */
    if (r->movies == NULL) {
        r->movies = (struct movie*) malloc(sizeof(struct movie));
    } else {
        r->movies = (struct movie*) realloc(r->movies, (r->movie_count + 1) * sizeof(struct movie));
    }
    /* add the new movie */
    r->movies[r->movie_count] = m;
    r->movie_count++;
    /* update the total rating and average rating */
    r->total_rating += m.rating;
    r->average_rating = (float) r->total_rating / r->movie_count;
}

/* Function to remove a movie from a rating system */
void remove_movie(struct rating_system* r, int index) {
    /* remove the movie */
    for (int i = index; i < r->movie_count - 1; i++) {
        r->movies[i] = r->movies[i+1];
    }
    r->movie_count--;
    /* update the total rating and average rating */
    r->total_rating -= r->movies[index].rating;
    r->average_rating = (float) r->total_rating / r->movie_count;
}

/* Function to print all movies in a rating system */
void print_movies(struct rating_system r) {
    printf("%s\n", r.name);
    for (int i = 0; i < r.movie_count; i++) {
        print_movie(r.movies[i]);
    }
}

/* Main function to run the program */
int main() {
    /* Initialize a new rating system */
    struct rating_system my_rating_system = init_rating_system("My Movies");

    /* Add some sample movies */
    struct movie movie1 = {"The Shawshank Redemption", 1994, "Frank Darabont", 9};
    struct movie movie2 = {"The Godfather", 1972, "Francis Ford Coppola", 10};
    add_movie(&my_rating_system, movie1);
    add_movie(&my_rating_system, movie2);

    /* Print all movies */
    print_movies(my_rating_system);

    /* Add a new movie */
    struct movie new_movie = get_movie();
    add_movie(&my_rating_system, new_movie);

    /* Print all movies */
    print_movies(my_rating_system);

    /* Remove a movie */
    printf("Enter the index of the movie you want to remove: ");
    int index;
    scanf("%d", &index);
    remove_movie(&my_rating_system, index);

    /* Print all movies */
    print_movies(my_rating_system);

    /* Free memory */
    free(my_rating_system.movies);

    return 0;
}