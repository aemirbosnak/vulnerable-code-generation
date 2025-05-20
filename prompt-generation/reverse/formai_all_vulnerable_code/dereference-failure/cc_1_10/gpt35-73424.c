//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define POP3_SERVER_PORT 110

// Function to print error message and exit
void error(char *msg)
{
    perror(msg);
    exit(0);
}

// Function to read response from server
void readResponse(int sockfd, char* buffer)
{
    bzero(buffer, MAX_BUFFER_SIZE);
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
        error("Error reading socket");
    printf("%s", buffer);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname username\n", argv[0]);
       exit(0);
    }
    portno = POP3_SERVER_PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("Error connecting");
    readResponse(sockfd, buffer); // Welcome message

    // Sending username
    char username[MAX_BUFFER_SIZE];
    sprintf(username, "USER %s\r\n", argv[2]);
    n = write(sockfd, username, strlen(username));
    if (n < 0)
         error("Error writing to socket");
    readResponse(sockfd, buffer); // Response to USER command

    // Sending password
    char password[MAX_BUFFER_SIZE];
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(password, "PASS %s\r\n", password);
    n = write(sockfd, password, strlen(password));
    if (n < 0)
         error("Error writing to socket");
    readResponse(sockfd, buffer); // Response to PASS command

    // Fetching mailbox status
    n = write(sockfd, "STAT\r\n", strlen("STAT\r\n"));
    if (n < 0)
         error("Error writing to socket");
    readResponse(sockfd, buffer); // Response to STAT command

    close(sockfd);
    return 0;
}