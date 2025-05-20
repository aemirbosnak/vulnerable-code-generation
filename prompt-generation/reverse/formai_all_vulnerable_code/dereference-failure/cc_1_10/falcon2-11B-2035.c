//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <target_host>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the target
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a request
    char request[] = "GET / HTTP/1.0\r\n\r\n";
    send(sock, request, sizeof(request), 0);

    // Receive a response
    char response[1024];
    memset(response, 0, sizeof(response));
    recv(sock, response, sizeof(response), 0);

    // Print the response
    printf("%s", response);

    // Close the socket
    close(sock);

    return 0;
}