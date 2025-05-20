//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char *command = "USER anonymous";

    // Step 1: Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Step 2: Connect to server
    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21); // default port

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Step 3: Login
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("ERROR sending command");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }
    printf("Login successful\n");

    // Step 4: Change directory
    command = "cd /path/to/directory";
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("ERROR sending command");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }
    printf("Changed directory\n");

    // Step 5: Download file
    command = "get filename.txt";
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("ERROR sending command");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }
    printf("Downloading file\n");

    // Step 6: Close socket
    close(sockfd);

    return 0;
}