//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

void print_usage(char* prog_name) {
    printf("%s [hostname] [port]\n", prog_name);
    printf("Example: %s 127.0.0.1 80\n", prog_name);
}

void print_header(char* prog_name, char* hostname, int port) {
    printf("%s %s %d\n", prog_name, hostname, port);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent* he;
    struct in_addr** addr_list;
    int num_addrs;

    he = gethostbyname(hostname);
    if (he == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(EXIT_FAILURE);
    }

    addr_list = (struct in_addr**) he->h_addr_list;
    num_addrs = he->h_length;

    for (int i = 0; i < num_addrs; i++) {
        struct sockaddr_in addr;

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = *((struct in_addr*) addr_list[i]);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        if (connect(sockfd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
            perror("Error connecting to host");
            exit(EXIT_FAILURE);
        }

        char buffer[MAX_BUFFER_SIZE];
        int n = read(sockfd, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        printf("%s\n", buffer);

        close(sockfd);
    }

    return 0;
}