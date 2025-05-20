//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <netdb.h>  
#include <arpa/inet.h>  

#define MIN_PORT 1  
#define MAX_PORT 65535  
#define TIMEOUT 5

void usage(char* program_name) {  
    printf("Usage: %s <IP address> [<start port>] [<end port>]\n", program_name);  
    printf("Defaults to scanning all ports from %d to %d\n", MIN_PORT, MAX_PORT);  
}  

int main(int argc, char* argv[]) {  
    struct sockaddr_in target;  
    struct hostent *host_info;  
    int start_port = MIN_PORT, end_port = MAX_PORT;  

    if (argc < 2) {  
        usage(argv[0]);  
        exit(1);  
    }  

    memset(&target, 0, sizeof(target));  
    target.sin_family = AF_INET;  
    target.sin_addr.s_addr = inet_addr(argv[1]);  

    if (target.sin_addr.s_addr == INADDR_NONE) {  
        host_info = gethostbyname(argv[1]);  

        if (host_info == NULL) {  
            fprintf(stderr, "Cannot resolve hostname %s\n", argv[1]);  
            exit(1);  
        }  

        memcpy(&target.sin_addr, host_info->h_addr, host_info->h_length);  
    }  

    if (argc > 2) {  
        start_port = atoi(argv[2]);  

        if (start_port < MIN_PORT || start_port > MAX_PORT) {  
            printf("Invalid start port %d. Allowed range: %d-%d\n", start_port, MIN_PORT, MAX_PORT);  
            exit(1);  
        }  
    }  

    if (argc > 3) {  
        end_port = atoi(argv[3]);  

        if (end_port < MIN_PORT || end_port > MAX_PORT) {  
            printf("Invalid end port %d. Allowed range: %d-%d\n", end_port, MIN_PORT, MAX_PORT);  
            exit(1);  
        }  
    }  

    printf("Scanning ports %d-%d on %s...\n", start_port, end_port, inet_ntoa(target.sin_addr));  

    for (int port = start_port; port <= end_port; port++) {  
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);  
        struct timeval timeout;  
        timeout.tv_sec = TIMEOUT;  
        timeout.tv_usec = 0;  

        if (sockfd < 0) {  
            continue;  
        }  

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {  
            continue;  
        }  

        if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {  
            continue;  
        }  

        target.sin_port = htons(port);  

        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {  
            printf("Port %d is open\n", port);  
        }  

        close(sockfd);  
    }  

    printf("Scan of %s is complete\n", inet_ntoa(target.sin_addr));  
    return 0;  
}