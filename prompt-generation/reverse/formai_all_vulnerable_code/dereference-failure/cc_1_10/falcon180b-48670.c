//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <IP Address> <Starting Port> <Ending Port>\n", program_name);
}

int is_valid_port(int port) {
    if (port <= 0 || port > 65535) {
        return 0;
    }
    return 1;
}

int scan_port(int sock, struct sockaddr_in *serv_addr, int port) {
    int valopt = 1;
    char buffer[BUFFER_SIZE];
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&valopt, sizeof(valopt));

    if (connect(sock, (struct sockaddr *)serv_addr, sizeof(struct sockaddr)) == 0) {
        sprintf(buffer, "Port %d is open.\n", port);
        write(1, buffer, strlen(buffer));
    } else {
        if (errno == ECONNREFUSED) {
            sprintf(buffer, "Port %d is closed.\n", port);
            write(1, buffer, strlen(buffer));
        } else {
            sprintf(buffer, "Error connecting to port %d: %s\n", port, strerror(errno));
            write(2, buffer, strlen(buffer));
        }
    }

    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    struct sockaddr_in serv_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    for (int i = atoi(argv[2]); i <= atoi(argv[3]); i++) {
        if (is_valid_port(i)) {
            scan_port(sock, &serv_addr, i);
        }
    }

    close(sock);
    return 0;
}