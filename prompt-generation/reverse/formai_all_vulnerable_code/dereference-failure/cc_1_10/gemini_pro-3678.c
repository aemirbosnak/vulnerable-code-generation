//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node {
    int year;
    char *event;
    struct Node *next;
} Node;

Node *head = NULL;

void addNode(int year, char *event) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->year = year;
    newNode->event = event;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d: %s\n", temp->year, temp->event);
        temp = temp->next;
    }
}

void freeList() {
    Node *temp = head;
    while (temp != NULL) {
        head = temp->next;
        free(temp->event);
        free(temp);
        temp = head;
    }
}

int main() {
    srand(time(NULL));

    addNode(1955, "A");
    addNode(1969, "B");
    addNode(1985, "C");
    addNode(2001, "D");
    addNode(2015, "E");

    int currentYear = 2023;
    int steps = 3;

    printf("Current year: %d\n", currentYear);
    printf("Steps: %d\n", steps);

    while (steps > 0) {
        // Randomly choose a direction to travel in time
        int direction = rand() % 2;

        // Decrement or increment the current year based on the direction chosen
        if (direction == 0) {
            currentYear--;
        } else {
            currentYear++;
        }

        // Find the event that occurred in the current year
        Node *temp = head;
        while (temp != NULL) {
            if (temp->year == currentYear) {
                // Print the event that occurred in the current year
                printf("Year: %d, Event: %s\n", temp->year, temp->event);

                // Decrement the number of steps remaining
                steps--;

                // Break out of the loop
                break;
            }
            temp = temp->next;
        }

        // If the current year is less than the first year in the list, reset the current year to the first year
        if (currentYear < 1955) {
            currentYear = 1955;
        }

        // If the current year is greater than the last year in the list, reset the current year to the last year
        if (currentYear > 2015) {
            currentYear = 2015;
        }
    }

    freeList();

    return 0;
}