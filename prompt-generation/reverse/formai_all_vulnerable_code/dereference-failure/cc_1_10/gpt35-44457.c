//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures
typedef struct {
    char* name;
    char* date;
    char* time;
} Appointment;

typedef struct {
    Appointment* appointments;
    int numAppointments;
} AppointmentList;

// Function prototyes
void initializeList(AppointmentList* list);
void addAppointment(AppointmentList* list, char* name, char* date, char* time);
void displayAppointments(AppointmentList* list);

int main() {
    AppointmentList appointmentList;
    initializeList(&appointmentList);
    
    printf("Welcome to the Appointment Scheduler!\n\n");
    
    int choice = 0;
    while (choice != 3) {
        printf("Please choose an option:\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Quit\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                // Get appointment details from user and add to list
                char* name = malloc(sizeof(char) * 50);
                char* date = malloc(sizeof(char) * 20);
                char* time = malloc(sizeof(char) * 20);
                
                printf("\nEnter name: ");
                scanf("%s", name);
                
                printf("Enter date: ");
                scanf("%s", date);
                
                printf("Enter time: ");
                scanf("%s", time);
                
                addAppointment(&appointmentList, name, date, time);
                printf("\nAppointment added!\n\n");
                break;
            }
            
            case 2: {
                // Display all appointments
                printf("\nAppointments:\n");
                displayAppointments(&appointmentList);
                printf("\n");
                break;
            }
            
            case 3: {
                // Quit program
                printf("\nGoodbye!\n");
                break;
            }
            
            default: {
                printf("\nInvalid choice! Please try again.\n\n");
                break;
            }
        }
    }
    
    // Free memory used by list
    for (int i = 0; i < appointmentList.numAppointments; i++) {
        free(appointmentList.appointments[i].name);
        free(appointmentList.appointments[i].date);
        free(appointmentList.appointments[i].time);
    }
    free(appointmentList.appointments);
    
    return 0;
}

void initializeList(AppointmentList* list) {
    list->appointments = NULL;
    list->numAppointments = 0;
}

void addAppointment(AppointmentList* list, char* name, char* date, char* time) {
    // Create new appointment
    Appointment newAppointment;
    newAppointment.name = malloc(sizeof(char) * strlen(name) + 1);
    strcpy(newAppointment.name, name);
    
    newAppointment.date = malloc(sizeof(char) * strlen(date) + 1);
    strcpy(newAppointment.date, date);
    
    newAppointment.time = malloc(sizeof(char) * strlen(time) + 1);
    strcpy(newAppointment.time, time);
    
    // Add appointment to list
    list->numAppointments++;
    list->appointments = realloc(list->appointments, sizeof(Appointment) * list->numAppointments);
    list->appointments[list->numAppointments - 1] = newAppointment;
}

void displayAppointments(AppointmentList* list) {
    for (int i = 0; i < list->numAppointments; i++) {
        printf("%d. %s on %s at %s\n", i+1, list->appointments[i].name, list->appointments[i].date, list->appointments[i].time);
    }
}