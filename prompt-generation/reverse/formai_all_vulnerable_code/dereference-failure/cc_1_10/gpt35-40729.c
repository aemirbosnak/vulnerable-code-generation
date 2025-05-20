//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 0; // number of movies
int *ratings; // array to store movie ratings
pthread_mutex_t lock; // mutex for thread synchronization

void *input_ratings(void *arg){
    int *index = (int *) arg;
    printf("Enter the rating (1-10) for movie %d: ", *index);

    // mutex lock to ensure thread synchronization
    pthread_mutex_lock(&lock);
    scanf("%d", &ratings[*index]);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void *calculate_average(void *arg){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += ratings[i];
    }
    double average = (double)sum / n;

    printf("The average rating of all %d movies is %.2f\n", n, average);

    pthread_exit(NULL);
}

int main(){
    printf("Enter the number of movies (n): ");
    scanf("%d", &n);

    ratings = (int*) malloc(n * sizeof(int));

    // initializes ratings array
    for(int i=0; i<n; i++){
        ratings[i] = 0;
    }

    pthread_t threads[n+1];

    // creates n threads for input ratings
    for(int i=0; i<n; i++){
        int *index = (int *) malloc(sizeof(int));
        *index = i;
        pthread_create(&threads[i], NULL, input_ratings, index);
    }

    // creates 1 thread to calculate the average rating
    pthread_create(&threads[n], NULL, calculate_average, NULL);

    // waits for all threads to finish executing
    for(int i=0; i<=n; i++){
        pthread_join(threads[i], NULL);
    }

    free(ratings); // frees ratings array from memory

    return 0;
}