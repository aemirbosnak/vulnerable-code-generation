//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

#define MAX_APPOINTMENTS 10 // Maximum number of appointments per day

struct appointment {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char description[100];
};

int num_appointments = 0; // Number of appointments scheduled
struct appointment appointments[MAX_APPOINTMENTS];

// Prompt user for a new appointment and add it to the appointments array
void new_appointment() {
    struct appointment new_appt;
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &new_appt.day, &new_appt.month, &new_appt.year);
    if (new_appt.day < 1 || new_appt.day > 31 || new_appt.month < 1 || new_appt.month > 12) {
        printf("Invalid date.\n");
        return;
    }
    printf("Enter time (HH:MM): ");
    scanf("%d:%d", &new_appt.hour, &new_appt.minute);
    if (new_appt.hour < 0 || new_appt.hour > 23 || new_appt.minute < 0 || new_appt.minute > 59) {
        printf("Invalid time.\n");
        return;
    }
    printf("Enter description: ");
    scanf(" %[^\n]", new_appt.description);
    appointments[num_appointments++] = new_appt;
    printf("Appointment added.\n");
}

// Print the user's schedule for the day
void view_schedule() {
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    int current_day = current_time->tm_mday;
    int current_month = current_time->tm_mon + 1;
    int current_year = current_time->tm_year + 1900;
    printf("Appointments for %d/%d/%d:\n", current_day, current_month, current_year);
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].day == current_day && appointments[i].month == current_month && appointments[i].year == current_year) {
            printf("%02d:%02d - %s\n", appointments[i].hour, appointments[i].minute, appointments[i].description);
        }
    }
}

int main() {
    // Main menu loop
    while (1) {
        printf("1. Schedule new appointment\n");
        printf("2. View schedule for today\n");
        printf("3. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                new_appointment();
                break;
            case 2:
                view_schedule();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}