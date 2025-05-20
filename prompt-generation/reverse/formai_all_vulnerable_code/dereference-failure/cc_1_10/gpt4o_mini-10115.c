//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
} Movie;

typedef struct {
    Movie *movies;
    int count;
    int capacity;
} MovieCollection;

void initializeCollection(MovieCollection *collection) {
    collection->count = 0;
    collection->capacity = 2; // Start with a small capacity
    collection->movies = (Movie *)malloc(collection->capacity * sizeof(Movie));
}

void resizeCollection(MovieCollection *collection) {
    collection->capacity *= 2; // Double the capacity
    collection->movies = (Movie *)realloc(collection->movies, collection->capacity * sizeof(Movie));
}

void addMovie(MovieCollection *collection, const char *title, float rating) {
    if (collection->count >= collection->capacity) {
        resizeCollection(collection);
    }
    strcpy(collection->movies[collection->count].title, title);
    collection->movies[collection->count].rating = rating;
    collection->count++;
}

void displayMovies(const MovieCollection *collection) {
    if (collection->count == 0) {
        printf("No movies rated yet!\n");
        return;
    }
    printf("\nMovie Collection:\n");
    for (int i = 0; i < collection->count; i++) {
        printf("%d. %s - Rating: %.1f\n", i + 1, collection->movies[i].title, collection->movies[i].rating);
    }
}

void freeCollection(MovieCollection *collection) {
    free(collection->movies);
    collection->movies = NULL;
}

int main() {
    MovieCollection collection;
    initializeCollection(&collection);
    
    int choice;
    char title[100];
    float rating;

    do {
        printf("\n--- Movie Rating System ---\n");
        printf("1. Add Movie\n");
        printf("2. Display Movies\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline after scanf

        switch (choice) {
        case 1:
            printf("Enter movie title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // Remove the newline character
            printf("Enter rating (0.0 to 5.0): ");
            scanf("%f", &rating);
            if (rating < 0.0 || rating > 5.0) {
                printf("Rating must be between 0.0 and 5.0. Please try again.\n");
                break;
            }
            addMovie(&collection, title, rating);
            printf("Movie added successfully!\n");
            break;

        case 2:
            displayMovies(&collection);
            break;

        case 3:
            printf("Exiting...\n");
            freeCollection(&collection);
            break;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    } while (choice != 3);

    return 0;
}