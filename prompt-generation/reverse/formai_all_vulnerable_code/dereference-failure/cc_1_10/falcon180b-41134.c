//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];
    char command[MAX_COMMAND_LENGTH];
    int n;

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port_number> <command>\n");
        return 1;
    }

    // Convert the server IP and port number from string to integer
    portno = atoi(argv[2]);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        return 1;
    }

    // Send command to server
    sprintf(sendbuffer, "%s\r\n", argv[3]);
    if (send(sockfd, sendbuffer, strlen(sendbuffer), 0) < 0) {
        printf("Error: Unable to send command to server\n");
        return 1;
    }

    // Receive response from server
    n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Error: Unable to receive response from server\n");
        return 1;
    }

    printf("Server response:\n%s", recvbuffer);

    // Close socket
    close(sockfd);

    return 0;
}