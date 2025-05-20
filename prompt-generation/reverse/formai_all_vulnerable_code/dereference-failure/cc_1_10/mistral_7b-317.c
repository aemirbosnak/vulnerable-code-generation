//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    float rating;
    struct movie *next;
} movie;

movie *movies = NULL;
int num_movies = 0;

void add_movie(char *title, float rating) {
    movie *new_movie = (movie *) malloc(sizeof(movie));
    strcpy(new_movie->title, title);
    new_movie->rating = rating;
    new_movie->next = movies;
    movies = new_movie;
    num_movies++;
}

void print_movies() {
    movie *current = movies;
    printf("Movies in the system:\n");
    while (current != NULL) {
        printf("%s - %.2f\n", current->title, current->rating);
        current = current->next;
    }
}

void calculate_average_rating() {
    float sum = 0.0;
    int i;
    movie *current = movies;

    for (i = 0; i < num_movies; i++, current++) {
        sum += current->rating;
    }

    printf("Average rating: %.2f\n", sum / num_movies);
}

int main() {
    char title[50];
    float rating;
    int choice;

    while (1) {
        printf("\n1. Add movie\n2. View movies\n3. Calculate average rating\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter movie title: ");
                scanf("%s", title);
                printf("Enter movie rating: ");
                scanf("%f", &rating);
                add_movie(title, rating);
                break;
            case 2:
                print_movies();
                break;
            case 3:
                calculate_average_rating();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}