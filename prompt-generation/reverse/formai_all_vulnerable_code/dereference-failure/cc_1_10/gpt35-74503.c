//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define appointment structure
struct Appointment {
    int day; // day of the appointment
    int month; // month of the appointment
    int year; // year of the appointment
    int hour; // hour of the appointment
    int minute; // minute of the appointment
    char description[100]; // description of the appointment
};

// function prototypes
void scheduleAppointment(struct Appointment **appointments, int *numAppointments);
void printAppointments(struct Appointment *appointments, int numAppointments);

int main() {

    // seed random number generator
    srand(time(NULL));

    // declare variables
    struct Appointment *appointments = NULL;
    int numAppointments = 0, option;

    // print menu of options
    printf("1. Schedule appointment\n");
    printf("2. Print appointments\n");
    printf("3. Exit\n");

    // loop until user selects the exit option
    do {
        // prompt user to select an option
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                scheduleAppointment(&appointments, &numAppointments);
                break;
            case 2:
                printAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    // free memory used by appointments
    free(appointments);

    return 0;
}

// function to schedule a new appointment
void scheduleAppointment(struct Appointment **appointments, int *numAppointments) {
    struct Appointment newAppointment;

    // prompt user for appointment details
    printf("Enter date of appointment (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &newAppointment.month, &newAppointment.day, &newAppointment.year);

    printf("Enter time of appointment (hh:mm): ");
    scanf("%d:%d", &newAppointment.hour, &newAppointment.minute);

    printf("Enter description of appointment: ");
    scanf(" %[^\n]", newAppointment.description);

    // resize array to hold new appointment
    (*numAppointments)++;
    (*appointments) = (struct Appointment*) realloc((*appointments), (*numAppointments) * sizeof(struct Appointment));

    // add new appointment to array
    (*appointments)[(*numAppointments) - 1] = newAppointment;

    printf("Appointment scheduled successfully!\n");
}

// function to print all appointments
void printAppointments(struct Appointment *appointments, int numAppointments) {
    int i;

    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("%-12s %-7s %-12s %-15s %s\n", "DATE", "TIME", "DAY", "MONTH", "DESCRIPTION");
        for (i = 0; i < numAppointments; i++) {
            printf("%02d/%02d/%d   %02d:%02d   %s    %d        %s\n",
                appointments[i].month, appointments[i].day, appointments[i].year,
                appointments[i].hour, appointments[i].minute,
                (appointments[i].year % 4 == 0 && appointments[i].year % 100 != 0 || appointments[i].year % 400 == 0) ? "LEAP YEAR" : "REGULAR YEAR",
                appointments[i].month,
                appointments[i].description);
        }
    }
}