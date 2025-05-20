//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define MAX_PORTS 10

struct host_info {
    char *hostname;
    int port;
    int status; // 0 = untested, 1 = reachable, -1 = unreachable
    struct host_info *next;
};

struct host_info *head = NULL;

void add_host(char *hostname, int port) {
    struct host_info *new_host = malloc(sizeof(struct host_info));
    new_host->hostname = strdup(hostname);
    new_host->port = port;
    new_host->status = 0;
    new_host->next = head;
    head = new_host;
}

void print_hosts() {
    struct host_info *current = head;
    while (current != NULL) {
        printf("%s:%d %s\n", current->hostname, current->port, current->status == 1 ? "reachable" : "unreachable");
        current = current->next;
    }
}

int check_host(char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);

    int result = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    close(sockfd);

    return result == 0 ? 1 : -1;
}

void test_hosts(struct host_info *host) {
    if (host == NULL) {
        return;
    }

    host->status = check_host(host->hostname, host->port);
    test_hosts(host->next);
}

int main() {
    add_host("www.google.com", 80);
    add_host("www.facebook.com", 80);
    add_host("www.amazon.com", 80);
    add_host("www.microsoft.com", 80);
    add_host("www.apple.com", 80);

    test_hosts(head);
    print_hosts();

    return 0;
}