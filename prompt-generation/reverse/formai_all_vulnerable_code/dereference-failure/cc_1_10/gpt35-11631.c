//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
/* FTP Client Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int openConnection(char *hostname, int port) {
    int sockfd;
    struct hostent *he;
    struct sockaddr_in server_addr;

    if ((he = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: Invalid hostname\n");
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: Unable to create socket\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
        fprintf(stderr, "Error: Unable to connect\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void sendCommand(int sockfd, char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error: Unable to send command\n");
        exit(EXIT_FAILURE);
    }
}

void receiveResponse(int sockfd, char *response) {
    if (recv(sockfd, response, BUFFER_SIZE, 0) < 0) {
        fprintf(stderr, "Error: Unable to receive response\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    char *hostname, *username, *password, *filename;
    int port, sockfd;
    char command[BUFFER_SIZE], response[BUFFER_SIZE];

    if (argc != 6) {
        fprintf(stderr, "Usage: %s hostname port username password filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
    filename = argv[5];

    sockfd = openConnection(hostname, port);

    receiveResponse(sockfd, response);
    printf("%s", response); // Display Welcome message

    sprintf(command, "USER %s\r\n", username);
    sendCommand(sockfd, command);
    receiveResponse(sockfd, response);
    printf("%s", response); // Display response to USER command

    sprintf(command, "PASS %s\r\n", password);
    sendCommand(sockfd, command);
    receiveResponse(sockfd, response);
    printf("%s", response); // Display response to PASS command

    sprintf(command, "TYPE I\r\n");
    sendCommand(sockfd, command);
    receiveResponse(sockfd, response);
    printf("%s", response); // Display response to TYPE command

    sprintf(command, "SIZE %s\r\n", filename);
    sendCommand(sockfd, command);
    receiveResponse(sockfd, response);
    printf("%s", response); // Display response to SIZE command (returns file size in bytes)

    sprintf(command, "RETR %s\r\n", filename);
    sendCommand(sockfd, command);
    receiveResponse(sockfd, response);
    printf("%s", response); // Display response to RETR command

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file for writing\n");
        exit(EXIT_FAILURE);
    }

    int bytes_received;
    char buffer[BUFFER_SIZE];
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);

    close(sockfd);

    printf("File downloaded successfully\n");

    return 0;
}