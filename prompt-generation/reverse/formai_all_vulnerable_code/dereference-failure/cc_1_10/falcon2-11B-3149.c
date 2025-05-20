//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to get user input
void getUserInput(char* message, char* inputBuffer, int bufferSize) {
    printf("%s: ", message);
    fgets(inputBuffer, bufferSize, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Remove the newline character
}

// Function to calculate average rating
float calculateAverage(int ratings[], int numRatings) {
    int sum = 0;
    for (int i = 0; i < numRatings; i++) {
        sum += ratings[i];
    }
    return (float) sum / numRatings;
}

// Function to display average rating
void displayAverage(float average) {
    printf("Average Rating: %.2f\n", average);
}

// Function to display all ratings
void displayAllRatings(int ratings[], int numRatings) {
    for (int i = 0; i < numRatings; i++) {
        printf("%d: %.2f\n", i + 1, ratings[i]);
    }
}

// Function to add a new rating
void addRating(int ratings[], int numRatings, int newRating) {
    ratings[numRatings] = newRating;
    numRatings++;
}

// Main function
int main() {
    int ratings[10] = {0}; // Array to store ratings
    int numRatings = 0; // Number of ratings

    // Get user input for movie name
    char movieName[100];
    getUserInput("Enter movie name: ", movieName, 100);

    // Get user input for ratings
    int rating1, rating2, rating3;
    getUserInput("Enter ratings (1-10): ", &rating1, 10);
    getUserInput("Enter ratings (1-10): ", &rating2, 10);
    getUserInput("Enter ratings (1-10): ", &rating3, 10);

    // Add ratings to the array
    addRating(ratings, numRatings, rating1);
    addRating(ratings, numRatings, rating2);
    addRating(ratings, numRatings, rating3);

    // Calculate average rating
    float average = calculateAverage(ratings, numRatings);

    // Display average rating
    displayAverage(average);

    // Display all ratings
    displayAllRatings(ratings, numRatings);

    return 0;
}