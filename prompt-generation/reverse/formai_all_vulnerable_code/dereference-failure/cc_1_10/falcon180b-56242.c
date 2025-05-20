//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage:./qos_monitor <IP Address> <Port Number>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            break;
        }

        int i;
        for (i = 0; i < bytes_received; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                printf("%s", buffer);
                memset(buffer, 0, BUFFER_SIZE);
            }
        }
    }

    close(sockfd);
    return 0;
}