//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <ctype.h>

// Function to scan the wireless network
void scan_wireless() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Could not create socket\n");
        return;
    }
    
    // Set socket timeout to 3 seconds
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        printf("Error setting socket timeout\n");
        return;
    }
    
    // Set socket options
    int optval = 1;
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        printf("Error setting socket options\n");
        return;
    }
    
    // Define the IP range to scan
    char* base_ip = "192.168.0.";
    int start_ip = 1;
    int end_ip = 255;
    char ip_addr[16];
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    
    // Scan each IP in the range
    for(int i = start_ip; i <= end_ip; i++) {
        // Build the IP address
        sprintf(ip_addr, "%s%d", base_ip, i);
        
        // Set the server address
        if(inet_pton(AF_INET, ip_addr, &server_addr.sin_addr) <= 0) {
            printf("Invalid IP address: %s\n", ip_addr);
            continue;
        }
        
        // Connect to the server
        if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            if(errno == ECONNREFUSED) {
                printf("No device found at IP address: %s\n", ip_addr);
            }
            continue;
        }
        
        // Receive data from the server
        char buffer[1024] = {0};
        if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
            printf("Error receiving data from IP address: %s\n", ip_addr);
            continue;
        }
        
        // Check if the received data contains wireless network information
        char* ptr = strstr(buffer, "ESSID:");
        if(ptr != NULL) {
            // Extract the wireless network name
            char* start = strchr(ptr, '\"');
            if(start != NULL) {
                start++;
                char* end = strchr(start, '\"');
                if(end != NULL) {
                    *end = '\0';
                    // Print the wireless network name and IP address
                    printf("Wireless network '%s' found at IP address %s\n", start, ip_addr);
                }
            }
        }
        
        // Close the connection
        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1) {
            printf("Could not create socket\n");
            return;
        }
    }
    
    // Close the socket
    close(sock);
}

// Main function
int main() {
    printf("Scanning wireless networks...\n");
    scan_wireless();
    printf("Scan complete.\n");
    return 0;
}