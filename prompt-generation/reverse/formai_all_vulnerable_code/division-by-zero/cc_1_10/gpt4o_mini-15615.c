//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int weight; // in kg
    int id; // baggage ID
} Bag;

Bag baggage[MAX_BAGS];
int count = 0;

// Function prototypes
void checkInBag();
void processBaggage();
void displayBaggage();
void surpriseBaggageHandling();
void simulateBaggageDrop();

int main() {
    srand(time(NULL)); // Seed for randomness
    int choice;

    do {
        printf("\nWelcome to the Baggage Handling System!\n");
        printf("1. Check-in Baggage\n");
        printf("2. Process Baggage\n");
        printf("3. Display Baggage\n");
        printf("4. Random Surprise Handling\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                checkInBag();
                break;
            case 2:
                processBaggage();
                break;
            case 3:
                displayBaggage();
                break;
            case 4:
                surpriseBaggageHandling();
                break;
            case 5:
                printf("Thank you for using the Baggage Handling System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void checkInBag() {
    if (count >= MAX_BAGS) {
        printf("Whoa! We're running out of space for bags!\n");
        return;
    }
    printf("Enter baggage name: ");
    scanf("%s", baggage[count].name);
    printf("Enter weight of the baggage (in kg): ");
    scanf("%d", &baggage[count].weight);
    baggage[count].id = count + 1; // Assign ID starting from 1
    count++;
    printf("Bag %s checked in successfully with ID %d!\n", baggage[count - 1].name, baggage[count - 1].id);
}

void processBaggage() {
    if (count == 0) {
        printf("No baggage to process! Please check-in some bags first.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Processing bag ID %d: %s, Weight: %d kg\n", baggage[i].id, baggage[i].name, baggage[i].weight);
        // Randomly determine if there's a mishap
        if (rand() % 10 < 2) { // 20% chance of mishap
            printf("Surprise! Bag %d has been sent to the secret isle!\n", baggage[i].id);
        } else {
            printf("Bag %d processed successfully!\n", baggage[i].id);
        }
    }
}

void displayBaggage() {
    if (count == 0) {
        printf("No baggage to display! It's a barren land!\n");
        return;
    }
    
    printf("Currently checked-in bags:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Weight: %d kg\n", baggage[i].id, baggage[i].name, baggage[i].weight);
    }
}

void surpriseBaggageHandling() {
    printf("🌟 Surprise! It's baggage carnival time! 🌟\n");
    simulateBaggageDrop();
}

void simulateBaggageDrop() {
    int randomDrop = rand() % count;
    printf("We've randomly dropped bag ID %d! Please retrieve it!\n", baggage[randomDrop].id);
}