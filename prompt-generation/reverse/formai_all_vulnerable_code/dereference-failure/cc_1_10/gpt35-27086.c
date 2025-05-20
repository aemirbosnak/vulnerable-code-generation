//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment{
    char name[20];
    char date[20];
    char time[10];
    int id;
};

typedef struct appointment Appointment;

void display_menu();
void make_appointment(Appointment **, int *);
void cancel_appointment(Appointment **, int *);

int main(){
    int num_appointments = 0;
    Appointment *appointments = NULL;
    display_menu();
    char choice;
    while(scanf(" %c", &choice) == 1){
        switch(choice){
            case '1':
                make_appointment(&appointments, &num_appointments);
                break;
            case '2':
                cancel_appointment(&appointments, &num_appointments);
                break;
            case '3':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
        display_menu();
    }
    return 0;
}

void display_menu(){
    printf("\n    --- Appointment Scheduler ---\n\n");
    printf("Enter 1 to schedule an appointment\n");
    printf("Enter 2 to cancel an appointment\n");
    printf("Enter 3 to exit the program\n");
}

void make_appointment(Appointment **appointments, int *num_appointments){
    Appointment new_appt;
    printf("\n    --- Scheduling New Appointment ---\n\n");
    printf("Enter name: ");
    scanf("%s", new_appt.name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", new_appt.date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", new_appt.time);
    new_appt.id = (*num_appointments)++;
    *appointments = realloc(*appointments, *num_appointments * sizeof(Appointment));
    (*appointments)[new_appt.id] = new_appt;
    printf("\nAppointment scheduled successfully. Your appointment ID is %d\n", new_appt.id);
}

void cancel_appointment(Appointment **appointments, int *num_appointments){
    if(*num_appointments == 0){
        printf("\nThere are no appointments to cancel.\n");
        return;
    }
    printf("\n    --- Cancelling an Appointment ---\n\n");
    printf("Enter appointment ID to cancel: ");
    int id;
    scanf("%d", &id);
    if(id >= *num_appointments || id < 0){
        printf("\nInvalid appointment ID. No appointment was cancelled.\n");
        return;
    }
    char response[5];
    printf("Are you sure you want to cancel appointment %d? (Y/N): ", id);
    scanf("%s", response);
    if(strcmp(response, "Y") == 0 || strcmp(response, "y") == 0){
        for(int i=id; i<*num_appointments-1; i++){
            (*appointments)[i] = (*appointments)[i+1];
            (*appointments)[i].id = i;
        }
        (*num_appointments)--;
        *appointments = realloc(*appointments, *num_appointments * sizeof(Appointment));
        printf("\nAppointment %d cancelled successfully.\n", id);
    }
    else{
        printf("\nNo appointment was cancelled.\n");
    }
}