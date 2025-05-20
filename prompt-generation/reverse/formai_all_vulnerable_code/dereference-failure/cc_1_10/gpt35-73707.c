//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int create_connection(const char *hostname, int port) {
    struct sockaddr_in server_address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create TCP socket");
        return -1;
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        perror("Failed to get host by name");
        close(sockfd);
        return -1;
    }

    memset((char *) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy((char *) &server_address.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port> [username]\n", argv[0]);
        return 0;
    }

    int sockfd = create_connection(argv[1], atoi(argv[2]));
    if (sockfd < 0) {
        printf("Error connecting to server\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Server: %s\n", buffer);
    }

    char command[BUFFER_SIZE];
    char *username = NULL;
    if (argc == 4) {
        username = argv[3];
        sprintf(command, "USER %s\r\n", username);
    } else {
        printf("Enter username: ");
        scanf("%s", buffer);
        username = buffer;
        sprintf(command, "USER %s\r\n", username);
    }

    send(sockfd, command, strlen(command), 0);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        printf("Server: %s\n", buffer);
    }

    printf("Enter password: ");
    char *password = getpass("");
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        printf("Server: %s\n", buffer);
    }

    char filename[BUFFER_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    sprintf(command, "RETR %s\r\n", filename);
    send(sockfd, command, strlen(command), 0);

    int filefd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (filefd < 0) {
        printf("Error opening file %s for writing: %s\n", filename, strerror(errno));
        close(sockfd);
        return -1;
    }

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        write(filefd, buffer, bytes_received);
    }

    close(filefd);
    close(sockfd);
    return 0;
}