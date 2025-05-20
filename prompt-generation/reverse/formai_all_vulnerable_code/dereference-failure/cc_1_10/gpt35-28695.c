//FormAI DATASET v1.0 Category: Movie Rating System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Define movie struct
struct movie {
    int id;
    char title[50];
    char director[50];
    int year;
    double rating;
};

// Define global variables
bool is_running = true;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
struct movie* movie_list[10];
int num_movies = 0;

// Define functions
void* input_handler(void *arg) {
    char input[50];
    while(is_running) {
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        pthread_mutex_lock(&mutex);
        if(num_movies == 10) {
            printf("Maximum number of movies reached. Please rate an existing movie.\n");
        } else {
            struct movie* new_movie = (struct movie*)malloc(sizeof(struct movie));
            new_movie->id = num_movies + 1;
            strcpy(new_movie->title, input);
            printf("Please enter the director: ");
            fgets(input, 50, stdin);
            input[strcspn(input, "\n")] = 0;
            strcpy(new_movie->director, input);
            printf("Please enter the year: ");
            fgets(input, 50, stdin);
            new_movie->year = atoi(input);
            new_movie->rating = 0.0;
            movie_list[num_movies] = new_movie;
            num_movies++;
            printf("Movie successfully added to list!\n");
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* rating_handler(void *arg) {
    while(is_running) {
        pthread_mutex_lock(&mutex);
        while(num_movies == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Please select a movie to rate (by ID): ");
        char input[50];
        fgets(input, 50, stdin);
        int selected_id = atoi(input);
        bool found_movie = false;
        for(int i = 0; i < num_movies; i++) {
            if(movie_list[i]->id == selected_id) {
                printf("Please enter your rating (out of 10): ");
                fgets(input, 50, stdin);
                double rating = atof(input);
                if(rating < 0 || rating > 10) {
                    printf("Invalid rating. Please rate between 0 and 10.\n");
                } else {
                    movie_list[i]->rating = rating;
                    printf("Your rating has been recorded. Thank you!\n");
                }
                found_movie = true;
                break;
            }
        }
        if(!found_movie) {
            printf("Invalid movie ID. Please try again.\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* print_handler(void *arg) {
    while(is_running) {
        pthread_mutex_lock(&mutex);
        while(num_movies == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("\n%-5s %-30s %-20s %-10s %-10s\n", "ID", "Title", "Director", "Year", "Rating");
        printf("-------------------------------------------------------------\n");
        for(int i = 0; i < num_movies; i++) {
            struct movie* m = movie_list[i];
            printf("%-5d %-30s %-20s %-10d %-10.1f\n", m->id, m->title, m->director, m->year, m->rating);
        }
        printf("\n");
        pthread_mutex_unlock(&mutex);
        sleep(2); // print every 2 seconds
    }
    pthread_exit(NULL);
}

int main() {
    printf("Welcome to the Movie Rating System!\n");

    pthread_t input_thread, rating_thread, print_thread;
    pthread_create(&input_thread, NULL, input_handler, NULL);
    pthread_create(&rating_thread, NULL, rating_handler, NULL);
    pthread_create(&print_thread, NULL, print_handler, NULL);

    char input[50];
    while(true) {
        printf("Press 'Q' to quit.\n");
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0;
        if(strcmp(input, "Q") == 0) {
            is_running = false;
            break;
        }
    }

    pthread_join(input_thread, NULL);
    pthread_join(rating_thread, NULL);
    pthread_join(print_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    for(int i = 0; i < num_movies; i++) {
        free(movie_list[i]);
    }

    printf("Thank you for using the Movie Rating System!\n");

    return 0;
}