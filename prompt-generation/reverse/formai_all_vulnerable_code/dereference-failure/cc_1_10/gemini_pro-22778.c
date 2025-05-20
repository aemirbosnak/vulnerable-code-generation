//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in servaddr;
} client_info;

void * checksum_calculator(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[MAX_BUFFER_SIZE];
    int nbytes;
    uint32_t checksum = 0;

    while ((nbytes = read(client->sockfd, buffer, MAX_BUFFER_SIZE)) > 0) {
        for (int i = 0; i < nbytes; i++) {
            checksum += buffer[i];
        }
    }

    if (nbytes < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("Checksum: %u\n", checksum);

    close(client->sockfd);
    free(client);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    client_info *client = (client_info *)malloc(sizeof(client_info));
    client->sockfd = sockfd;
    client->servaddr = servaddr;

    pthread_t thread;
    if (pthread_create(&thread, NULL, checksum_calculator, (void *)client) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);

    return 0;
}