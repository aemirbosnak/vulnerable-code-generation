//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_RANGE 1024

int main() {
    int sock = 0;
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    char buffer[1024];
    char *port_str;
    int port;

    // Step 1: Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Step 2: Set up the server address
    server_host = gethostbyname("example.com"); // Replace with your target host
    if (server_host == NULL) {
        perror("gethostbyname failed");
        exit(1);
    }
    memcpy(&server_addr, server_host->h_addr, server_host->h_length);

    // Step 3: Set up the port range
    port_str = "1-65535"; // Replace with your target port range
    port = atoi(port_str);
    if (port < 1 || port > 65535) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    // Step 4: Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Step 5: Send a SYN packet to the server
    send(sock, "SYN", 3, 0);

    // Step 6: Receive the SYN-ACK packet from the server
    recv(sock, buffer, 1024, 0);

    // Step 7: Extract the port number from the SYN-ACK packet
    port = ntohs(get_port(buffer));

    // Step 8: Print the found port
    printf("Port %d found on %s\n", port, inet_ntoa(server_addr.sin_addr));

    // Step 9: Close the socket
    close(sock);

    return 0;
}

// Helper function to extract the port number from the SYN-ACK packet
int get_port(char *buffer) {
    int port;
    char *p;

    // Look for the port number in the SYN-ACK packet
    for (p = buffer; *p != '\0'; p++) {
        if (*p == ')') {
            // Found the end of the port number
            port = atoi(p + 1);
            break;
        }
    }

    // Return the found port number
    return port;
}