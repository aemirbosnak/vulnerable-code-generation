//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <netdb.h>

#define PORT 80 // HTTP port
#define MAX_RECV_BUFFER 4096 // Maximum size of the receive buffer
#define TIMEOUT 5 // Timeout for network scanning

bool scan_ip(char *ip_address) {
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    if(inet_pton(AF_INET, ip_address, &server_address.sin_addr) < 0) {
        perror("inet_pton");
        return false;
    }
    
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1) {
        perror("socket");
        return false;
    }
    
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    
    if(setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        close(socket_fd);
        return false;
    }
    
    if(setsockopt(socket_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        close(socket_fd);
        return false;
    }
    
    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        if(errno == EINPROGRESS) {
            fd_set set;
            FD_ZERO(&set);
            FD_SET(socket_fd, &set);
            
            if(select(socket_fd + 1, NULL, &set, NULL, &timeout) == 1) {
                int error;
                socklen_t length = sizeof(error);
                
                if(getsockopt(socket_fd, SOL_SOCKET, SO_ERROR, &error, &length) == -1 || error) {
                    perror("getsockopt");
                    close(socket_fd);
                    return false;
                }
                
                printf("%s\n", ip_address);
                close(socket_fd);
                return true;
            }
            else {
                perror("select");
                close(socket_fd);
                return false;
            }
        }
        else {
            perror("connect");
            close(socket_fd);
            return false;
        }
    }
    
    printf("%s\n", ip_address);
    close(socket_fd);
    return true;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <network prefix>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *prefix = argv[1];
    
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    
    struct addrinfo *result;
    int status = getaddrinfo(prefix, NULL, &hints, &result);
    if(status != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }
    
    int count = 0;
    for(struct addrinfo *p = result; p != NULL; p = p->ai_next) {
        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(p->ai_family, &((struct sockaddr_in *)p->ai_addr)->sin_addr, ip_address, INET_ADDRSTRLEN);
        
        if(count % 10 == 0) {
            printf("%-15s ", "IP Address");
            printf("%-12s\n", "Status");
            printf("--------------- ------------\n");
        }
        
        if(scan_ip(ip_address)) {
            count++;
        }
    }
    
    printf("\nScan complete. Found %d host(s).\n", count);
    
    freeaddrinfo(result);
    return EXIT_SUCCESS;
}