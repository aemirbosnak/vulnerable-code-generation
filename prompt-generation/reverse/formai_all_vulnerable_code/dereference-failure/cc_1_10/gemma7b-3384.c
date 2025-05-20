//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGER_NAME_LENGTH 50
#define MAX_Luggage_PIECE_NUMBER 10

typedef struct Passenger {
    char name[MAX_PASSENGER_NAME_LENGTH];
    int numLuggagePieces;
    struct Passenger* next;
} Passenger;

typedef struct LuggagPiece {
    char description[MAX_PASSENGER_NAME_LENGTH];
    int weight;
    struct LuggagPiece* next;
} LuggagPiece;

void addPassenger(Passenger** head, char* name, int numLuggagePieces) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numLuggagePieces = numLuggagePieces;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void addLuggagePiece(LuggagPiece** head, char* description, int weight) {
    LuggagPiece* newLuggagePiece = malloc(sizeof(LuggagPiece));
    strcpy(newLuggagePiece->description, description);
    newLuggagePiece->weight = weight;
    newLuggagePiece->next = NULL;

    if (*head == NULL) {
        *head = newLuggagePiece;
    } else {
        (*head)->next = newLuggagePiece;
    }
}

void handleBaggage(Passenger* passenger) {
    printf("Passenger name: %s\n", passenger->name);
    printf("Number of luggage pieces: %d\n", passenger->numLuggagePieces);

    LuggagPiece* luggagePiece = passenger->numLuggagePieces ? passenger->numLuggagePieces : NULL;
    while (luggagePiece) {
        printf("Luggage piece description: %s\n", luggagePiece->description);
        printf("Luggage piece weight: %d\n", luggagePiece->weight);
        luggagePiece = luggagePiece->next;
    }
}

int main() {
    Passenger* head = NULL;
    LuggagPiece* luggageHead = NULL;

    addPassenger(&head, "John Doe", 3);
    addLuggagePiece(&luggageHead, "Suitcase", 20);
    addLuggagePiece(&luggageHead, "Handbag", 10);
    addLuggagePiece(&luggageHead, "Backpack", 15);

    handleBaggage(head);

    return 0;
}