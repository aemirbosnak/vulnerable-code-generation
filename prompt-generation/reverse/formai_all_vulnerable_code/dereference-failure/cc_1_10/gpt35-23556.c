//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    // get the host name and the path from the user input
    char *url = argv[1];
    char *path;
    if(strncmp(url, "http://", 7) == 0) {
        url += 7;
    }
    path = strchr(url, '/');
    if(path == NULL) {
        path = "/";
    } else {
        *path++ = '\0';
    }

    // get the host IP address
    struct hostent *hostinfo = gethostbyname(url);
    if(hostinfo == NULL) {
        fprintf(stderr, "Unknown host: %s\n", url);
        exit(1);
    }

    // create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // connect to the server
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(DEFAULT_PORT);
    memcpy(&serveraddr.sin_addr, hostinfo->h_addr_list[0], hostinfo->h_length);
    if(connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // build the HTTP request message
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.0\r\nHost: %s\r\nUser-Agent: Mozilla/5.0\r\n\r\n", path, url);

    // send the HTTP request message to the server
    ssize_t nsend = send(sockfd, request, strlen(request), 0);
    if(nsend < 0) {
        perror("Error sending request message");
        exit(1);
    }

    // receive the HTTP response message from the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t nrecv;
    while((nrecv = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[nrecv] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }
    if(nrecv < 0) {
        perror("Error receiving response message");
        exit(1);
    }

    // close the socket
    close(sockfd);

    return 0;
}