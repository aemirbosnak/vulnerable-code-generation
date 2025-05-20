//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

void scan_ports(int sock, int start, int end) {
    int i, j, found = 0;
    struct sockaddr_in serv_addr;
    socklen_t len = sizeof(serv_addr);

    for (i = start; i <= end; i++) {
        // Create a socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket() failed");
            exit(1);
        }

        // Set address and port
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
            perror("inet_pton() failed");
            exit(1);
        }

        // Connect to the port
        if (connect(sock, (struct sockaddr *)&serv_addr, len) < 0) {
            perror("connect() failed");
            exit(1);
        }

        // Check if the port is open
        if (send(sock, "Hello, world!", 13, 0) == -1) {
            perror("send() failed");
            exit(1);
        }

        // Receive the response
        char buff[1024];
        recv(sock, buff, 1024, 0);

        // Check if the response is "Hello, world!"
        if (strcmp(buff, "Hello, world!") != 0) {
            found = 1;
            break;
        }

        // Close the socket
        close(sock);
    }

    // Print the results
    if (found == 0) {
        printf("Port %d is open\n", i);
    } else {
        printf("Port %d is closed\n", i);
    }
}

int main(int argc, char *argv[]) {
    int sock, start, end;

    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    start = atoi(argv[1]);
    end = atoi(argv[2]);

    // Scan the ports
    for (sock = start; sock <= end; sock++) {
        scan_ports(sock, start, end);
    }

    return 0;
}