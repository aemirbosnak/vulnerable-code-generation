//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define struct for movie information
typedef struct {
   char title[50];
   int year;
   float rating;
   int num_ratings;
} movie_t;

// Function to add a new movie to the database
void add_movie(movie_t* db, int* num_movies)
{
   // Get title, year, and rating from user input
   printf("Enter movie title:\n");
   scanf("%s", db[*num_movies].title);
   
   printf("Enter year released:\n");
   scanf("%d", &db[*num_movies].year);
   
   printf("Enter rating (0-10):\n");
   scanf("%f", &db[*num_movies].rating);
   
   // Initialize number of ratings for this movie to 0
   db[*num_movies].num_ratings = 0;

   // Print confirmation message
   printf("Added %s (%d) with a rating of %.1f\n\n", db[*num_movies].title, db[*num_movies].year, db[*num_movies].rating);
   
   // Increment number of movies in database
   (*num_movies)++;
}

// Function to rate an existing movie
void rate_movie(movie_t* db, int num_movies)
{
   char title[50];
   int i;
   
   // Get title of movie to rate from user input
   printf("Enter movie title to rate:\n");
   scanf("%s", title);
   
   // Loop through movie database to find matching title
   for(i = 0; i < num_movies; i++)
   {
      if(strcmp(db[i].title, title) == 0)
      {
         // Get new rating from user input
         printf("Enter new rating (0-10):\n");
         scanf("%f", &db[i].rating);
         
         // Increment number of ratings for this movie
         (db[i].num_ratings)++;
         
         // Print confirmation message
         printf("Rated %s (%d) with a new rating of %.1f\n\n", db[i].title, db[i].year, db[i].rating);
         
         return;
      }
   }
   
   // If title was not found, print error message
   printf("Error: movie not found\n\n");
}

// Function to print all movies in the database
void print_movies(movie_t* db, int num_movies)
{
   int i;
   
   // Loop through movie database and print each movie's information
   for(i = 0; i < num_movies; i++)
   {
      printf("%s (%d): %.1f/10 (%d ratings)\n", db[i].title, db[i].year, db[i].rating, db[i].num_ratings);
   }
   
   printf("\n");
}

int main()
{
   // Initialize variables
   movie_t* db;
   int num_movies = 0;
   int option;

   // Initial memory allocation for the movies database
   db = malloc(10 * sizeof(movie_t));
   
   // Loop to run user interface until quit option is chosen
   do
   {
      // Print options to user
      printf("Choose an option:\n");
      printf("1. Add a movie\n");
      printf("2. Rate an existing movie\n");
      printf("3. See all movies\n");
      printf("4. Quit\n");
      
      // Get option from user input
      scanf("%d", &option);
      
      // Handle chosen option
      switch(option)
      {
         case 1:
            add_movie(db, &num_movies);
            break;
         
         case 2:
            rate_movie(db, num_movies);
            break;
         
         case 3:
            print_movies(db, num_movies);
            break;
         
         case 4:
            printf("Goodbye!\n");
            break;
         
         default:
            printf("Error: option not recognized\n\n");
            break;
      }
   } while(option != 4);

   // Free allocated memory for the movies database
   free(db);
   
   return 0;
}