//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to calculate the Fibonacci sequence up to n terms
int fibonacci(int n) {
    int f0 = 0, f1 = 1, f2, i;
    for (i = 3; i <= n; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

// Function to send Fibonacci sequence numbers over a socket connection
void sendFibonacci(int sockfd, int n) {
    char buf[100];
    int i;
    for (i = 0; i < n; i++) {
        sprintf(buf, "%d", fibonacci(i));
        send(sockfd, buf, strlen(buf), 0);
        sleep(1); // Add a delay between sending each number
    }
}

int main(int argc, char **argv) {
    int sockfd, n, portno;
    struct sockaddr_in serveraddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up server address struct
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[1]));
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    // Bind to the port
    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept a connection
    if ((n = accept(sockfd, NULL, NULL)) < 0) {
        perror("accept");
        exit(1);
    }

    // Send Fibonacci sequence numbers over the socket connection
    sendFibonacci(n, 10); // Send 10 Fibonacci numbers

    close(sockfd);

    return 0;
}