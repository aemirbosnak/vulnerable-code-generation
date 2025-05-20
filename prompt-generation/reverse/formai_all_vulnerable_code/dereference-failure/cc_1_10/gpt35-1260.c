//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
/*
 * Ada's Simple Web Server
 * Written by Ada Lovelace
 * 
 * This program creates a simple web server that listens on a specified port
 * and responds to HTTP GET requests by serving the requested file, if present.
 * 
 * To use, compile with: gcc webserver.c -o webserver
 * Then run: ./webserver [port]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_REQUEST_SIZE 2048 // maximum size of HTTP request
#define MAX_RESPONSE_SIZE 1024 // maximum size of HTTP response
#define MAX_FILE_SIZE 1048576 // maximum size of file to be served

// function to serve a requested file
void serve_file(int connfd, char *filename) {
    // open file for reading
    int filefd = open(filename, O_RDONLY);
    
    // check if file exists and can be read
    if (filefd < 0) {
        // file not found
        printf("HTTP/1.1 404 Not Found\r\n\r\n");
        write(connfd, "404 Not Found", strlen("404 Not Found"));
        return;
    }
    
    // get size of file
    struct stat st;
    fstat(filefd, &st);
    int filesize = st.st_size;
    
    // check if file is too big to serve
    if (filesize > MAX_FILE_SIZE) {
        // file too large
        printf("HTTP/1.1 413 Request Entity Too Large\r\n\r\n");
        write(connfd, "413 Request Entity Too Large", strlen("413 Request Entity Too Large"));
        close(filefd);
        return;
    }
    
    // read file into buffer
    char *filebuf = (char *) malloc(filesize);
    read(filefd, filebuf, filesize);
    
    // generate HTTP response header
    char response[MAX_RESPONSE_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", filesize);
    
    // send HTTP response header and file content
    write(connfd, response, strlen(response));
    write(connfd, filebuf, filesize);
    
    // free buffer and close file
    free(filebuf);
    close(filefd);
}

int main(int argc, char **argv) {
    // parse command line arguments
    if (argc != 2) {
        printf("Usage: ./webserver [port]\n");
        return 1;
    }
    int port = atoi(argv[1]);
    if (port <= 0) {
        printf("Invalid port number\n");
        return 1;
    }
    
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }
    
    // bind socket to port
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error binding socket to port\n");
        close(sockfd);
        return 1;
    }
    
    // listen for incoming connections
    if (listen(sockfd, 10) < 0) {
        printf("Error listening for connections\n");
        close(sockfd);
        return 1;
    }
    
    // main server loop
    while (1) {
        // accept incoming connection
        int connfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
        if (connfd < 0) {
            printf("Error accepting connection\n");
            continue;
        }
        
        // read HTTP request
        char request[MAX_REQUEST_SIZE];
        int n = read(connfd, request, MAX_REQUEST_SIZE);
        if (n < 0) {
            printf("Error reading request\n");
            close(connfd);
            continue;
        }
        
        // parse HTTP request to get requested file
        char *filename = strtok(request, " ");
        if (strcmp(filename, "GET") != 0) {
            // unsupported HTTP method
            printf("HTTP/1.1 405 Method Not Allowed\r\n\r\n");
            write(connfd, "405 Method Not Allowed", strlen("405 Method Not Allowed"));
            close(connfd);
            continue;
        }
        filename = strtok(NULL, " ");
        
        // serve requested file
        if (filename != NULL) {
            filename++;
            serve_file(connfd, filename);
        }
        
        // close connection
        close(connfd);
    }
    
    // close socket
    close(sockfd);
    return 0;
}