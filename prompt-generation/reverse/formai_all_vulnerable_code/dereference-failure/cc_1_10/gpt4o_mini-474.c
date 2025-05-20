//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 100
#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char description[MAX_DESC];
    char date[11]; // Format: YYYY-MM-DD
} Apt;

Apt *scheduler[MAX_APPOINTMENTS];
int count = 0;

void addAppointment() {
    if (count >= MAX_APPOINTMENTS) {
        printf("Scheduler is full!\n");
        return;
    }
    scheduler[count] = (Apt *)malloc(sizeof(Apt));
    printf("Enter the description of the appointment: ");
    getchar(); // To consume newline
    fgets(scheduler[count]->description, MAX_DESC, stdin);
    scheduler[count]->description[strcspn(scheduler[count]->description, "\n")] = 0; // Remove newline
    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf("%10s", scheduler[count]->date);
    count++;
    printf("Appointment added!\n");
}

void viewAppointments() {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s on %s\n", i + 1, scheduler[i]->description, scheduler[i]->date);
    }
}

void deleteAppointment() {
    if (count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > count) {
        printf("Invalid appointment number.\n");
        return;
    }
    free(scheduler[index - 1]);
    for (int i = index - 1; i < count - 1; i++) {
        scheduler[i] = scheduler[i + 1];
    }
    count--;
    printf("Appointment deleted!\n");
}

void menu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addAppointment(); break;
            case 2: viewAppointments(); break;
            case 3: deleteAppointment(); break;
            case 4: 
                printf("Exiting...\n");
                for (int i = 0; i < count; i++) {
                    free(scheduler[i]);
                }
                exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}