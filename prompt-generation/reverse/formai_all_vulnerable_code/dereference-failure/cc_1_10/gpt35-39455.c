//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

void receive(int socket, char **buffer) {
    int current_size = 0;
    int buff_size = MAX_BUFF_SIZE;
    char *temp_buffer = malloc(buff_size);
    int received;
    do {
        received = recv(socket, temp_buffer + current_size, MAX_BUFF_SIZE, 0);
        if (received < 0) {
            printf("Error while receiving data from server\n");
            exit(1);
        }
        current_size += received;
        if (current_size == buff_size) {
            buff_size += MAX_BUFF_SIZE;
            temp_buffer = realloc(temp_buffer, buff_size);
        }
    } while (received == MAX_BUFF_SIZE);

    *buffer = temp_buffer;

    return;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\nUsage: %s <server> <port> <username>\n", argv[0]);
        return -1;
    }

    char *server = argv[1];
    char *username = argv[3];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;

    // Create socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return -1;
    }

    // Fill in server_address details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server);
    server_address.sin_port = htons(port);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    // Receive server response
    char *buffer;
    receive(socket_desc, &buffer);

    printf("Server response: %s\n", buffer);

    free(buffer);

    // Login
    char user_cmd[MAX_BUFF_SIZE];
    sprintf(user_cmd, "1 LOGIN %s\r\n", username);
    send(socket_desc, user_cmd, strlen(user_cmd), 0);

    // Receive server response
    receive(socket_desc, &buffer);
    printf("Server response: %s\n", buffer);

    free(buffer);

    // Logout
    char logout_cmd[] = "1 LOGOUT\r\n";
    send(socket_desc, logout_cmd, strlen(logout_cmd), 0);

    // Receive server response
    receive(socket_desc, &buffer);
    printf("Server response: %s\n", buffer);

    free(buffer);

    close(socket_desc);

    return 0;
}