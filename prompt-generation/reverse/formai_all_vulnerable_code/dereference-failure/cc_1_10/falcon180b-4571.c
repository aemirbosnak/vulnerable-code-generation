//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

void main() {
    int sd, i, maxsd, rc, valread, totread = 0, packet_size;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = TRUE;
    char ip[16];

    // Create socket
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed");
        exit(0);
    }

    // Set reuse address
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    // Set linger
    struct linger linger;
    linger.l_onoff = 1;
    linger.l_linger = 10;
    setsockopt(sd, SOL_SOCKET, SO_LINGER, (char *)&linger, sizeof(linger));

    // Set time out
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    setsockopt(sd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv));
    setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

    // Bind socket
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed");
        exit(0);
    }

    // Listen for incoming connections
    if (listen(sd, 5) < 0) {
        printf("listen failed");
        exit(0);
    }

    while (TRUE) {
        // Accept incoming connection
        if ((rc = accept(sd, (struct sockaddr *)&cli_addr, (socklen_t*)&maxsd)) < 0) {
            printf("accept failed");
            exit(0);
        }

        // Get IP address of client
        inet_ntop(AF_INET, &cli_addr.sin_addr, ip, 16);

        // Send welcome message to client
        send(rc, "Welcome to the server\r\n", 23, 0);

        // Send current date and time to client
        time_t now = time(NULL);
        char* dt = ctime(&now);
        send(rc, dt, strlen(dt), 0);

        // Close connection
        close(rc);
    }
}