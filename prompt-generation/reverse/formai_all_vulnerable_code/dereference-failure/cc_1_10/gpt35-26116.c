//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
// POP3 Client Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define MAX_MSG_LEN 1024
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_MSG_LEN];
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Get server details
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Get username and password
    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LEN, stdin);
    password[strcspn(password, "\n")] = '\0';

    // Send username to server
    bzero(buffer, MAX_MSG_LEN);
    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer, MAX_MSG_LEN);
    n = read(sockfd, buffer, MAX_MSG_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    // Send password to server
    bzero(buffer, MAX_MSG_LEN);
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer, MAX_MSG_LEN);
    n = read(sockfd, buffer, MAX_MSG_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    // Authenticate with server
    if (strstr(buffer, "+OK") == NULL) {
        fprintf(stderr, "Authentication failed\n");
        exit(1);
    }

    // Get list of messages
    bzero(buffer, MAX_MSG_LEN);
    strcpy(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer, MAX_MSG_LEN);
    n = read(sockfd, buffer, MAX_MSG_LEN);
    if (n < 0)
        error("ERROR reading from socket");
    
    // Print list of messages
    printf("%s", buffer);

    // Get message number
    printf("Enter message number: ");
    fgets(buffer, MAX_MSG_LEN, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    // Retrieve message
    bzero(buffer, MAX_MSG_LEN);
    sprintf(buffer, "RETR %s\r\n", buffer);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer, MAX_MSG_LEN);
    n = read(sockfd, buffer, MAX_MSG_LEN);
    if (n < 0)
        error("ERROR reading from socket");

    // Print message
    while (strstr(buffer, ".\r\n") == NULL) {
        printf("%s", buffer);
        bzero(buffer, MAX_MSG_LEN);
        n = read(sockfd, buffer, MAX_MSG_LEN);
        if (n < 0)
            error("ERROR reading from socket");
    }

    // Quit session with server
    bzero(buffer, MAX_MSG_LEN);
    strcpy(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // Close connection
    close(sockfd);

    return 0;
}