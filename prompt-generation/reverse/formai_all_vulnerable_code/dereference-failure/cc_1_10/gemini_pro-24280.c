//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFF_SIZE 1024
#define INTERVAL 300

struct host_info {
    char *hostname;
    int status;
    time_t last_checked;
};

struct host_info *hosts;
int num_hosts;

void add_host(char *hostname) {
    hosts = realloc(hosts, (num_hosts + 1) * sizeof(struct host_info));
    hosts[num_hosts].hostname = hostname;
    hosts[num_hosts].status = 0;
    hosts[num_hosts].last_checked = time(NULL);
    num_hosts++;
}

int check_host(struct host_info *host) {
    struct hostent *he;
    struct sockaddr_in addr;
    int sockfd;

    he = gethostbyname(host->hostname);
    if (he == NULL) {
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)he->h_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return -1;
    }

    close(sockfd);

    return 0;
}

void monitor_hosts() {
    time_t now = time(NULL);

    for (int i = 0; i < num_hosts; i++) {
        if (now - hosts[i].last_checked > INTERVAL) {
            hosts[i].status = check_host(&hosts[i]);
            hosts[i].last_checked = now;
        }
    }
}

void print_report() {
    printf("Host\t\tStatus\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("%s\t\t", hosts[i].hostname);
        if (hosts[i].status == 0) {
            printf("Up");
        } else {
            printf("Down");
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hostnames>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        add_host(argv[i]);
    }

    while (1) {
        monitor_hosts();
        print_report();
        sleep(INTERVAL);
    }

    return 0;
}