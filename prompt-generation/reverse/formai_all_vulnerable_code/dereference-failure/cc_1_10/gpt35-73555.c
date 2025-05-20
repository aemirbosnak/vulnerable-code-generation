//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 2048
#define MAX_RESPONSE_SIZE 4096

char* send_http_request(const char* hostname, const unsigned short port, const char* path, const char* method)
{
    char request[MAX_REQUEST_SIZE] = {0};
    char response[MAX_RESPONSE_SIZE] = {0};
    char* response_body = NULL;
    struct sockaddr_in server;
    struct hostent* host;
    int sockfd, bytes, total_bytes = 0;
    
    // Creating a socket - Internet domain and TCP stream
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation error");
        exit(1);
    }
    
    // Getting server IP address
    host = gethostbyname(hostname);
    if (host == NULL)
    {
        perror("Host resolution error");
        exit(1);
    }
    
    // Populating the server address structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr*) host->h_addr);
    
    // Connecting to the server
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        perror("Connection error");
        exit(1);
    }
    
    // Generating the http request
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\nAccept: */*\r\n\r\n", method, path, hostname);
    
    // Sending the http request
    bytes = send(sockfd, request, strlen(request), 0);
    if (bytes < 0)
    {
        perror("Sending error");
        exit(1);
    }
    
    // Receiving the http response by chunks
    do
    {
        bytes = recv(sockfd, response + total_bytes, MAX_RESPONSE_SIZE - total_bytes, 0);
        if (bytes < 0)
        {
            perror("Receiving error");
            exit(1);
        }
        total_bytes += bytes;
    } while (bytes > 0);
    
    // Closing the socket
    close(sockfd);
    
    // Parsing the http response for the body
    response_body = strstr(response, "\r\n\r\n");
    if (response_body != NULL)
    {
        response_body += 4; // skipping "\r\n\r\n"
    }
    
    return response_body;
}

int main(int argc, char* argv[])
{
    const char* hostname = "example.com";
    const unsigned short port = 80;
    const char* path = "/";
    const char* method = "GET";
    char* response_body = NULL;
    
    // Sending the http request and receiving the response
    response_body = send_http_request(hostname, port, path, method);
    
    // Printing the http response body
    if (response_body != NULL)
    {
        printf("%s\n", response_body);
    }
    
    return 0;
}