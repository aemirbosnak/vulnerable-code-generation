//FormAI DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PORT 65535

bool is_valid_ip(char *ip){
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}

void scan_port(char *ip, int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        printf("Socket error: %s\n", strerror(errno));
        return;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &(addr.sin_addr));
    int conn = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if(conn == 0){
        printf("[+] Port %d open\n", port);
        close(sock);
        return;
    }
    close(sock);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s <ip>\n", argv[0]);
        exit(0);
    }
    if(!is_valid_ip(argv[1])){
        printf("Invalid IP address\n");
        exit(1);
    }
    printf("Scanning IP: %s\n", argv[1]);
    for(int port = 1; port <= MAX_PORT; port++){
        scan_port(argv[1], port);
    }
    printf("Scan complete\n");
    return 0;
}