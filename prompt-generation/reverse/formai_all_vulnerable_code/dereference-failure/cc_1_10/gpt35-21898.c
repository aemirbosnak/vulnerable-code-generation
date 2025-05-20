//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct appointment {
    int day;
    int month;
    int year;
    char* name;
    char* description;
} Appointment;

void addAppointment(Appointment** appointmentList, int* numAppointments) {
    // Increase the size of the appointment list array
    *numAppointments += 1;
    *appointmentList = (Appointment*)realloc(*appointmentList, *numAppointments * sizeof(Appointment));

    // Get the appointment details from the user
    printf("Enter appointment day:");
    scanf("%d", &((*appointmentList)[*numAppointments - 1].day));
    printf("Enter appointment month:");
    scanf("%d", &((*appointmentList)[*numAppointments - 1].month));
    printf("Enter appointment year:");
    scanf("%d", &((*appointmentList)[*numAppointments - 1].year));
    printf("Enter appointment name:");
    char name[50];
    scanf("%s", name);
    (*appointmentList)[*numAppointments - 1].name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy((*appointmentList)[*numAppointments - 1].name, name);
    printf("Enter appointment description:");
    char description[100];
    scanf(" %[^\n]s", description);
    (*appointmentList)[*numAppointments - 1].description = (char*)malloc((strlen(description) + 1) * sizeof(char));
    strcpy((*appointmentList)[*numAppointments - 1].description, description);

    printf("Appointment added!\n");
}

void listAppointments(Appointment* appointmentList, int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments!\n");
        return;
    }

    printf("Appointments:\n");
    printf("Date\t\t\tName\t\t\tDescription\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%02d/%02d/%04d\t\t%s\t\t%s\n", appointmentList[i].day, appointmentList[i].month, appointmentList[i].year, appointmentList[i].name, appointmentList[i].description);
    }
}

void deleteAppointment(Appointment** appointmentList, int* numAppointments) {
    if (*numAppointments == 0) {
        printf("No appointments to delete!\n");
        return;
    }

    int day, month, year;
    printf("Enter the date of the appointment to delete:\n");
    printf("Day:");
    scanf("%d", &day);
    printf("Month:");
    scanf("%d", &month);
    printf("Year:");
    scanf("%d", &year);

    int indexToDelete = -1;
    for (int i = 0; i < *numAppointments; i++) {
        if (day == (*appointmentList)[i].day && month == (*appointmentList)[i].month && year == (*appointmentList)[i].year) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("No appointment found with the specified date!\n");
        return;
    }

    // Free memory of the appointment being deleted
    free((*appointmentList)[indexToDelete].name);
    (*appointmentList)[indexToDelete].name = NULL;
    free((*appointmentList)[indexToDelete].description);
    (*appointmentList)[indexToDelete].description = NULL;

    // Shift all the elements after the deleted appointment one place to the left
    for (int i = indexToDelete; i < *numAppointments - 1; i++) {
        (*appointmentList)[i] = (*appointmentList)[i + 1];
    }

    // Reduce the size of the appointment list array
    *numAppointments -= 1;
    *appointmentList = (Appointment*)realloc(*appointmentList, *numAppointments * sizeof(Appointment));

    printf("Appointment deleted!\n");
}

int main() {
    Appointment* appointmentList = NULL;
    int numAppointments = 0;
    int choice;

    do {
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. Add appointment\n");
        printf("2. List appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(&appointmentList, &numAppointments);
                break;

            case 2:
                listAppointments(appointmentList, numAppointments);
                break;

            case 3:
                deleteAppointment(&appointmentList, &numAppointments);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    // Free memory allocated to appointmentList
    for (int i = 0; i < numAppointments; i++) {
        free(appointmentList[i].name);
        free(appointmentList[i].description);
    }
    if (appointmentList) {
        free(appointmentList);
    }

    printf("Goodbye!\n");

    return 0;
}