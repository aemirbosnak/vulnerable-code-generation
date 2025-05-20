//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define TIMEOUT 10000 //10 seconds

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hostname/IP address>\n", argv[0]);
        exit(1);
    }

    //Get the hostname or IP address from the command line
    char *hostname = argv[1];

    //Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    //Set a timeout on the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT / 1000;
    tv.tv_usec = (TIMEOUT % 1000) * 1000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    //Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    //Create the ping message
    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);
    sprintf(buf, "PING %s", hostname);

    //Send the ping message
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr = *(struct in_addr *) host->h_addr;
    if (sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("sendto");
        exit(1);
    }

    //Receive the ping response
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    int n = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *) &from, &fromlen);
    if (n < 0) {
        perror("recvfrom");
        exit(1);
    }

    //Print the ping response
    printf("Received %d bytes from %s: %s\n", n, inet_ntoa(from.sin_addr), buf);

    //Close the socket
    close(sockfd);

    return 0;
}