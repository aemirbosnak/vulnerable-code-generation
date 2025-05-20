//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[50];
    char date[10];
    char time[6];
};

struct node {
    struct appointment data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void addAppointment() {
    struct appointment newAppointment;
    printf("\nEnter name: ");
    scanf("%s", newAppointment.name);
    printf("\nEnter date (mm/dd): ");
    scanf("%s", newAppointment.date);
    printf("\nEnter time (hh:mm): ");
    scanf("%s", newAppointment.time);

    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = newAppointment;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        current->next = newNode;
        current = newNode;
    }

    printf("\nAppointment added successfully!\n");
}

void printAppointments() {
    if (head == NULL) {
        printf("\nNo appointments yet!");
    } else {
        printf("\nAll Appointments");
        printf("\n----------------");
        struct node *temp = head;
        while (temp != NULL) {
            printf("\nName: %s", temp->data.name);
            printf("\nDate: %s", temp->data.date);
            printf("\nTime: %s\n", temp->data.time);
            temp = temp->next;
        }
    }
}

void deleteAppointment() {
    if (head == NULL) {
        printf("\nNo appointments yet!");
    } else {
        printf("\nEnter date (mm/dd) of appointment to be deleted: ");
        char dateToDelete[10];
        scanf("%s", dateToDelete);
        struct node *temp = head;
        struct node *prev = NULL;
        while (temp != NULL) {
            if (strcmp(temp->data.date, dateToDelete) == 0) {
                printf("\n%s's appointment on %s at %s has been deleted!", temp->data.name, temp->data.date, temp->data.time);
                if (prev == NULL) {
                    head = temp->next;
                    free(temp);
                    break;
                } else {
                    prev->next = temp->next;
                    free(temp);
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    int option;

    while (1) {
        printf("\n\nAppointment Scheduler");
        printf("\n---------------------");
        printf("\n1) Add Appointment");
        printf("\n2) View Appointments");
        printf("\n3) Delete Appointment");
        printf("\n4) Exit");
        printf("\n\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addAppointment();
                break;
            case 2:
                printAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option! Please try again.");
                break;
        }
    }
    return 0;
}