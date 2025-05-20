//FormAI DATASET v1.0 Category: Hotel Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    int roomNumber;
    int reservationStatus;
    struct node *next;
} Node;

int main() {
    int numRooms, choice, roomNum, reserveStatus;
    char roomName[50];
    Node *head = NULL;
    
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numRooms);
    
    // initializing the list with empty nodes for each room
    for (int i = 0; i < numRooms; i++) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->roomNumber = i + 1;
        newNode->reservationStatus = 0;
        newNode->next = head;
        head = newNode;
    }
    
    while (1) {
        printf("\n");
        printf("1. Reserve a room\n");
        printf("2. Check reservation status\n");
        printf("3. Cancel reservation\n");
        printf("4. Print room status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the name for the room: ");
                scanf("%s", roomName);
                printf("Enter the room number: ");
                scanf("%d", &roomNum);
                
                Node *temp = head;
                while (temp) {
                    if (temp->roomNumber == roomNum) {
                        if (temp->reservationStatus) {
                            printf("Sorry, the room is already reserved.\n");
                        } else {
                            strcpy(temp->name, roomName);
                            temp->reservationStatus = 1;
                            printf("Room %d has been reserved.\n", temp->roomNumber);
                        }
                        break;
                    }
                    temp = temp->next;
                }
                if (!temp) {
                    printf("Invalid room number.\n");
                }
                break;
                
            case 2:
                printf("Enter the room number: ");
                scanf("%d", &roomNum);
                
                temp = head;
                while (temp) {
                    if (temp->roomNumber == roomNum) {
                        if (temp->reservationStatus) {
                            printf("Room %d is reserved by %s.\n", temp->roomNumber, temp->name);
                        } else {
                            printf("Room %d is available.\n", temp->roomNumber);
                        }
                        break;
                    }
                    temp = temp->next;
                }
                if (!temp) {
                    printf("Invalid room number.\n");
                }
                break;
                
            case 3:
                printf("Enter the room number to cancel reservation: ");
                scanf("%d", &roomNum);
                
                temp = head;
                while (temp) {
                    if (temp->roomNumber == roomNum) {
                        if (temp->reservationStatus) {
                            strcpy(temp->name, "");
                            temp->reservationStatus = 0;
                            printf("Reservation for room %d has been cancelled.\n", temp->roomNumber);
                        } else {
                            printf("There is no reservation for room %d.\n", temp->roomNumber);
                        }
                        break;
                    }
                    temp = temp->next;
                }
                if (!temp) {
                    printf("Invalid room number.\n");
                }
                break;
                
            case 4:
                printf("Room Status:\n");
                printf("Room Number     Name         Reservation Status\n");
                printf("---------------------------------------------------\n");
                temp = head;
                while (temp) {
                    printf("%-15d%-13s", temp->roomNumber, temp->name);
                    if (temp->reservationStatus) {
                        printf("Reserved\n");
                    } else {
                        printf("Available\n");
                    }
                    temp = temp->next;
                }
                break;
                
            case 5:
                exit(0);
                
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}