//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 100

typedef struct Guest {
    char name[50];
    int room_no;
    float bill;
    struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", newGuest->name);
    printf("Enter room number: ");
    scanf("%d", &newGuest->room_no);
    printf("Enter bill: ");
    scanf("%f", &newGuest->bill);

    newGuest->next = NULL;

    if (head == NULL) {
        head = newGuest;
    } else {
        Guest* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newGuest;
    }

    return head;
}

void printGuests(Guest* head) {
    Guest* temp = head;
    while (temp) {
        printf("Name: %s, Room No: %d, Bill: %.2f\n", temp->name, temp->room_no, temp->bill);
        temp = temp->next;
    }
}

int main() {
    Guest* head = NULL;

    char choice;

    do {
        printf("Enter choice: (I/P/Q): ");
        scanf("%c", &choice);

        switch (choice) {
            case 'I':
                head = insertGuest(head);
                break;
            case 'P':
                printGuests(head);
                break;
            case 'Q':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'Q');

    return 0;
}