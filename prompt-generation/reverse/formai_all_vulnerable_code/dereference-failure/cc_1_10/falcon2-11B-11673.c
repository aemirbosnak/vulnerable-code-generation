//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    
    char *host = argv[1];
    int port = atoi(argv[2]);
    
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(1);
    }
    
    struct in_addr *ip_addr = (struct in_addr *)host_entry->h_addr_list[0];
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = ip_addr->s_addr;
    
    int connect_ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_ret == -1) {
        perror("connect");
        exit(1);
    }
    
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }
    
    if (n > 0) {
        printf("Connected to %s:%d\n", host, port);
        printf("Received: %s\n", buffer);
    } else {
        printf("Connection failed\n");
    }
    
    close(sockfd);
    return 0;
}