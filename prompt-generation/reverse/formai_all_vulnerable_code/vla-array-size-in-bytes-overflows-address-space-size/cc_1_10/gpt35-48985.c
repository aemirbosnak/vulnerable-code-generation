//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include<stdio.h>
#include<string.h>

//structure to hold movie information
struct movie {
    char title[50];
    char genre[20];
    int rating;
};

//function to display movie information
void displayMovie(struct movie m) {
    printf("Movie: %s\n", m.title);
    printf("Genre: %s\n", m.genre);
    printf("Rating: %d\n", m.rating);
    printf("--------------------------\n");
}

int main() {
    int numMovies;
    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);
    struct movie movies[numMovies];

    //inputting movie information
    for(int i=0; i<numMovies; i++) {
        printf("Enter movie title: ");
        scanf(" %[^\n]%*c", movies[i].title);
        printf("Enter genre: ");
        scanf(" %[^\n]%*c", movies[i].genre);
        printf("Enter rating out of 10: ");
        scanf("%d", &movies[i].rating);
    }

    //displaying movie information
    printf("Movie Ratings:\n");
    for(int i=0; i<numMovies; i++) {
        displayMovie(movies[i]);
    }

    //calculating average rating
    int totalRating = 0;
    for(int i=0; i<numMovies; i++) {
        totalRating += movies[i].rating;
    }
    float avgRating = (float) totalRating / numMovies;

    //displaying average rating
    printf("Average Rating: %.2f\n", avgRating);

    //displaying movies with rating above average
    printf("Movies with rating above average:\n");
    for(int i=0; i<numMovies; i++) {
        if(movies[i].rating > avgRating) {
            displayMovie(movies[i]);
        }
    }

    return 0;
}