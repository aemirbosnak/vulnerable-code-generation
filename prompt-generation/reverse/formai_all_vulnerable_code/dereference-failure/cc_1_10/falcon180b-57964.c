//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024


int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int port;
    char buffer[BUF_SIZE];
    char *ip;
    int num_ports = 0;
    FILE *file;
    char filename[50] = "ports.txt";

    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            fprintf(file, "Port %d is open.\n", port);
            num_ports++;
        } else if (errno == ECONNREFUSED) {
            fprintf(file, "Port %d is closed.\n", port);
        } else {
            fprintf(file, "Error: Could not check port %d.\n", port);
        }
    }

    fclose(file);
    printf("Scanned %d ports.\n", num_ports);

    return 0;
}