//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct Appointment {
    int id;
    char *name;
    char *date;
    char *time;
    char *location;
    char *notes;
} Appointment;

// Function to create a new appointment
Appointment* create_appointment(int id, char *name, char *date, char *time, char *location, char *notes) {
    Appointment *appointment = (Appointment*)malloc(sizeof(Appointment));
    appointment->id = id;
    appointment->name = strdup(name);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    appointment->location = strdup(location);
    appointment->notes = strdup(notes);
    return appointment;
}

// Function to print an appointment
void print_appointment(Appointment *appointment) {
    printf("Appointment ID: %d\n", appointment->id);
    printf("Name: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("Location: %s\n", appointment->location);
    printf("Notes: %s\n", appointment->notes);
}

// Function to compare two appointments by date and time
int compare_appointments(Appointment *a, Appointment *b) {
    int date_comparison = strcmp(a->date, b->date);
    if (date_comparison == 0) {
        return strcmp(a->time, b->time);
    } else {
        return date_comparison;
    }
}

// Function to sort an array of appointments by date and time
void sort_appointments(Appointment **appointments, int size) {
    qsort(appointments, size, sizeof(Appointment*), compare_appointments);
}

// Function to find an appointment by ID
Appointment* find_appointment_by_id(Appointment **appointments, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (appointments[i]->id == id) {
            return appointments[i];
        }
    }
    return NULL;
}

// Function to delete an appointment by ID
void delete_appointment_by_id(Appointment **appointments, int size, int id) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (appointments[i]->id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Appointment *appointment = appointments[index];
        for (int i = index; i < size - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        free(appointment->name);
        free(appointment->date);
        free(appointment->time);
        free(appointment->location);
        free(appointment->notes);
        free(appointment);
    }
}

// Main function
int main() {
    // Initialize the array of appointments
    Appointment *appointments[] = {
        create_appointment(1, "John Doe", "2023-03-08", "10:00 AM", "Room 101", "Meeting with client"),
        create_appointment(2, "Jane Doe", "2023-03-10", "02:00 PM", "Room 202", "Interview for new position"),
        create_appointment(3, "Bob Smith", "2023-03-12", "04:00 PM", "Room 303", "Project planning meeting"),
        create_appointment(4, "Alice Jones", "2023-03-14", "08:00 AM", "Room 404", "Training session"),
        create_appointment(5, "Tom Brown", "2023-03-16", "12:00 PM", "Room 505", "Lunch with team"),
    };
    const int size = sizeof(appointments) / sizeof(Appointment*);

    // Sort the appointments by date and time
    sort_appointments(appointments, size);

    // Print the sorted appointments
    printf("Sorted appointments:\n");
    for (int i = 0; i < size; i++) {
        print_appointment(appointments[i]);
        printf("\n");
    }

    // Find an appointment by ID
    int id = 3;
    Appointment *appointment = find_appointment_by_id(appointments, size, id);
    if (appointment != NULL) {
        printf("Found appointment with ID %d:\n", id);
        print_appointment(appointment);
        printf("\n");
    } else {
        printf("No appointment found with ID %d.\n", id);
    }

    // Delete an appointment by ID
    id = 5;
    delete_appointment_by_id(appointments, size, id);

    // Print the remaining appointments
    printf("Remaining appointments:\n");
    for (int i = 0; i < size - 1; i++) {
        print_appointment(appointments[i]);
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        free(appointments[i]->name);
        free(appointments[i]->date);
        free(appointments[i]->time);
        free(appointments[i]->location);
        free(appointments[i]->notes);
        free(appointments[i]);
    }

    return 0;
}