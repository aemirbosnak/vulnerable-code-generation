//FormAI DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_TITLE_LENGTH 50

/* Structure for holding movie data */
typedef struct {
    char title[MAX_TITLE_LENGTH];
    int rating;
} movie_t;

/* Function prototypes */
void print_menu();
void add_movie(movie_t movies[], int *num_movies);
void view_movies(movie_t movies[], int num_movies);
void rate_movie(movie_t movies[], int num_movies);
void save_movies(movie_t movies[], int num_movies);
void load_movies(movie_t movies[], int *num_movies);

/* Main function */
int main() {
    
    movie_t movies[MAX_MOVIES];  // array to hold movies
    int num_movies = 0;  // keeps track of number of movies in array
    int option;

    load_movies(movies, &num_movies);  // load movies from file

    do {
        print_menu();  // print the menu
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_movie(movies, &num_movies);  // add a new movie
                break;
            case 2:
                view_movies(movies, num_movies);  // view the list of movies
                break;
            case 3:
                rate_movie(movies, num_movies);  // rate a movie
                break;
            case 4:
                save_movies(movies, num_movies);  // save the movies to file
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 5);

    return 0;
}

/* Function to print the menu */
void print_menu() {
    printf("Welcome to the C Movie Rating System!\n");
    printf("1. Add a Movie\n");
    printf("2. View Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Save Movies\n");
    printf("5. Exit\n");
    printf("Enter your selection: ");
}

/* Function to add a movie to the array */
void add_movie(movie_t movies[], int *num_movies) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie: ");
    getchar();  // clear the input buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);

    // remove newline character from end of title string
    title[strlen(title)-1] = '\0';  

    strcpy(movies[*num_movies].title, title);
    movies[*num_movies].rating = -1;  // set initial rating to -1
    (*num_movies)++;
    printf("Movie added successfully.\n");
}

/* Function to view the list of movies */
void view_movies(movie_t movies[], int num_movies) {
    if (num_movies == 0) {
        printf("There are no movies in the list.\n");
        return;
    }
    printf("Title\t\t\t\tRating\n");
    for (int i=0; i<num_movies; i++) {
        printf("%s", movies[i].title);
        for (int j=0; j<MAX_TITLE_LENGTH-strlen(movies[i].title); j++) {
            printf(" ");
        }
        if (movies[i].rating == -1) {
            printf("Not Rated\n");
        } else {
            printf("%d\n", movies[i].rating);
        }
    }
}

/* Function to rate a movie */
void rate_movie(movie_t movies[], int num_movies) {
    if (num_movies == 0) {
        printf("There are no movies in the list.\n");
        return;
    }
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the movie you want to rate: ");
    getchar();  // clear the input buffer
    fgets(title, MAX_TITLE_LENGTH, stdin);

    // remove newline character from end of title string
    title[strlen(title)-1] = '\0';  

    int found = 0;
    for (int i=0; i<num_movies; i++) {
        if (strcmp(title, movies[i].title) == 0) {
            printf("Enter your rating (0-10): ");
            scanf("%d", &movies[i].rating);
            printf("Rating saved successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie not found.\n");
    }
}

/* Function to save the movies to a file */
void save_movies(movie_t movies[], int num_movies) {
    FILE *fp;
    fp = fopen("movies.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i=0; i<num_movies; i++) {
        fprintf(fp, "%s,%d\n", movies[i].title, movies[i].rating);
    }

    fclose(fp);
    printf("Movies saved to file.\n");
}

/* Function to load the movies from a file */
void load_movies(movie_t movies[], int *num_movies) {
    FILE *fp;
    fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        return;
    }

    char line[MAX_TITLE_LENGTH + 5];
    while (fgets(line, MAX_TITLE_LENGTH + 5, fp) != NULL) {
        char *token = strtok(line, ",");
        strcpy(movies[*num_movies].title, token);
        token = strtok(NULL, ",");
        movies[*num_movies].rating = atoi(token);
        (*num_movies)++;
    }

    fclose(fp);
}