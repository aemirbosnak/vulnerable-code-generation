//GPT-4o-mini DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_RATINGS 5

// Structure to hold movie information
typedef struct Movie {
    char title[MAX_TITLE_LENGTH];
    int ratings[MAX_RATINGS];
    int ratingCount;
    struct Movie *next;
} Movie;

// Function prototypes
Movie* createMovie(const char* title);
void addMovie(Movie **head, const char* title);
void rateMovie(Movie *head, const char* title, int rating);
void displayMovies(Movie *head);
void freeMovies(Movie *head);

int main() {
    Movie *head = NULL;
    int choice, rating;
    char title[MAX_TITLE_LENGTH];

    while (1) {
        printf("\n=== Movie Rating System ===\n");
        printf("1. Add Movie\n");
        printf("2. Rate Movie\n");
        printf("3. Display Movies\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline from title
                addMovie(&head, title);
                break;

            case 2:
                printf("Enter movie title to rate: ");
                fgets(title, MAX_TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline from title
                printf("Enter your rating (1-5): ");
                scanf("%d", &rating);

                if (rating < 1 || rating > 5) {
                    printf("Invalid rating! Please enter a rating between 1 and 5.\n");
                } else {
                    rateMovie(head, title, rating);
                }
                break;

            case 3:
                displayMovies(head);
                break;

            case 4:
                freeMovies(head);
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

// Create a new movie node
Movie* createMovie(const char* title) {
    Movie *newMovie = (Movie *)malloc(sizeof(Movie));
    strncpy(newMovie->title, title, MAX_TITLE_LENGTH);
    newMovie->ratingCount = 0;
    newMovie->next = NULL;
    return newMovie;
}

// Add a movie to the linked list
void addMovie(Movie **head, const char* title) {
    Movie *newMovie = createMovie(title);
    newMovie->next = *head;
    *head = newMovie;
    printf("Movie added successfully: %s\n", title);
}

// Rate a movie
void rateMovie(Movie *head, const char* title, int rating) {
    Movie *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (current->ratingCount < MAX_RATINGS) {
                current->ratings[current->ratingCount] = rating;
                current->ratingCount++;
                printf("Rating of %d added to movie: %s\n", rating, title);
            } else {
                printf("Maximum ratings reached for movie: %s\n", title);
            }
            return;
        }
        current = current->next;
    }
    printf("Movie not found: %s\n", title);
}

// Display all movies with their average ratings
void displayMovies(Movie *head) {
    Movie *current = head;
    if (current == NULL) {
        printf("No movies to display.\n");
        return;
    }

    printf("\n=== Movie Ratings ===\n");
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        if (current->ratingCount > 0) {
            int sum = 0;
            for (int i = 0; i < current->ratingCount; i++) {
                sum += current->ratings[i];
            }
            printf("Average Rating: %.2f\n", (float)sum / current->ratingCount);
        } else {
            printf("No ratings yet.\n");
        }
        current = current->next;
    }
}

// Free the allocated memory for the movies
void freeMovies(Movie *head) {
    Movie *current = head;
    while (current != NULL) {
        Movie *temp = current;
        current = current->next;
        free(temp);
    }
}