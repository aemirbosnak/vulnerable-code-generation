//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Please specify a hostname or IP address to scan\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 2;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // default port for HTTP

    // Parse the command line arguments to get the hostname or IP address
    char *host = argv[1];
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("Invalid IP address or hostname");
        return 3;
    }

    // Set the port range to scan
    int start_port = 1024;
    int end_port = 65535;
    if (argc > 2) {
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    }

    // Perform the port scan
    for (int port = start_port; port <= end_port; port++) {
        // Create a sockaddr structure for the current port
        struct sockaddr_in port_addr;
        port_addr.sin_family = AF_INET;
        port_addr.sin_port = htons(port);
        port_addr.sin_addr = serv_addr.sin_addr;

        // Send a SYN packet to the target port
        int syn_packet_len = sendto(sock, "SYN", 3, 0, (struct sockaddr *)&port_addr, sizeof(port_addr));
        if (syn_packet_len < 0) {
            perror("sendto failed");
            continue;
        }

        // Wait for a response (if any)
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(sock, (struct sockaddr *)&port_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Print the port number and the client IP address
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &port_addr.sin_addr, client_ip, sizeof(client_ip));
        printf("%d - %s\n", port, client_ip);

        // Close the client socket
        close(client_sock);
    }

    // Close the listening socket
    close(sock);

    return 0;
}