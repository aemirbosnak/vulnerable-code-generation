//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Movie {
    char title[100];
    int rating;
    struct Movie* next;
} Movie;

void addMovie(Movie** head, char* title, int rating) {
    Movie* newMovie = (Movie*) malloc(sizeof(Movie));
    strcpy(newMovie->title, title);
    newMovie->rating = rating;
    newMovie->next = *head;
    *head = newMovie;
}

void printMovieList(Movie* head) {
    Movie* current = head;
    printf("\nMOVIE RATING SYSTEM\n===============\n");
    printf("Title\t\tRating\n");
    printf("--------------------\n");
    while (current != NULL) {
        printf("%s\t\t%d\n", current->title, current->rating);
        current = current->next;
    }
}

void getMovieInput(char* title, int* rating) {
    printf("Enter movie title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("Enter movie rating (1-10): ");
    scanf("%d", rating);
}

int main() {
    Movie* movieList = NULL;
    char title[100];
    int rating;

    while (1) {
        system("clear"); // or use 'cls' for Windows
        printf("*****************************\n");
        printf("*** Welcome to the Movie Rating ***\n");
        printf("*** System! (Type 'q' to quit) ***\n");
        printf("*****************************\n");

        printf("\nDo you want to add a new movie? [y/n]: ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            getMovieInput(title, &rating);
            addMovie(&movieList, title, rating);
            printf("Movie added successfully!\n");
            printf("Press any key to continue...");
            getchar();
        }

        printMovieList(movieList);
        printf("\nPress any key to continue...");
        getchar();

        if (choice == 'q') {
            break;
        }
    }

    Movie* current = movieList;
    while (current != NULL) {
        Movie* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}