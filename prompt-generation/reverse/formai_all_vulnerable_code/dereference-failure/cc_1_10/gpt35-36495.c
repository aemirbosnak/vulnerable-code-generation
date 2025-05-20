//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please select an option:\n");
    printf("1. Add a movie\n");
    printf("2. Rate a movie\n");
    printf("3. View movie ratings\n");
    printf("4. Exit\n");
}

void addMovie(int *movieIds, char **movieTitles, int *movieRatings, int *numMovies) {
    printf("Enter the title of the movie: ");
    char *title = malloc(sizeof(char) * 100);
    scanf("%s", title);

    movieIds[*numMovies] = *numMovies + 1;
    movieTitles[*numMovies] = title;
    movieRatings[*numMovies] = -1;

    printf("Movie has been added!\n");
    (*numMovies)++;
}

void rateMovie(int *movieRatings, int numMovies) {
    printf("Enter the ID of the movie you want to rate: ");
    int id;
    scanf("%d", &id);

    if (id < 1 || id > numMovies) {
        printf("Invalid ID entered!\n");
        return;
    }

    printf("Enter your rating (0-10) for the movie: ");
    int rating;
    scanf("%d", &rating);

    if (rating < 0 || rating > 10) {
        printf("Invalid rating entered!\n");
        return;
    }

    movieRatings[id - 1] = rating;
    printf("Thanks for rating the movie!\n");
}

void viewMovieRatings(int *movieIds, char **movieTitles, int *movieRatings, int numMovies) {
    printf("Movie ID\tTitle\t\t\tRating\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%d\t\t%-30s\t%d\n", movieIds[i], movieTitles[i], movieRatings[i]);
    }
}

int main() {
    int numMovies = 0;
    int *movieIds = malloc(sizeof(int) * 100);
    char **movieTitles = malloc(sizeof(char *) * 100);
    int *movieRatings = malloc(sizeof(int) * 100);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie(movieIds, movieTitles, movieRatings, &numMovies);
                break;
            case 2:
                rateMovie(movieRatings, numMovies);
                break;
            case 3:
                viewMovieRatings(movieIds, movieTitles, movieRatings, numMovies);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice entered!\n");
        }
    } while (choice != 4);

    free(movieIds);
    free(movieTitles);
    free(movieRatings);

    return 0;
}