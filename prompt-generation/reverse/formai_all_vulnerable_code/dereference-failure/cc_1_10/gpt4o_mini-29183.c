//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_APPOINTMENTS 100
#define BUFFER_SIZE 256

typedef struct {
    char patient_name[50];
    char appointment_time[30];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Mutex for thread safety
pthread_mutex_t mutex;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    free(client_socket);
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0';

        pthread_mutex_lock(&mutex);
        if (strncmp(buffer, "SCHEDULE", 8) == 0) {
            char name[50], time[30];
            sscanf(buffer + 9, "%s %s", name, time);
            if (appointment_count < MAX_APPOINTMENTS) {
                strcpy(appointments[appointment_count].patient_name, name);
                strcpy(appointments[appointment_count].appointment_time, time);
                appointment_count++;
                send(sock, "Appointment Scheduled\n", 22, 0);
            } else {
                send(sock, "Max appointments reached\n", 25, 0);
            }
        } else if (strncmp(buffer, "VIEW", 4) == 0) {
            char response[BUFFER_SIZE] = "Appointments:\n";
            for (int i = 0; i < appointment_count; i++) {
                char temp[100];
                sprintf(temp, "%s at %s\n", appointments[i].patient_name, appointments[i].appointment_time);
                strcat(response, temp);
            }
            send(sock, response, strlen(response), 0);
        } else if (strncmp(buffer, "CANCEL", 6) == 0) {
            char name[50];
            sscanf(buffer + 7, "%s", name);
            int found = 0;
            for (int i = 0; i < appointment_count; i++) {
                if (strcmp(appointments[i].patient_name, name) == 0) {
                    for (int j = i; j < appointment_count - 1; j++) {
                        appointments[j] = appointments[j + 1];
                    }
                    appointment_count--;
                    found = 1;
                    break;
                }
            }
            send(sock, found ? "Appointment Canceled\n" : "No appointment found\n", 22, 0);
        } else {
            send(sock, "Invalid Command\n", 17, 0);
        }
        pthread_mutex_unlock(&mutex);
    }

    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    pthread_mutex_init(&mutex, NULL);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set sock opt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Appointment Scheduler Server is Running on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_t thread_id;
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)new_sock) != 0) {
            perror("Could not create thread");
        }
    }

    close(server_fd);
    pthread_mutex_destroy(&mutex);
    return 0;
}