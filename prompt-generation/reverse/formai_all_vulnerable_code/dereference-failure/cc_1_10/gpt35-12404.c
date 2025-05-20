//FormAI DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int roomNumber;
    int daysStayed;
    float totalCost;
    struct guest *next;
};

typedef struct guest Guest;

Guest *head = NULL;

void addGuest(char *name, int roomNumber, int daysStayed, float totalCost) {
    Guest *newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->roomNumber = roomNumber;
    newGuest->daysStayed = daysStayed;
    newGuest->totalCost = totalCost;
    newGuest->next = NULL;

    if(head == NULL) {
        head = newGuest;

        printf("\n%s added to the system!\n", name);
    } else {
        Guest *temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newGuest;

        printf("\n%s added to the system!\n", name);
    }
}

void displayGuests() {
    if(head == NULL) {
        printf("\nNo guests in the system!\n");
    } else {
        printf("----------------------------------------------\n");
        printf("Name\tRoom No.\tDays\tTotal Cost\n");
        printf("----------------------------------------------\n");

        Guest *temp = head;

        while(temp != NULL) {
            printf("%s \t%d \t%d \t%.2f\n", temp->name, temp->roomNumber, temp->daysStayed, temp->totalCost);
            temp = temp->next;
        }

        printf("----------------------------------------------\n");
    }
}

int main() {
    int choice;
    char name[50];
    int roomNumber;
    int daysStayed;
    float totalCost;

    do {
        printf("1. Add guest\n");
        printf("2. Display guests\n");
        printf("3. Exit\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter guest name: ");
                scanf("%s", name);
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter number of days stayed: ");
                scanf("%d", &daysStayed);
                printf("Enter total cost: ");
                scanf("%f", &totalCost);

                addGuest(name, roomNumber, daysStayed, totalCost);
                break;

            case 2:
                displayGuests();
                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}