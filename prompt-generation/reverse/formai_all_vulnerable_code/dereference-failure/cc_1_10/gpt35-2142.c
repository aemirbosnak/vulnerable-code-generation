//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define MAX_IP_LEN 16

struct host {
    char ip[MAX_IP_LEN];
    char banner[128];
};

int do_scan(const char *ip) {
    struct addrinfo hints;
    struct addrinfo *res;
    struct sockaddr_in addr;
    int sockfd, status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if ((status = getaddrinfo(ip, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    memcpy(&addr, res->ai_addr, sizeof(addr));
    freeaddrinfo(res);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno != ECONNREFUSED && errno != EHOSTUNREACH)
            perror("connect");
        close(sockfd);
        return 0;
    }

    printf("%s open\n", ip);
    close(sockfd);
    return 1;
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[128];
    char *token;
    char *delim = " ,\t\n";
    struct host hosts[MAX_HOSTS];
    int i, j, num_hosts;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <hosts file>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        return 1;
    }

    num_hosts = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (num_hosts == MAX_HOSTS) {
            fprintf(stderr, "too many hosts, increase MAX_HOSTS\n");
            return 1;
        }

        token = strtok(line, delim);
        strncpy(hosts[num_hosts].ip, token, sizeof(hosts[num_hosts].ip) - 1);
        hosts[num_hosts].ip[sizeof(hosts[num_hosts].ip) - 1] = '\0';

        while ((token = strtok(NULL, delim)) != NULL)
            strncat(hosts[num_hosts].banner, token, sizeof(hosts[num_hosts].banner) - strlen(hosts[num_hosts].banner) - 1);

        num_hosts++;
    }

    fclose(fp);

    for (i = 0; i < num_hosts; i++) {
        printf("Scanning %s (%s)\n", hosts[i].ip, hosts[i].banner);
        do_scan(hosts[i].ip);
    }

    return 0;
}