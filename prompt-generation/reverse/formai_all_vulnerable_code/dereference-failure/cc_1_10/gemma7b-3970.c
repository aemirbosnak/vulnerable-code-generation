//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5

typedef struct Rating {
    char name[50];
    int rating;
    struct Rating* next;
} Rating;

Rating* createRating(char* name, int rating) {
    Rating* newRating = malloc(sizeof(Rating));
    strcpy(newRating->name, name);
    newRating->rating = rating;
    newRating->next = NULL;
    return newRating;
}

void addRating(Rating* ratings, char* name, int rating) {
    Rating* newRating = createRating(name, rating);
    if (ratings == NULL) {
        ratings = newRating;
    } else {
        ratings->next = newRating;
        ratings = ratings->next;
    }
}

int getRating(Rating* ratings, char* name) {
    for (Rating* currentRating = ratings; currentRating; currentRating = currentRating->next) {
        if (strcmp(currentRating->name, name) == 0) {
            return currentRating->rating;
        }
    }
    return -1;
}

int main() {
    Rating* ratings = NULL;
    addRating(ratings, "John Doe", 5);
    addRating(ratings, "Jane Doe", 3);
    addRating(ratings, "Bob Smith", 4);

    int johnDoeRating = getRating(ratings, "John Doe");
    printf("John Doe's rating: %d\n", johnDoeRating);

    return 0;
}