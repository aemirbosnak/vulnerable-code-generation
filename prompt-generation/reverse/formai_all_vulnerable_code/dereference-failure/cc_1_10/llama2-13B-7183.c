//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define IP_ADDRESS "192.168.1.100" // Replace with your target IP address

int main(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    char buffer[256];

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Replace with your desired port
    server_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);

    // Connect to the target IP address and port
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect error");
        return 1;
    }

    // Send a SYN packet to the target IP address and port
    send(sock, "SYN", 3, 0);

    // Receive a SYN-ACK packet from the target IP address and port
    recv(sock, buffer, 256, 0);

    // Extract the target port number from the SYN-ACK packet
    int target_port = ntohs(get_port(buffer));

    // Print the open ports on the target IP address
    printf("Open ports on %s:%d:\n", IP_ADDRESS, target_port);

    // Scan for open ports from 1 to 65535
    for (int i = 1; i <= MAX_PORTS; i++) {
        // Send a SYN packet to the target IP address and port
        send(sock, "SYN", 3, 0);

        // Receive a SYN-ACK packet from the target IP address and port
        recv(sock, buffer, 256, 0);

        // Extract the target port number from the SYN-ACK packet
        int curr_port = ntohs(get_port(buffer));

        // Check if the port is open
        if (curr_port != target_port) {
            printf("Port %d is open\n", curr_port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}

// Function to extract the port number from the SYN-ACK packet
int get_port(char *buffer)
{
    // Parse the SYN-ACK packet to extract the port number
    char *p = strtok(buffer, ")");
    char *q = strtok(NULL, ")");
    int port = atoi(q);

    return port;
}