//FormAI DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORT 65535
#define TIMEOUT 3
#define BUFFER_SIZE 1024

void print_banner(void);
void usage(char *program_name);
void scan_port(char *target_ip, int port);

int main(int argc, char **argv) {
    int option;
    char *target_ip;
    int start_port, end_port;

    print_banner();
    if (argc < 3) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    target_ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = argc > 3 ? atoi(argv[3]) : start_port;

    if (end_port < start_port) {
        printf("[-] Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    for (int port = start_port; port <= end_port; port++) {
        scan_port(target_ip, port);
    }

    return EXIT_SUCCESS;
}

void print_banner(void) {
    printf("....\\\n");
    printf(".../\n");
    printf("..//\n");
    printf(".//\n");
    printf("//....\n\n");

    printf("Welcome to the Post-Apocalyptic Port Scanner!\n\n");
}

void usage(char *program_name) {
    printf("Usage: %s <target_ip> <start_port> [end_port]\n", program_name);
    printf("    target_ip       the IP address of the target machine\n");
    printf("    start_port      the first port to scan\n");
    printf("    end_port        the last port to scan (optional: default is start_port)\n");
}

void scan_port(char *target_ip, int port) {
    struct sockaddr_in target_addr;
    int sock_fd;
    int flags;
    int status;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        return;
    }

    // Set socket to non-blocking mode
    flags = fcntl(sock_fd, F_GETFL, 0);
    fcntl(sock_fd, F_SETFL, flags | O_NONBLOCK);

    // Set socket address
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);
    target_addr.sin_port = htons(port);

    // Connect to target
    status = connect(sock_fd, (struct sockaddr *) &target_addr, sizeof(target_addr));

    // Check if connection was successful
    if (status == 0) {
        printf("[+] Port %d is open on %s\n", port, target_ip);
    } else {
        fd_set set;
        struct timeval timeout;

        FD_ZERO(&set);
        FD_SET(sock_fd, &set);

        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        status = select(sock_fd + 1, NULL, &set, NULL, &timeout);

        if (status == 1) {
            int error;
            socklen_t len = sizeof(error);
            getsockopt(sock_fd, SOL_SOCKET, SO_ERROR, &error, &len);

            if (error == 0) {
                printf("[+] Port %d is open on %s\n", port, target_ip);
            }
        }
    }

    close(sock_fd);
}