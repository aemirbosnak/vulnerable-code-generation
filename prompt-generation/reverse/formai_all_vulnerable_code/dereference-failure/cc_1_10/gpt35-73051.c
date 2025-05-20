//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

// Function to scan the port on the target machine
void scanPort(char* target_addr, int port)
{
    // Create TCP socket 
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0)
    {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    struct sockaddr_in target_sockaddr = {0};
    target_sockaddr.sin_family = AF_INET;
    target_sockaddr.sin_port = htons(port);
    target_sockaddr.sin_addr.s_addr = inet_addr(target_addr);
    memset(&(target_sockaddr.sin_zero), 0, sizeof(target_sockaddr.sin_zero));
    
    // Try to connect to port
    if(connect(sock, (struct sockaddr*)&target_sockaddr, sizeof(target_sockaddr)) >= 0)
    {
        printf("Port %d is open on %s!\n", port, target_addr);
    }
    
    close(sock);
}

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Usage: %s <target IP address> <port range>\n", argv[0]);
        printf("Example usage: %s 192.168.1.1 1-1024\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char* target_addr = argv[1];
    char* port_range = argv[2];
    
    char* port_min_str = strtok(port_range, "-");
    char* port_max_str = strtok(NULL, "-");
    
    int port_min = atoi(port_min_str);
    int port_max = atoi(port_max_str);

    // Check port range
    if(port_min < 1 || port_max > 65535 || port_min >= port_max)
    {
        printf("Invalid port range!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Scanning ports %d-%d on %s...\n", port_min, port_max, target_addr);
    
    // Scan all ports in the specified range
    for(int port = port_min; port <= port_max; port++)
    {
        scanPort(target_addr, port);
    }
    
    printf("Port scan completed!\n");
    
    return 0;
}