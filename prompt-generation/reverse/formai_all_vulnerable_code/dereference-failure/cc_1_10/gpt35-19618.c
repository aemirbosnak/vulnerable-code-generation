//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

/* Function to print error message and exit */
void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sock; /* Socket descriptor */
    struct sockaddr_in serv_addr; /* Server address structure */
    char request[BUFSIZE]; /* HTTP request message buffer */
    char response[BUFSIZE]; /* HTTP response message buffer */
    int bytes_received = 0; /* Number of bytes received */
    int total_bytes_received = 0; /* Total number of bytes received */
    int i = 0; /* Loop counter */
    char *host; /* Hostname */
    char *path; /* HTTP path */
    int port; /* Port number */

    /* Check command line arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    port = atoi(argv[2]);
    path = argv[3];

    /* Create socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error("Error opening socket");
    }

    /* Set server address parameters */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    /* Connect to server */
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    /* Build HTTP request message */
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    /* Send HTTP request message to server */
    if (send(sock, request, strlen(request), 0) != strlen(request)) {
        error("Error sending request to server");
    }

    /* Receive HTTP response message from server */
    while ((bytes_received = recv(sock, response + total_bytes_received, BUFSIZE - total_bytes_received - 1, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    /* Check for error in receive */
    if (bytes_received < 0) {
        error("Error receiving response from server");
    }

    /* Null terminate response string */
    response[total_bytes_received] = '\0';

    /* Print response message */
    printf("%s", response);

    /* Close socket */
    close(sock);

    return 0;
}