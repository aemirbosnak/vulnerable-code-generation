//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct movie {
    char title[50];
    char director[50];
    int year;
    char rating[5];
};

int main() {
    int num_movies, i;
    char username[20], password[20];
    printf("Welcome to the C Movie Rating System!\n\n");
    printf("Please create a username: ");
    scanf("%s", username);
    printf("Please create a password: ");
    scanf("%s", password);
    printf("\nThank you!\n\n");

    printf("Please enter the number of movies you would like to rate: ");
    scanf("%d", &num_movies);

    struct movie *movies = malloc(num_movies * sizeof(struct movie));

    for (i = 0; i < num_movies; i++) {
        printf("Please enter the title of movie #%d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Please enter the director of movie #%d: ", i+1);
        scanf("%s", movies[i].director);
        printf("Please enter the year of movie #%d: ", i+1);
        scanf("%d", &movies[i].year);
        printf("Please enter your rating for movie #%d (1-10): ", i+1);
        scanf("%s", movies[i].rating);
    }

    printf("\nThank you for rating your movies!\n\n");

    printf("Please log in to see the average ratings for the movies.\n");
    char input_username[20], input_password[20];
    printf("Username: ");
    scanf("%s", input_username);
    printf("Password: ");
    scanf("%s", input_password);
    if (strcmp(input_username, username) != 0 || strcmp(input_password, password) != 0) {
        printf("\nInvalid login. Goodbye!\n");
        return 0;
    }

    printf("\n\nHere are the list of movies rated by you and their average rating.\n\n");

    for (i = 0; i < num_movies; i++) {
        int sum = 0, j;
        for (j = 0; j < strlen(movies[i].rating); j++) {
            sum += movies[i].rating[j] - '0';
        }
        printf("%s (Director: %s, Year: %d) - Average rating: %.2f\n", movies[i].title, movies[i].director, movies[i].year, (float)sum/strlen(movies[i].rating));
    }

    free(movies);

    printf("\n\nThank you for using the C Movie Rating System! Goodbye!\n");

    return 0;
}