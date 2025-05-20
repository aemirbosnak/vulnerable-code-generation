//FormAI DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SOCKET_ERROR -1
#define ERROR 1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[]) {
    char* hostname;
    int start_port, end_port;

    if(argc != 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(ERROR);
    } else {
        hostname = argv[1];
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    }

    struct sockaddr_in s_addr;

    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(end_port);
    s_addr.sin_addr.s_addr = inet_addr(hostname);

    int s_fd;
    int count = 0;
    int status;

    for(int i = start_port; i <= end_port; i++) {
        s_addr.sin_port = htons(i);
        s_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if(s_fd == SOCKET_ERROR) {
            perror("Failed to create socket");
            exit(ERROR);
        } 

        status = connect(s_fd, (struct sockaddr*)&s_addr, sizeof(s_addr));

        if(status == SOCKET_ERROR) {
            printf("Port %d is closed\n", i);
            close(s_fd);
        } else {
            printf("Port %d is open\n", i);
            close(s_fd);
            count++;
        }
    }

    printf("\nScan completed!\n");
    printf("%d open port(s) found in range: [%d-%d]\n", count, start_port, end_port);

    return SUCCESS;
}