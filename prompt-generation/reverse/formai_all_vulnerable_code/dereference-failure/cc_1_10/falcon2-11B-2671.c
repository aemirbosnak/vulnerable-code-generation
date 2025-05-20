//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netdb.h>
#include <stdlib.h>
#include <time.h>

//function to perform ping test
int ping(char* host, int port) {
    struct sockaddr_in serverAddr;
    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in addr;
    struct timeval start_time, end_time;
    fd_set readfds;
    int rv;

    //step1: create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Cannot create socket\n");
        exit(1);
    }

    //step2: create an address structure for the server
    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error: Invalid host name\n");
        exit(1);
    }
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy((char*) &addr.sin_addr.s_addr, (char*) server->h_addr, server->h_length);
    addr.sin_port = htons(port);

    //step3: connect to the server
    if ((connect(sockfd, (struct sockaddr *) &addr, sizeof(addr))) < 0) {
        perror("Error: Connection Failed\n");
        exit(1);
    }

    //step4: send the ping request
    char request[80];
    strcpy(request, "Ping request to ");
    strcat(request, host);
    strcat(request, " (");
    strcat(request, inet_ntoa(addr.sin_addr));
    strcat(request, ") - ");
    strcat(request, host);
    strcat(request, " is alive\n");

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error: Could not send request\n");
        exit(1);
    }

    //step5: wait for the reply
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    n = select(sockfd+1, &readfds, NULL, NULL, NULL);
    if (n == -1) {
        perror("Error: Select failed\n");
        exit(1);
    }

    //step6: receive the reply
    memset(&addr, 0, sizeof(addr));
    if ((n = recv(sockfd, &addr, sizeof(addr), 0)) < 0) {
        perror("Error: Could not receive reply\n");
        exit(1);
    }
    if ((addr.sin_addr.s_addr!= 0) && (addr.sin_port!= 0)) {
        printf("Pong from %s\n", inet_ntoa(addr.sin_addr));
    }

    //step7: close the socket
    close(sockfd);

    return 0;
}

int main() {
    int port = 80;
    char host[] = "www.google.com";

    ping(host, port);

    return 0;
}