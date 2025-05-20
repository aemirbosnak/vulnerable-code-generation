//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1234

// Structure to represent the robot's position and task
typedef struct {
    int x;
    int y;
    char task;
} robot_t;

// Function to create a new robot and return its address
robot_t *create_robot(void) {
    robot_t *robot = (robot_t *) malloc(sizeof(robot_t));
    robot->x = 0;
    robot->y = 0;
    robot->task = 'n'; // 'n' for none
    return robot;
}

// Function to move the robot to a new position
void move_robot(robot_t *robot, int x, int y) {
    robot->x = x;
    robot->y = y;
}

// Function to perform a task
void perform_task(robot_t *robot, char task) {
    robot->task = task;
}

// Function to send the robot's position and task to the client
void send_robot_state(int sock, robot_t *robot) {
    char buffer[10];
    sprintf(buffer, "%d %d %c", robot->x, robot->y, robot->task);
    send(sock, buffer, strlen(buffer), 0);
}

// Function to handle incoming connections and send the robot's state
void handle_connection(int sock) {
    robot_t *robot = create_robot();
    while (1) {
        char buffer[10];
        recv(sock, buffer, 10, 0);
        int x, y;
        char task;
        sscanf(buffer, "%d %d %c", &x, &y, &task);
        move_robot(robot, x, y);
        perform_task(robot, task);
        send_robot_state(sock, robot);
    }
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(sock, 3);
    printf("Listening for connections...\n");

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_connection(client_sock);
        close(client_sock);
    }

    return 0;
}