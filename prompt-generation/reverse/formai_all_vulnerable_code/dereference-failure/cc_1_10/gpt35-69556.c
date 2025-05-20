//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

// Recursive function to send http requests
void sendHTTP(int sockfd, char *request, int remaining) {
    // send the request to the server
    write(sockfd, request, strlen(request));
    
    // check if we have remaining requests
    if (remaining == 0) {
        return;
    }
    
    // read the response from the server
    char buffer[1024];
    int n = read(sockfd, buffer, 1024);
    buffer[n] = '\0';
    printf("%s", buffer);
    
    // send next request
    sendHTTP(sockfd, request, remaining-1);
}

int main(int argc, char *argv[]) {
    // check for valid arguments
    if (argc != 4) {
        printf("Usage: %s <server_address> <server_port> <num_requests>\n", argv[0]);
        exit(1);
    }
    char *server_address = argv[1];
    int server_port = atoi(argv[2]);
    int num_requests = atoi(argv[3]);
    
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // get server information
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }
    
    // configure server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(server_port);
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    // send http request
    char *request = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: keep-alive\r\n\r\n";
    sendHTTP(sockfd, request, num_requests);
    
    // close socket
    close(sockfd);
    return 0;
}