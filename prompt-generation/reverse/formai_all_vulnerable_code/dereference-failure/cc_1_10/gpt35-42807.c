//FormAI DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rating {
    char movie[50];
    int rating;
    struct rating *next;
} Rating;

Rating *head = NULL;

void add_rating(Rating **ratings, char movie[50], int rating) {
    if (*ratings == NULL) {
        *ratings = (Rating *) malloc(sizeof(Rating));
        strcpy((*ratings)->movie, movie);
        (*ratings)->rating = rating;
        (*ratings)->next = NULL;
    } else {
        add_rating(&((*ratings)->next), movie, rating);
    }
}

void display_ratings(Rating *ratings) {
    if (ratings == NULL) {
        printf("No ratings available.\n");
    } else {
        printf("Movie \t Rating\n");
        printf("----------------\n");
        while (ratings != NULL) {
            printf("%s \t %d\n", ratings->movie, ratings->rating);
            ratings = ratings->next;
        }
    }
}

int main() {
    int choice;
    char movie[50];
    int rating;

    printf("Welcome to C Movie Rating System!\n");

    do {
        printf("\nMenu:\n1. Add Rating\n2. Display Ratings\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie name: ");
                scanf("%s", movie);
                printf("Enter rating (out of 10): ");
                scanf("%d", &rating);

                add_rating(&head, movie, rating);
                printf("Rating added successfully!\n");
                break;
            case 2:
                display_ratings(head);
                break;
            case 3:
                printf("Thank you for using C Movie Rating System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}