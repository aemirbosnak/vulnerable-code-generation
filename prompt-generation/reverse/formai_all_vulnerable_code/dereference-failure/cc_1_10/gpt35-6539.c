//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Checking for command line arguments
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Creating socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Cannot create socket");
        exit(1);
    }

    // Getting host information from DNS
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR: No such host: %s\n", argv[1]);
        exit(1);
    }

    // Creating server address
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connecting to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Cannot connect to server");
        exit(1);
    }

    // Variable initialization
    char buffer[BUFFER_SIZE];
    int n;

    // Reading server response
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        perror("ERROR: Cannot read server response");
        exit(1);
    }

    // Printing server response
    buffer[n] = '\0';
    printf("Server Response: %s\n", buffer);

    // Sending user credentials to server
    char username[255], password[255];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR: Cannot send username to server");
        exit(1);
    }
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    buffer[n] = '\0';
    printf("Server Response: %s\n", buffer);
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR: Cannot send password to server");
        exit(1);
    }
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    buffer[n] = '\0';
    printf("Server Response: %s\n", buffer);

    // Listing emails
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR: Cannot send LIST command to server");
        exit(1);
    }
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    buffer[n] = '\0';
    printf("Server Response: %s\n", buffer);

    // Quitting connection
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR: Cannot send QUIT command to server");
        exit(1);
    }
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    buffer[n] = '\0';
    printf("Server Response: %s\n", buffer);

    close(sockfd);
    return 0;
}