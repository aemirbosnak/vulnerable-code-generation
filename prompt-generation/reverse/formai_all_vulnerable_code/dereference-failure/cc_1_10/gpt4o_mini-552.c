//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void create_socket(int *sockfd) {
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("ERROR opening socket");
    }
}

void connect_to_server(int sockfd, struct sockaddr_in server_address) {
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error("ERROR connecting to server");
    }
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("ERROR sending command");
    }
}

void receive_response(int sockfd, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        error("ERROR receiving response");
    }
}

void authenticate_ftp(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, BUFFER_SIZE, "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd, buffer);
    printf("Response: %s", buffer);
    
    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd, buffer);
    printf("Response: %s", buffer);
}

void list_files(int sockfd) {
    char buffer[BUFFER_SIZE];
    
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd, buffer);
    printf("Response: %s", buffer);

    // Example: Extracting IP and Port for Passive mode
    int p1, p2;
    if (sscanf(buffer, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &p1, &p2) != 2) {
        fprintf(stderr, "Couldn't parse PASV response\n");
        return;
    }
    
    int data_port = p1 * 256 + p2;
    
    struct sockaddr_in data_address;
    data_address.sin_family = AF_INET;
    data_address.sin_addr.s_addr = INADDR_ANY;
    data_address.sin_port = htons(data_port);
    
    int data_sockfd;
    create_socket(&data_sockfd);
    
    connect_to_server(data_sockfd, data_address);
    
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd, buffer);
    printf("Response: %s", buffer);

    while (recv(data_sockfd, buffer, BUFFER_SIZE - 1, 0) > 0) {
        printf("File: %s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(data_sockfd);
    receive_response(sockfd, buffer);
    printf("Response: %s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    int sockfd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    create_socket(&sockfd);
    
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy((char *)&server_address.sin_addr.s_addr, (char *)server->h_addr_list[0], server->h_length);
    server_address.sin_port = htons(PORT);

    connect_to_server(sockfd, server_address);

    receive_response(sockfd, buffer);
    printf("Response: %s", buffer);
    
    authenticate_ftp(sockfd, username, password);

    list_files(sockfd);

    close(sockfd);
    return 0;
}