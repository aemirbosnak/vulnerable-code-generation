//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

int movies_count = 0;

typedef struct {
    char title[50];
    float ratings[MAX_RATINGS];
    int ratings_count;
} Movie;

Movie movies[MAX_MOVIES];

void add_movie() {
    printf("\nEnter movie title: ");
    scanf("%49s", &movies[movies_count].title);
    movies[movies_count].ratings_count = 0;
    movies_count++;
}

void add_rating() {
    int movie_index;
    printf("\nEnter movie index: ");
    scanf("%d", &movie_index);
    if (movie_index >= movies_count) {
        printf("\nInvalid movie index!");
        return;
    }
    float rating;
    printf("Enter movie rating: ");
    scanf("%f", &rating);
    Movie *movie = &movies[movie_index];
    if (movie->ratings_count >= MAX_RATINGS) {
        printf("Maximum number of ratings reached!");
        return;
    }
    movie->ratings[movie->ratings_count++] = rating;
    printf("\nRating added to %s", movie->title);
}

float get_average_rating(float *ratings, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += ratings[i];
    }
    return total / count;
}

void print_movies() {
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < movies_count; i++) {
        Movie movie = movies[i];
        float average_rating = get_average_rating(movie.ratings, movie.ratings_count);
        printf("%d. %s - %.2f\n", i, movie.title, average_rating);
    }
}

int main() {

    int option;
    do {
        printf("\n\nMovie Rating System Menu:\n");
        printf("1. Add movie\n");
        printf("2. Add rating\n");
        printf("3. Print movies list\n");
        printf("4. Quit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_movie();
                break;
            case 2:
                add_rating();
                break;
            case 3:
                print_movies();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid option!");
                break;
        }
    } while (option != 4);

    return 0;
}