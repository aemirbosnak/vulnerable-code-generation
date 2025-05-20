//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Node structure for linked list
 */
typedef struct Node {
    char name[20];
    int time;
    struct Node* next;
} Node;

/*
 * Function to add new node to the linked list
 */
void addNode(Node** head, char* name, int time) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->time = time;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
    }
    else {
        Node* current = *head;
        while(current->next != NULL && current->next->time < time) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    printf("\nAppointment scheduled for %s at %d:00", name, time);
}

/*
 * Function to display the contents of the linked list
 */
void displayList(Node* head) {
    if(head == NULL) {
        printf("\nNo appointments scheduled.");
    }
    else {
        printf("\nAppointments:");
        while(head != NULL) {
            printf("\n%s - %d:00", head->name, head->time);
            head = head->next;
        }
    }
}

/*
 * Function to remove node from the linked list based on name
 */
void removeNode(Node** head, char* name) {
    if(*head == NULL) {
        printf("\nNo appointments scheduled.");
    }
    else {
        Node* current = *head;
        Node* previous = NULL;
        bool found = false;
        while(current != NULL) {
            if(strcmp(current->name, name) == 0) {
                found = true;
                break;
            }
            previous = current;
            current = current->next;
        }
        if(!found) {
            printf("\nAppointment for %s not found.", name);
        }
        else {
            if(previous == NULL) {
                *head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("\nAppointment for %s has been removed.", name);
        }
    }
}

int main() {
    Node* head = NULL;
    int choice;
    char name[20];
    int time;
    do {
        printf("\n\nAppointment scheduler");
        printf("\n1. Schedule an appointment");
        printf("\n2. Display scheduled appointments");
        printf("\n3. Cancel an appointment");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter name of patient: ");
                scanf("%s", name);
                printf("\nEnter appointment time (9-16): ");
                scanf("%d", &time);
                if(time < 9 || time > 16) {
                    printf("Invalid time. Please enter time between 9 and 16");
                }
                else {
                    addNode(&head, name, time);
                }
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("\nEnter name of patient to cancel appointment: ");
                scanf("%s", name);
                removeNode(&head, name);
                break;
            case 4:
                printf("\nExiting program.");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.");
                break;
        }
    } while(choice != 4);
    return 0;
}