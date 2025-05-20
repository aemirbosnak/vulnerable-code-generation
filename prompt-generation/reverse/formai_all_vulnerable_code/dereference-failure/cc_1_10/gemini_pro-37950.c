//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr = *(struct in_addr *) host->h_addr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: could not create socket");
        return 1;
    }

    if (connect(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error: could not connect to server");
        return 1;
    }

    char buf[BUFSIZE];
    int nbytes;

    // Send a request to the server
    strcpy(buf, "GET / HTTP/1.1\r\nHost: ");
    strcat(buf, hostname);
    strcat(buf, "\r\n\r\n");

    nbytes = send(sock, buf, strlen(buf), 0);
    if (nbytes == -1) {
        perror("Error: could not send request");
        return 1;
    }

    // Receive the response from the server
    nbytes = recv(sock, buf, BUFSIZE, 0);
    if (nbytes == -1) {
        perror("Error: could not receive response");
        return 1;
    }

    // Parse the response and print the download speed
    char *contentLengthStr = strstr(buf, "Content-Length: ");
    if (contentLengthStr == NULL) {
        fprintf(stderr, "Error: could not find Content-Length header in response\n");
        return 1;
    }

    contentLengthStr += strlen("Content-Length: ");
    int contentLength = atoi(contentLengthStr);

    char *startTimestampStr = strstr(buf, "Date: ");
    if (startTimestampStr == NULL) {
        fprintf(stderr, "Error: could not find Date header in response\n");
        return 1;
    }

    startTimestampStr += strlen("Date: ");
    long long startTimestamp = atol(startTimestampStr);

    char *endTimestampStr = strstr(buf, "\r\n\r\n");
    if (endTimestampStr == NULL) {
        fprintf(stderr, "Error: could not find end of headers in response\n");
        return 1;
    }

    endTimestampStr += strlen("\r\n\r\n");
    long long endTimestamp = atol(endTimestampStr);

    double elapsedTime = (endTimestamp - startTimestamp) / 1000.0;
    double downloadSpeed = contentLength / elapsedTime;

    printf("Download speed: %.2f KB/s\n", downloadSpeed);

    close(sock);

    return 0;
}