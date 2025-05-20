//FormAI DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREAD 65535

void scan_port(int port) {
    int socket_desc;
    struct sockaddr_in server;
     
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Port %d is closed\n", port);
        exit(0);
    }

    printf("Port %d is open\n", port);
}

int main(int argc, char *argv[]) {
    int start = 1, end = MAX_THREAD, i;
 
    if (argc == 2) {
        start = atoi(argv[1]);
        end = start + 1;
    } else if (argc == 3) {
        start = atoi(argv[1]);
        end = atoi(argv[2]) + 1;
    } else if (argc > 3) {
        printf("Invalid input format\n");
        return 0;
    }
 
    printf("Scanning started...\n");
    printf("Range: %d-%d\n", start, end-1);

    for (i = start; i < end; i++) {
        scan_port(i);
    }

    printf("Scan complete!\n");
    return 0;
}