//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Structures to represent the noble FTP Client
typedef struct {
    char hostname[100];
    char username[50];
    char password[50];
    int port;
} FTPClient;

// Aquire server's favor
void aquire_server_favor(FTPClient *client) {
    printf("Thou art entering the realm of the FTP server: %s\n", client->hostname);
    printf("With noble username: %s\n", client->username);
}

// Establish a connection to the remote kingdom
int connect_to_server(FTPClient *client) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Alas, the socket could not be forged!\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);
    inet_pton(AF_INET, client->hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "The connection to the server has been thwarted!\n");
        exit(EXIT_FAILURE);
    }
    printf("Connection to the server hath been established!\n");
    return sockfd;
}

// Send command to the server
void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent command: %s", command);
}

// Receive response from the server
void receive_response(int sockfd) {
    char buffer[1024];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        fprintf(stderr, "Oh no! The response from the server was lost!\n");
        return;
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received data
    printf("Response from server: %s\n", buffer);
}

// Send authentication credentials
void send_authentication(int sockfd, FTPClient *client) {
    char command[256];
    sprintf(command, "USER %s\r\n", client->username);
    send_command(sockfd, command);
    receive_response(sockfd);

    sprintf(command, "PASS %s\r\n", client->password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Main quest begins here
int main() {
    FTPClient *client = malloc(sizeof(FTPClient));
    strcpy(client->hostname, "ftp.example.com");
    strcpy(client->username, "noble_user");
    strcpy(client->password, "sacred_password");
    client->port = 21;

    aquire_server_favor(client);
    int sockfd = connect_to_server(client);
    send_authentication(sockfd, client);

    // Here we could continue to implement more commands like LIST, RETR, STOR, etc.

    // Clean up and close the connection to the kingdom
    close(sockfd);
    free(client);
    return 0;
}