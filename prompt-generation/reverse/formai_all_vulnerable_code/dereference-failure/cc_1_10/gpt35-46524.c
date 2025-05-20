//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    
    int sockfd, port, numbytes;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char sendbuf[BUFSIZE], recvbuf[BUFSIZE];

    // Check if correct number of arguments are provided
    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(1);
    }

    // Convert port from string to integer
    port = atoi(argv[2]);

    // Get server information using hostname
    if ((server = gethostbyname(argv[1])) == NULL) {
        printf("Error: no such host as %s\n", argv[1]);
        exit(1);
    }

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: failed to create socket\n");
        exit(1);
    }

    // Initialize connection parameters
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: failed to connect to server %s:%d\n", argv[1], port);
        exit(1);
    }

    // Send email message to server
    sprintf(sendbuf, "EHLO client\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    numbytes = recv(sockfd, recvbuf, BUFSIZE, 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);

	sprintf(sendbuf, "MAIL FROM: <sender@example.com>\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    numbytes = recv(sockfd, recvbuf, BUFSIZE, 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);
    
    sprintf(sendbuf, "RCPT TO: <receiver@example.com>\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    numbytes = recv(sockfd, recvbuf, BUFSIZE, 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);
    
    sprintf(sendbuf, "DATA\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    numbytes = recv(sockfd, recvbuf, BUFSIZE, 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);
    
    sprintf(sendbuf, "Subject: %s\r\n", argv[3]);
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    sprintf(sendbuf, "\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    sprintf(sendbuf, "%s\r\n", argv[3]);
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    
    sprintf(sendbuf, ".\r\n");
    send(sockfd, sendbuf, strlen(sendbuf), 0);
    numbytes = recv(sockfd, recvbuf, BUFSIZE, 0);
    recvbuf[numbytes] = '\0';
    printf("%s", recvbuf);
    
    // Close the socket
    close(sockfd);

    return 0;
}