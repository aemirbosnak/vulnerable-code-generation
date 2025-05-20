//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

void connect_to_server(char *ip_address, int port) {
    struct sockaddr_in server_address;
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(-1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server\n");
        exit(-1);
    }

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    read(client_socket, buffer, MAX_BUFFER_SIZE);

    printf("%s\n", buffer);

    while (1) {
        printf("Enter your username: ");
        char username[MAX_BUFFER_SIZE];
        fgets(username, MAX_BUFFER_SIZE, stdin);
        username[strlen(username) - 1] = '\0';

        printf("Enter your password: ");
        char password[MAX_BUFFER_SIZE];
        fgets(password, MAX_BUFFER_SIZE, stdin);
        password[strlen(password) - 1] = '\0';

        char user_command[MAX_BUFFER_SIZE];
        snprintf(user_command, MAX_BUFFER_SIZE, "USER %s\r\n", username);
        write(client_socket, user_command, strlen(user_command));

        char user_response[MAX_BUFFER_SIZE];
        memset(user_response, 0, MAX_BUFFER_SIZE);
        read(client_socket, user_response, MAX_BUFFER_SIZE);

        if (strncmp(user_response, "+OK", 3) != 0) {
            printf("Invalid username. Please try again.\n");
            continue;
        }

        char pass_command[MAX_BUFFER_SIZE];
        snprintf(pass_command, MAX_BUFFER_SIZE, "PASS %s\r\n", password);
        write(client_socket, pass_command, strlen(pass_command));

        char pass_response[MAX_BUFFER_SIZE];
        memset(pass_response, 0, MAX_BUFFER_SIZE);
        read(client_socket, pass_response, MAX_BUFFER_SIZE);

        if (strncmp(pass_response, "+OK", 3) != 0) {
            printf("Invalid password. Please try again.\n");
            continue;
        }

        printf("Successfully logged in!\n");
        break;
    }

    while (1) {
        printf("Enter command (QUIT to exit): ");
        char command[MAX_BUFFER_SIZE];
        fgets(command, MAX_BUFFER_SIZE, stdin);
        command[strlen(command) - 1] = '\0';

        if (strncmp(command, "QUIT", 4) == 0) {
            write(client_socket, "QUIT\r\n", 6);

            char quit_response[MAX_BUFFER_SIZE];
            memset(quit_response, 0, MAX_BUFFER_SIZE);
            read(client_socket, quit_response, MAX_BUFFER_SIZE);

            printf("%s\n", quit_response);
            break;
        }

        write(client_socket, command, strlen(command));

        char response[MAX_BUFFER_SIZE];
        memset(response, 0, MAX_BUFFER_SIZE);
        read(client_socket, response, MAX_BUFFER_SIZE);

        printf("%s\n", response);
    }

    close(client_socket);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(-1);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    connect_to_server(ip_address, port);

    return 0;
}