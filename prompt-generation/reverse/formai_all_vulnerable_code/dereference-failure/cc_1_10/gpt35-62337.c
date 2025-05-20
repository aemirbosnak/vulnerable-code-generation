//FormAI DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int sockfd, portno;
    float time_elapsed;
    clock_t start, end;
 
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    
    portno = 80;
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
 
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }
 
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("\nTesting ping...\n");
    start = clock();

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) >= 0) {
        printf("\n%s is live! Pinging...\n", argv[1]);
        
        end = clock();
        time_elapsed = ((float) (end - start)) / CLOCKS_PER_SEC;
        printf("\nPing successful! Time elapsed: %f seconds\n", time_elapsed);
    }
    else {
        printf("\n%s is not responding\n", argv[1]);
    }
 
    close(sockfd);
    return 0;
}