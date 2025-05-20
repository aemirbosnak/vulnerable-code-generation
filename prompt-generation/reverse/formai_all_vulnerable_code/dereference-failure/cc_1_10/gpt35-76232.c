//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_address> <port_number> <sender_email>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);
    char *sender_email = argv[3];

    // create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // set server address structure
    struct sockaddr_in server_address_struct;
    server_address_struct.sin_family = AF_INET;
    server_address_struct.sin_port = htons(port_number);
    inet_pton(AF_INET, server_address, &server_address_struct.sin_addr);

    // connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address_struct, sizeof(server_address_struct)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // read server greeting
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    if (read(client_socket, buffer, MAX_BUFFER) == -1) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // send HELO command
    char helo_command[MAX_BUFFER];
    sprintf(helo_command, "HELO %s\r\n", server_address);
    if (send(client_socket, helo_command, strlen(helo_command), 0) == -1) {
        perror("Error sending HELO command");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAX_BUFFER);
    if (read(client_socket, buffer, MAX_BUFFER) == -1) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // send MAIL FROM command
    char mail_from_command[MAX_BUFFER];
    sprintf(mail_from_command, "MAIL FROM:<%s>\r\n", sender_email);
    if (send(client_socket, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAX_BUFFER);
    if (read(client_socket, buffer, MAX_BUFFER) == -1) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s\n", buffer);

    close(client_socket);
    return 0;
}