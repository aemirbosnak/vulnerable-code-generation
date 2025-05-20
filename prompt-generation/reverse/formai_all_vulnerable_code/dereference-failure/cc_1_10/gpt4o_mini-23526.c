//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_ftp(const char *hostname, int *control_socket) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create socket
    *control_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (*control_socket < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host: %s\n", hostname);
        exit(0);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(*control_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(*control_socket, buffer, BUFFER_SIZE - 1);
    printf("Server: %s", buffer);
}

void send_command(int control_socket, const char *command, char *response) {
    write(control_socket, command, strlen(command));
    write(control_socket, "\r\n", 2); // FTP commands end with CRLF
    read(control_socket, response, BUFFER_SIZE - 1);
    printf("Server: %s", response);
}

void login(int control_socket, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    // Send USER command
    send_command(control_socket, username, response);

    // Send PASS command
    send_command(control_socket, password, response);
}

void list_files(int control_socket) {
    char response[BUFFER_SIZE];

    // Set the transfer mode to passive
    send_command(control_socket, "PASV", response);

    // Extract the IP address and port for data connection
    int p1, p2;
    sscanf(response, "%*s %*s %*s %*s %*s %*s %d,%d", &p1, &p2);
    int data_port = (p1 * 256) + p2;

    // Create data socket
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    memset((char *)&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    data_addr.sin_port = htons(data_port);

    if (bind(data_socket, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("ERROR on binding data socket");
    }

    listen(data_socket, 1);

    // Send the LIST command
    send_command(control_socket, "LIST", response);

    // Accept the connection
    int new_socket = accept(data_socket, NULL, NULL);
    if (new_socket < 0) {
        error("ERROR on accept");
    }

    // Read the file list
    char file_list[BUFFER_SIZE];
    while (read(new_socket, file_list, BUFFER_SIZE - 1) > 0) {
        printf("%s", file_list);
        memset(file_list, 0, BUFFER_SIZE);
    }

    close(new_socket);
    close(data_socket);
}

void disconnect(int control_socket) {
    char response[BUFFER_SIZE];
    send_command(control_socket, "QUIT", response);
    close(control_socket);
    printf("Disconnected from server\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    int control_socket;

    connect_to_ftp(hostname, &control_socket);
    login(control_socket, username, password);
    list_files(control_socket);
    disconnect(control_socket);

    return 0;
}