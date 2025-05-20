//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: enthusiastic
//Hello there! Do you want to know how to build a HTTP client in C? 
//Well, you're in luck because I'm going to show you how to do it! 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide the URL of the website to connect.\n");
        exit(EXIT_FAILURE);
    }
    //Let's get the hostname and path from the provided URL
    char *url = argv[1];
    char *hostname = strtok(url, "/");
    char *path = strtok(NULL, "");
    printf("Host: %s\n", hostname);
    printf("Path: %s\n", path);

    //Let's use the getaddrinfo method to get the ip address of the host
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(hostname, "http", &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in *address = (struct sockaddr_in *)res->ai_addr;
    char *ip = inet_ntoa(address->sin_addr);
    printf("IP: %s\n", ip);

    //Let's create a socket and connect it to the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Socket creation failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); //HTTP port
    inet_pton(AF_INET, ip, &server_address.sin_addr);

    status = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(status == -1) {
        printf("Connection failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    //Let's prepare the HTTP request message
    char *request_template = "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request[BUFFER_SIZE] = {0};
    sprintf(request, request_template, path, hostname);

    //Let's send the HTTP request to the server
    status = send(sockfd, request, strlen(request), 0);
    if(status == -1) {
        printf("Sending request to server failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    printf("Request Message Sent.\n");

    //Let's receive the response from the server
    char response[BUFFER_SIZE] = {0};
    status = recv(sockfd, response, BUFFER_SIZE, 0);
    if(status == -1) {
        printf("Receiving response from server failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    printf("Response Message Received.\n");
    printf("%s", response);

    //Let's close the connection and exit
    close(sockfd);
    printf("Connection Closed.\n");
    return 0;
}