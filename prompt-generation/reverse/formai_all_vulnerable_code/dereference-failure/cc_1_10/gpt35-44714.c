//FormAI DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void scanPort(char *ip, int port) {
    struct sockaddr_in target_addr;
    int sock;
    
    // creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return;
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(ip);
    target_addr.sin_port = htons(port);

    // connecting to the specified port
    if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
        printf("Port %d is open!\n", port);
    }
    else {
        printf("Port %d is closed!\n", port);
    }
    
    close(sock);
}

int main(int argc, char *argv[]) {
    char *ip;
    int start_port, end_port, i;
    
    if (argc < 4) {
        printf("Usage: %s [ip] [start_port] [end_port]\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, ip);

    for (i = start_port; i <= end_port; i++) {
        scanPort(ip, i);
    }

    printf("Scan complete\n");

    return 0;
}