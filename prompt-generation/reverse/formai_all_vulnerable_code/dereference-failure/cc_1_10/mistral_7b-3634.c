//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_MIN 1
#define PORT_MAX 65535
#define BUF_SIZE 1024
#define BANNER "\n===============[ Retro Port Scanner v1.0 ]===============\n"
#define TIMEOUT 500
#define RAND_MAX 10000

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int random_number() {
    int seed = time(NULL);
    srand(seed);
    return rand() % RAND_MAX;
}

void print_banner() {
    printf(BANNER);
}

int is_open(int port) {
    int sockfd, ret;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Can't create socket\n");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret < 0) {
        close(sockfd);
        return 0;
    }

    close(sockfd);
    return 1;
}

void scan(int start_port, int end_port) {
    int i;

    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    for (i = start_port; i <= end_port; i++) {
        if (is_open(i)) {
            printf("\033[1;31mPort %d is open\033[0m\n", i);
        } else {
            printf("\033[1;34mPort %d is closed\033[0m\n", i);
        }
        usleep(random_number() * 1000);
    }
}

int main(int argc, char *argv[]) {
    print_banner();

    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    scan(atoi(argv[1]), atoi(argv[2]));

    return 0;
}