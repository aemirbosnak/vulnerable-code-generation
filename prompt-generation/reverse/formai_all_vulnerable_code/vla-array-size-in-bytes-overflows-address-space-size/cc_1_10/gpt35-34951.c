//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include<stdio.h>
#include<string.h>

//Structure to store details of a movie
struct movie
{
    char name[50];      //Name of the movie
    float rating;       //Rating of the movie
    int year;           //Year of release of the movie
};

int main()
{
    int n;                      //Number of movies
    float sum_ratings = 0;      //Sum of all movie ratings
    float avg_rating;           //Average movie rating
    int year_count[20] = {0};   //Count of movies released in each year (from 2000 to 2019)

    printf("Enter the number of movies: ");
    scanf("%d", &n);

    struct movie m[n];

    //Input details of each movie
    printf("Enter details of each movie:\n");
    for(int i=0; i<n; i++)
    {
        printf("Name of the movie: ");
        scanf("%s", m[i].name);

        printf("Rating of the movie: ");
        scanf("%f", &m[i].rating);
        sum_ratings += m[i].rating;

        printf("Year of release of the movie (2000-2019): ");
        scanf("%d", &m[i].year);
        year_count[m[i].year-2000]++;
    }

    //Calculate average movie rating
    avg_rating = sum_ratings/n;

    //Display movie rating statistics
    printf("\nMovie rating statistics:\n");
    printf("Total number of movies: %d\n", n);
    printf("Average movie rating: %.2f\n", avg_rating);
    printf("Movies released in each year:\n");
    for(int i=0; i<20; i++)
    {
        printf("Year %d: %d\n", i+2000, year_count[i]);
    }

    return 0;
}