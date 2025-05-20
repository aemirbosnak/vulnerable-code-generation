//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for storing appointment details
typedef struct {
    char date[20];
    char time[20];
    char patient[50];
    int room;
} Appointment;

// function to display menu options
void display_menu() {
    printf("\n***** Appointment Scheduler *****\n");
    printf("1. Add appointment\n");
    printf("2. View appointment\n");
    printf("3. Update appointment\n");
    printf("4. Delete appointment\n");
    printf("5. Exit\n");
}

// function to add an appointment
void add_appointment(Appointment ***appointments, int *num_appointments) {
    int room;
    char date[20], time[20], patient[50];
    printf("\nEnter appointment details:\n");
    printf("Date: ");
    scanf("%s", date);
    printf("Time: ");
    scanf("%s", time);
    printf("Patient name: ");
    scanf("%s", patient);
    printf("Room number: ");
    scanf("%d", &room);
    // allocate memory for new appointment
    (*num_appointments)++;
    (*appointments) = (Appointment **)realloc(*appointments, (*num_appointments)*sizeof(Appointment *));
    (*appointments)[(*num_appointments)-1] = (Appointment *)malloc(sizeof(Appointment));
    // copy details into new appointment
    strcpy((*appointments)[(*num_appointments)-1]->date, date);
    strcpy((*appointments)[(*num_appointments)-1]->time, time);
    strcpy((*appointments)[(*num_appointments)-1]->patient, patient);
    (*appointments)[(*num_appointments)-1]->room = room;
    printf("\nAppointment added successfully!\n");
}

// function to view all appointments
void view_appointments(Appointment **appointments, int num_appointments) {
    printf("\nAll appointments:\n");
    for (int i=0; i<num_appointments; i++) {
        printf("\nAppointment #%d:\n", i+1);
        printf("Date: %s\n", appointments[i]->date);
        printf("Time: %s\n", appointments[i]->time);
        printf("Patient name: %s\n", appointments[i]->patient);
        printf("Room number: %d\n", appointments[i]->room);
    }
}

// function to update an existing appointment
void update_appointment(Appointment **appointments, int num_appointments) {
    int appointment_num, option;
    printf("\nEnter appointment number to update: ");
    scanf("%d", &appointment_num);
    if (appointment_num<1 || appointment_num>num_appointments) {
        printf("\nInvalid appointment number!\n");
        return;
    }
    printf("\nAppointment #%d:\n", appointment_num);
    printf("1. Date: %s\n", appointments[appointment_num-1]->date);
    printf("2. Time: %s\n", appointments[appointment_num-1]->time);
    printf("3. Patient name: %s\n", appointments[appointment_num-1]->patient);
    printf("4. Room number: %d\n", appointments[appointment_num-1]->room);
    printf("\nEnter option to update: ");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Enter new date: ");
            scanf("%s", appointments[appointment_num-1]->date);
            break;
        case 2:
            printf("Enter new time: ");
            scanf("%s", appointments[appointment_num-1]->time);
            break;
        case 3:
            printf("Enter new patient name: ");
            scanf("%s", appointments[appointment_num-1]->patient);
            break;
        case 4:
            printf("Enter new room number: ");
            scanf("%d", &appointments[appointment_num-1]->room);
            break;
        default:
            printf("\nInvalid option!\n");
    }
    printf("\nAppointment updated successfully!\n");
}

// function to delete an existing appointment
void delete_appointment(Appointment ***appointments, int *num_appointments) {
    int appointment_num;
    printf("\nEnter appointment number to delete: ");
    scanf("%d", &appointment_num);
    if (appointment_num<1 || appointment_num>*num_appointments) {
        printf("\nInvalid appointment number!\n");
        return;
    }
    // move all appointments after the deleted one up one index
    for (int i=appointment_num-1; i<*num_appointments-1; i++) {
        (*appointments)[i] = (*appointments)[i+1];
    }
    // free memory of last appointment
    free((*appointments)[*num_appointments-1]);
    // reduce the number of appointments
    (*num_appointments)--;
    // reallocate memory for the new number of appointments
    (*appointments) = (Appointment **)realloc(*appointments, (*num_appointments)*sizeof(Appointment *));
    printf("\nAppointment deleted successfully!\n");
}

int main() {
    int option, num_appointments=0;
    Appointment **appointments = NULL;
    do {
        display_menu();
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_appointment(&appointments, &num_appointments);
                break;
            case 2:
                if (num_appointments==0) {
                    printf("\nNo appointments to view!\n");
                    break;
                }
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                if (num_appointments==0) {
                    printf("\nNo appointments to update!\n");
                    break;
                }
                update_appointment(appointments, num_appointments);
                break;
            case 4:
                if (num_appointments==0) {
                    printf("\nNo appointments to delete!\n");
                    break;
                }
                delete_appointment(&appointments, &num_appointments);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    } while (option!=5);
    // free memory of remaining appointments
    for (int i=0; i<num_appointments; i++) {
        free(appointments[i]);
    }
    // free memory of array of pointers
    free(appointments);
    return 0;
}