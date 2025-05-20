//FormAI DATASET v1.0 Category: Database querying ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about a movie
typedef struct {
    char title[50];
    char director[50];
    int year;
    double rating;
} Movie;

int main() {
    // Open the database file for reading
    FILE *db = fopen("movies.db", "r");
    if (db == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    // Count the number of movies in the database
    int num_movies = 0;
    char ch;
    while ((ch = fgetc(db)) != EOF) { // Read each character in the file
        if (ch == '\n') { // Each line represents one movie
            num_movies++;
        }
    }
    rewind(db);

    // Allocate memory for an array of Movie structs
    Movie *movies = malloc(num_movies * sizeof(Movie));
    if (movies == NULL) {
        printf("Error allocating memory for movies array.\n");
        return 1;
    }

    // Read in each movie from the database file and store it in the array
    int i = 0;
    while (!feof(db)) {
        fscanf(db, "%[^,],%[^,],%d,%lf\n", movies[i].title, movies[i].director, &movies[i].year, &movies[i].rating);
        i++;
    }

    // Close the database file
    fclose(db);

    // Print out all the movies in the database
    for (int j = 0; j < num_movies; j++) {
        printf("Movie %d:\n", j+1);
        printf("Title: %s\n", movies[j].title);
        printf("Director: %s\n", movies[j].director);
        printf("Year: %d\n", movies[j].year);
        printf("Rating: %.2lf\n\n", movies[j].rating);
    }

    // Search for a specific movie by title
    char search_title[50];
    printf("Enter the title of the movie to search for: ");
    scanf("%s", search_title);

    for (int k = 0; k < num_movies; k++) {
        if (strcmp(movies[k].title, search_title) == 0) { // If the titles match
            printf("Movie found!\n");
            printf("Title: %s\n", movies[k].title);
            printf("Director: %s\n", movies[k].director);
            printf("Year: %d\n", movies[k].year);
            printf("Rating: %.2lf\n", movies[k].rating);
            break; // Exit the loop
        }
    }

    // Free the memory allocated for the array of movies
    free(movies);
    
    return 0;
}