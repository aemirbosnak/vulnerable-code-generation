//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 512
#define POP3_PORT 110
#define BUFFER_SIZE 1024

char *server_address;
int server_port;
int server_socket;

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        close(server_socket);
        exit(0);
    }
}

void send_command(char *command) {
    send(server_socket, command, strlen(command), 0);
}

void receive_response(char *response) {
    memset(response, 0, MAX_COMMAND_LENGTH);
    int bytes_received = recv(server_socket, response, MAX_COMMAND_LENGTH - 1, 0);
    if (bytes_received <= 0) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }
    response[bytes_received] = '\0';
    printf("%s", response);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server_address> <port> <username>\n", argv[0]);
        exit(1);
    }

    server_address = argv[1];
    server_port = atoi(argv[2]);
    char *username = argv[3];

    signal(SIGINT, signal_handler);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    char auth_command[MAX_COMMAND_LENGTH];
    sprintf(auth_command, "USER %s\r\n", username);
    send_command(auth_command);
    receive_response(auth_command);

    char pass_command[MAX_COMMAND_LENGTH];
    sprintf(pass_command, "PASS %s\r\n", username);
    send_command(pass_command);
    receive_response(pass_command);

    char list_command[MAX_COMMAND_LENGTH];
    sprintf(list_command, "LIST\r\n");
    send_command(list_command);
    receive_response(list_command);

    close(server_socket);
    return 0;
}