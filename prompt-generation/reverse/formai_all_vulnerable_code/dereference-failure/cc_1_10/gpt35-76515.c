//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Define the buffer size
#define BUFFER_SIZE 4096

// Define the default http port
#define HTTP_PORT 80

// Define the function for handling errors
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Check if the arguments are correct
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname [port]\n", argv[0]);
        exit(1);
    }

    // Get the port number, if provided
    portno = (argc == 3) ? atoi(argv[2]) : HTTP_PORT;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Get the server from the hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Set up the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Bind the socket to the local address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd, 5);

    // Loop to accept new connections
    while (1) {
        socklen_t clilen = sizeof(cli_addr);

        // Accept a new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        // Create a new process to handle the connection
        int pid = fork();
        if (pid < 0)
            error("ERROR on fork");

        if (pid == 0) {
            // This is the child process, so handle the request
            close(sockfd);

            // Read the message from the client
            bzero(buffer, BUFFER_SIZE);
            n = read(newsockfd, buffer, BUFFER_SIZE);
            if (n < 0)
                error("ERROR reading from socket");

            // Parse the http request
            char method[BUFFER_SIZE], path[BUFFER_SIZE], protocol[BUFFER_SIZE];
            sscanf(buffer, "%s %s %s", method, path, protocol);

            // Replace the path with the full url
            if (strncmp(path, "/", 1) == 0) {
                strcat(path, "index.html");
            }
            char url[BUFFER_SIZE];
            sprintf(url, "http://%s:%d%s", argv[1], portno, path);

            // Create a new socket to connect to the server
            int server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd < 0)
                error("ERROR opening socket");

            // Connect to the server
            if (connect(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
                error("ERROR connecting to server");

            // Send the request to the server
            n = write(server_fd, buffer, strlen(buffer));
            if (n < 0)
                error("ERROR writing to socket");

            // Read the response from the server
            bzero(buffer, BUFFER_SIZE);
            n = read(server_fd, buffer, BUFFER_SIZE);
            if (n < 0)
                error("ERROR reading from socket");

            // Send the response to the client
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0)
                error("ERROR writing to socket");

            // Clean up
            close(server_fd);
            close(newsockfd);
            exit(0);
        } else {
            // This is the parent process, so close the connection and loop to accept more connections
            close(newsockfd);
        }
    }

    // Close the socket
    close(sockfd);

    // Return success
    return 0;
}