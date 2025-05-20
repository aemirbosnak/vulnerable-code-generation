//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 30
#define MAX_APPOINTMENTS 5

struct Appointment {
    char date[MAX_SIZE];
    char time[MAX_SIZE];
    char patient_name[MAX_SIZE];
    char doctor_name[MAX_SIZE];
    char reason[MAX_SIZE];
};

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_SIZE];
    int count = 0;

    printf("Welcome to the Appointment Scheduler!\n");

    while (1) {
        printf("\nEnter 1 to add an appointment\nEnter 2 to view all appointments\nEnter 3 to exit\n");
        fgets(input, MAX_SIZE, stdin);

        if (input[0] == '1' && strlen(input) == 2) {
            printf("\nPlease enter the date of the appointment (example: 01/01/2022): ");
            fgets(appointments[count].date, MAX_SIZE, stdin);

            printf("Please enter the time of the appointment (example: 2:30 PM): ");
            fgets(appointments[count].time, MAX_SIZE, stdin);

            printf("Please enter the patient's name: ");
            fgets(appointments[count].patient_name, MAX_SIZE, stdin);

            printf("Please enter the doctor's name: ");
            fgets(appointments[count].doctor_name, MAX_SIZE, stdin);

            printf("Please enter the reason for the appointment: ");
            fgets(appointments[count].reason, MAX_SIZE, stdin);

            count++;
            printf("\nAppointment successfully added!\n");
        } else if (input[0] == '2' && strlen(input) == 2) {
            if (count == 0) {
                printf("\nNo appointments to display!\n");
            } else {
                printf("\nAll Appointments:\n");
                for (int i = 0; i < count; i++) {
                    printf("\nAppointment #%d:\n", i + 1);
                    printf("Date: %s", appointments[i].date);
                    printf("Time: %s", appointments[i].time);
                    printf("Patient's Name: %s", appointments[i].patient_name);
                    printf("Doctor's Name: %s", appointments[i].doctor_name);
                    printf("Reason: %s", appointments[i].reason);
                }
            }
        } else if (input[0] == '3' && strlen(input) == 2) {
            printf("\nThank you for using the Appointment Scheduler!\n");
            return 0;
        } else {
            printf("\nInvalid input. Please try again!\n");
        }   
    }
}