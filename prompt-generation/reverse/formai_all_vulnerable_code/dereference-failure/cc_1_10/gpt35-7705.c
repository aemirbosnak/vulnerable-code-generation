//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

//Function to get the host by name
struct hostent *getHostByName(char *hostname)
{
    struct hostent *hostinfo;
    if ((hostinfo = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Unknown hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    return hostinfo;
}

//Function to send a HTTP request and print the response
void sendHTTPRequest(char *hostname, char *path)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024], httpRequest[1024];
    portno = 80;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    server = getHostByName(hostname);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    sprintf(httpRequest, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
    if (write(sockfd, httpRequest, strlen(httpRequest)) < 0) {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }
    printf("HTTP Response:\n");
    while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    printf("\n");
    if (n < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    close(sockfd);
}

//Main function for testing
int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname path\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    sendHTTPRequest(argv[1], argv[2]);
    return 0;
}