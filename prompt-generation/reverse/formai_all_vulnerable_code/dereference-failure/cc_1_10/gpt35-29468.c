//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_LEN 1024
#define HOSTNAME "www.google.com"
#define PORT 80

int main() {
    char ip_addr[MAX_MSG_LEN], request[MAX_MSG_LEN], response[MAX_MSG_LEN];
    struct sockaddr_in serv_addr = {0};
    struct hostent *he;
    int sock, len;
    
    // Resolve IP address from hostname
    if((he = gethostbyname(HOSTNAME)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    inet_ntop(AF_INET, he->h_addr_list[0], ip_addr, sizeof(ip_addr));
    
    // Open socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Setup server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr.s_addr);
    
    // Connect to server
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    
    // Send HTTP request
    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", HOSTNAME);
    len = strlen(request);
    if(write(sock, request, len) != len) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    // Receive HTTP response
    len = read(sock, response, MAX_MSG_LEN - 1);
    response[len] = '\0';
    printf("%s", response);
    
    // Close socket
    close(sock);
    
    return EXIT_SUCCESS;
}