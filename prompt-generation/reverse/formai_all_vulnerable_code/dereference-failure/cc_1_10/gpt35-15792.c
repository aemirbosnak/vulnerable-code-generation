//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct appointment{
    int day;
    int month;
    int year;
    char time[6];
    char name[30];
    struct appointment *next;
};

struct appointment *head = NULL;

void add_appointment(int day, int month, int year, char time[6], char name[30]){
    struct appointment *new_appointment = (struct appointment*)malloc(sizeof(struct appointment));
    new_appointment->day = day;
    new_appointment->month = month;
    new_appointment->year = year;
    strcpy(new_appointment->time, time);
    strcpy(new_appointment->name, name);
    new_appointment->next = NULL;
    if(head == NULL){
        head = new_appointment;
        return;
    }
    struct appointment *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_appointment;
}

void delete_appointment(char name[30]){
    struct appointment *temp = head;
    struct appointment *prev = NULL;
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\nAppointment not found.\n");
        return;
    }
    if(prev == NULL){
        head = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
}

void print_appointments(){
    struct appointment *temp = head;
    while(temp != NULL){
        printf("\nName: %s", temp->name);
        printf("\nDate: %d/%d/%d", temp->day, temp->month, temp->year);
        printf("\nTime: %s\n", temp->time);
        temp = temp->next;
    }
}

void menu(){
    printf("\n-----------------------\n");
    printf(" APPOINTMENT SCHEDULER\n");
    printf("-----------------------\n\n");
    printf("1. Add appointment\n");
    printf("2. Delete appointment\n");
    printf("3. Print appointments\n");
    printf("4. Exit\n");
    printf("\nEnter choice: ");
}

void clear(){
    while(getchar() != '\n'){
    }
}

int main(){
    int choice, day, month, year;
    char name[30], time[6];
    while(1){
        
        menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter name: ");
                clear();
                fgets(name, 30, stdin);
                name[strlen(name)-1] = '\0';
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &day, &month, &year);
                printf("Enter time (hh:mm): ");
                scanf("%s", time);
                add_appointment(day, month, year, time, name);
                printf("\nAppointment added successfully!\n");
                break;
            case 2:
                printf("\nEnter name: ");
                clear();
                fgets(name, 30, stdin);
                name[strlen(name)-1] = '\0';
                delete_appointment(name);
                break;
            case 3:
                print_appointments();
                break;
            case 4:
                printf("\nGoodbye!");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}