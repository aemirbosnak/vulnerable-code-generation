//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for Appointment
typedef struct Appointment {
    char date[11];
    char time[6];
    char name[50];
    char reason[100];
} Appointment;

// function to retrieve the appointments from file
int getAppointments(Appointment **appointments, int *numAppointments) {
    *numAppointments = 0;
    char line[200], *token;
    FILE *file = fopen("appointments.txt", "r");
    while (fgets(line, sizeof(line), file)) {
        (*numAppointments)++;
    }
    fclose(file);

    file = fopen("appointments.txt", "r");
    *appointments = malloc((*numAppointments) * sizeof(Appointment));
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        strcpy((*appointments)[count].date, token);
        token = strtok(NULL, ",");
        strcpy((*appointments)[count].time, token);
        token = strtok(NULL, ",");
        strcpy((*appointments)[count].name, token);
        token = strtok(NULL, "\n");
        strcpy((*appointments)[count].reason, token);
        count++;
    }
    fclose(file);

    return 0;
}

// function to add a new appointment
int addAppointment() {
    char date[11], time[6], name[50], reason[100];
    printf("Enter the date of appointment (mm/dd/yyyy): ");
    scanf("%s", date);
    printf("Enter the time of appointment (hh:mm): ");
    scanf("%s", time);
    printf("Enter patient name: ");
    scanf("%s", name);
    printf("Enter the reason for the appointment: ");
    scanf("%s", reason);

    FILE *file;
    file = fopen("appointments.txt", "a");
    fprintf(file, "%s,%s,%s,%s\n", date, time, name, reason);
    fclose(file);

    printf("Appointment scheduled successfully!\n");
    return 0;
}

// function to delete an appointment
int deleteAppointment() {
    char date[11], time[6], name[50];
    printf("Enter the date of appointment to delete (mm/dd/yyyy): ");
    scanf("%s", date);
    printf("Enter the time of appointment to delete (hh:mm): ");
    scanf("%s", time);
    printf("Enter patient name: ");
    scanf("%s", name);

    char line[200], *token;
    int count = 0;
    FILE *file = fopen("appointments.txt", "r");
    int numAppointments = 0;
    while (fgets(line, sizeof(line), file)) {
        numAppointments++;
    }
    fclose(file);

    Appointment *appointments = malloc(numAppointments * sizeof(Appointment));
    file = fopen("appointments.txt", "r");
    count = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        strcpy(appointments[count].date, token);
        token = strtok(NULL, ",");
        strcpy(appointments[count].time, token);
        token = strtok(NULL, ",");
        strcpy(appointments[count].name, token);
        token = strtok(NULL, "\n");
        strcpy(appointments[count].reason, token);
        count++;
    }
    fclose(file);

    int i, found = -1;
    for (i = 0; i < numAppointments; i++) {
        if (!strcmp(appointments[i].date, date) && !strcmp(appointments[i].time, time) && !strcmp(appointments[i].name, name)) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Appointment not found!\n");
        return -1;
    }

    file = fopen("appointments.txt", "w");
    for (i = 0; i < numAppointments; i++) {
        if (i != found) {
            fprintf(file, "%s,%s,%s,%s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].reason);
        }
    }
    fclose(file);

    printf("Appointment deleted successfully!\n");
    return 0;
}

// function to display all the appointments
int displayAppointments() {
    Appointment *appointments;
    int numAppointments;
    getAppointments(&appointments, &numAppointments);
    int i;
    printf("Date\t\tTime\t\tPatient Name\tReason\n");
    for (i = 0; i < numAppointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].reason);
    }
    free(appointments);

    return 0;
}

// main function
int main() {
    int option = 0;
    while (option != 4) {
        printf("\n\n\nAppointment Scheduler\n\n1. Schedule a new appointment\n2. Delete an appointment\n3. Display all appointments\n4. Quit\n\nSelect an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addAppointment();
                break;
            case 2:
                deleteAppointment();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}