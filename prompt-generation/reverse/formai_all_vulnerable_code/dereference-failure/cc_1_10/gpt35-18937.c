//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
    char reason[100];
    struct Appointment* next;
};

typedef struct Appointment Appointment;

Appointment* head = NULL;

void scheduleAppointment(char name[], int day, int month, int year, char time[], char reason[]){
    Appointment* appointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(appointment->name, name);
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    strcpy(appointment->time, time);
    strcpy(appointment->reason, reason);
    appointment->next = NULL;

    if(head == NULL){
        head = appointment;
        return;
    }
    else{
        Appointment* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = appointment;
    }
    printf("\nAppointment Scheduled!\n");
}

void showAppointments(){
    if(head == NULL){
        printf("\nNo Scheduled Appointments\n");
        return;
    }
    else{
        printf("\nScheduled Appointments:\n");
        Appointment* curr = head;
        int count = 1;
        while(curr != NULL){
            printf("\nAppointment #%d\n", count);
            printf("Name: %s\n", curr->name);
            printf("Date: %d/%d/%d\n", curr->day, curr->month, curr->year);
            printf("Time: %s\n", curr->time);
            printf("Reason: %s\n", curr->reason);
            curr = curr->next;
            count++;
        }
    }
}

void cancelAppointment(){
    if(head == NULL){
        printf("\nNo Scheduled Appointments to Cancel\n");
        return;
    }
    else{
        char name[50];
        int day, month, year;
        printf("\nEnter the name for the appointment to cancel: ");
        scanf("%s", name);
        printf("Enter the date for the appointment to cancel (dd mm yyyy): ");
        scanf("%d %d %d", &day, &month, &year);

        Appointment* curr = head;
        if(strcmp(curr->name, name) == 0 && curr->day == day && curr->month == month && curr->year == year){
            head = curr->next;
            free(curr);
            printf("\nAppointment Canceled!\n");
            return;
        }

        Appointment* prev = NULL;
        while(curr != NULL){
            if(strcmp(curr->name, name) == 0 && curr->day == day && curr->month == month && curr->year == year){
                prev->next = curr->next;
                free(curr);
                printf("\nAppointment Canceled!\n");
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    printf("\nNo matching appointment found to cancel.\n");
}

int main(){
    int choice = -1;
    while(choice != 0){
        printf("\nEnter 1 to Schedule an Appointment:");
        printf("\nEnter 2 to View Scheduled Appointments:");
        printf("\nEnter 3 to Cancel an Appointment:");
        printf("\nEnter 0 to Exit:");
        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the name for the appointment: ");
                char name[50];
                scanf("%s", name);
                int day, month, year;
                printf("Enter the date for the appointment (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                char time[10];
                printf("Enter the time for the appointment (hh:mm am/pm): ");
                scanf("%s", time);
                printf("Enter the reason for the appointment: ");
                char reason[100];
                scanf("%s", reason);
                scheduleAppointment(name, day, month, year, time, reason);
                break;

            case 2:
                showAppointments();
                break;

            case 3:
                cancelAppointment();
                break;

            case 0:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid choice! Try Again.\n");
                break;
        }
    }
    return 0;
}