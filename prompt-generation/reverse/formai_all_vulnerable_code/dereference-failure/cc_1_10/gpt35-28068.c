//FormAI DATASET v1.0 Category: Movie Rating System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold movie details
typedef struct {
    char name[50];
    char genre[20];
    float rating;
} Movie;

//Function to add a new movie to the database
void add_movie(Movie *database, int *count) {
    printf("\nEnter the movie name: ");
    scanf(" %[^\n]", database[*count].name);

    printf("Enter the genre: ");
    scanf(" %[^\n]", database[*count].genre);

    printf("Enter the rating (0.0 to 10.0): ");
    scanf("%f", &database[*count].rating);

    (*count)++;
}

//Function to display all the movies in the database
void display_movies(Movie *database, int count) {
    if(count==0) {
        printf("\nNo movies in the database!\n");
        return;
    }
    printf("\nMovies in the database: \n");
    for(int i=0;i<count;i++) {
        printf("\n%d. %s\n", i+1, database[i].name);
        printf("Genre: %s\n", database[i].genre);
        printf("Rating: %.1f\n", database[i].rating);
    }
}

//Function to search movie by genre
void search_genre(Movie *database, int count, char *genre) {
    printf("\nSearch results for %s movies: \n", genre);
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strcmp(database[i].genre, genre)==0) {
            printf("\n%d. %s\n", found+1, database[i].name);
            printf("Genre: %s\n", database[i].genre);
            printf("Rating: %.1f\n", database[i].rating);
            found = 1;
        }
    }
    if(found==0) {
        printf("\nNo %s movies found!\n", genre);
    }
}

//Function to search movie by name
void search_name(Movie *database, int count, char *name) {
    printf("\nSearch results for '%s': \n", name);
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strstr(database[i].name, name)!=NULL) {
            printf("\n%d. %s\n", found+1, database[i].name);
            printf("Genre: %s\n", database[i].genre);
            printf("Rating: %.1f\n", database[i].rating);
            found = 1;
        }
    }
    if(found==0) {
        printf("\nNo movies found with '%s' in their name!\n", name);
    }
}

//Function to rate a movie
void rate_movie(Movie *database, int count, char *name) {
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strcmp(database[i].name, name)==0) {
            printf("\nEnter a rating (0.0 to 10.0) for %s: ", name);
            scanf("%f", &database[i].rating);
            printf("\nRating updated!\n");
            found = 1;
            break;
        }
    }
    if(found==0) {
        printf("\nMovie not found!\n");
    }
}

int main() {
    Movie *database = malloc(sizeof(Movie)*100);
    int count = 0;
    char option, name[50], genre[20];

    while(1) {
        printf("\n\nC Movie Rating System\n");
        printf("------------------------\n");
        printf("1. Add a new movie\n");
        printf("2. Display all the movies\n");
        printf("3. Search movies by genre\n");
        printf("4. Search movies by name\n");
        printf("5. Rate a movie\n");
        printf("6. Exit\n");
        printf("------------------------\n");
        printf("Enter your option: ");

        scanf(" %c", &option);

        switch(option) {
            case '1':
                add_movie(database, &count);
                break;
            case '2':
                display_movies(database, count);
                break;
            case '3':
                printf("\nEnter the genre to search: ");
                scanf(" %[^\n]", genre);
                search_genre(database, count, genre);
                break;
            case '4':
                printf("\nEnter the name to search: ");
                scanf(" %[^\n]", name);
                search_name(database, count, name);
                break;
            case '5':
                printf("\nEnter the name of the movie to rate: ");
                scanf(" %[^\n]", name);
                rate_movie(database, count, name);
                break;
            case '6':
                printf("\nThank you for using C Movie Rating System!\n");
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    }
    return 0;
}