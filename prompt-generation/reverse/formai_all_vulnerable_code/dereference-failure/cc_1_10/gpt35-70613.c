//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: c_wireless_scanner <IP address> <Port>\n");
    printf("Example: c_wireless_scanner 192.168.1.1 80\n");
}

int main(int argc, char *argv[]) {

    // Check correct number of arguments
    if (argc != 3) {
        print_usage();
        return -1;
    }

    // Create socket
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    // Set socket options for reuse
    int option = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    // Set up server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return -1;
    }

    // Send request to server
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Error sending request to server: %s\n", strerror(errno));
        return -1;
    }

    // Receive response from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int received;
    if ((received = recv(sock, buffer, BUFFER_SIZE, 0)) < 0) {
        printf("Error receiving response from server: %s\n", strerror(errno));
        return -1;
    }

    // Print response
    printf("Received response from server: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}