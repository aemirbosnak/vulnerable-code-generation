//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024
#define BUFFER_SIZE 1024

void scan_ports(int sockfd, int target_ip, int start_port, int end_port) {
    int i, port;
    struct sockaddr_in target_addr;

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = htonl(target_ip);

    for (i = start_port; i <= end_port; i++) {
        if (i == 80)
            continue;  // skip port 80 (HTTP)

        port = htons(i);
        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open\n", i);
            close(sockfd);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <target_ip> <start_port> <end_port> <output_file>\n", argv[0]);
        return 1;
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    FILE *output_file = fopen(argv[4], "w");

    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    scan_ports(sockfd, target_ip, start_port, end_port);

    close(sockfd);
    fclose(output_file);

    return 0;
}