//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
/*
* The following program simulates a client-server architecture where the server sends the current date and time to the client.
* The client displays the date and time received from the server.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};

    // Get the current time
    time_t current_time;
    char* time_string;
    current_time = time(NULL);
    time_string = ctime(&current_time);

    printf("Current time is %s\n", time_string);

    // Send the time to the client
    send(new_socket, time_string, strlen(time_string), 0);

    printf("Time sent to client.\n");

    // Receive confirmation from the client
    valread = read(new_socket, buffer, 1024);

    printf("%s\n", buffer);

    close(new_socket);
    close(server_fd);

    return 0;
}