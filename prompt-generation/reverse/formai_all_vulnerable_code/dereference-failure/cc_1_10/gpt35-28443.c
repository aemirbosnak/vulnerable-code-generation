//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080

typedef struct {
    bool up;
    bool down;
    bool left;
    bool right;
} directions_t;

void *remote_controller(void *arg){
    directions_t *directions_ptr = (directions_t *) arg;
    char command;
    while(true){
        // Get input from user
        printf("Please enter the direction (u for up, d for down, l for left, r for right): ");
        scanf("%c", &command);
        getchar();

        // Update the directions
        switch(command){
            case 'u':
                directions_ptr->up = true;
                break;

            case 'd':
                directions_ptr->down = true;
                break;

            case 'l':
                directions_ptr->left = true;
                break;

            case 'r':
                directions_ptr->right = true;
                break;

            default:
                printf("Invalid input\n");
        }
    }
}

void *drone_controller(void *arg){
    directions_t *directions_ptr = (directions_t *) arg;
    int socket_fd;
    struct sockaddr_in server_address, drone_address;
    char buffer[1024] = {0};

    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Fill server information
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket with the server address
    if (bind(socket_fd, (const struct sockaddr *)&server_address, sizeof(server_address)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    int len, bytes_sent;
    while(true){
        // Reset the directions
        directions_ptr->up = false;
        directions_ptr->down = false;
        directions_ptr->left = false;
        directions_ptr->right = false;

        // Get the input directions
        pthread_join(pthread_create(&remote_controller, NULL, remote_controller, directions_ptr), NULL);

        // Send the input directions to the drone
        if (directions_ptr->up){
            bytes_sent = sendto(socket_fd, "up", strlen("up"), 0, (const struct sockaddr *)&drone_address, sizeof(drone_address));
            if (bytes_sent == -1) perror("Could not send the message");
        }

        if (directions_ptr->down){
            bytes_sent = sendto(socket_fd, "down", strlen("down"), 0, (const struct sockaddr *)&drone_address, sizeof(drone_address));
            if (bytes_sent == -1) perror("Could not send the message");
        }

        if (directions_ptr->left){
            bytes_sent = sendto(socket_fd, "left", strlen("left"), 0, (const struct sockaddr *)&drone_address, sizeof(drone_address));
            if (bytes_sent == -1) perror("Could not send the message");
        }

        if (directions_ptr->right){
            bytes_sent = sendto(socket_fd, "right", strlen("right"), 0, (const struct sockaddr *)&drone_address, sizeof(drone_address));
            if (bytes_sent == -1) perror("Could not send the message");
        }

        sleep(1);
    }
}

int main(){
    pthread_t drone_controller_thread;
    directions_t *directions_ptr = (directions_t *) malloc(sizeof(directions_t));

    // Initialize the directions
    directions_ptr->up = false;
    directions_ptr->down = false;
    directions_ptr->left = false;
    directions_ptr->right = false;

    // Create the drone controller thread
    pthread_create(&drone_controller_thread, NULL, drone_controller, directions_ptr);

    // Join the drone controller thread
    pthread_join(drone_controller_thread, NULL);

    free(directions_ptr);
    return 0;
}