//FormAI DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DigitalDiary {
    char date[20];
    char event[100];
    struct DigitalDiary *next;
};

typedef struct DigitalDiary diary;

// function to add an event to the digital diary
void addEvent(diary **head, char* date, char* event) {
    diary *newEvent = (diary*) malloc(sizeof(diary));
    strcpy(newEvent->date, date);
    strcpy(newEvent->event, event);
    newEvent->next = NULL;

    if (*head == NULL) {
        *head = newEvent;
    } else {
        diary *last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newEvent;
    }
}

// function to print all the events in the digital diary
void printDiary(diary *head) {
    diary *temp = head;
    printf("\nDate\t    Event\n");
    while (temp != NULL) {
        printf("%s\t%s\n", temp->date, temp->event);
        temp = temp->next;
    }
}

int main() {
    diary *head = NULL;
    int num_players, choice;
    char date[20], event[100];

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    while (num_players >= 1) {
        printf("\nPlayer %d's turn\n", num_players);
        printf("1. Add an event\n");
        printf("2. Print the diary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the date of the event (dd/mm/yyyy): ");
            scanf("%s", date);
            printf("Enter the event: ");
            scanf("%s", event);

            addEvent(&head, date, event);
            printf("\nEvent added to the diary!\n");
        } else if (choice == 2) {
            printDiary(head);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid input!\n");
        }
        
        num_players--;
    }

    return 0;
}