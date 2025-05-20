//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: distributed
// temperature_monitor.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_SENSORS 5
#define BUFFER_SIZE 256
#define SERVER_PORT 8080
#define SENSOR_PORT 8081

typedef struct {
    int id;
    float temperature;
} Sensor;

Sensor sensors[MAX_SENSORS];

void *sensor_thread(void *arg) {
    int sensor_id = *(int *)arg;
    free(arg);
    while (1) {
        sensors[sensor_id].temperature = (rand() % 100) + (float)(rand() % 100) / 100; // Simulated random temperature
        printf("Sensor %d: Reporting temperature %.2f°C\n", sensor_id, sensors[sensor_id].temperature);
        sleep(2); // Send every 2 seconds
    }
    return NULL;
}

void *server_thread(void *arg) {
    int sock_fd, new_sock_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock_fd, 3);

    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        new_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (new_sock_fd < 0) {
            perror("Failed to accept connection");
            continue;
        }
        
        recv(new_sock_fd, buffer, BUFFER_SIZE, 0);
        printf("Server: Received data from sensor: %s\n", buffer);
        
        close(new_sock_fd);
    }
    close(sock_fd);
    return NULL;
}

int main() {
    srand(time(NULL));
    
    // Initialize sensors
    for (int i = 0; i < MAX_SENSORS; i++) {
        sensors[i].id = i;
        sensors[i].temperature = 0.0;
    }

    pthread_t sensor_ids[MAX_SENSORS];
    pthread_t server_id;

    // Start server thread
    if (pthread_create(&server_id, NULL, server_thread, NULL) != 0) {
        perror("Failed to create server thread");
        return EXIT_FAILURE;
    }

    // Start sensor threads
    for (int i = 0; i < MAX_SENSORS; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        
        if (pthread_create(&sensor_ids[i], NULL, sensor_thread, arg) != 0) {
            perror("Failed to create sensor thread");
            return EXIT_FAILURE;
        }
    }

    // Main thread waits for sensor threads to complete
    for (int i = 0; i < MAX_SENSORS; i++) {
        pthread_join(sensor_ids[i], NULL);
    }

    pthread_join(server_id, NULL);
    return 0;
}