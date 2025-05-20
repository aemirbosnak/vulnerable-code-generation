//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
 
#define BUFFER_SIZE 1024
 
void receive(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t n;
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n < 0) {
        perror("recv");
    }
}
 
int main(int argc, char** argv) {
    char* host = "imap.gmail.com";
    char* user = "username@gmail.com";
    char* password = "p@ssw0rd";
 
    struct addrinfo hints, *res;
 
    // Set up the hints struct
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
 
    // Get the address information for the host
    int status = getaddrinfo(host, "993", &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
 
    // Create the socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
 
    // Connect to the host
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
 
    // Receive the initial server response
    receive(sockfd);
 
    // Send the login command
    char login_cmd[BUFFER_SIZE];
    snprintf(login_cmd, sizeof(login_cmd), "A1 LOGIN %s %s\r\n", user, password);
    send(sockfd, login_cmd, strlen(login_cmd), 0);
 
    // Receive the login response
    receive(sockfd);
 
    // Send the select command to choose the inbox
    char select_cmd[BUFFER_SIZE];
    snprintf(select_cmd, sizeof(select_cmd), "A2 SELECT INBOX\r\n");
    send(sockfd, select_cmd, strlen(select_cmd), 0);
 
    // Receive the select response
    receive(sockfd);
 
    // Send the fetch command to get the latest email
    char fetch_cmd[BUFFER_SIZE];
    snprintf(fetch_cmd, sizeof(fetch_cmd), "A3 FETCH 1 BODY[]\r\n");
    send(sockfd, fetch_cmd, strlen(fetch_cmd), 0);
 
    // Receive the fetch response
    receive(sockfd);
 
    // Close the socket
    close(sockfd);
 
    return 0;
}