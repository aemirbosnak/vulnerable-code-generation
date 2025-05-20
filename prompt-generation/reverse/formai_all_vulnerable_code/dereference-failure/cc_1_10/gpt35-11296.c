//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment{
    char name[50];
    int age;
    char address[100];
    char email[50];
    char phone[15];
    int day;
    int month;
    int year;
    char time[10];
};

struct node{
    struct appointment data;
    struct node *next;
}*head;

void addAppointment(){
    struct node *newAppointment, *temp;
    newAppointment = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter Patient's Name: ");
    scanf("%s", newAppointment->data.name);

    printf("\nEnter Patient's Age: ");
    scanf("%d", &newAppointment->data.age);

    printf("\nEnter Patient's Address: ");
    scanf("%s", newAppointment->data.address);

    printf("\nEnter Patient's Email: ");
    scanf("%s", newAppointment->data.email);

    printf("\nEnter Patient's Phone Number: ");
    scanf("%s", newAppointment->data.phone);

    printf("\nEnter Appointment Date (dd mm yyyy): ");
    scanf("%d %d %d", &newAppointment->data.day, &newAppointment->data.month, &newAppointment->data.year);

    printf("\nEnter Appointment Time (hh:mm AM/PM): ");
    scanf("%s", newAppointment->data.time);

    newAppointment->next = NULL;

    if(head == NULL){
        head = newAppointment;
    }else if (newAppointment->data.year < head->data.year){
        newAppointment->next = head;
        head = newAppointment;
    }else if (newAppointment->data.year == head->data.year){
        if(newAppointment->data.month < head->data.month){
            newAppointment->next = head;
            head = newAppointment;
        }else if(newAppointment->data.month == head->data.month){
            if(newAppointment->data.day < head->data.day){
                newAppointment->next = head;
                head = newAppointment;
            }else{
                temp = head;
                while(temp->next != NULL && temp->next->data.year == newAppointment->data.year && temp->next->data.month == newAppointment->data.month && temp->next->data.day < newAppointment->data.day){
                    temp = temp->next;
                }
                newAppointment->next = temp->next;
                temp->next = newAppointment;
            }
        }else{
            temp = head;
            while(temp->next != NULL && temp->next->data.year == newAppointment->data.year && temp->next->data.month < newAppointment->data.month){
                temp = temp->next;
            }
            newAppointment->next = temp->next;
            temp->next = newAppointment;
        }
    }else{
        temp = head;
        while(temp->next != NULL && temp->next->data.year < newAppointment->data.year){
            temp = temp->next;
        }
        newAppointment->next = temp->next;
        temp->next = newAppointment;
    }

    printf("\nAppointment Added!");
}

void getAppointmentsByDate(){
    if(head == NULL){
        printf("\nNo Appointments Found!");
    }else{
        int day, month, year;
        struct node *temp;
        temp = head;

        printf("\nEnter Date (dd mm yyyy): ");
        scanf("%d %d %d", &day, &month, &year);

        while(temp != NULL && temp->data.year <= year && temp->data.month <= month && temp->data.day <= day){
            if(temp->data.year == year && temp->data.month == month && temp->data.day == day){
                printf("\nAppointment Details:");
                printf("\nName: %s", temp->data.name);
                printf("\nAge: %d", temp->data.age);
                printf("\nAddress: %s", temp->data.address);
                printf("\nEmail: %s", temp->data.email);
                printf("\nPhone: %s", temp->data.phone);
                printf("\nAppointment Date: %d/%d/%d", temp->data.day, temp->data.month, temp->data.year);
                printf("\nAppointment Time: %s", temp->data.time);
            }
            temp = temp->next;
        }

        if(temp == NULL){
            printf("\nNo Appointments Found on the Entered Date");
        }
    }
}

void deleteAppointment(){
    if(head == NULL){
        printf("\nNo Appointments Found!");
    }else{
        char tempName[50];
        struct node *temp, *prev;
        temp = head;

        printf("\nEnter the Name of the Patient whose Appointment you want to cancel: ");
        scanf("%s", tempName);

        if(strcmp(head->data.name, tempName) == 0){
            head = head->next;
            free(temp);
            printf("\nAppointment Cancelled Successfully!");
            return;
        }

        while(temp != NULL && strcmp(temp->data.name, tempName) != 0){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            printf("\nNo Appointment Found!");
        }else{
            prev->next = temp->next;
            free(temp);
            printf("\nAppointment Cancelled Successfully!");
        }
    }
}

int main(){
    int option = 0;

    head = NULL;

    while(option != 4){
        printf("\n\n*****Appointment Scheduler*****\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments By Date\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addAppointment();
                break;
            case 2:
                getAppointmentsByDate();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("\n\nExiting Appointment Scheduler...\n\n");
                exit(0);
            default:
                printf("\n\nInvalid Option!\n\n");
                break;
        }
    }
    return 0;
}