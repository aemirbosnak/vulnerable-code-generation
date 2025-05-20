//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

// function to send a message
void send_message(int sockfd, char* msg) {
    send(sockfd, msg, strlen(msg), 0);
}

// function to receive a message
void receive_message(int sockfd, char* buffer) {
    memset(buffer, 0, MAX_BUFFER_SIZE);
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
}

int main(int argc, char *argv[]) {
    // make sure we have the correct number of arguments
    if(argc != 4) {
        printf("Usage: %s hostname username password\n", argv[0]);
        exit(1);
    }

    // get the hostname
    char* hostname = argv[1];

    // get the username
    char* username = argv[2];

    // get the password
    char* password = argv[3];

    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // make sure the socket was created successfully
    if(sockfd < 0) {
        perror("Error creating socket: ");
        exit(1);
    }

    // get the hostname
    struct hostent *server = gethostbyname(hostname);

    // make sure the hostname is correct
    if(server == NULL) {
        fprintf(stderr,"Error: no such host as %s\n", hostname);
        exit(1);
    }

    // set up the server address
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    // connect to the server
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server: ");
        exit(1);
    }

    // receive the server's welcome message
    char buffer[MAX_BUFFER_SIZE];
    receive_message(sockfd, buffer);
    printf("%s\n", buffer);

    // send the login information
    send_message(sockfd, "USER ");
    send_message(sockfd, username);
    send_message(sockfd, "\r\n");
    receive_message(sockfd, buffer);
    printf("%s\n", buffer);

    send_message(sockfd, "PASS ");
    send_message(sockfd, password);
    send_message(sockfd, "\r\n");
    receive_message(sockfd, buffer);
    printf("%s\n", buffer);

    // send the command to list all emails
    send_message(sockfd, "LIST\r\n");
    receive_message(sockfd, buffer);
    printf("%s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}