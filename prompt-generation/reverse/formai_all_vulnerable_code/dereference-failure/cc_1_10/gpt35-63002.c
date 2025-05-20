//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment{
    char name[20];
    char date[12];
    char time[10];
    struct appointment *next;
};

void addAppointment(struct appointment **head_ref){
    struct appointment *new_appointment = (struct appointment*) malloc(sizeof(struct appointment));
    printf("Enter Name: ");
    scanf("%s", new_appointment->name);
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", new_appointment->date);
    printf("Enter time (hh:mm AM/PM): ");
    scanf("%s", new_appointment->time);

    new_appointment->next = (*head_ref);
    (*head_ref) = new_appointment;

    printf("Successfully added appointment of '%s' on %s at %s\n", new_appointment->name, new_appointment->date, new_appointment->time);
}

void displayAppointments(struct appointment *head){
    struct appointment *temp = head;

    printf("\nAppointment Schedule:\n\n");
    printf("|------------------------------------------|\n");
    printf("| Name \t| Date \t\t| Time \t|\n");
    printf("|------------------------------------------|\n");

    while(temp != NULL){
        printf("| %s \t| %s \t| %s \t|\n", temp->name, temp->date, temp->time);
        printf("|------------------------------------------|\n");
        temp = temp->next;
    }
}

void searchAppointment(struct appointment *head, char patient_name[]){
    struct appointment *temp = head;
    int found = 0;

    while(temp != NULL){
        if(strcmp(temp->name, patient_name) == 0){
            printf("\n Appointment found of '%s' on %s at %s\n", temp->name, temp->date, temp->time);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if(!found){
        printf("\nNo appointment found of '%s'\n", patient_name);
    }
}

int main(){
    int choice;
    char patient_name[20];

    struct appointment *head = NULL;

    while(1){
        printf("\n\n-----Appointment Scheduler-----\n\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Search Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                addAppointment(&head);
                break;
            case 2:
                displayAppointments(head);
                break;
            case 3:
                printf("\nEnter patient name to search: ");
                scanf("%s", patient_name);
                searchAppointment(head, patient_name);
                break;
            case 4:
                printf("\nExiting Program");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.");
        }
    }

    return 0;
}