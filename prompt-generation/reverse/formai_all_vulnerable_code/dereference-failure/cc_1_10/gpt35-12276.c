//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <unistd.h> 

#define TIMEOUT 1 // Timeout for each connection attempt in seconds

void scan_port(char * ip_addr, int port_num);

int main(int argc, char *argv[]) 
{ 
    if (argc < 2 || argc > 3) { // Check for correct number of arguments
        printf("Usage: %s <ip address> [<port number>]\n", argv[0]);
        exit(1);
    }
    
    char* ip_addr = argv[1];
    int port_num;
    
    if (argc == 3) { // Check if a port number is specified
        port_num = atoi(argv[2]);
        scan_port(ip_addr, port_num);
    } else { // Scan all ports if no port number is specified
        for (int i = 1; i <= 65535; i++) {
            scan_port(ip_addr, i);
        }
    }
    
    return 0; 
} 

/* Function to scan a specific port on a given IP address */
void scan_port(char * ip_addr, int port_num) { 
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) { 
        printf("Could not create socket"); 
    } 
    
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);
    
    fd_set readfds;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    // Set socket options for timeout
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) { 
        printf("Port %d is open on %s\n", port_num, ip_addr);
    } else {
        printf("Port %d is closed on %s\n", port_num, ip_addr);
    }
    
    close(sock); 
}