//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the rating system
#define RATING_MAX 10
#define RATING_MIN 0

// Define the movie genres
#define GENRE_ACTION 1
#define GENRE_COMEDY 2
#define GENRE_DRAMA 3
#define GENRE_HORROR 4
#define GENRE_ROMANCE 5
#define GENRE_SCI_FI 6
#define GENRE_THRILLER 7
#define GENRE_WESTERN 8

// Define the movie structure
typedef struct movie {
    char title[100];
    int year;
    int genre;
    float rating;
} movie;

// Define the user structure
typedef struct user {
    char name[100];
    int age;
    int gender;
    int favoriteGenre;
} user;

// Define the function to generate a random movie
movie generateMovie() {
    movie m;
    
    // Generate a random title
    strcpy(m.title, "Movie Title ");
    char title[10];
    for (int i = 0; i < 10; i++) {
        title[i] = 'a' + rand() % 26;
    }
    strcat(m.title, title);
    
    // Generate a random year
    m.year = 1900 + rand() % 100;
    
    // Generate a random genre
    m.genre = rand() % 8 + 1;
    
    // Generate a random rating
    m.rating = RATING_MIN + (float)(rand() % (RATING_MAX - RATING_MIN + 1)) / 10;
    
    return m;
}

// Define the function to generate a random user
user generateUser() {
    user u;
    
    // Generate a random name
    strcpy(u.name, "User Name ");
    char name[10];
    for (int i = 0; i < 10; i++) {
        name[i] = 'a' + rand() % 26;
    }
    strcat(u.name, name);
    
    // Generate a random age
    u.age = 18 + rand() % 65;
    
    // Generate a random gender
    u.gender = rand() % 2 + 1;
    
    // Generate a random favorite genre
    u.favoriteGenre = rand() % 8 + 1;
    
    return u;
}

// Define the main function
int main() {
    // Set the random seed
    srand(time(NULL));
    
    // Generate a random movie
    movie m = generateMovie();
    
    // Generate a random user
    user u = generateUser();
    
    // Print the movie and user information
    printf("Movie Title: %s\n", m.title);
    printf("Movie Year: %d\n", m.year);
    printf("Movie Genre: ");
    switch (m.genre) {
        case GENRE_ACTION: printf("Action\n"); break;
        case GENRE_COMEDY: printf("Comedy\n"); break;
        case GENRE_DRAMA: printf("Drama\n"); break;
        case GENRE_HORROR: printf("Horror\n"); break;
        case GENRE_ROMANCE: printf("Romance\n"); break;
        case GENRE_SCI_FI: printf("Sci-Fi\n"); break;
        case GENRE_THRILLER: printf("Thriller\n"); break;
        case GENRE_WESTERN: printf("Western\n"); break;
    }
    printf("Movie Rating: %.1f\n", m.rating);
    
    printf("\nUser Name: %s\n", u.name);
    printf("User Age: %d\n", u.age);
    printf("User Gender: ");
    switch (u.gender) {
        case 1: printf("Male\n"); break;
        case 2: printf("Female\n"); break;
    }
    printf("User Favorite Genre: ");
    switch (u.favoriteGenre) {
        case GENRE_ACTION: printf("Action\n"); break;
        case GENRE_COMEDY: printf("Comedy\n"); break;
        case GENRE_DRAMA: printf("Drama\n"); break;
        case GENRE_HORROR: printf("Horror\n"); break;
        case GENRE_ROMANCE: printf("Romance\n"); break;
        case GENRE_SCI_FI: printf("Sci-Fi\n"); break;
        case GENRE_THRILLER: printf("Thriller\n"); break;
        case GENRE_WESTERN: printf("Western\n"); break;
    }
    
    return 0;
}