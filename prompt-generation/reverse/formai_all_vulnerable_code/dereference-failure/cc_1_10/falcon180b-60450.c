//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    int port = 8080;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (argc > 1) {
        // Use provided hostname or IP address
        host = gethostbyname(argv[1]);
        if (host == NULL) {
            fprintf(stderr, "gethostbyname failed: %s\n", hstrerror(h_errno));
            exit(EXIT_FAILURE);
        }
        memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    } else {
        // Use localhost
        server_addr.sin_addr.s_addr = INADDR_LOOPBACK;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send request
    char *request = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);

    // Receive response
    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        if (result == 0) {
            fprintf(stderr, "Connection closed by server\n");
            exit(EXIT_FAILURE);
        }
        bytes_received += result;
    }
    buffer[bytes_received] = '\0';

    // Print response
    printf("Response:\n%s\n", buffer);

    // Close socket
    close(sock);
    return 0;
}