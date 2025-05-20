//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFF_SIZE];
    char username[MAX_BUFF_SIZE], password[MAX_BUFF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get server IP address using hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    // Set up server address struct
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Get username and password from user
    printf("Enter Email Address: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Send login command to server
    sprintf(buffer, "LOGIN %s %s\n", username, password);
    write(sockfd, buffer, strlen(buffer));

    // Read server response
    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send select command to server to choose mailbox
    write(sockfd, "SELECT INBOX\n", strlen("SELECT INBOX\n"));

    // Read server response
    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send fetch command to server to get message
    write(sockfd, "FETCH 1 BODY[TEXT]\n", strlen("FETCH 1 BODY[TEXT]\n"));

    // Read server response
    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sockfd);
    
    return 0;
}