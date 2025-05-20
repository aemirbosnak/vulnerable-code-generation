//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in target;
    char *ip_address;
    char *header = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:64.0) Gecko/20100101 Firefox/64.0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nAccept-Language: en-US,en;q=0.5\r\nAccept-Encoding: gzip, deflate, br\r\nDNT: 1\r\nConnection: keep-alive\r\nUpgrade-Insecure-Requests: 1\r\n\r\n";
    char *response;
    int response_len;
    char *search_str = "Wireless Network Connection";
    
    if (argc != 2) {
        printf("Usage: %s [IP address]\n", argv[0]);
        exit(1);
    }
    
    ip_address = argv[1];
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // set target address and port
    memset(&target, 0, sizeof(target)); 
    target.sin_family = AF_INET;
    target.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_address, &target.sin_addr);
    
    // connect to target
    printf("Scanning %s...\n", ip_address);
    if (connect(sockfd, (struct sockaddr *) &target, sizeof(target)) < 0) {
        perror("Error connecting to target");
        exit(1);
    }
    
    // send HTTP request
    char request[1024];
    sprintf(request, header, ip_address);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(1);
    }
    
    // receive response
    response = malloc(sizeof(char) * 65536);
    response_len = recv(sockfd, response, 65536, 0);
    if (response_len < 0) {
        perror("Error receiving response");
        exit(1);
    }
    
    // search for wireless network connection
    char *search_res = strstr(response, search_str);
    if (search_res) {
        printf("%s: FOUND\n", search_str);
    } else {
        printf("%s: NOT FOUND\n", search_str);
    }
    
    // cleanup
    free(response);
    close(sockfd);
    
    return 0;
}