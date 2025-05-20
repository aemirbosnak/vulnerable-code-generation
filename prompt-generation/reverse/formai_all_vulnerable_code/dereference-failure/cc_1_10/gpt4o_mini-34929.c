//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function prototypes
void *movement_control(void *arg);
void *status_report(void *arg);
void *sensor_control(void *arg);

typedef struct {
    int sock;
    char *movement_command;
} control_args;

pthread_mutex_t lock;

int main() {
    pthread_t movement_thread, status_thread, sensor_thread;
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Set address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Create the threads
    pthread_create(&movement_thread, NULL, movement_control, NULL);
    pthread_create(&status_thread, NULL, status_report, NULL);
    pthread_create(&sensor_thread, NULL, sensor_control, NULL);

    printf("Robot control server is running on port %d...\n", PORT);
    
    // Accept incoming connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        memset(buffer, 0, BUFFER_SIZE);
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Command received: %s\n", buffer);
        
        pthread_mutex_lock(&lock);
        control_args *args = malloc(sizeof(control_args));
        args->sock = new_socket;
        args->movement_command = strdup(buffer);
        pthread_create(&movement_thread, NULL, movement_control, args);
        pthread_mutex_unlock(&lock);
    }

    // Clean up
    pthread_join(movement_thread, NULL);
    pthread_join(status_thread, NULL);
    pthread_join(sensor_thread, NULL);
    close(server_fd);
    return 0;
}

// Movement control thread
void *movement_control(void *arg) {
    control_args *args = (control_args *)arg;
    char *command = args->movement_command;
    
    if (strcmp(command, "FORWARD") == 0) {
        printf("Moving forward...\n");
    }
    else if (strcmp(command, "BACKWARD") == 0) {
        printf("Moving backward...\n");
    }
    else if (strcmp(command, "LEFT") == 0) {
        printf("Turning left...\n");
    }
    else if (strcmp(command, "RIGHT") == 0) {
        printf("Turning right...\n");
    }
    else {
        printf("Unknown command.\n");
    }

    send(args->sock, "Command executed", strlen("Command executed"), 0);
    free(args->movement_command);
    free(args);
    close(args->sock);
    return NULL;
}

// Status reporting thread
void *status_report(void *arg) {
    while(1) {
        sleep(5);
        printf("Current status: Robot is operational.\n");
    }
    return NULL;
}

// Sensor control thread
void *sensor_control(void *arg) {
    while(1) {
        sleep(3);
        printf("Sensors check: All systems functional.\n");
    }
    return NULL;
}