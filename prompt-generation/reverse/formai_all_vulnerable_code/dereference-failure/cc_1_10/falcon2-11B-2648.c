//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[100];
    
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <light_id>\n", argv[0]);
        exit(1);
    }
    
    portno = atoi(argv[1]);
    int light_id = atoi(argv[2]);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    
    while (1) {
        bzero(buffer, sizeof(buffer));
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL) == -1) {
            perror("recvfrom");
            exit(1);
        }
        
        if (strcmp(buffer, "on") == 0) {
            printf("Turning on light %d...\n", light_id);
            system("echo 'on' | nc 127.0.0.1 31337");
        } else if (strcmp(buffer, "off") == 0) {
            printf("Turning off light %d...\n", light_id);
            system("echo 'off' | nc 127.0.0.1 31337");
        } else {
            printf("Unknown command: %s\n", buffer);
        }
    }
    
    return 0;
}