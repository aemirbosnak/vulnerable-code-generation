//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024

// function to establish a connection with the server
int connect_to_server(const char *hostname, const char *port) {
    
    int sockfd, status;
    struct addrinfo hints, *res; 
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if((status = getaddrinfo(hostname, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct addrinfo *p;
    for(p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if(sockfd == -1) {
            perror("socket error");
            continue;
        }

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect error");
            continue;
        }

        break;
    }

    freeaddrinfo(res);

    if(p == NULL) {
        fprintf(stderr, "Could not connect to the server\n");
        exit(EXIT_FAILURE);
    }
   

    return sockfd;

}

// function to authenticate with the server 
bool authenticate(int sockfd, const char *username, const char *password) {

    char buffer[MAX_BUFFER_SIZE];

    // send the login command and receive the response from the server
    sprintf(buffer, ". login %s %s\r\n", username, password);
    if(send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send error");
        return false;
    }

    if(recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv error");
        return false;
    }
 
    // check if the authentication was successful
    if(strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "IMAP login failed\n");
        return false;
    }

    return true;

}

// function to fetch emails from the server
void fetch_emails(int sockfd) {

    char buffer[MAX_BUFFER_SIZE];
    int num_emails = 0;

    // send the fetch command and receive the response from the server
    if(send(sockfd, ". fetch 1:* (body[header.fields (subject from)])\r\n", 52, 0) == -1) {
        perror("send error");
        return;
    }

    while(1) {
        int n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if(n == -1) {
            perror("recv error");
            break;
        } else if(n == 0) {
            break;
        } else {
            buffer[n] = '\0';
            printf("%s", buffer);
            if(strstr(buffer, "OK FETCH completed") != NULL) {
                break;
            } else if(strstr(buffer, "FETCH") != NULL) {
                num_emails++;
            }
        }
    }

    printf("Received %d emails\n", num_emails);

}

int main(int argc, char **argv) {

    if(argc != 4) {
        fprintf(stderr, "Usage: %s hostname port username\n", argv[0]);
        return EXIT_FAILURE;
    }

    // get the hostname, port and username
    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *username = argv[3];

    // get the password interactively
    char *password = getpass("Enter your password: ");

    // establish a connection with the server
    int sockfd = connect_to_server(hostname, port);

    // authenticate with the server
    if(!authenticate(sockfd, username, password)) {
        return EXIT_FAILURE;
    }

    // fetch emails from the server
    fetch_emails(sockfd);

    // close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}