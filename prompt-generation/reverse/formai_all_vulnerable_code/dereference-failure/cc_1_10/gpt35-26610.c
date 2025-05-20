//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100
#define SLOT_TIME_IN_SECONDS 1200

typedef struct Appointment{
    int id;
    time_t appointmentDateTime;
    char clientName[50];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int nextId = 1;
int numAppointments = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

bool isValidTime(time_t desiredTime) {
    time_t now = time(NULL);
    double timeDiff = difftime(desiredTime, now);
    if (timeDiff < SLOT_TIME_IN_SECONDS) {
        return false;
    }
    return true;
}

int findAvailableSlot() {
    int i = 0;
    bool foundSlot = false;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].id == 0) {
            foundSlot = true;
            break;
        }
    }
    if (!foundSlot) {
        return -1;
    }
    return i;
}

void* manageAppointments(void* arg) {
    int* argPtr = (int*) arg;
    int appointmentSlot = *argPtr;
    char clientName[50];
    printf("Enter client name for appointment slot %d: ", appointmentSlot);
    fgets(clientName, 50, stdin);
    int len = strlen(clientName);
    if (len > 0 && clientName[len-1] == '\n') {
        clientName[len-1] = '\0';
    }
    printf("Enter date and time for appointment slot %d (YYYY-MM-DD HH:MM): ", appointmentSlot);
    char input[50];
    fgets(input, 50, stdin);
    struct tm tm = {0};
    strptime(input, "%Y-%m-%d %H:%M", &tm);
    time_t desiredTime = mktime(&tm);
    if (!isValidTime(desiredTime)) {
        printf("Invalid time. Appointments must be scheduled at least 20 minutes in advance.\n");
        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
    }
    appointments[appointmentSlot].id = nextId;
    nextId++;
    appointments[appointmentSlot].appointmentDateTime = desiredTime;
    strncpy(appointments[appointmentSlot].clientName, clientName, 50);
    appointments[appointmentSlot].clientName[49] = '\0';
    numAppointments++;
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void printAppointments() {
    printf("*** Appointments ***\n");
    int i = 0;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].id != 0) {
            struct tm* timeInfo = localtime(&appointments[i].appointmentDateTime);
            char timeString[50];
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M", timeInfo);
            printf("%d: %s - %s\n", appointments[i].id, timeString, appointments[i].clientName);
        }
    }
}

int main(int argc, char** argv) {
    pthread_t threads[MAX_APPOINTMENTS];
    int slotIds[MAX_APPOINTMENTS];
    while (numAppointments < MAX_APPOINTMENTS) {
        int slot = findAvailableSlot();
        if (slot == -1) {
            printf("No available slots.\n");
            break;
        }
        if (argc == 2 && strcmp(argv[1], "-a") == 0) {
            printf("Auto mode enabled\n");
            srand(time(NULL));
            int sleepTime = rand() % SLOT_TIME_IN_SECONDS + 1;
            printf("Sleeping for %d seconds before scheduling appointment.\n", sleepTime);
            sleep(sleepTime);
            printf("Scheduling appointment in slot %d.\n", slot);
            char clientName[50];
            sprintf(clientName, "Client %d", nextId);
            time_t desiredTime = time(NULL) + SLOT_TIME_IN_SECONDS + rand() % 1200 + 1;
            appointments[slot].id = nextId;
            nextId++;
            appointments[slot].appointmentDateTime = desiredTime;
            strncpy(appointments[slot].clientName, clientName, 50);
            appointments[slot].clientName[49] = '\0';
            numAppointments++;
            continue;
        }
        slotIds[numAppointments] = slot;
        pthread_create(&threads[numAppointments], NULL, manageAppointments, (void*) &slotIds[numAppointments]);
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&condition, &mutex);
        pthread_mutex_unlock(&mutex);
    }
    printAppointments();
    return 0;
}