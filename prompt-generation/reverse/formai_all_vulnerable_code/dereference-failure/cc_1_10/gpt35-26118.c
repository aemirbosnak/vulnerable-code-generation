//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  
    char *hostname = argv[1];

    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct in_addr **addr_list;
    addr_list = (struct in_addr **) he->h_addr_list;
    struct in_addr ip_addr = *addr_list[0];
    char *ip_addr_str = inet_ntoa(ip_addr);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;     
    serv_addr.sin_port = htons(80);     
    if (inet_pton(AF_INET, ip_addr_str, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }
  
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    char response_buffer[BUFFER_SIZE];
    size_t bytes_received = recv(sockfd, response_buffer, BUFFER_SIZE - 1, 0);
    response_buffer[bytes_received] = '\0';
    printf("%s", response_buffer);

    close(sockfd);

    return 0;
}