//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read user input
void read_user_input(char* buf, int buf_size) {
    int i;
    char c;
    for (i = 0; i < buf_size - 1; i++) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        buf[i] = c;
    }
    buf[i] = '\0';
}

// Function to print ratings
void print_ratings(int* ratings, int num_ratings) {
    int i;
    for (i = 0; i < num_ratings; i++) {
        printf("Rating %d: %s\n", i + 1, ratings[i]);
    }
}

// Function to sort ratings
void sort_ratings(int* ratings, int num_ratings) {
    int i, j;
    for (i = 0; i < num_ratings - 1; i++) {
        for (j = i + 1; j < num_ratings; j++) {
            if (ratings[i] > ratings[j]) {
                int temp = ratings[i];
                ratings[i] = ratings[j];
                ratings[j] = temp;
            }
        }
    }
}

// Function to calculate average rating
double calculate_average_rating(int* ratings, int num_ratings) {
    int sum = 0;
    for (int i = 0; i < num_ratings; i++) {
        sum += ratings[i];
    }
    return (double) sum / num_ratings;
}

int main() {
    int num_ratings;
    printf("Enter the number of ratings: ");
    read_user_input(&num_ratings, 1);
    int* ratings = (int*) malloc(num_ratings * sizeof(int));
    for (int i = 0; i < num_ratings; i++) {
        printf("Enter rating %d: ", i + 1);
        read_user_input(&ratings[i], 1);
    }
    sort_ratings(ratings, num_ratings);
    printf("Ratings (sorted):\n");
    print_ratings(ratings, num_ratings);
    printf("Average rating: %.2f\n", calculate_average_rating(ratings, num_ratings));
    free(ratings);
    return 0;
}