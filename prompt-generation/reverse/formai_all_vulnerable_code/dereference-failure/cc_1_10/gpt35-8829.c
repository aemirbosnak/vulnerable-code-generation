//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <signal.h>

#define TIMEOUT 5 // the amount of time to wait for a response
#define MAX_ATTEMPTS 3 // maximum number of attempts to send a packet before declaring host dead
#define PORT "80" // default port to connect to

struct host {
    char* name;
    char* ip;
    int alive; // 0 if dead, 1 if alive
    int failed_attempts; // number of failed attempts to contact host
    struct timeval last_checked; // the last time the host was checked
};

// function to resolve name to ip address
char* resolve_ip(char* hostname) {
    struct hostent* he;
    struct in_addr** addr_list;
    if ((he = gethostbyname(hostname)) == NULL) {
        return NULL;
    }
    addr_list = (struct in_addr**)he->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
        return inet_ntoa(*addr_list[i]);
    }
    return NULL;
}

// function to check if a host is alive
void check_host(struct host* h) {
    int sock, status;
    struct addrinfo hints;
    struct addrinfo* res;
    struct timeval start, end;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ((status = getaddrinfo(h->ip, PORT, &hints, &res)) != 0) {
        perror("getaddrinfo error");
        return;
    }
    start = (struct timeval){0};
    end = (struct timeval){0};
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0) {
        perror("socket error");
        return;
    }
    gettimeofday(&start, NULL);
    if ((status = connect(sock, res->ai_addr, res->ai_addrlen)) < 0) {
        h->alive = 0;
    } else {
        h->alive = 1;
    }
    gettimeofday(&end, NULL);
    close(sock);
    h->last_checked = end;
}

// function to print various statistics of the monitored hosts
void print_stats(struct host** hosts, int num_hosts) {
    int total_alive = 0;
    int total_dead = 0;
    int total_failed_attempts = 0;
    struct timeval now;
    gettimeofday(&now, NULL);
    printf("\n%-20s %-20s %-15s %-15s %-15s\n", "Name", "IP", "Alive", "Failures", "Last Checked");
    for (int i = 0; i < num_hosts; i++) {
        printf("%-20s %-20s ", hosts[i]->name, hosts[i]->ip);
        if (hosts[i]->alive) {
            total_alive++;
            printf("%-15s", "YES");
        } else {
            total_dead++;
            printf("%-15s", "NO");
        }
        printf("%-15d %-15d seconds ago\n", hosts[i]->failed_attempts, (int)(now.tv_sec - hosts[i]->last_checked.tv_sec));
        total_failed_attempts += hosts[i]->failed_attempts;
    }
    printf("\nTotal live hosts: %d\n", total_alive);
    printf("Total dead hosts: %d\n", total_dead);
    printf("Total failed attempts: %d\n\n", total_failed_attempts);
}

int main() {
    struct host* hosts[3]; // array to store monitored hosts
    hosts[0] = malloc(sizeof(struct host));
    hosts[0]->name = "www.google.com";
    hosts[0]->ip = resolve_ip(hosts[0]->name);
    hosts[0]->alive = 0;
    hosts[0]->failed_attempts = 0;
    hosts[0]->last_checked = (struct timeval){0};
    hosts[1] = malloc(sizeof(struct host));
    hosts[1]->name = "www.yahoo.com";
    hosts[1]->ip = resolve_ip(hosts[1]->name);
    hosts[1]->alive = 0;
    hosts[1]->failed_attempts = 0;
    hosts[1]->last_checked = (struct timeval){0};
    hosts[2] = malloc(sizeof(struct host));
    hosts[2]->name = "www.bing.com";
    hosts[2]->ip = resolve_ip(hosts[2]->name);
    hosts[2]->alive = 0;
    hosts[2]->failed_attempts = 0;
    hosts[2]->last_checked = (struct timeval){0};
    while (1) {
        for (int i = 0; i < 3; i++) {
            check_host(hosts[i]);
            if (!hosts[i]->alive) {
                hosts[i]->failed_attempts++;
                if (hosts[i]->failed_attempts >= MAX_ATTEMPTS) {
                    printf("%s is dead!\n", hosts[i]->name);
                }
            } else {
                hosts[i]->failed_attempts = 0;
            }
        }
        print_stats(hosts, 3);
        sleep(TIMEOUT); // wait before checking again
    }
    for (int i = 0; i < 3; i++) {
        free(hosts[i]);
    }
    return 0;
}