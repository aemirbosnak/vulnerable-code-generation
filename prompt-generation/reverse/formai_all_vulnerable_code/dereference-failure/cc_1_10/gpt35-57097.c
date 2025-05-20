//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date date;
    char reason[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu();
void add_appointment();
void view_appointments();
void clear_input_buffer();
void get_date(Date* date);

int main() {
    int choice;

    printf("***Appointment Scheduler***\n\n");
    display_menu();

    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                display_menu();
                break;
            case 2:
                view_appointments();
                display_menu();
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                display_menu();
                break;
        }
    } while (choice != 3);

    return 0;
}

void display_menu() {
    printf("\n1. Add appointment");
    printf("\n2. View appointments");
    printf("\n3. Exit");
}

void add_appointment() {
    if (appointment_count == MAX_APPOINTMENTS) {
        printf("\nMaximum number of appointments reached. Unable to add new appointment.\n");
    } else {
        printf("\nEnter name: ");
        clear_input_buffer();
        fgets(appointments[appointment_count].name, sizeof(appointments[appointment_count].name), stdin);

        printf("\nEnter date of appointment (dd/mm/yyyy): ");
        get_date(&appointments[appointment_count].date);

        printf("\nEnter reason: ");
        clear_input_buffer();
        fgets(appointments[appointment_count].reason, sizeof(appointments[appointment_count].reason), stdin);

        appointment_count++;

        printf("\nAppointment added successfully.\n");
    }
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("\nNo appointments found.\n");
    } else {
        printf("\nAppointments:\n");
        printf("Date\t\t\tName\tReason\n");

        for (int i = 0; i < appointment_count; i++) {
            printf("%02d/%02d/%04d\t%s\t%s\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year,
                    appointments[i].name, appointments[i].reason);
        }
    }
}

void clear_input_buffer() {
    while (getchar() != '\n');
}

void get_date(Date* date) {
    char input[11];
    char* token;

    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0'; // Remove newline character

    token = strtok(input, "/"); // First token
    date->day = atoi(token);

    token = strtok(NULL, "/"); // Second token
    date->month = atoi(token);

    token = strtok(NULL, "/"); // Third token
    date->year = atoi(token);
}