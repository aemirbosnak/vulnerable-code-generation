//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

// function to scan a single port 
void scanPort(char *ip, int port) 
{ 
    int sock = socket(AF_INET, SOCK_STREAM, 0); 
    struct sockaddr_in server; 
    server.sin_addr.s_addr = inet_addr(ip); 
    server.sin_family = AF_INET; 
    server.sin_port = htons(port); 
  
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0 ) 
    { 
        printf("Port %d closed on %s\n", port, ip); 
    } 
    else 
    { 
        printf("Port %d open on %s\n", port, ip); 
    } 
    close(sock); 
} 

// function to scan multiple ports 
void scanPorts(char *ip, int start, int end) 
{ 
    printf("Scanning ports %d-%d on %s...\n", start, end, ip); 
    for(int i = start; i <= end; i++) 
    { 
        scanPort(ip, i); 
    } 
    printf("Port scan on %s complete.\n", ip); 
} 

// the main function 
int main(int argc, char *argv[]) 
{ 
    // check for correct input from user 
    if (argc < 3) 
    { 
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]); 
        return -1; 
    } 

    char *ip = argv[1]; 
    int start = atoi(argv[2]); 
    int end = atoi(argv[3]); 
    
    // check for valid port numbers 
    if (start < 0 || end > 65535) 
    { 
        printf("Invalid port range.\n"); 
        return -1; 
    } 
    
    // start scanning the ports 
    scanPorts(ip, start, end); 

    return 0; 
}