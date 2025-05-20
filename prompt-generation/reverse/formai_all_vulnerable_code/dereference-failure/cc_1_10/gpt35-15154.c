//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    // Check if server address and port are provided as arguments
    if(argc != 3) {
        perror("Please provide server address and port as command line arguments.");
        return 1;
    }

    // Create socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        perror("Failed to create socket");
        return 1;
    }

    // Server address and port
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect");
        return 1;
    }

    // Get server response
    char response[BUFFER_SIZE];
    if(recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        return 1;
    }

    printf("%s", response);

    // Login credentials
    char user[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    printf("Username: ");
    fgets(user, BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);

    // Authenticate login credentials
    char login_buffer[BUFFER_SIZE];
    sprintf(login_buffer, "USER %sPASS %s", user, password);
    if(send(socket_desc, login_buffer, strlen(login_buffer), 0) < 0) {
        perror("Failed to send login credentials");
        return 1;
    }

    // Get server response
    if(recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        return 1;
    }

    printf("%s", response);

    // List all emails
    if(send(socket_desc, "LIST\n", strlen("LIST\n"), 0) < 0) {
        perror("Failed to send LIST command");
        return 1;
    }

    // Get server response
    if(recv(socket_desc, response, BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        return 1;
    }

    printf("%s", response);

    close(socket_desc);

    return 0;
}