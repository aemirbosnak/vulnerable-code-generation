//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

//Function to create a socket and connect to the server
int createClientSocket(char *ipAddress, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Reset servaddr
    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if(inet_pton(AF_INET, ipAddress, &servaddr.sin_addr)<=0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send http request
void sendHttpRequest(int sockfd, char * message) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // sending http request
    if(send(sockfd, message, strlen(message),0) == -1) {
        perror("Send Failed");
        exit(EXIT_FAILURE);
    }
    printf("HTTP request sent successfully\n");

    // receive http response
    while(true) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int valread = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if(valread <= 0) {
            break;
        }
        printf("%s", buffer);
    }
}

int main(int argc, char const *argv[]) {
    if(argc != 3) {
        printf("Usage: ./httpclient <IP address> <PORT NO>\n");
        return EXIT_FAILURE;
    }

    char *ipAddress = argv[1];
    int port = atoi(argv[2]);
    int sockfd = createClientSocket(ipAddress, port);

    char message[MAX_BUFFER_SIZE];
    memset(message, 0, MAX_BUFFER_SIZE);
    
    // create http request
    char path[] = "/index.html";
    char hostname[] = "www.example.com";
    sprintf(message, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    printf("\n\nHTTP request:\n%s\n", message);

    //send http request
    sendHttpRequest(sockfd, message);

    return EXIT_SUCCESS;
}