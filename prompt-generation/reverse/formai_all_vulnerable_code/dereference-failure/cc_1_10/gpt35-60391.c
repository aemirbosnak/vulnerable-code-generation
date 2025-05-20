//FormAI DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <target_ip> <port_range>\n", argv[0]);
        return 1;
    }
    
    char *target_ip = argv[1];
    char *port_range = argv[2];
    char port[6];

    printf("Scanning ports from %s...\n", port_range);
    
    // create socket
    int socket_desc;
    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        return 1;
    }

    // fill in target address data structure
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);
    
    for(int i = atoi(strtok(port_range, "-")); i <= atoi(strtok(NULL, "-")); i++) {
        memset(port, 0, sizeof(port));
        sprintf(port, "%d", i);

        // fill in target port data structure
        target_addr.sin_port = htons(i);
        
        // connect to target
        if (connect(socket_desc, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d open\n", i);
            close(socket_desc);
        }
    }
    
    printf("Scan complete\n");
    return 0;
}