//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_DEVICES 50 
#define SCAN_TIMEOUT 5

int main(int argc, char* argv[]) {

    printf("Starting wireless network scanner...\n");

    struct hostent *host;
    struct in_addr **addr_list;
    char device_list[MAX_DEVICES][20] = {{0}};
    int devices_found = 0;

    int socket_desc;
    struct sockaddr_in server_addr;
    char *hostname;
    char ip[20];

    // Get local IP address
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    struct sockaddr_in my_addr;
    bzero(&my_addr,sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(0);
    bind(socket_desc, (struct sockaddr*)&my_addr, sizeof(my_addr));
    socklen_t len = sizeof(my_addr);
    getsockname(socket_desc, (struct sockaddr*)&my_addr, &len);
    char* local_ip = inet_ntoa(my_addr.sin_addr);
    close(socket_desc);

    // Scan for devices on the network
    printf("Scanning...\n");
    for (int i=1; i<=255; i++) {
        char ip[20];
        sprintf(ip, "%s.%d", local_ip, i);

        // Get device info
        host = gethostbyname(ip);
        if (host != NULL) {
            addr_list = (struct in_addr **)host->h_addr_list;
            for (int j=0; addr_list[j] != NULL; j++) {
                strcpy(ip, inet_ntoa(*addr_list[j]));
            }

            // Check if device is a wireless scanner
            if (strstr(host->h_name, "WL") != NULL || strstr(host->h_name, "Scanner") != NULL) {
                printf("Device found: %s (%s)\n", host->h_name, ip);
                strcpy(device_list[devices_found++], ip);
            }
        }

        // Sleep for SCAN_TIMEOUT seconds
        sleep(SCAN_TIMEOUT);
    }

    // Check for rogue devices
    int rogue_devices = 0;
    for (int i=0; i<devices_found; i++) {
        hostname = device_list[i];
        bzero(&server_addr,sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(22);
        inet_pton(AF_INET, hostname, &server_addr.sin_addr);

        // Create socket
        socket_desc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (socket_desc == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            return 1;
        }

        // Connect to device
        if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
            printf("Device %s is a rogue device!\n", hostname);
            rogue_devices++;
        }

        close(socket_desc);
    }

    // Print results
    printf("Scan complete: %d devices found, %d rogue devices.\n", devices_found, rogue_devices);

    return 0;
}