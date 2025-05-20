//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 1024

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Resolve the hostname and port number
    struct hostent *server = gethostbyname("pop3.example.com");
    struct in_addr *ip = (struct in_addr *)server->h_addr_list[0];
    int port = server->h_length == 0? 110 : ntohs(*((unsigned short *)server->h_addr_list[1]));

    // Create a socket address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ip->s_addr;
    addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send the username and password
    char username[MAXLINE], password[MAXLINE];
    printf("Enter username: ");
    fgets(username, MAXLINE, stdin);
    printf("Enter password: ");
    fgets(password, MAXLINE, stdin);

    // Send the username and password to the server
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    // Receive the server's response
    char response[MAXLINE];
    recv(sockfd, response, MAXLINE, 0);

    // Print the server's response
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}