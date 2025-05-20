//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

void print_help() {
    printf("Port scanner, yo! \n");
    printf("USAGE: %s <host> <start_port> <end_port>\n", __func__);
    printf("Example: %s 8.8.8.8 22 2222\n", __func__);
}

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    char buffer[1024];

    if (argc < 3) {
        print_help();
        return 1;
    }

    // Parse host and port range
    server_host = gethostbyname(argv[1]);
    if (server_host == NULL) {
        printf("Invalid hostname: %s\n", argv[1]);
        return 2;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 3;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return 4;
    }

    // Send SYN packet to initiate connection
    send(sock, "SYN", 3, 0);

    // Receive response
    recv(sock, buffer, 1024, 0);

    // Print received packet
    printf("Received packet: %s\n", buffer);

    // Close connection
    close(sock);

    return 0;
}