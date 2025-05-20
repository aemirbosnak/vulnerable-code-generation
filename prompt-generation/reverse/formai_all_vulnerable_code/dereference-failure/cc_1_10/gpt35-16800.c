//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to configure the rating system criteria
void configure_ratings(int *ratings, int num_ratings){
    printf("Please enter the %d ratings criteria\n", num_ratings);
    for(int i=0; i<num_ratings; i++){
        printf("Rating %d: ", i+1);
        scanf("%d", &ratings[i]);
    }
}

//Function to rate the movie based on configured ratings criteria
float rate_movie(int *ratings, int num_ratings){
    int *counts = (int*)malloc(num_ratings * sizeof(int));
    memset(counts, 0, num_ratings * sizeof(int)); //Initialize counts array to 0
    int total_votes = 0;
    int rating;

    printf("Please enter the ratings (enter -1 to stop): ");
    while(1){
        scanf("%d", &rating);
        if(rating == -1){
            break;
        }
        for(int i=0; i<num_ratings; i++){
            if(rating >= ratings[i]){
                counts[i]++;
                total_votes++;
                break;
            }
        }
    }

    printf("Total votes: %d\n", total_votes);
    printf("-----Ratings-----\n");
    float weighted_rating = 0.0;
    for(int i=0; i<num_ratings; i++){
        float percentage = (float)counts[i] / total_votes;
        weighted_rating += ratings[i] * percentage;
        printf("%d Stars: %.2f%%\n", ratings[i], percentage*100);
    }
    free(counts);
    return weighted_rating;
}

int main(){

    //Configure the ratings criteria 
    int num_ratings;
    printf("How many ratings criteria would you like to configure? ");
    scanf("%d", &num_ratings);
    int *ratings = (int*)malloc(num_ratings * sizeof(int));
    configure_ratings(ratings, num_ratings);

    //Rate the movie based on user inputs
    float rating = rate_movie(ratings, num_ratings);
    printf("Weighted Rating: %.2f Stars\n", rating);

    free(ratings);
    return 0;
}