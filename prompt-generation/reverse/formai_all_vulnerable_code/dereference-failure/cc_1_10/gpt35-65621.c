//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h> 
#include <stdlib.h>
#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <unistd.h> 

int main(int argc, char *argv[]) 
{ 
    if(argc < 2) 
    { 
        printf("\nUsage: %s <IP Address> <optional: start port> <optional: end port>\n", argv[0]); 
        printf("If no range is specified, the program will scan all ports from 1-65535\n"); 
        exit(1); 
    } 
    
    int start_port = 1, end_port = 65535; 
    if(argc >= 3) 
    { 
        start_port = atoi(argv[2]); 
    } 
    
    if(argc == 4) 
    { 
        end_port = atoi(argv[3]); 
    } 
    
    int sock, status, port; 
    struct sockaddr_in server_addr; 
    
    // create socket 
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    
    if(sock == -1) 
    { 
        printf("\nSocket creation failed. Exiting...\n"); 
        exit(1); 
    } 
    
    // set server address 
    server_addr.sin_family = AF_INET; 
    inet_pton(AF_INET, argv[1], &(server_addr.sin_addr)); 
    
    // start scanning 
    printf("\nStarting port scan on %s...\n", argv[1]); 
    for(port = start_port; port <= end_port; port++) 
    { 
        server_addr.sin_port = htons(port); 
        status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)); 
        
        if(status == 0) 
        { 
            printf("Port %d: \t Open\n", port); 
        } 
        else 
        { 
            printf("Port %d: \t Closed\n", port); 
        } 
    } 
    
    printf("\nScan complete.\n"); 
    
    return 0; 
}