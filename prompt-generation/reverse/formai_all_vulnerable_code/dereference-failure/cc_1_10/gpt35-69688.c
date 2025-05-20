//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check if all arguments are supplied
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    // Convert port number from string to integer
    portno = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Fill in server details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Read response from server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send request to server for authentication
    char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    printf("Username: ");
    fgets(username, MAX_BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    sprintf(buffer, "USER %sPASS %s\n", username, password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send request to server for list of emails
    sprintf(buffer, "LIST\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);
    
    return 0;
}