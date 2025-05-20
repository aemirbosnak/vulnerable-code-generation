//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    int hour;
    char name[100];
};

void addAppointment(struct appointment *appts, int *numAppts);
void removeAppointment(struct appointment *appts, int *numAppts);
void printAppointments(struct appointment *appts, int numAppts);

int main() {
    struct appointment appts[100];
    int numAppts = 0;
    int choice = 0;

    while (choice != 4) {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Remove Appointment\n");
        printf("3. Print Appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addAppointment(appts, &numAppts);
                break;
            case 2:
                removeAppointment(appts, &numAppts);
                break;
            case 3:
                printAppointments(appts, numAppts);
                break;
            case 4:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}

void addAppointment(struct appointment *appts, int *numAppts) {
    int hour;
    char name[100];

    printf("Enter hour (0-23): ");
    scanf("%d", &hour);

    if (hour < 0 || hour > 23) {
        printf("Invalid hour. Please try again.\n\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", name);

    appts[*numAppts].hour = hour;
    strcpy(appts[*numAppts].name, name);
    (*numAppts)++;

    printf("Appointment added!\n\n");
}

void removeAppointment(struct appointment *appts, int *numAppts) {
    int index;
    int hour;

    printf("Enter hour of appointment to remove: ");
    scanf("%d", &hour);

    for (int i = 0; i < *numAppts; i++) {
        if (appts[i].hour == hour) {
            index = i;
            break;
        } else if (i == *numAppts - 1) {
            printf("No appointment at that hour.\n\n");
            return;
        }
    }

    for (int i = index; i < *numAppts - 1; i++) {
        appts[i] = appts[i+1];
    }
    (*numAppts)--;
    printf("Appointment removed!\n\n");
}

void printAppointments(struct appointment *appts, int numAppts) {
    printf("Appointments:\n");
    for (int i = 0; i < numAppts; i++) {
        printf("%d: %s\n", appts[i].hour, appts[i].name);
    }
    printf("\n");
}