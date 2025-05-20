//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct hostent *server;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host exists! Check your input!\n");
        exit(1);
    }

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    portno = 80;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Error connecting");
    printf("Connected to %s (IP address: %s)\n\n", argv[1], inet_ntoa(*(struct in_addr *)server->h_addr));

    char buffer[BUFSIZE];
    char *command = "iwconfig wlan0 | grep Signal | awk '{print $4}'";
    while (1) {
        bzero(buffer, BUFSIZE);
        n = write(sockfd, command, strlen(command));
        if (n < 0)
            error("Error writing to socket");
        n = read(sockfd, buffer, BUFSIZE - 1);
        if (n < 0)
            error("Error reading from socket");
        printf("Signal strength: %s dBm\n", buffer);
        sleep(1);
    }

    close(sockfd);
    return 0;
}