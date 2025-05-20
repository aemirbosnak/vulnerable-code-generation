//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *title;
    float rating;
} Movie;

Movie movies[100];
int num_movies = 0;

int main() {
    int num_ratings, i;

    // Prompt the user for the number of ratings
    printf("How many ratings do you want to enter? ");
    scanf("%d", &num_ratings);

    // Prompt the user for each rating
    for (i = 0; i < num_ratings; i++) {
        char title[100];
        float rating;

        // Prompt the user for the movie title
        printf("Enter movie title: ");
        fgets(title, sizeof(title), stdin);

        // Prompt the user for the movie rating
        printf("Enter movie rating: ");
        scanf("%f", &rating);

        // Create a new movie struct and add it to the array
        movies[num_movies].id = num_movies;
        strcpy(movies[num_movies].title, title);
        movies[num_movies].rating = rating;
        num_movies++;
    }

    // Sort the movies by rating in descending order
    for (i = 0; i < num_movies - 1; i++) {
        for (int j = 0; j < num_movies - i - 1; j++) {
            if (movies[j].rating < movies[j + 1].rating) {
                Movie temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }

    // Print out the sorted movie ratings
    printf("Movie Rating System\n");
    printf("-------------------\n");
    printf("ID | Title | Rating\n");
    printf("-------------------\n");
    for (i = 0; i < num_movies; i++) {
        printf("%3d | %-30s | %3.1f\n", movies[i].id, movies[i].title, movies[i].rating);
    }

    return 0;
}