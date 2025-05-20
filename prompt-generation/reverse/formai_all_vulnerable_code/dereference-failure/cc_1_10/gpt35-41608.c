//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_DEVICES 50
#define MAX_NAME_LENGTH 50
#define MAX_IP_LENGTH 16

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
} Device;

int main() {
    Device devices[MAX_DEVICES];
    int num_devices = 0;

    printf("Welcome to the Network Topology Mapper!\n\n");

    printf("Enter an IP address to scan the network (e.g. 192.168.1.0): ");
    char ip_address[MAX_IP_LENGTH];
    fgets(ip_address, MAX_IP_LENGTH, stdin);
    
    // Remove newline character
    ip_address[strcspn(ip_address, "\n")] = 0;

    for (int i = 1; i <= 255; i++) {
        // Construct IP address
        char current_ip[MAX_IP_LENGTH];
        sprintf(current_ip, "%s.%d", ip_address, i);

        // Create socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Error creating socket");
            exit(1);
        }

        // Set socket options
        int opt = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        // Fill in socket address structure
        struct sockaddr_in server_addr;
        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(current_ip);
        server_addr.sin_port = htons(80);

        // Connect to server
        int connection_status = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
        if (connection_status == 0) { // Connection successful
            struct hostent *host;
            host = gethostbyaddr(&server_addr.sin_addr, sizeof(server_addr.sin_addr), AF_INET);

            strcpy(devices[num_devices].name, host->h_name);
            strcpy(devices[num_devices].ip, current_ip);

            num_devices++;

            printf("Found device %s at IP address %s\n", host->h_name, current_ip);

        } else { // Connection unsuccessful
            printf("Could not connect to device at IP address %s\n", current_ip);
        }

        close(sock);
    }

    printf("\n\nNetwork Topology:\n\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s)\n", devices[i].name, devices[i].ip);
    }

    return 0;
}