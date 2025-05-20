//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

// Welcome to the mind-bending realm of FTP clients, where cryptic commands dance and electrons navigate treacherous tunnels.

// Prepare for the interstellar journey by gathering the celestial coordinates.
struct sockaddr_in server;
int sockfd;

// Decode the cosmic runes to establish a connection with the distant server.
void connect_to_server(char *hostname, int port) {
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Invalid hostname.\n");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = **(struct in_addr **)host->h_addr_list;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }
}

// Initiate the ethereal exchange of data with the server.
void send_command_and_retrieve_response(char *command) {
    char response[512];
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, sizeof(response), 0);
    printf("%s\n", response);
}

// Embark on an interstellar journey to retrieve a celestial treasure.
void retrieve_file(char *filename) {
    char command[512];
    sprintf(command, "RETR %s", filename);
    send_command_and_retrieve_response(command);
    int file = open(filename, O_WRONLY | O_CREAT, 0644);
    if (file < 0) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }
    char buffer[512];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        write(file, buffer, bytes_received);
    }
    close(file);
    printf("File received successfully.\n");
}

// Ascend to the ethereal realm and present the celestial coordinates for the server's guidance.
void main() {
    char hostname[256];
    int port;
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port: ");
    scanf("%d", &port);
    connect_to_server(hostname, port);
    char command[512];
    while (1) {
        printf("Enter FTP command (USER, PASS, RETR, QUIT): ");
        scanf("%s", command);
        if (strcmp(command, "QUIT") == 0) {
            break;
        }
        send_command_and_retrieve_response(command);
        if (strcmp(command, "RETR") == 0) {
            char filename[256];
            printf("Enter filename: ");
            scanf("%s", filename);
            retrieve_file(filename);
        }
    }
    close(sockfd);
}