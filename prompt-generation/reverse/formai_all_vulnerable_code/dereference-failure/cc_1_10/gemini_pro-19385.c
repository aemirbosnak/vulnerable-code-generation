//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Appointment data structure
typedef struct Appointment {
    int id;
    char *name;
    char *time;
    char *date;
    struct Appointment *next;
} Appointment;

// Appointments list
Appointment *head = NULL;

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a new appointment
void add_appointment(int id, char *name, char *time, char *date) {
    // Allocate memory for the new appointment
    Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));

    // Set the appointment data
    new_appointment->id = id;
    new_appointment->name = strdup(name);
    new_appointment->time = strdup(time);
    new_appointment->date = strdup(date);
    new_appointment->next = NULL;

    // Acquire the lock
    pthread_mutex_lock(&mutex);

    // Add the new appointment to the list
    if (head == NULL) {
        head = new_appointment;
    } else {
        Appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }

    // Release the lock
    pthread_mutex_unlock(&mutex);
}

// Function to delete an appointment
void delete_appointment(int id) {
    // Acquire the lock
    pthread_mutex_lock(&mutex);

    // Find the appointment to delete
    Appointment *current = head;
    Appointment *previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    // If the appointment was found, delete it
    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current->name);
        free(current->time);
        free(current->date);
        free(current);
    }

    // Release the lock
    pthread_mutex_unlock(&mutex);
}

// Function to print the list of appointments
void print_appointments() {
    // Acquire the lock
    pthread_mutex_lock(&mutex);

    // Print the appointments
    Appointment *current = head;
    while (current != NULL) {
        printf("%d %s %s %s\n", current->id, current->name, current->time, current->date);
        current = current->next;
    }

    // Release the lock
    pthread_mutex_unlock(&mutex);
}

// Function to simulate a user adding an appointment
void *add_appointment_thread(void *args) {
    // Get the appointment data
    int id = *(int *)args;
    char name[] = "John Doe";
    char time[] = "10:00 AM";
    char date[] = "2023-03-08";

    // Add the appointment
    add_appointment(id, name, time, date);

    return NULL;
}

// Function to simulate a user deleting an appointment
void *delete_appointment_thread(void *args) {
    // Get the appointment data
    int id = *(int *)args;

    // Delete the appointment
    delete_appointment(id);

    return NULL;
}

// Main function
int main() {
    // Create threads to simulate users adding and deleting appointments
    pthread_t thread1, thread2;
    int id1 = 1;
    int id2 = 2;
    pthread_create(&thread1, NULL, add_appointment_thread, &id1);
    pthread_create(&thread2, NULL, delete_appointment_thread, &id2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the list of appointments
    print_appointments();

    return 0;
}