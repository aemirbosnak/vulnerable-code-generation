//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
// The POP3 Client Case by Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFSIZE 1024

// Function to check for any errors while creating sockets
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char buffer[BUFSIZE];

    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Step 1: Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Step 2: Get the POP3 server hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Step 3: Set the server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // Step 4: Connect to the POP3 server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Step 5: Read the welcome message from the POP3 server
    bzero(buffer, BUFSIZE);
    n = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s", buffer);

    // Step 6: Send the USER command to the POP3 server
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "USER %s\r\n", "username");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) 
        error("ERROR writing to socket");

    // Step 7: Read the response from the POP3 server
    bzero(buffer, BUFSIZE);
    n = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s", buffer);

    // Step 8: Send the PASS command to the POP3 server
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "PASS %s\r\n", "password");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) 
        error("ERROR writing to socket");

    // Step 9: Read the response from the POP3 server
    bzero(buffer, BUFSIZE);
    n = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s", buffer);

    // Step 10: Send the LIST command to the POP3 server
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "LIST\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) 
        error("ERROR writing to socket");

    // Step 11: Read the response from the POP3 server
    bzero(buffer, BUFSIZE);
    n = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s", buffer);

    // Step 12: Send the QUIT command to the POP3 server
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) 
        error("ERROR writing to socket");

    // Step 13: Read the response from the POP3 server
    bzero(buffer, BUFSIZE);
    n = recv(sockfd, buffer, BUFSIZE-1, 0);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s", buffer);

    // Step 14: Close the socket
    close(sockfd);

    return 0;
}