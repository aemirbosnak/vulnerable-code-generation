//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
/*
 * Appointment Scheduler Program
 *
 * This program allows for easy scheduling of appointments
 * and manages multiple schedules for different users.
 *
 * Written by [Your Name]
 * Date: [Current Date]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCHEDULES 10
#define MAX_USERS 100
#define MAX_APPOINTMENTS 100

/* User Struct Definition */
typedef struct user {
    char* name;
    int id;
    int schedule_id;
} User;

/* Schedule Struct Definition */
typedef struct schedule {
    int id;
    int num_appointments;
    char** appointments;
} Schedule;

/* Global Variables */
User users[MAX_USERS];
int num_users = 0;
Schedule schedules[MAX_SCHEDULES];
int num_schedules = 0;

/* Function Declarations */
void add_user();
void add_schedule();
void view_users();
void view_schedules();
void view_appointments(int schedule_id);
void add_appointment(int schedule_id, char* appointment);
void remove_appointment(int schedule_id, int appointment_num);

/* Main Function */
int main() {
    printf("Welcome to the Appointment Scheduler!\n\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add User\n");
        printf("2. Add Schedule\n");
        printf("3. View Users\n");
        printf("4. View Schedules\n");
        printf("5. View Appointments\n");
        printf("6. Add Appointment\n");
        printf("7. Remove Appointment\n");
        printf("8. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;

            case 2:
                add_schedule();
                break;

            case 3:
                view_users();
                break;

            case 4:
                view_schedules();
                break;

            case 5: {
                printf("Please enter the ID of the schedule you want to view: ");
                int schedule_id;
                scanf("%d", &schedule_id);
                view_appointments(schedule_id);
                break;
            }
            
            case 6: {
                printf("Please enter the ID of the schedule you want to add an appointment to: ");
                int schedule_id;
                scanf("%d", &schedule_id);

                printf("Please enter the appointment: ");
                char appointment[100];
                scanf("%s", appointment);

                add_appointment(schedule_id, appointment);
                break;
            }

            case 7: {
                printf("Please enter the ID of the schedule you want to remove an appointment from: ");
                int schedule_id;
                scanf("%d", &schedule_id);

                printf("Please enter the number of the appointment you want to remove: ");
                int appointment_num;
                scanf("%d", &appointment_num);

                remove_appointment(schedule_id, appointment_num);
                break;
            }

            case 8:
                printf("Thank you for using the Appointment Scheduler!\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

/* Function Definitions */

/* Add User Function */
void add_user() {
    if (num_users >= MAX_USERS) {
        printf("Error adding user: Maximum number of users reached\n");
        return;
    }

    printf("Please enter the user's name: ");
    char name[100];
    scanf("%s", name);

    User new_user = {
        .name = malloc(strlen(name) + 1),
        .id = num_users,
        .schedule_id = -1
    };

    strcpy(new_user.name, name);

    users[num_users++] = new_user;

    printf("%s added successfully\n", name);
}

/* Add Schedule Function */
void add_schedule() {
    if (num_schedules >= MAX_SCHEDULES) {
        printf("Error adding schedule: Maximum number of schedules reached\n");
        return;
    }

    printf("Please enter the schedule ID: ");
    int id;
    scanf("%d", &id);

    Schedule new_schedule = {
        .id = id,
        .num_appointments = 0
    };

    schedules[num_schedules++] = new_schedule;

    printf("Schedule ID %d created successfully\n", id);
}

/* View Users Function */
void view_users() {
    printf("Users:\n");
    printf("ID\tName\tSchedule ID\n");

    for (int i = 0; i < num_users; i++) {
        User user = users[i];
        printf("%d\t%s\t%d\n", user.id, user.name, user.schedule_id);
    }
}

/* View Schedules Function */
void view_schedules() {
    printf("Schedules:\n");
    printf("ID\tAppointments\n");

    for (int i = 0; i < num_schedules; i++) {
        Schedule schedule = schedules[i];

        printf("%d\t", schedule.id);

        if (schedule.num_appointments == 0) {
            printf("No appointments\n");
        } else {
            for (int j = 0; j < schedule.num_appointments; j++) {
                printf("%s", schedule.appointments[j]);

                if (j < schedule.num_appointments - 1) {
                    printf(", ");
                }
            }
            printf("\n");
        }
    }
}

/* View Appointments Function */
void view_appointments(int schedule_id) {
    for (int i = 0; i < num_schedules; i++) {
        Schedule schedule = schedules[i];

        if (schedule.id == schedule_id) {
            printf("Schedule ID %d Appointments:\n", schedule_id);

            if (schedule.num_appointments == 0) {
                printf("No appointments\n");
            } else {
                for (int j = 0; j < schedule.num_appointments; j++) {
                    printf("%d. %s\n", j + 1, schedule.appointments[j]);
                }
            }

            return;
        }
    }

    printf("Error: Could not find schedule with ID %d\n", schedule_id);
}

/* Add Appointment Function */
void add_appointment(int schedule_id, char* appointment) {
    for (int i = 0; i < num_schedules; i++) {
        Schedule* schedule = &schedules[i];

        if (schedule->id == schedule_id) {
            if (schedule->num_appointments >= MAX_APPOINTMENTS) {
                printf("Error adding appointment: Maximum number of appointments reached\n");
                return;
            }

            char* new_appointment = malloc(strlen(appointment) + 1);
            strcpy(new_appointment, appointment);

            schedule->appointments[schedule->num_appointments++] = new_appointment;

            printf("%s added to schedule ID %d successfully\n", appointment, schedule_id);

            return;
        }
    }

    printf("Error: Could not find schedule with ID %d\n", schedule_id);
}

/* Remove Appointment Function */
void remove_appointment(int schedule_id, int appointment_num) {
    for (int i = 0; i < num_schedules; i++) {
        Schedule* schedule = &schedules[i];

        if (schedule->id == schedule_id) {
            if (appointment_num > schedule->num_appointments || appointment_num <= 0) {
                printf("Error removing appointment: Invalid appointment number\n");
                return;
            }

            free(schedule->appointments[appointment_num - 1]);

            for (int j = appointment_num; j < schedule->num_appointments; j++) {
                schedule->appointments[j - 1] = schedule->appointments[j];
            }

            schedule->num_appointments--;

            printf("Appointment %d removed from schedule ID %d successfully\n", appointment_num, schedule_id);

            return;
        }
    }

    printf("Error: Could not find schedule with ID %d\n", schedule_id);
}