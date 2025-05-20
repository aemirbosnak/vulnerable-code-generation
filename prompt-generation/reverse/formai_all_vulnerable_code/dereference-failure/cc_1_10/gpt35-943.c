//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, bytes_received;
    char buffer[BUFFER_SIZE], *command;
    struct sockaddr_in server_address;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send username to server
    printf("Username: ");
    scanf("%s", buffer);
    command = (char *) malloc(strlen(buffer) + 6);
    sprintf(command, "USER %s\r\n", buffer);
    send(client_socket, command, strlen(command), 0);
    free(command);

    // Receive response from server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send password to server
    printf("Password: ");
    scanf("%s", buffer);
    command = (char *) malloc(strlen(buffer) + 6);
    sprintf(command, "PASS %s\r\n", buffer);
    send(client_socket, command, strlen(command), 0);
    free(command);

    // Receive response from server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Enter passive mode
    send(client_socket, "PASV\r\n", 6, 0);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';

    // Parse pasv response
    printf("Pasv response: %s", buffer);

    char *port_start = strchr(buffer, '(');
    char *port_end = strchr(port_start, ')');
    *port_end = '\0';

    char *h1, *h2, *h3, *h4, *p1, *p2;
    h1 = strtok(port_start + 1, ",");
    h2 = strtok(NULL, ",");
    h3 = strtok(NULL, ",");
    h4 = strtok(NULL, ",");
    p1 = strtok(NULL, ",");
    p2 = strtok(NULL, ",");

    char data_ip[BUFFER_SIZE];
    sprintf(data_ip, "%s.%s.%s.%s", h1, h2, h3, h4);
    int data_port = atoi(p1) * 256 + atoi(p2);

    printf("Data IP: %s\n", data_ip);
    printf("Data port: %d\n", data_port);

    // Connect to data socket
    struct sockaddr_in data_address;

    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket < 0) {
        perror("Error creating data socket");
        exit(EXIT_FAILURE);
    }

    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(data_port);
    data_address.sin_addr.s_addr = inet_addr(data_ip);

    if (connect(data_socket, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) {
        perror("Error connecting to data socket");
        exit(EXIT_FAILURE);
    }

    // List directory
    send(client_socket, "LIST\r\n", 6, 0);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    while ((bytes_received = recv(data_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close sockets
    close(data_socket);
    close(client_socket);

    return 0;
}