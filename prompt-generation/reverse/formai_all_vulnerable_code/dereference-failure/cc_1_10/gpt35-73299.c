//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // check if enough arguments are passed
    if (argc != 3) {
        printf("Usage: %s [IP Address] [port number]\n", argv[0]);
        return 1;
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // define server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid IP Address");
        return 1;
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // send FTP command to server
    char command[BUFFER_SIZE];
    printf("Enter FTP Command: ");
    fgets(command, BUFFER_SIZE, stdin);
    write(sockfd, command, strlen(command));

    // receive response from server
    char response[BUFFER_SIZE];
    int bytes_received = read(sockfd, response, BUFFER_SIZE);
    if (bytes_received < 0) {
        perror("Error receiving response");
        return 1;
    }

    // print server response
    printf("Response: %s", response);

    // close socket
    close(sockfd);
    return 0;
}