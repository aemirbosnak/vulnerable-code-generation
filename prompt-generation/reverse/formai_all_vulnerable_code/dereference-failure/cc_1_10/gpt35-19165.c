//FormAI DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TIMEOUT 5

void scan_port(char *host, int port){
    struct sockaddr_in address;
    int sock, result, optval = 1;
    fd_set readfds;
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    result = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));
    if(result < 0){
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, host, &address.sin_addr);
    memset(&(address.sin_zero), '\0', 8);

    result = connect(sock, (struct sockaddr *)&address, sizeof(struct sockaddr));
    if(result == 0){
        printf("%d/tcp\topen\n", port);
    } else{
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        select(sock + 1, NULL, &readfds, NULL, &tv);
        if (FD_ISSET(sock, &readfds)){
            printf("%d/tcp\tclosed\n", port);
        } else {
            printf("%d/tcp\tfiltered\n", port);
        }
    }
    close(sock);
}

int main(int argc, char *argv[]){
    char *host;
    int port, i;
    
    if(argc != 3){
        printf("Usage: ./scanner <ip_address> <starting_port>\n");
        exit(EXIT_FAILURE);
    }
    
    host = argv[1];
    port = atoi(argv[2]);
    
    printf("Scanning %s...\n", host);
    for(i = port; i <= 65535; i++){
        scan_port(host, i);
    }
    printf("Scan complete.\n");
    return 0;
}