//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, port, sent_bytes;
    char buffer[MAX_BUFFER_SIZE], *hostname, *path;
    struct sockaddr_in server_addr;
    struct hostent *host;
    
    if (argc != 3) { // check if the arguments are valid
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    hostname = argv[1];
    port = atoi(argv[2]);
    path = "/";
    
    // create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("Cannot create socket\n");
        exit(1);
    }
    
    // resolve the hostname to an IP address
    host = gethostbyname(hostname);
    if (!host) {
        printf("Cannot resolve hostname\n");
        exit(1);
    }
    
    // set the server address
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;
    server_addr.sin_port = htons(port);
    
    // connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Cannot connect to server\n");
        exit(1);
    }
    
    // build the HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    
    // send the HTTP request to the server
    sent_bytes = send(sock_fd, buffer, strlen(buffer), 0);
    if (sent_bytes == -1) {
        printf("Cannot send data to server\n");
        exit(1);
    }
    
    // receive the HTTP response from the server
    memset(&buffer, 0, sizeof(buffer));
    while (recv(sock_fd, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
        memset(&buffer, 0, sizeof(buffer));
    }
    
    // close the socket
    close(sock_fd);
    
    return 0;
}