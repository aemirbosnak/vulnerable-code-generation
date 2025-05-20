//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 1024

typedef struct {
    char name[MAXLINE];
    char ip_address[MAXLINE];
} Host;

Host * hosts[MAXLINE];
int total_hosts = 0;

void read_hosts_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening hosts file: %s\n", strerror(errno));
        exit(1);
    }

    char line[MAXLINE];
    while (fgets(line, MAXLINE, fp)) {
        char * name = strtok(line, ",");
        char * ip_address = strtok(NULL, "\n");
        Host * host = (Host *) malloc(sizeof(Host));
        strcpy(host->name, name);
        strcpy(host->ip_address, ip_address);
        hosts[total_hosts++] = host;
    }
}

void ping_hosts() {
    int i;
    for (i = 0; i < total_hosts; i++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            fprintf(stderr, "Error creating socket for %s: %s\n", hosts[i]->name, strerror(errno));
            continue;
        }

        struct sockaddr_in servaddr;
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(hosts[i]->ip_address);
        servaddr.sin_port = htons(22);

        if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
            fprintf(stderr, "Error connecting to %s: %s\n", hosts[i]->name, strerror(errno));
        } else {
            printf("%s is up!\n", hosts[i]->name);
        }

        close(sockfd);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hosts_file\n", argv[0]);
        exit(1);
    }

    read_hosts_file(argv[1]);
    ping_hosts();

    return 0;
}