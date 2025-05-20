//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct movie {
    char title[50];
    char director[50];
    char cast[100];
    int runtime;
    char genre[20];
    int rating;
};

void addmovie(struct movie *movies, int count) {
    printf("Enter movie title: ");
    scanf("%s", movies[count].title);

    printf("Enter movie director: ");
    scanf("%s", movies[count].director);

    printf("Enter movie cast: ");
    scanf("%s", movies[count].cast);

    printf("Enter movie runtime (in minutes): ");
    scanf("%d", &movies[count].runtime);

    printf("Enter movie genre: ");
    scanf("%s", movies[count].genre);

    printf("Enter movie rating (out of 10): ");
    scanf("%d", &movies[count].rating);
}

void displaymovies(struct movie movies[], int count) {
    for(int i=0; i<count; i++) {
        printf("\nMovie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Cast: %s\n", movies[i].cast);
        printf("Runtime: %d minutes\n", movies[i].runtime);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d/10\n\n", movies[i].rating);
    }
}

int main() {
    int count;

    printf("Enter the number of movies to rate: ");
    scanf("%d", &count);

    struct movie movies[count];

    for(int i=0; i<count; i++) {
        addmovie(movies, i);
    }

    displaymovies(movies, count);

    return 0;
}