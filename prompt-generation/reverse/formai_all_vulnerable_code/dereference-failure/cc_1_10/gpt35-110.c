//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

//Appointment structure
typedef struct {
    char* name;
    int day;
    int month;
    int year;
    char* time;
} Appointment;

//Function to add an appointment
void addAppointment(Appointment* appointments, int* appointmentCount) {
    //Checking if the maximum number of appointments have already been scheduled
    if (*appointmentCount >= MAX_APPOINTMENTS) {
        printf("Sorry! Maximum appointments scheduled.\n");
        return;
    }
    
    //Creating appointment pointer using dynamic memory allocation
    Appointment* newAppointment = malloc(sizeof(Appointment));
    newAppointment->name = malloc(20 * sizeof(char));
    newAppointment->time = malloc(10 * sizeof(char));
    
    //User inputs for appointment details
    printf("Enter your name: ");
    scanf("%s", newAppointment->name);
    
    printf("Enter the day (1-31): ");
    scanf("%d", &newAppointment->day);
    
    printf("Enter the month (1-12): ");
    scanf("%d", &newAppointment->month);
    
    printf("Enter the year: ");
    scanf("%d", &newAppointment->year);
    
    printf("Enter the time (e.g. 09:30 AM): ");
    scanf("%s", newAppointment->time);
    
    //Adding the new appointment to the list
    appointments[*appointmentCount] = *newAppointment;
    *appointmentCount += 1;
    
    printf("\nAppointment scheduled successfully!\n");
}

//Function to print all appointments
void printAppointments(Appointment* appointments, int appointmentCount) {
    if (appointmentCount == 0) {
        printf("No appointments found!\n");
        return;
    }
    
    printf("Scheduled Appointments:\n");
    printf("S.no.\tName\tDate\tTime\n");
    for (int i = 0; i < appointmentCount; i++) {
        Appointment appointment = appointments[i];
        printf("%d\t%s\t%d/%d/%d\t%s\n", i+1, appointment.name, 
               appointment.day, appointment.month, appointment.year, appointment.time);
    }
}

//Function to delete an appointment
void deleteAppointment(Appointment* appointments, int* appointmentCount) {
    if (*appointmentCount == 0) {
        printf("No appointments found!\n");
        return;
    }
    
    int appointmentIndex;
    printf("Enter the serial number of the appointment you want to delete: ");
    scanf("%d", &appointmentIndex);
    
    if (appointmentIndex > *appointmentCount || appointmentIndex < 1) {
        printf("Invalid appointment number!\n");
        return;
    }

    //Deleting the appointment from the list by shifting all the elements to the left
    for (int i = appointmentIndex-1; i < *appointmentCount-1; i++) {
        appointments[i] = appointments[i+1];
    }
    *appointmentCount -= 1;
    
    printf("\nAppointment deleted successfully!\n");
}

int main() {
    //Appointment list using dynamic memory allocation
    Appointment* appointments = malloc(MAX_APPOINTMENTS * sizeof(Appointment));
    int appointmentCount = 0;
    
    //Menu for the appointment scheduler
    while (true) {
        printf("\nMenu:\n");
        printf("1. Schedule an appointment\n");
        printf("2. Print all appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Exit\n");
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addAppointment(appointments, &appointmentCount);
                break;
            case 2:
                printAppointments(appointments, appointmentCount);
                break;
            case 3:
                deleteAppointment(appointments, &appointmentCount);
                break;
            case 4:
                printf("\nExiting appointment scheduler.\n");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
}