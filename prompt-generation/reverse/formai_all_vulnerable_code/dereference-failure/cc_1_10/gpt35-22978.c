//FormAI DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

void scanPort(char *ip, int port)
{
    int socket_desc = 0, conn_status = 0;
    struct sockaddr_in server_addr;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("[ERROR]: Could not create socket\n");
        return;
    }

    // Set server address data
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Attempt to connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Port %d closed\n", port);
        fflush(stdout);
        return;
    } else {
        printf("Port %d open\n", port);
        fflush(stdout);
    }
    close(socket_desc);
}

int main(int argc, char **argv)
{
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate input
    if (argc != 4 || strcmp(ip_address, "") == 0 || start_port < 1 || end_port > 65535) {
        printf("[ERROR]: Invalid input format\n");
        return 1;
    }

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip_address);

    // Scan each port within the range
    for (int i = start_port; i <= end_port; i++) {
        scanPort(ip_address, i);
    }

    printf("Port scan complete\n");

    return 0;
}