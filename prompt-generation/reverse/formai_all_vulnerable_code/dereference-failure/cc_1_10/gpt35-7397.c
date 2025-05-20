//FormAI DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold movie information
struct movie {
    char title[50];
    char genre[20];
    int year;
    double rating;
};

// A function to read movie data from a file and store it in an array of structs
void readInputFile(struct movie *movies, int size, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open input file.\n");
        exit(1);
    }

    char line[100];
    int index = 0;
    while (fgets(line, sizeof(line), fp) != NULL && index < size) {
        char *token = strtok(line, ",");
        strcpy(movies[index].title, token);

        token = strtok(NULL, ",");
        strcpy(movies[index].genre, token);

        token = strtok(NULL, ",");
        movies[index].year = atoi(token);

        token = strtok(NULL, ",");
        movies[index].rating = atof(token);

        index++;
    }

    fclose(fp);
}

// A function to find the highest rated movie in an array of structs
struct movie findHighestRatedMovie(struct movie *movies, int size) {
    struct movie highestRated = movies[0];
    for (int i = 1; i < size; i++) {
        if (movies[i].rating > highestRated.rating) {
            highestRated = movies[i];
        }
    }
    return highestRated;
}

// A function to find all movies in an array of structs that have a certain genre
void findMoviesByGenre(struct movie *movies, int size, char *genre) {
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("%s (%d) - %s - %.2lf/10\n", movies[i].title, movies[i].year, movies[i].genre, movies[i].rating);
        }
    }
}

int main() {
    // Define the size of the movie array
    int size = 10;

    // Allocate memory for the movie array
    struct movie *movies = malloc(size * sizeof(struct movie));
    if (movies == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    // Read movie data from input file
    readInputFile(movies, size, "movies.txt");

    // Find the highest rated movie
    struct movie highestRated = findHighestRatedMovie(movies, size);
    printf("The highest rated movie is %s (%d) - %s - %.2lf/10\n", highestRated.title, highestRated.year, highestRated.genre, highestRated.rating);

    // Find all movies with the genre "action"
    printf("\nMovies with the genre 'action':\n");
    findMoviesByGenre(movies, size, "action");

    // Free memory used by the movie array
    free(movies);
    return 0;
}