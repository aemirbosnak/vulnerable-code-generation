//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 4096 // Max size of buffer

void error(char *msg) // Error message function
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[BUFSIZE], address[INET_ADDRSTRLEN];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    memset(&buffer, 0, BUFSIZE);

    // Check for the required arguments
    if (argc < 3) {
       fprintf(stderr,"usage: %s hostname port\n", argv[0]);
       exit(1);
    }

    portno = atoi(argv[2]); // Get the port number passed as an argument

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]); // Get the host details
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Initialize the serv_addr structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // Bind the socket with server address
        error("ERROR on binding");

    listen(sockfd, 5); // Start listening for connections
    clilen = sizeof(cli_addr);

    while (1) { // Loop to accept incoming connections and handle them
        newsockfd = accept(sockfd,
                 (struct sockaddr *) &cli_addr,
                 &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        inet_ntop(AF_INET, &(cli_addr.sin_addr), address, INET_ADDRSTRLEN); // Get client address and print it
        printf("Incoming connection from %s:%d\n", address, ntohs(cli_addr.sin_port));

        bzero(buffer, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE); // Read the request from client
        if (n < 0)
            error("ERROR reading from socket");

        printf("\n========================== Client Request ==========================\n%s\n", buffer);

        int client_socket = socket(AF_INET, SOCK_STREAM, 0); // Create a socket to connect to requested server
        if (client_socket < 0)
            error("ERROR opening socket");

        char request_uri[BUFSIZE];
        char request_host[BUFSIZE];
        sscanf(buffer, "GET %s HTTP/1.1\r\nHost: %s", request_uri, request_host); // Parse the request and get the URI and requested host

        server = gethostbyname(request_host); // Get the host details of requested server
        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(0);
        }

        // Initialize the serv_addr structure of requested server
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr,
              (char *)&serv_addr.sin_addr.s_addr,
              server->h_length);
        serv_addr.sin_port = htons(80);

        if (connect(client_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) // Connect to the requested server
            error("ERROR connecting");

        n = write(client_socket, buffer, strlen(buffer)); // Write the client request to the requested server
        if (n < 0)
            error("ERROR writing to socket");

        bzero(buffer, BUFSIZE);
        while ((n = read(client_socket, buffer, BUFSIZE)) > 0) { // Read the response from requested server and write it to client
            n = write(newsockfd, buffer, n);
            if (n < 0)
                error("ERROR writing to socket");
            bzero(buffer, BUFSIZE);
        }

        if (n < 0) // Check for errors in reading from server
            error("ERROR reading from socket");

        close(client_socket); // Close the socket for the requested server
        close(newsockfd); // Close the connection with the client
    }

    close(sockfd); // Close the listening socket
    return 0;
}