//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define PORT_NUMBER 65535

// Function to check if a port is open or not
int check_port(int sock, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (result == 0) {
        close(sock);
        return TRUE;
    } else if (errno == ECONNREFUSED) {
        close(sock);
        return FALSE;
    } else {
        close(sock);
        return FALSE;
    }
}

// Function to scan all ports and print open ports
void scan_ports() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (int i = 1; i <= PORT_NUMBER; i++) {
        if (check_port(sock, i)) {
            printf("Port %d is open\n", i);
        }
    }

    close(sock);
}

int main() {
    scan_ports();
    return 0;
}