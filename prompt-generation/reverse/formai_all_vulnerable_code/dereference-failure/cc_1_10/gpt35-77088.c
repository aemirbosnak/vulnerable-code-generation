//FormAI DATASET v1.0 Category: Movie Rating System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct movie {
    char title[50];
    char genre[20];
    int rating;
};

struct movie_list {
    struct movie m;
    struct movie_list *next;
};

void add_movie(struct movie_list **head, struct movie m) {
    struct movie_list *new_movie = (struct movie_list*) malloc(sizeof(struct movie_list));
    new_movie->m = m;
    new_movie->next = *head;
    *head = new_movie;
}

void print_list(struct movie_list *head) {
    struct movie_list *current = head;
    while(current != NULL) {
        printf("%s - %s - %d/10\n", current->m.title, current->m.genre, current->m.rating);
        current = current->next;
    }
}

int main() {

    int option = 0;
    char title_input[50];
    char genre_input[20];
    int rating_input;

    struct movie_list *head = NULL;

    printf("Welcome to the Movie Rating System!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1: 
                printf("\nPlease enter the movie title: ");
                scanf("%s", title_input);
                printf("Please enter the movie genre: ");
                scanf("%s", genre_input);
                printf("Please rate the movie from 1 to 10: ");
                scanf("%d", &rating_input);
                struct movie new_movie = {title_input, genre_input, rating_input};
                add_movie(&head, new_movie);
                printf("Movie added successfully!\n");
                break;

            case 2:
                if(head == NULL) {
                    printf("\nNo movies added yet.\n");
                } else {
                    printf("\nHere are all the movies:\n");
                    print_list(head);
                }
                break;

            case 3:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while(option != 3);

    return 0;
}