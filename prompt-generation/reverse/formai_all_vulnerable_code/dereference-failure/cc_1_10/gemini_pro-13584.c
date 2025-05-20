//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
struct appointment {
    char title[50];
    char date[20];
    char time[20];
    char location[50];
};

// Function to create a new appointment
struct appointment* create_appointment(char *title, char *date, char *time, char *location) {
    struct appointment *new_appointment = malloc(sizeof(struct appointment));
    strcpy(new_appointment->title, title);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    strcpy(new_appointment->location, location);
    return new_appointment;
}

// Function to print an appointment
void print_appointment(struct appointment *appointment) {
    printf("Title: %s\n", appointment->title);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("Location: %s\n", appointment->location);
}

// Function to compare two appointments by date and time
int compare_appointments(struct appointment *a, struct appointment *b) {
    int date_cmp = strcmp(a->date, b->date);
    if (date_cmp == 0) {
        return strcmp(a->time, b->time);
    } else {
        return date_cmp;
    }
}

// Function to sort an array of appointments by date and time
void sort_appointments(struct appointment **appointments, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare_appointments(appointments[j], appointments[j + 1]) > 0) {
                struct appointment *temp = appointments[j];
                appointments[j] = appointments[j + 1];
                appointments[j + 1] = temp;
            }
        }
    }
}

// Function to print a list of appointments
void print_appointments(struct appointment **appointments, int n) {
    for (int i = 0; i < n; i++) {
        print_appointment(appointments[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of appointments
    struct appointment **appointments = malloc(5 * sizeof(struct appointment *));
    appointments[0] = create_appointment("Jousting Tournament", "May 1st", "10:00 AM", "Castle Field");
    appointments[1] = create_appointment("Feast of the King", "May 15th", "7:00 PM", "Great Hall");
    appointments[2] = create_appointment("Council Meeting", "May 20th", "9:00 AM", "Throne Room");
    appointments[3] = create_appointment("Hunt in the Forest", "May 25th", "11:00 AM", "Sherwood Forest");
    appointments[4] = create_appointment("Wedding of the Lord", "June 1st", "12:00 PM", "Chapel");

    // Sort the appointments by date and time
    sort_appointments(appointments, 5);

    // Print the sorted appointments
    print_appointments(appointments, 5);

    return 0;
}