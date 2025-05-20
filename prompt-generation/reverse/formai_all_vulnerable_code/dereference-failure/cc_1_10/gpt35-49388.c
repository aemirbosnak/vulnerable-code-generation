//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

//defining the movie struct
struct movie {
    char title[50];
    char genre[20];
    int releaseYear;
    float rating;
};

//function to get user input for movie details
void getMovieDetails(struct movie *m){
    printf("\nEnter Movie Title : ");
    fgets(m->title, 50, stdin);
    printf("Enter Movie Genre : ");
    fgets(m->genre, 20, stdin);
    printf("Enter Movie Release Year : ");
    scanf("%d", &m->releaseYear);
    printf("Enter Movie Rating : ");
    scanf("%f", &m->rating);
    getchar();  //to clear input buffer
}

//function to display a single movie's details
void displayMovieDetails(struct movie m){
    printf("\nTitle : %s", m.title);
    printf("Genre : %s", m.genre);
    printf("Release Year : %d\n", m.releaseYear);
    printf("Rating : %f\n", m.rating);
}

int main(){
    int choice, numMovies = 0, i;
    float totalRating = 0, avgRating;

    struct movie *movies = (struct movie*)malloc(sizeof(struct movie) * 10);  //allocating memory for 10 movies

    do{
        printf("\n*** Movie Rating System ***\n");
        printf("1. Add Movie Details\n");
        printf("2. Display All Movie Details\n");
        printf("3. Display Top Rated Movie\n");
        printf("4. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        getchar();  //to clear input buffer

        switch(choice){
            case 1:
                if(numMovies < 10){
                    printf("\n*** Enter Movie Details ***\n");
                    getMovieDetails(&movies[numMovies]);
                    numMovies++;
                }
                else{
                    printf("\nMaximum number of movies added!\n");
                }
                break;

            case 2:
                if(numMovies == 0){
                    printf("\nNo movies added yet!\n");
                }
                else{
                    printf("\n*** All Movie Details ***\n");
                    for(i=0; i<numMovies; i++){
                        displayMovieDetails(movies[i]);
                    }
                }
                break;

            case 3:
                if(numMovies == 0){
                    printf("\nNo movies added yet!\n");
                }
                else{
                    totalRating = 0;
                    for(i=0; i<numMovies; i++){
                        totalRating += movies[i].rating;
                    }
                    avgRating = totalRating / numMovies;

                    printf("\n*** Top Rated Movie ***\n");
                    for(i=0; i<numMovies; i++){
                        if(movies[i].rating >= avgRating){
                            displayMovieDetails(movies[i]);
                        }
                    }
                }
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    }while(choice != 4);

    free(movies);  //freeing the allocated memory
    
    return 0;
}