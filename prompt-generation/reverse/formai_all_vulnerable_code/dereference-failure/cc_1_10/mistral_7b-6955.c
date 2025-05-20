//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_NAME_LENGTH 50
#define MAX_RATINGS 10

typedef struct {
    char title[MAX_NAME_LENGTH];
    float rating[MAX_RATINGS];
    int num_ratings;
} Movie;

void add_rating(Movie *movie, float rating);
float get_average_rating(const Movie *movie);

int main() {
    Movie movies[MAX_MOVIES];
    char name[MAX_NAME_LENGTH];
    float rating;
    int choice, index = 0;

    while (1) {
        printf("1. Add Rating\n");
        printf("2. Display Movie\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (index >= MAX_MOVIES) {
                    printf("Maximum number of movies reached!\n");
                    break;
                }
                printf("Enter movie title: ");
                scanf("%s", name);
                strcpy(movies[index].title, name);
                printf("Enter rating: ");
                scanf("%f", &rating);
                add_rating(&movies[index], rating);
                index++;
                break;
            case 2:
                if (index == 0) {
                    printf("No movies added yet!\n");
                    break;
                }
                printf("Enter movie index to display: ");
                scanf("%d", &choice);
                if (choice >= 0 && choice < index) {
                    printf("Title: %s\n", movies[choice].title);
                    printf("Average Rating: %.2f\n", get_average_rating(&movies[choice]));
                } else {
                    printf("Invalid index!\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void add_rating(Movie *movie, float rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->rating[movie->num_ratings] = rating;
        movie->num_ratings++;
    } else {
        printf("Maximum number of ratings reached!\n");
    }
}

float get_average_rating(const Movie *movie) {
    float sum = 0.0;
    for (int i = 0; i < movie->num_ratings; i++) {
        sum += movie->rating[i];
    }
    return sum / movie->num_ratings;
}