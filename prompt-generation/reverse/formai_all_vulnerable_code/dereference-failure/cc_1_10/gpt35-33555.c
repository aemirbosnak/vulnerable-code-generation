//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LIMIT 100

//Define a structure to represent an appointment
struct Appointment {
    char date[20];
    char time[20];
    char name[MAX_LIMIT];
    char reason[MAX_LIMIT];
    struct Appointment *next;
};

struct Appointment *start = NULL;

//Function to add a New Appointment to the Linked List
void addAppointment() {
    struct Appointment *newAppointment = (struct Appointment*) malloc(sizeof(struct Appointment));
    printf("\nEnter the Appointment Date (dd-mm-yyyy): ");
    scanf("%s", newAppointment->date);
    printf("\nEnter the Appointment Time (hh:mm AM/PM): ");
    scanf("%s", newAppointment->time);
    printf("\nEnter Patient Name: ");
    scanf("%s", newAppointment->name);
    printf("\nEnter Reason for Appointment: ");
    scanf(" %[^\n]s", newAppointment->reason);
    newAppointment->next = NULL;

    if(start == NULL) {
        start = newAppointment; 
    } else {
        struct Appointment *temp = start;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newAppointment;
    }
    printf("\nAppointment Added Successfully!");
}
//Function to list all the Appointments in the Linked List
void listAppointments() {
    int count = 1;
    if(start == NULL) {
        printf("\nNo Appointments Found!\n");
    } else {
        struct Appointment *temp = start;
        printf("\nList of Appointments: \n");
        while(temp != NULL) {
            printf("\nAppointment %d \nDate: %s \nTime: %s \nName: %s \nReason: %s\n", count, temp->date, temp->time, temp->name, temp->reason);
            temp = temp->next;
            count++;
        }
    }
}

//Function to delete an Appointment from the Linked List
void deleteAppointment() {
    if(start == NULL) {
        printf("\nNo Appointments Found!\n");
    } else {
        int number;
        printf("\nEnter the Serial Number of the Appointment you wish to Delete: ");
        scanf("%d", &number);
        if(number == 1) {
            struct Appointment *temp = start;
            start = start->next;
            free(temp);
            printf("\nAppointment Deleted Successfully!\n");
        } else {
            struct Appointment *temp = start;
            int count = 1;
            while(temp != NULL && count < number - 1) {
                temp = temp->next;
                count++;
            }
            if(temp == NULL || temp->next == NULL) {
                printf("\nInvalid Selection!\n");
            } else {
                struct Appointment *toDelete = temp->next;
                temp->next = toDelete->next;
                free(toDelete);
                printf("\nAppointment Deleted Successfully!\n");
            }
        }
    }
}

int main() {
    printf("\nWelcome to the Smart Appointment Scheduler!\n");
    printf("\nChoose from the following options:\n");
    int option;
    do {
        printf("\n1. Add New Appointment");
        printf("\n2. List All Appointments");
        printf("\n3. Delete Appointment");
        printf("\n4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                addAppointment();
                break;
            case 2:
                listAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("\nSmart Appointment Scheduler Closed!");
                break;
            default:
                printf("\nInvalid Option! Please try again!\n");
        }
    } while(option != 4);
    return 0;
}