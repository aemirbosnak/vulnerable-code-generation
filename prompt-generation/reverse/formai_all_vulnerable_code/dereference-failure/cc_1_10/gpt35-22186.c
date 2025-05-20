//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_APP_PER_DAY 5
#define TOTAL_DAYS 7

struct Appointment {
    char name[MAX_NAME_LEN];
    int day;
    int time;
};

void displayMenu();
void getAppointment(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], char name[MAX_NAME_LEN], int day, int time);
void cancelAppointment(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], char name[MAX_NAME_LEN], int day, int time);
void displayAppointments(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], int day);
int isAppointmentAvailable(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], int day, int time);
void clearInput();

int main() {
    struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY];
    int choice, day, time;
    char name[MAX_NAME_LEN];
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Get new appointment
                printf("\nEnter details:\n");
                printf("Name: ");
                clearInput();
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Day (1-7): ");
                scanf("%d", &day);
                printf("Time (9-17): ");
                scanf("%d", &time);
                
                if (day < 1 || day > TOTAL_DAYS) {
                    printf("\nInvalid day entered!\n\n");
                } else if (time < 9 || time > 17) {
                    printf("\nInvalid time entered!\n\n");
                } else if (isAppointmentAvailable(appointments, day - 1, time - 9)) {
                    getAppointment(appointments, name, day - 1, time - 9);
                    printf("\nAppointment created successfully!\n\n");
                } else {
                    printf("\nAppointment slot not available!\n\n");
                }
                break;
                
            case 2: // Cancel appointment
                printf("\nEnter details:\n");
                printf("Name: ");
                clearInput();
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Day (1-7): ");
                scanf("%d", &day);
                printf("Time (9-17): ");
                scanf("%d", &time);
                
                if (day < 1 || day > TOTAL_DAYS) {
                    printf("\nInvalid day entered!\n\n");
                } else if (time < 9 || time > 17) {
                    printf("\nInvalid time entered!\n\n");
                } else {
                    cancelAppointment(appointments, name, day - 1, time - 9);
                    printf("\nAppointment cancelled successfully!\n\n");
                }
                break;
                
            case 3: // Display appointments
                printf("\nEnter day to view (1-7): ");
                scanf("%d", &day);
                
                if (day < 1 || day > TOTAL_DAYS) {
                    printf("\nInvalid day entered!\n\n");
                } else {
                    displayAppointments(appointments, day - 1);
                }
                break;
                
            case 4:
                printf("\nProgram terminated.\n");
                break;
                
            default:
                printf("\nInvalid choice entered!\n\n");
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("======================\n");
    printf("1. Get new appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. Display appointments\n");
    printf("4. Exit\n");
    printf("\nEnter choice (1-4): ");
}

void getAppointment(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], char name[MAX_NAME_LEN], int day, int time) {
    struct Appointment newAppointment = {0};
    strcpy(newAppointment.name, name);
    newAppointment.day = day;
    newAppointment.time = time;
    appointments[day][time] = newAppointment;
}

void cancelAppointment(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], char name[MAX_NAME_LEN], int day, int time) {
    if (strcmp(appointments[day][time].name, name) == 0) {
        struct Appointment emptyAppointment = {0};
        appointments[day][time] = emptyAppointment;
    } else {
        printf("\nNo appointment found with the given details.\n\n");
    }
}

void displayAppointments(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], int day) {
    printf("\nAppointments for day %d:\n", day + 1);
    for (int i = 0; i < MAX_APP_PER_DAY; i++) {
        if (strcmp(appointments[day][i].name, "") != 0) {
            printf("%d:00 - %d:00 - %s\n", i + 9, i + 10, appointments[day][i].name);
        }
    }
    printf("\n");
}

int isAppointmentAvailable(struct Appointment appointments[TOTAL_DAYS][MAX_APP_PER_DAY], int day, int time) {
    if (strcmp(appointments[day][time].name, "") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void clearInput() {
    while (getchar() != '\n');
}