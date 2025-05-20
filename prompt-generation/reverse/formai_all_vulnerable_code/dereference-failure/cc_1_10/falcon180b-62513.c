//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char *name;
    char *date;
    char *time;
    struct appointment *next;
};

void add_appointment(struct appointment **head, char *name, char *date, char *time) {
    struct appointment *new_appointment = malloc(sizeof(struct appointment));
    new_appointment->name = name;
    new_appointment->date = date;
    new_appointment->time = time;
    new_appointment->next = *head;
    *head = new_appointment;
}

void print_appointments(struct appointment *head) {
    while (head!= NULL) {
        printf("Name: %s\nDate: %s\nTime: %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    struct appointment *head = NULL;
    int choice, num_appointments = 0;
    char name[100], date[100], time[100];

    do {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter time (HH:MM): ");
            scanf("%s", time);
            add_appointment(&head, name, date, time);
            num_appointments++;
            break;
        case 2:
            printf("Number of appointments: %d\n", num_appointments);
            print_appointments(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}