//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include<stdio.h>

/* Struct to hold movie details */
struct movie {
    char title[50];
    char director[50];
    int year;
    float rating;
};

/* Function to get user input for a movie */
struct movie get_movie_info(){
    struct movie m;
    printf("Enter movie name: ");
    scanf("%s", &m.title);
    printf("Enter director name: ");
    scanf("%s", &m.director);
    printf("Enter movie release year: ");
    scanf("%d", &m.year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &m.rating);
    return m;
}

/* Function to print movie details */
void print_movie(struct movie m){
    printf("\nMovie title: %s\n", m.title);
    printf("Director: %s\n", m.director);
    printf("Release year: %d\n", m.year);
    printf("Rating: %.2f/10\n", m.rating);
}

/* Function to get average rating of a list of movies */
float get_average_rating(struct movie movies[], int size){
    float total = 0;
    for(int i=0; i<size; i++){
        total += movies[i].rating;
    }
    return total/size;
}

int main(){
    int num_movies;
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    struct movie movies[num_movies];
    for(int i=0; i<num_movies; i++){
        printf("\nEnter details for movie #%d\n", i+1);
        movies[i] = get_movie_info();
    }

    printf("\n\nMovie rating list:\n");
    for(int i=0; i<num_movies; i++){
        print_movie(movies[i]);
    }

    printf("\n\nAverage movie rating: %.2f/10", get_average_rating(movies, num_movies));

    return 0;
}