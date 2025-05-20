//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
/* The Case of the Missing HTTP Response */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Function to concatenate two strings
char* concat(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char*)malloc(len1 + len2 + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char *host = "www.example.com";
    char *path = "/index.html";
    portno = 80;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Resolve hostname to IP address
    server = gethostbyname(host);

    if (server == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    // Set server address and port number
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send HTTP GET request
    char *request = concat("GET ", path);
    request = concat(request, " HTTP/1.1\r\nHost: ");
    request = concat(request, host);
    request = concat(request, "\r\n\r\n");
    printf("Sending request:\n%s", request);
    n = write(sockfd, request, strlen(request));

    if (n < 0) {
        printf("Error writing to socket\n");
        return 1;
    }

    // Receive HTTP response
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1023);

    if (n < 0) {
        printf("Error reading from socket\n");
        return 1;
    }

    printf("Response:\n%s", buffer);

    close(sockfd);
    return 0;
}