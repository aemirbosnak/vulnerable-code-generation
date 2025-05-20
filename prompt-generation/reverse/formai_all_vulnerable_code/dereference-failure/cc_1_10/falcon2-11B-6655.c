//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, bytes_sent, bytes_received, portno;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char ip_address[INET_ADDRSTRLEN];
    char* result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    portno = htons(5000);
    serv_addr.sin_port = portno;

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in binding\n");
        exit(1);
    }

    server = gethostbyname("www.speedtest.net");
    if (server == NULL) {
        printf("Error in getting hostname\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connecting\n");
        exit(1);
    }

    printf("Enter the URL you want to test: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcat(buffer, "\n");

    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        printf("Error in sending data\n");
        exit(1);
    }

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error in receiving data\n");
        exit(1);
    }

    result = (char*) malloc(BUFFER_SIZE);
    strcpy(result, buffer);

    printf("Internet Speed Test Result:\n");
    printf("URL: %s\n", result);
    printf("Download Speed: %s\n", buffer);

    free(result);
    close(sockfd);
    return 0;
}