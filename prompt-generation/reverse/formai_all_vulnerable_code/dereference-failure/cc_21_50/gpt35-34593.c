//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Node structure for the linked list
typedef struct Node {
    char location[50];
    struct Node* next;
} Node;

// Function to print the current location of the user
void printLocation(Node* currentLocation) {
    printf("You are currently at %s.\n", currentLocation->location);
}

int main() {
    printf("Welcome to our GPS Navigation Simulation!\n");
    
    // Creating the linked list of locations
    Node* head = NULL;
    Node* current = NULL;
    
    head = (Node*) malloc(sizeof(Node));
    strcpy(head->location, "Central Park");
    current = head;
    
    current->next = (Node*) malloc(sizeof(Node));
    current = current->next;
    strcpy(current->location, "Empire State Building");
    
    current->next = (Node*) malloc(sizeof(Node));
    current = current->next;
    strcpy(current->location, "Times Square");
    
    current->next = (Node*) malloc(sizeof(Node));
    current = current->next;
    strcpy(current->location, "Statue of Liberty");
    
    current->next = (Node*) malloc(sizeof(Node));
    current = current->next;
    strcpy(current->location, "Brooklyn Bridge");
    current->next = NULL;

    printf("Here are the available locations:\n\n");
    // Printing the locations
    current = head;
    while (current != NULL) {
        printf("%s\n", current->location);
        current = current->next;
    }
    printf("\n");

    printf("Please enter your starting location: ");
    char startingLocation[50];
    scanf("%s", startingLocation);

    // Initializing the current location of the user
    current = head;
    while (current != NULL && strcmp(current->location, startingLocation) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Sorry, we don't have information about that location.\n");
    } else {
        printLocation(current); // Printing the initial location of the user
        bool navigating = true;

        while(navigating) {
            printf("Where would you like to go? (Enter 'end' to stop navigation) ");
            char destination[50];
            scanf("%s", destination);

            if (strcmp(destination, "end") == 0) {
                navigating = false;
                printf("Thank you for using our GPS Navigation Simulation!\n");
            } else {
                bool locationFound = false;
                Node* temp = head;
                while (temp != NULL) {
                    if (strcmp(temp->location, destination) == 0) {
                        locationFound = true;
                        current = temp;
                        break;
                    }
                    temp = temp->next;
                }
                if (!locationFound) {
                    printf("Sorry, we don't have information about that location.\n");
                } else {
                    printf("Directions from %s to %s:\n", startingLocation, current->location);
                    printf("1. Head ");
                    if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("south ");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("north ");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("north ");
                    }
                    printf("on ");
                    if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("Madison Avenue.\n");
                    } else if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("7th Avenue.\n");
                    } else if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("5th Avenue.\n");
                    } else if (strcmp(startingLocation, "Central Park") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("Madison Avenue.\n");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("7th Avenue.\n");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("5th Avenue.\n");
                    } else if (strcmp(startingLocation, "Empire State Building") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("7th Avenue.\n");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("7th Avenue.\n");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("5th Avenue.\n");
                    } else if (strcmp(startingLocation, "Times Square") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("5th Avenue.\n");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("5th Avenue.\n");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("5th Avenue.\n");
                    } else if (strcmp(startingLocation, "Statue of Liberty") == 0 && strcmp(current->location, "Brooklyn Bridge") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Central Park") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Empire State Building") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Times Square") == 0) {
                        printf("1st Avenue.\n");
                    } else if (strcmp(startingLocation, "Brooklyn Bridge") == 0 && strcmp(current->location, "Statue of Liberty") == 0) {
                        printf("1st Avenue.\n");
                    }
                    printLocation(current); // Updating the current location of the user
                }
            }
        }
    }
    return 0;
}