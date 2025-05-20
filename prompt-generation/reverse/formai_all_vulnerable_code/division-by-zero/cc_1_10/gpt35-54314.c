//FormAI DATASET v1.0 Category: Movie Rating System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_MOVIES 1000
#define MAX_REVIEWS 100000
#define MAX_USERS 100000

typedef struct {
    char title[100];
    char director[100];
    int year;
    float avg_rating;
    int num_ratings;
} movie_t;

typedef struct {
    int user_id, movie_id;
    float rating;
} review_t;

movie_t movies[MAX_MOVIES];
review_t reviews[MAX_REVIEWS];
int num_movies = 0, num_reviews = 0, num_users = 0;

void add_movie(char *title, char *director, int year) {
    // add a new movie to the database
    strcpy(movies[num_movies].title, title);
    strcpy(movies[num_movies].director, director);
    movies[num_movies].year = year;
    movies[num_movies].avg_rating = 0;
    movies[num_movies].num_ratings = 0;
    num_movies++;
}

void add_review(int user_id, int movie_id, float rating) {
    // add a new review to the database
    reviews[num_reviews].user_id = user_id;
    reviews[num_reviews].movie_id = movie_id;
    reviews[num_reviews].rating = rating;
    num_reviews++;
}

void update_movie_rating(int movie_id) {
    // update the average rating of a movie
    float total_rating = 0;
    int num_ratings = 0;
    for (int i = 0; i < num_reviews; i++) {
        if (reviews[i].movie_id == movie_id) {
            total_rating += reviews[i].rating;
            num_ratings++;
        }
    }
    if (num_ratings > 0) {
        movies[movie_id].avg_rating = total_rating / num_ratings;
        movies[movie_id].num_ratings = num_ratings;
    }
}

void print_movie_rating(int movie_id) {
    // print the rating of a movie
    printf("%s (dir. %s, %d) - ", movies[movie_id].title, movies[movie_id].director, movies[movie_id].year);
    if (movies[movie_id].num_ratings == 0) {
        printf("No ratings.");
    } else {
        printf("%.1f (%d ratings)", movies[movie_id].avg_rating, movies[movie_id].num_ratings);
    }
    printf("\n");
}

void *add_movies(void *arg) {
    // thread function to add movies to the database
    char *movies[] = {
        "The Shawshank Redemption", "The Godfather", "The Godfather: Part II", "The Dark Knight", 
        "12 Angry Men", "Schindler's List", "The Lord of the Rings: The Return of the King", 
        "Pulp Fiction", "The Good, the Bad and the Ugly", "Fight Club", "Forrest Gump", 
        "Inception", "The Lord of the Rings: The Fellowship of the Ring", "Star Wars: Episode V - The Empire Strikes Back",
        "The Lord of the Rings: The Two Towers", "The Matrix", "Goodfellas", "One Flew Over the Cuckoo's Nest",
        "Seven Samurai", "Se7en", "The Silence of the Lambs", "It's a Wonderful Life", "Life is Beautiful",
        "The Prestige", "Alien", "The Lion King", "Back to the Future", "Terminator 2: Judgment Day",
        "Saving Private Ryan", "The Departed", "Whiplash", "The Intouchables", NULL
    };
    char *directors[] = {
        "Frank Darabont", "Francis Ford Coppola", "Francis Ford Coppola", "Christopher Nolan", 
        "Sidney Lumet", "Steven Spielberg", "Peter Jackson", 
        "Quentin Tarantino", "Sergio Leone", "David Fincher", "Robert Zemeckis", 
        "Christopher Nolan", "Peter Jackson", "Irvin Kershner",
        "Peter Jackson", "Lana Wachowski", "Martin Scorsese", "Milos Forman",
        "Akira Kurosawa", "David Fincher", "Jonathan Demme", "Frank Capra", "Roberto Benigni",
        "Christopher Nolan", "Ridley Scott", "Roger Allers", "Robert Zemeckis", "James Cameron",
        "Steven Spielberg", "Martin Scorsese", "Damien Chazelle", "Olivier Nakache and Eric Toledano", NULL
    };
    int years[] = {
        1994, 1972, 1974, 2008, 
        1957, 1993, 2003, 
        1994, 1966, 1999, 1994, 
        2010, 2001, 1980,
        2002, 1999, 1995, 1975,
        1954, 1995, 1991, 1946, 1997,
        2006, 1979, 1994, 1985, 1991,
        1998, 2006, 2014, 2011, 0
    };
    int i = 0;
    while (movies[i] != NULL) {
        add_movie(movies[i], directors[i], years[i]);
        i++;
        usleep(rand() % 1000000);
    }
    return NULL;
}

void *add_reviews(void *arg) {
    // thread function to add reviews to the database
    int num_users = *(int*)arg;
    for (int i = 0; i < num_users; i++) {
        int movie_id = rand() % num_movies;
        float rating = (rand() % 50) / 10.0;
        add_review(i, movie_id, rating);
        update_movie_rating(movie_id);
        usleep(rand() % 1000000);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    pthread_t add_movies_thread, add_reviews_thread;
    int num_users = 10000;

    // start the thread to add movies
    pthread_create(&add_movies_thread, NULL, add_movies, NULL);

    // start the thread to add reviews
    pthread_create(&add_reviews_thread, NULL, add_reviews, &num_users);

    // wait for both threads to finish
    pthread_join(add_movies_thread, NULL);
    pthread_join(add_reviews_thread, NULL);

    // print the ratings of all movies
    for (int i = 0; i < num_movies; i++) {
        print_movie_rating(i);
    }
    return 0;
}