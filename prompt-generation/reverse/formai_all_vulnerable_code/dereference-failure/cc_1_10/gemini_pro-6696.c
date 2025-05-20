//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_PING_COUNT 10

struct ping_packet {
    uint32_t sequence_number;
    time_t timestamp;
};

void print_usage(const char *program_name) {
    printf("Usage: %s <hostname> [<ping_count>]\n", program_name);
    printf("Example: %s google.com 5\n", program_name);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];

    int ping_count = MAX_PING_COUNT;
    if (argc >= 3) {
        ping_count = atoi(argv[2]);
    }

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    int status = getaddrinfo(hostname, NULL, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }

    int socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socket_fd == -1) {
        perror("socket");
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    struct sockaddr_in destination_address;
    memset(&destination_address, 0, sizeof(struct sockaddr_in));
    destination_address.sin_family = AF_INET;
    destination_address.sin_addr = ((struct sockaddr_in *)result->ai_addr)->sin_addr;

    freeaddrinfo(result);

    struct ping_packet packet;
    memset(&packet, 0, sizeof(struct ping_packet));

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    for (int i = 0; i < ping_count; i++) {
        packet.sequence_number = i + 1;
        packet.timestamp = time(NULL);

        int sent_bytes = sendto(socket_fd, &packet, sizeof(struct ping_packet), 0, (struct sockaddr *)&destination_address, sizeof(struct sockaddr_in));
        if (sent_bytes == -1) {
            perror("sendto");
            close(socket_fd);
            return EXIT_FAILURE;
        }

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(socket_fd, &read_fds);

        int select_result = select(socket_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (select_result == -1) {
            perror("select");
            close(socket_fd);
            return EXIT_FAILURE;
        }

        if (FD_ISSET(socket_fd, &read_fds)) {
            int received_bytes = recvfrom(socket_fd, buffer, MAX_BUFFER_SIZE, 0, NULL, NULL);
            if (received_bytes == -1) {
                perror("recvfrom");
                close(socket_fd);
                return EXIT_FAILURE;
            }

            struct ping_packet *received_packet = (struct ping_packet *)buffer;
            
            time_t now = time(NULL);
            double elapsed_time = difftime(now, received_packet->timestamp);

            printf("Ping %d: %.3f ms\n", received_packet->sequence_number, elapsed_time * 1000);
        } else {
            printf("Ping %d: Timeout\n", i + 1);
        }
    }

    close(socket_fd);

    return EXIT_SUCCESS;
}