//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <interval> <website>\n", argv[0]);
        return 1;
    }
    
    int interval = atoi(argv[1]);
    char *website = argv[2];
    struct hostent *host = gethostbyname(website);
    if (!host) {
        printf("Error: Unknown host %s\n", website);
        return 2;
    }
    
    int port = 80;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr*) host->h_addr);
    addr.sin_port = htons(port);
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Failed to create socket\n");
        return 3;
    }
    
    if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        printf("Error: Failed to connect to %s:%d\n", website, port);
        return 4;
    }
    
    printf("Website uptime monitor activated: %s\nPress CTRL+C to stop.\n", website);
    
    while (1) {
        char request[1024];
        sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", website);
        if (send(sock, request, strlen(request), 0) < 0) {
            printf("Error: Failed to send data to server\n");
            return 5;
        }
        
        char response[1024];
        if (recv(sock, response, sizeof(response), 0) < 0) {
            printf("Error: Failed to receive data from server\n");
            return 6;
        }
        
        if (strstr(response, "200 OK") == NULL) {
            printf("Website is down!\n");
        }
        else {
            printf("Website is up!\n");
        }
        
        sleep(interval);
    }
    
    close(sock);
    return 0;
}