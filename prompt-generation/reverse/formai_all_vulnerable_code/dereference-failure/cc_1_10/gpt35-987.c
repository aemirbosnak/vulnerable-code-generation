//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096 /* Max text line length */
#define PORT 80 /* Default HTTP Port */

/* Function to create a socket and connect to a server using its hostname and port number */
int client_connect(char* hostname, int port) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent* host;

    /* Get the IP address of the server using its hostname */
    if ((host = gethostbyname(hostname)) == NULL) {
        fprintf(stderr,"Error: Can't resolve hostname %s\n", hostname);
        exit(1);
    }

    /* Set up the socket address structure */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    /* Create the socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Can't open socket\n");
        exit(1);
    }

    /* Connect to the server using the socket and socket address */
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: Can't connect to server\n");
        exit(1);
    }

    return sockfd;
}

/* Function to send an HTTP GET request to a server */
void client_send(int sockfd, char* path, char* host) {
    char sendline[MAXLINE];

    /* Build the GET request string */
    sprintf(sendline, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    /* Send the GET request to the server */
    if (write(sockfd, sendline, strlen(sendline)) < 0) {
        fprintf(stderr, "Error: Can't write to server\n");
        exit(1);
    }
}

/* Function to receive and print the response from the server */
void client_receive(int sockfd) {
    char recvline[MAXLINE];
    int n;
    while ((n = read(sockfd, recvline, MAXLINE-1)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }
}

/* Main function to run the HTTP client */
int main(int argc, char **argv) {
    int sockfd;
    char* hostname;
    char* path;
    int port = PORT;

    /* Parse command line arguments */
    if (argc < 2) {
        fprintf(stderr,"usage: %s <hostname> [port] <path>\n", argv[0]);
        exit(1);
    }
    hostname = argv[1];
    if (argc > 2) {
        port = atoi(argv[2]);
    }
    path = argv[3];

    /* Connect to the server */
    sockfd = client_connect(hostname, port);

    /* Send the HTTP GET request */
    client_send(sockfd, path, hostname);

    /* Receive and print the response from the server */
    client_receive(sockfd);

    /* Close the socket */
    close(sockfd);

    return 0;
}