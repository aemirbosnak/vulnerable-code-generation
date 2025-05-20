//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    char command[256];

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Create server address/port structure
    portno = 21; // Default port for FTP
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Resolve server name to IP address
    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        perror("Error, no such host");
        exit(1);
    }

    // Copy address into serv_addr structure
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("FTP client connected to %s\n", server->h_name);

    // Send username
    strcpy(command, "USER anonymous\r\n");
    send(sockfd, command, strlen(command), 0);

    // Send password
    strcpy(command, "PASS <your_password>\r\n");
    send(sockfd, command, strlen(command), 0);

    // Send FTP commands
    strcpy(command, "PWD\r\n");
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("Error receiving PWD command");
        exit(1);
    }
    printf("Remote system: %s\n", buffer);

    strcpy(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("Error receiving LIST command");
        exit(1);
    }
    printf("File list: %s\n", buffer);

    strcpy(command, "QUIT\r\n");
    send(sockfd, command, strlen(command), 0);
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("Error receiving QUIT command");
        exit(1);
    }
    printf("Remote system: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}