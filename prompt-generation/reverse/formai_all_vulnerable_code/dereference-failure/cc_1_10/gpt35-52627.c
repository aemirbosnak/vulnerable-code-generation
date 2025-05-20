//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

#define MAX_LOCATIONS 10
#define MAX_LOCATION_NAME 20

// Array to store locations
char locations[MAX_LOCATIONS][MAX_LOCATION_NAME];

// Function to add location to array
void addLocation(int index, char *location){
    for(int i=0; i<MAX_LOCATION_NAME; i++){
        locations[index][i] = location[i];
    }
}

// Function to display all locations
void displayLocations(){
    printf("Current locations: ");
    for(int i=0; i<MAX_LOCATIONS; i++){
        if(locations[i][0] != '\0'){
            printf("%s, ", locations[i]);
        }
    }
    printf("\n");
}

// Function to find the index of a location in the array
int findLocation(char *location){
    for(int i=0; i<MAX_LOCATIONS; i++){
        if(strcmp(locations[i], location) == 0){
            return i;
        }
    }
    return -1;
}

// Main function
int main(){

    // Populate initial locations
    addLocation(0, "Home");
    addLocation(1, "Work");
    addLocation(2, "Gym");

    // Display current locations
    displayLocations();
    
    // Get user input for new destination
    char destination[MAX_LOCATION_NAME];
    printf("Enter destination: ");
    scanf("%s", destination);

    // Find the index of the destination
    int index = findLocation(destination);

    // Determine if destination is valid
    if(index == -1){
        printf("Invalid destination\n");
        exit(0);
    }

    // Display driving directions
    printf("Starting location: %s\n", locations[0]);
    for(int i=1; i<=index; i++){
        printf("Drive to %s\n", locations[i]);
    }
    printf("Arrived at %s\n", locations[index]);

    return 0;
}