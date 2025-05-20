//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hotel data structure
typedef struct Hotel {
    char name[50];
    char address[100];
    int num_rooms;
    int num_floors;
    int num_stars;
    float avg_rating;
    int num_reviews;
} Hotel;

// Function to create a new hotel
Hotel* create_hotel(char* name, char* address, int num_rooms, int num_floors, int num_stars, float avg_rating, int num_reviews) {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    strcpy(hotel->name, name);
    strcpy(hotel->address, address);
    hotel->num_rooms = num_rooms;
    hotel->num_floors = num_floors;
    hotel->num_stars = num_stars;
    hotel->avg_rating = avg_rating;
    hotel->num_reviews = num_reviews;
    return hotel;
}

// Function to print hotel details
void print_hotel(Hotel* hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    printf("Number of Floors: %d\n", hotel->num_floors);
    printf("Number of Stars: %d\n", hotel->num_stars);
    printf("Average Rating: %f\n", hotel->avg_rating);
    printf("Number of Reviews: %d\n", hotel->num_reviews);
}

// Main function
int main() {
    // Create a new hotel
    Hotel* hotel = create_hotel("The Grand Hotel", "123 Main Street", 100, 10, 5, 4.5, 100);

    // Print the hotel details
    printf("Welcome to %s!\n", hotel->name);
    printf("We're located at %s and have %d rooms over %d floors.\n", hotel->address, hotel->num_rooms, hotel->num_floors);
    printf("We're proud to have earned %d stars and an average rating of %f from our guests.\n", hotel->num_stars, hotel->avg_rating);
    printf("We've received %d reviews so far, and we're always looking for feedback to improve our service.\n", hotel->num_reviews);

    // Free the memory allocated for the hotel
    free(hotel);

    return 0;
}