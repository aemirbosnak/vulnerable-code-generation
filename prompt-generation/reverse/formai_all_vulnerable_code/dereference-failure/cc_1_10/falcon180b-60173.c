//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char buffer[MAX];
    int n;

    // Check if the user has provided a valid IP address
    if (argc!= 2) {
        fprintf(stderr, "Usage:./ping <IP address>\n");
        exit(1);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(1);
    }

    // Get the host information
    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "No such host: %s\n", argv[1]);
        exit(1);
    }

    // Fill in the server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, he->h_addr, he->h_length);
    serv_addr.sin_port = htons(12345);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    // Send the ping message
    n = send(sock, "PING", strlen("PING"), 0);
    if (n == -1) {
        perror("send failed");
        exit(1);
    }

    // Receive the response
    n = recv(sock, buffer, MAX, 0);
    if (n == -1) {
        perror("recv failed");
        exit(1);
    }

    // Close the socket
    close(sock);

    // Print the response
    printf("Response: %s\n", buffer);

    return 0;
}