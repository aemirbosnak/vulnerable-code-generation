//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *ip;
    int port;
    int timeout;
    char *host;
    int len;
    char buf[1024];
    int ret;
    struct timeval tv;
    fd_set fdset;
    int maxfd;

    // Check the number of arguments
    if (argc!= 5) {
        printf("Usage: %s <IP Address> <Port> <Timeout> <Hostname>\n", argv[0]);
        exit(1);
    }

    // Get the IP address
    ip = argv[1];

    // Get the port
    port = atoi(argv[2]);

    // Get the timeout
    timeout = atoi(argv[3]);

    // Get the hostname
    host = argv[4];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Set the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        exit(1);
    }

    // Set the timeout
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    // Send a message to the server
    ret = send(sock, host, strlen(host), 0);
    if (ret == -1) {
        printf("Error: Could not send message to server\n");
        exit(1);
    }

    // Receive a message from the server
    len = sizeof(buf);
    ret = recv(sock, buf, len, 0);
    if (ret == -1) {
        printf("Error: Could not receive message from server\n");
        exit(1);
    }

    // Close the socket
    close(sock);

    // Print the message
    printf("Message from server: %s\n", buf);

    return 0;
}