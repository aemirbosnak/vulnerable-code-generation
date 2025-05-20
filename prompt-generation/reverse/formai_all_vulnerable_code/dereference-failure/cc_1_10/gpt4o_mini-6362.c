//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

#define MAX_APPOINTMENTS 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;
sem_t sem;

void *schedule_appointment(void *arg) {
    char *client_name = (char *)arg;
    sem_wait(&sem); // Wait to access the critical section

    if (appointment_count < MAX_APPOINTMENTS) {
        printf("%s is scheduling an appointment...\n", client_name);
        printf("Enter appointment time (HH MM): ");
        int hour, minute;
        scanf("%d %d", &hour, &minute);

        // Store the appointment
        strcpy(appointments[appointment_count].name, client_name);
        appointments[appointment_count].hour = hour;
        appointments[appointment_count].minute = minute;
        appointment_count++;

        printf("Appointment scheduled for %s at %02d:%02d\n", client_name, hour, minute);
    } else {
        printf("Appointment limit reached! %s could not schedule.\n", client_name);
    }

    sem_post(&sem); // Signal that we're done
    return NULL;
}

void *cancel_appointment(void *arg) {
    char *client_name = (char *)arg;
    sem_wait(&sem); // Wait to access the critical section

    printf("%s is attempting to cancel an appointment...\n", client_name);
    for (int i = 0; i < appointment_count; i++) {
        if (strcmp(appointments[i].name, client_name) == 0) {
            // Remove the appointment
            for (int j = i; j < appointment_count - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointment_count--;
            printf("Appointment for %s canceled successfully.\n", client_name);
            sem_post(&sem);
            return NULL;
        }
    }

    printf("No appointment found for %s to cancel.\n", client_name);
    sem_post(&sem); // Signal that we're done
    return NULL;
}

void *list_appointments(void *arg) {
    sem_wait(&sem); // Wait to access the critical section

    printf("Current appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf(" %d: %s at %02d:%02d\n", i + 1, appointments[i].name, appointments[i].hour, appointments[i].minute);
    }

    sem_post(&sem); // Signal that we're done
    return NULL;
}

int main() {
    pthread_t clients[10];
    sem_init(&sem, 0, 1); // Initialize semaphore

    for (int i = 0; i < 10; i++) {
        char *client_name = malloc(NAME_LENGTH);
        snprintf(client_name, NAME_LENGTH, "Client%d", i + 1);
        
        // Schedule appointments for some clients
        if (i % 2 == 0) {
            pthread_create(&clients[i], NULL, schedule_appointment, (void *)client_name);
        } 
        // Cancel appointments for others
        else {
            pthread_create(&clients[i], NULL, cancel_appointment, (void *)client_name);
        }
    }

    // List appointments from a separate thread
    pthread_t listing_thread;
    pthread_create(&listing_thread, NULL, list_appointments, NULL);

    // Join all client threads
    for (int i = 0; i < 10; i++) {
        pthread_join(clients[i], NULL);
    }

    pthread_join(listing_thread, NULL);
    
    // Clean up
    sem_destroy(&sem);
    return 0;
}