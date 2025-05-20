//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

struct sockaddr_in server_addr;
int sockfd;
char data[MAX_DATA_SIZE];

void main() {
    int n;
    struct hostent *host;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    host = gethostbyname("localhost");
    
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    server_addr.sin_addr.s_addr = *(long *)host->h_addr;
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    printf("Connected to server\n");
    
    while (1) {
        bzero(data, MAX_DATA_SIZE);
        n = read(sockfd, data, MAX_DATA_SIZE);
        
        if (n == 0) {
            printf("Server disconnected\n");
            exit(1);
        }
        
        printf("Received data: %s\n", data);
    }
}