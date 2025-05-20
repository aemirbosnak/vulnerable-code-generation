//FormAI DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, i, port, start, end;
    struct sockaddr_in sin;
    char remote_addr[16];
    fd_set fds;
    struct timeval tv;
    int val;

    // Check if the arguments are correct
    if(argc != 4) {
        printf("Usage: %s <remote address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // Get the remote address
    strcpy(remote_addr, argv[1]);
    // Get the start and end ports
    start = atoi(argv[2]);
    end = atoi(argv[3]);

    // Set up the socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket");
        return 1;
    }

    // Set the timeout to half a second
    tv.tv_sec = 0;
    tv.tv_usec = 500000;

    // Set the address and port of the remote server
    sin.sin_family = AF_INET;
    sin.sin_port = htons(start);
    sin.sin_addr.s_addr = inet_addr(remote_addr);

    // Loop through all the ports between start and end
    for(port=start; port<=end; port++) {
        // Set the new port
        sin.sin_port = htons(port);
        // Connect to the remote server
        if(connect(sock, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) == 0) {
            // The port is open, print a message
            printf("Port %d is open.\n", port);
        }
        // Set up the file descriptors
        FD_ZERO(&fds);
        FD_SET(sock, &fds);
        // Wait for the timeout
        val = select(sock+1, &fds, NULL, NULL, &tv);
        if(val == -1) {
            perror("select");
            return 1;
        }
        else if(val) {
            // There was data to be read, close the connection
            close(sock);
            // Set up the socket
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if(sock < 0) {
                perror("socket");
                return 1;
            }
            continue;
        }
        else {
            // There was no data to be read, the port is closed
            printf("Port %d is closed.\n", port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}