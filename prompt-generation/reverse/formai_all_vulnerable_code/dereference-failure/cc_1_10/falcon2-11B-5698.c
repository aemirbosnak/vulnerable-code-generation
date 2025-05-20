//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new guest
void addGuest(int *guestCount, char **guestList, char *guestName, char *guestEmail) {
    // Check if guest list is full
    if (*guestCount >= 100) {
        printf("Sorry, the guest list is full. Please try again later.\n");
        return;
    }
    
    // Add the guest to the list
    guestList[*guestCount] = (char *) malloc(strlen(guestName) + 1);
    strcpy(guestList[*guestCount], guestName);
    
    guestEmail = (char *) malloc(strlen(guestEmail) + 1);
    strcpy(guestEmail, guestEmail);
    
    (*guestCount)++;
}

// Function to remove a guest
void removeGuest(int *guestCount, char **guestList, char *guestName) {
    // Check if the guest exists
    for (int i = 0; i < *guestCount; i++) {
        if (strcmp(guestList[i], guestName) == 0) {
            // Remove the guest from the list
            free(guestList[i]);
            guestList[i] = NULL;
            guestList[i] = NULL;
            (*guestCount)--;
            return;
        }
    }
    
    // Guest does not exist
    printf("Sorry, the guest '%s' does not exist.\n", guestName);
}

// Function to update a guest's information
void updateGuest(int *guestCount, char **guestList, char *guestName, char *guestEmail) {
    // Check if the guest exists
    for (int i = 0; i < *guestCount; i++) {
        if (strcmp(guestList[i], guestName) == 0) {
            // Update the guest's information
            guestEmail = (char *) malloc(strlen(guestEmail) + 1);
            strcpy(guestEmail, guestEmail);
            guestList[i] = guestEmail;
            return;
        }
    }
    
    // Guest does not exist
    printf("Sorry, the guest '%s' does not exist.\n", guestName);
}

// Function to retrieve a guest's information
void retrieveGuest(int *guestCount, char **guestList, char *guestName) {
    // Check if the guest exists
    for (int i = 0; i < *guestCount; i++) {
        if (strcmp(guestList[i], guestName) == 0) {
            // Print the guest's information
            printf("Guest: %s\nEmail: %s\n", guestList[i], guestList[i]);
            return;
        }
    }
    
    // Guest does not exist
    printf("Sorry, the guest '%s' does not exist.\n", guestName);
}

int main() {
    int guestCount = 0;
    char **guestList = NULL;
    
    // Add a new guest
    addGuest(&guestCount, &guestList, "John Doe", "john.doe@example.com");
    
    // Retrieve the guest's information
    retrieveGuest(&guestCount, &guestList, "John Doe");
    
    // Remove the guest
    removeGuest(&guestCount, &guestList, "John Doe");
    
    // Update the guest's information
    updateGuest(&guestCount, &guestList, "John Doe", "john.doe@newemail.com");
    
    // Retrieve the guest's information again
    retrieveGuest(&guestCount, &guestList, "John Doe");
    
    return 0;
}