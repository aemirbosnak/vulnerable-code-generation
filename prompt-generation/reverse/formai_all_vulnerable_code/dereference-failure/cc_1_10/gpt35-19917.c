//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Struct for movie rating
typedef struct 
{
    char title[50];
    float rating;
} Movie;

// Function to add movie rating
void addRating(Movie *movies, int size)
{
    char title[50];
    float rating;
    printf("Enter the title of the movie: ");
    scanf("%s", title);
    printf("Enter the movie rating (out of 10): ");
    scanf("%f", &rating);

    // Add the rating to the selected movie
    for (int i = 0; i < size; i++) 
    {
        // Check if the title of the movie matches.
        if (strcmp(movies[i].title, title) == 0)
        {
            movies[i].rating += rating;
            printf("\n%s has been rated %.2f out of 10\n", title, movies[i].rating);
            return;
        }
    }
    // If the movie was not found, alert the user.
    printf("\n%s was not found. Please add the movie before rating.\n", title);
}

// Function to add a new movie to the system.
void addMovie(Movie *movies, int size)
{
    char title[50];
    float rating;
    printf("Enter the title of the movie: ");
    scanf("%s", title);
    printf("Enter the initial movie rating (out of 10): ");
    scanf("%f", &rating);

    // Create and append the new movie to the array.
    Movie newMovie;
    strcpy(newMovie.title, title);
    newMovie.rating = rating;
    movies[size] = newMovie;
    printf("\n%s with a rating of %.2f out of 10 has been added.\n", title, rating);
}

// The main menu display function.
void displayMenu()
{
    printf("Please select an option:\n");
    printf("1. Add a movie\n");
    printf("2. Add a movie rating\n");
    printf("3. Exit\n");
}

int main()
{
    int choice;
    int size = 0;
    Movie *movies = malloc(sizeof(Movie) * 100);

    // Run the program until the user exits.
    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (size < 100) 
                {
                    addMovie(movies, size);
                    size++;
                } 
                else 
                {
                    printf("\nThe movie database is full! Cannot add more movies.\n");
                }
                break;
            case 2:
                if (size > 0) 
                {
                    addRating(movies, size);
                } 
                else 
                {
                    printf("\nThere are no movies in the database! Add a movie before rating.\n");
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 3);

    free(movies);

    return 0;
}