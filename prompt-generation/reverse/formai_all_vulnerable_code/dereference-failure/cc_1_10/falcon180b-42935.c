//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove leading/trailing whitespaces from a string
char* trim(char* str) {
    char* end;
    // Trim leading spaces
    while(isspace(*str)) str++;
    // Trim trailing spaces
    if((end = strchr(str, '\0'))!= NULL) {
        while(end > str && isspace(*(end - 1))) end--;
        *end = '\0';
    }
    return str;
}

// Function to read a line from the input file
char* read_line(FILE* fp) {
    char line[1024];
    fgets(line, sizeof(line), fp);
    return trim(strdup(line));
}

// Function to parse the movie rating from the input file
int parse_rating(char* line) {
    int rating = 0;
    sscanf(line, "%d", &rating);
    return rating;
}

// Function to print the list of movies and their ratings
void print_movies(char** movies, int* ratings, int num_movies) {
    printf("List of movies:\n");
    for(int i = 0; i < num_movies; i++) {
        printf("%s - Rating: %d\n", movies[i], ratings[i]);
    }
}

// Function to sort the list of movies by their ratings in descending order
void sort_movies(char** movies, int* ratings, int num_movies) {
    for(int i = 0; i < num_movies - 1; i++) {
        for(int j = i + 1; j < num_movies; j++) {
            if(ratings[j] > ratings[i]) {
                // Swap movies and ratings
                char* temp_movie = movies[i];
                movies[i] = movies[j];
                movies[j] = temp_movie;
                int temp_rating = ratings[i];
                ratings[i] = ratings[j];
                ratings[j] = temp_rating;
            }
        }
    }
}

int main() {
    FILE* fp;
    char line[1024];
    char* filename = "movies.txt";

    // Open the input file
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the list of movies and their ratings from the input file
    int num_movies = 0;
    char** movies = NULL;
    int* ratings = NULL;
    while(fgets(line, sizeof(line), fp)!= NULL) {
        char* movie = read_line(fp);
        int rating = parse_rating(movie);
        movies = realloc(movies, sizeof(char*) * ++num_movies);
        ratings = realloc(ratings, sizeof(int) * num_movies);
        movies[num_movies - 1] = movie;
        ratings[num_movies - 1] = rating;
    }

    // Sort the list of movies by their ratings in descending order
    sort_movies(movies, ratings, num_movies);

    // Print the list of movies and their ratings
    print_movies(movies, ratings, num_movies);

    // Free memory
    for(int i = 0; i < num_movies; i++) {
        free(movies[i]);
    }
    free(movies);
    free(ratings);

    // Close the input file
    fclose(fp);
    return 0;
}