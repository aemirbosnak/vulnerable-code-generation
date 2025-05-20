//FormAI DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>      // For I/O functions
#include <stdlib.h>     // For standard functions
#include <sys/socket.h> // For socket related functions
#include <netinet/in.h> // For internet related functions
#include <string.h>     // For string related functions
#include <arpa/inet.h>  // For inet related functions
 
// Function to scan a port
int scan_port(char *ip, int port) {
    int sockfd, conn, status;
    struct sockaddr_in target;
 
    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
    // Target socket details
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip);
 
    // Try to connect to the target socket
    conn = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
 
    // Close the socket
    close(sockfd);
 
    if(conn == 0) {
        status = 1; // Port is open
    }
    else {
        status = 0; // Port is closed
    }
 
    return status;
}
 
// Main function
int main(int argc, char *argv[]) {
    int ports[] = {21, 22, 23, 80, 443, 3389, 8080}; // Array of commonly used ports
 
    // Check if IP and Port arguments were passed
    if(argc < 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        printf("Example: %s 127.0.0.1 80\n", argv[0]);
        exit(0);
    }
 
    char *ip = argv[1];
    int port = atoi(argv[2]);
 
    // Check if the port is valid
    if(port < 1 || port > 65535) {
        printf("Invalid Port\n"); 
        exit(0);
    }
 
    printf("Scanning Port %d on %s\n", port, ip);
    printf("=================================\n");
 
    // Scan the specified port on the IP address
    int result = scan_port(ip, port);
 
    if(result == 1) {
        printf("[+] Port %d is Open\n", port); 
    }
    else {
        printf("[-] Port %d is Closed\n", port); 
    }
 
    // Scan commonly used ports if no specific port was specified
    if(argc == 2) {
        printf("\nScanning Common Ports\n");
        printf("=========================");
 
        for(int i=0; i < sizeof(ports)/sizeof(ports[0]); i++) {
            printf("\nPort %d\t-\t", ports[i]);
            int result = scan_port(ip, ports[i]);
 
            if(result == 1) {
                printf("[+] Open\n"); 
            }
            else {
                printf("[-] Closed\n"); 
            }
        }
    }
 
    return 0;
}