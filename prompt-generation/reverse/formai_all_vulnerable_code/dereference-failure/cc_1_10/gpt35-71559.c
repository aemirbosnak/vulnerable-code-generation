//FormAI DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// define a structure to hold movie information
struct movie {
    char title[50];
    char genre[20];
    int rating;
    struct movie* next;
};

// recursively display the linked list of movies
void display_movies(struct movie* current) {
    if (current == NULL) {
        printf("No movies to display\n");
        return;
    }
    printf("%s (%s): %d/10\n", current->title, current->genre, current->rating);
    display_movies(current->next);
}

// recursively add a new movie to the linked list
struct movie* add_movie(struct movie* current) {
    char title[50];
    char genre[20];
    int rating;
    struct movie* new_movie = malloc(sizeof(struct movie));
    printf("Enter movie title (or 'quit' to finish adding movies): ");
    scanf("%s", title);
    if (strcmp(title, "quit") == 0) {
        free(new_movie);
        return current;
    }
    printf("Enter movie genre: ");
    scanf("%s", genre);
    printf("Enter movie rating (1-10): ");
    scanf("%d", &rating);
    if (rating < 1 || rating > 10) {
        printf("Invalid rating, rating must be between 1 and 10\n");
        free(new_movie);
        return add_movie(current);
    }
    strcpy(new_movie->title, title);
    strcpy(new_movie->genre, genre);
    new_movie->rating = rating;
    new_movie->next = current;
    printf("Movie added successfully!\n");
    return add_movie(new_movie);
}

int main() {
    struct movie* movie_list = NULL;
    int choice;
    do {
        printf("\n-----------------------------\n");
        printf("1. Add a movie\n");
        printf("2. Display movies\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                movie_list = add_movie(movie_list);
                break;
            case 2:
                display_movies(movie_list);
                break;
            case 3:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice, please enter a number between 1 and 3\n");
        }
    } while (choice != 3);
    return 0;
}