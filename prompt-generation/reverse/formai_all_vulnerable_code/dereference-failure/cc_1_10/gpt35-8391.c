//FormAI DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]){
    int sock, start_port, end_port;
    struct sockaddr_in target;
    char *ip_address;
    int i, open_ports = 0;
    
    if(argc < 3){
        printf("Usage: %s <IP address> <start_port> <end_port>\n", argv[0]);
        return 1;
    }
    
    ip_address = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);
    
    // Create socket
    if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        perror("socket() failed");
        return 1;
    }
    
    // Set target address
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_address);
    
    // Scan for open ports
    printf("Scanning %s for open ports %d-%d...\n", ip_address, start_port, end_port);
    for(i = start_port; i <= end_port; i++){
        target.sin_port = htons(i);
        if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0){
            printf("Port %d is open.\n", i);
            open_ports++;
        }
        close(sock);
    }
    
    // Output scan results
    if(open_ports == 0){
        printf("No open ports found on %s.\n", ip_address);
    } else if(open_ports == 1){
        printf("1 open port found on %s.\n", ip_address);
    } else {
        printf("%d open ports found on %s.\n", open_ports, ip_address);
    }
    
    return 0;
}