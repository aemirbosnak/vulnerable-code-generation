//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>

// Function to scan a port and print its status
void scanPort(int port, struct sockaddr_in *addr, int timeout) {
    struct timeval timeout_val;
    timeout_val.tv_sec = timeout;
    timeout_val.tv_usec = 0;

    // Create a TCP socket
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the address struct
    memset(&addr->sin_zero, 0, sizeof(addr->sin_zero));
    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = htonl(INADDR_ANY);
    addr->sin_port = htons(port);

    // Connect to the server
    if (connect(tcp_socket, (struct sockaddr*)addr, sizeof(addr->sin_addr)) < 0) {
        perror("connect");
        close(tcp_socket);
        exit(1);
    }

    // Send the SYN packet
    char packet[1024];
    packet[0] = 'S';
    packet[1] = 'Y';
    packet[2] = 'N';
    packet[3] = '\0';
    send(tcp_socket, packet, 4, 0);

    // Receive the ACK packet
    char ack[1024];
    if (recv(tcp_socket, ack, 4, 0) < 0) {
        perror("recv");
        close(tcp_socket);
        exit(1);
    }
    if (ack[0] == 'A' && ack[1] == 'C' && ack[2] == 'K' && ack[3] == '\0') {
        printf("%s - open\n", inet_ntoa(addr->sin_addr));
    } else {
        printf("%s - closed\n", inet_ntoa(addr->sin_addr));
    }

    // Close the socket
    close(tcp_socket);
}

// Function to scan a range of ports
void scanRange(int start, int end, struct sockaddr_in *addr, int timeout) {
    for (int i = start; i <= end; i++) {
        scanPort(i, addr, timeout);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    struct hostent *host_ent = gethostbyname(argv[1]);
    if (host_ent == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    bcopy((char *)host_ent->h_addr_list[0], (char *)&addr.sin_addr.s_addr, host_ent->h_length);
    addr.sin_port = htons(atoi(argv[2]));

    struct timeval timeout = {.tv_sec = 3,.tv_usec = 0 };

    // Scan the range of ports
    scanRange(atoi(argv[2]), atoi(argv[3]), &addr, timeout.tv_sec * 1000 + timeout.tv_usec / 1000);

    return 0;
}