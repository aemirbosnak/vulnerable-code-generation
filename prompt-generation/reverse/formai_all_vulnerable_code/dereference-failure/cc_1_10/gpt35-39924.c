//FormAI DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 1000 // maximum number of movies in the database
#define TITLE_LEN 50 // maximum length of movie title
#define MAX_STARS 5 // maximum number of stars a movie can receive
#define MAX_REVIEWS 20 // maximum number of reviews a movie can receive
#define MAX_REVIEW_LEN 100 // maximum length of a movie review

// structure for storing movie information
struct movie {
    char title[TITLE_LEN];
    int num_reviews;
    char reviews[MAX_REVIEWS][MAX_REVIEW_LEN];
    double rating;
};

// function prototypes
void add_movie(struct movie movies[], int *num_movies);
void show_movies(struct movie movies[], int num_movies);
void add_review(struct movie movies[], int num_movies);
void show_reviews(struct movie movies[], int num_movies);

int main() {
    // array to store movie information
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;

    // welcome message
    printf("Welcome to the Unique C Movie Rating System!\n\n");

    // main menu loop
    while (1) {
        int choice;
        printf("Please choose an option:\n");
        printf("1. Add a new movie\n");
        printf("2. Show movie list\n");
        printf("3. Add a new review\n");
        printf("4. Show movie reviews\n");
        printf("5. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(movies, &num_movies);
                break;
            case 2:
                show_movies(movies, num_movies);
                break;
            case 3:
                add_review(movies, num_movies);
                break;
            case 4:
                show_reviews(movies, num_movies);
                break;
            case 5:
                printf("Thank you for using the Unique C Movie Rating System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }
}

// function to add a movie to the database
void add_movie(struct movie movies[], int *num_movies) {
    // check if maximum number of movies has been reached
    if (*num_movies == MAX_MOVIES) {
        printf("The database is full. Cannot add any more movies.\n");
        return;
    }

    // get input from user
    printf("Please enter the title of the movie (up to %d characters):\n> ", TITLE_LEN - 1);
    fflush(stdin);
    fgets(movies[*num_movies].title, TITLE_LEN, stdin);
    movies[*num_movies].title[strlen(movies[*num_movies].title) - 1] = '\0';

    // initialize movie information
    movies[*num_movies].num_reviews = 0;
    movies[*num_movies].rating = 0.0;

    // increment number of movies in the database
    (*num_movies)++;

    printf("Movie added successfully.\n");
}

// function to show list of movies in the database
void show_movies(struct movie movies[], int num_movies) {
    // check if there are any movies in the database
    if (num_movies == 0) {
        printf("There are no movies in the database.\n");
        return;
    }

    // print list of movies
    printf("Movie List:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s\n", i + 1, movies[i].title);
    }
}

// function to add a review to a movie
void add_review(struct movie movies[], int num_movies) {
    // check if there are any movies in the database
    if (num_movies == 0) {
        printf("There are no movies in the database.\n");
        return;
    }

    int choice;
    // prompt user to select a movie
    printf("Please select a movie to review:\n");
    show_movies(movies, num_movies);
    printf("> ");
    scanf("%d", &choice);

    // check if choice is valid
    if (choice < 1 || choice > num_movies) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // get input from user
    printf("Please enter your review of the movie (up to %d characters):\n> ", MAX_REVIEW_LEN - 1);
    fflush(stdin);
    fgets(movies[choice - 1].reviews[movies[choice - 1].num_reviews], MAX_REVIEW_LEN, stdin);
    movies[choice - 1].reviews[movies[choice - 1].num_reviews][strlen(movies[choice - 1].reviews[movies[choice - 1].num_reviews]) - 1] = '\0';

    // add rating to movie
    int stars;
    printf("Please enter your rating (1-5 stars):\n> ");
    scanf("%d", &stars);
    if (stars < 1 || stars > MAX_STARS) {
        printf("Invalid rating. Please try again.\n");
        return;
    }
    movies[choice - 1].rating = (movies[choice - 1].rating * movies[choice - 1].num_reviews + stars) / (double) (movies[choice - 1].num_reviews + 1);

    // increment number of reviews for movie
    movies[choice - 1].num_reviews++;

    printf("Review added successfully.\n");
}

// function to show reviews of a movie
void show_reviews(struct movie movies[], int num_movies) {
    // check if there are any movies in the database
    if (num_movies == 0) {
        printf("There are no movies in the database.\n");
        return;
    }

    int choice;
    // prompt user to select a movie
    printf("Please select a movie to view reviews:\n");
    show_movies(movies, num_movies);
    printf("> ");
    scanf("%d", &choice);

    // check if choice is valid
    if (choice < 1 || choice > num_movies) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // print list of reviews for the movie
    printf("Reviews for '%s' (average rating: %.2f):\n", movies[choice - 1].title, movies[choice - 1].rating);
    for (int i = 0; i < movies[choice - 1].num_reviews; i++) {
        printf("%d. %s\n", i + 1, movies[choice - 1].reviews[i]);
    }
}