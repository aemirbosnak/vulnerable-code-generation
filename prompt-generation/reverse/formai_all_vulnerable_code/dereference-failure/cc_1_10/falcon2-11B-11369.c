//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int sockfd, n, portno, len;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char *buf, *temp;
    char command[100];
    char* server_name = "mail.example.com";
    char* pop3_server = "pop3.example.com";

    // Step 1: Open socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Resolve host name to IP address
    server = gethostbyname(server_name);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    // Step 3: Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Step 4: Send POP3 command
    strcpy(command, "USER username password");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Step 5: Receive response
    bzero(buf, 100);
    n = recv(sockfd, buf, 100, 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Step 6: Display response
    temp = buf;
    while (*temp!= '\0') {
        if (*temp == '+' || *temp == '-' || *temp == '*') {
            printf("%c", *temp);
        }
        temp++;
    }

    // Step 7: Disconnect from the server
    close(sockfd);
    return 0;
}