//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [host name]\n", argv[0]);
        exit(1);
    }

    char *host_name = argv[1];
    struct hostent *host_info = gethostbyname(host_name);

    if (!host_info) {
        fprintf(stderr, "Error: Cannot resolve host '%s'\n", host_name);
        exit(1);
    }

    printf("Resolved '%s' to %s\n",
           host_name,
           inet_ntoa(*(struct in_addr*)host_info->h_addr_list[0]));

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd < 0) {
        perror("Error: Could not create socket");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(22),
        .sin_addr = *(struct in_addr*)host_info->h_addr_list[0]
    };

    int res = connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (res < 0) {
        perror("Error: Could not connect to host");
        exit(1);
    }

    // send packets to server
    for (int i = 0; i < 10; i++) {
        printf("Sending packet %d...\n", i);
        if (send(socket_fd, "QoS", 3, 0) < 0) {
            perror("Error: Could not send packet");
            exit(1);
        }
        sleep(1);
    }

    printf("Successfully sent all packets to host\n");
    return 0;
}