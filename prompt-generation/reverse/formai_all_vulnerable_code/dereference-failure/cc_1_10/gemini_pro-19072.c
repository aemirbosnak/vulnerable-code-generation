//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 100
#define MAX_PORTS 100

struct host {
        char *name;
        struct in_addr addr;
        int port;
};

struct host *hosts[MAX_HOSTS];
int num_hosts = 0;

struct port {
        int port;
        int open;
};

struct port *ports[MAX_PORTS];
int num_ports = 0;

void scan_host(struct host *host)
{
        int sockfd;
        struct sockaddr_in addr;
        int i;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
                perror("socket");
                exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_addr = host->addr;
        for (i = 0; i < num_ports; i++) {
                addr.sin_port = htons(ports[i]->port);
                if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
                        ports[i]->open = 1;
                } else {
                        ports[i]->open = 0;
                }
        }

        close(sockfd);
}

void print_results()
{
        int i, j;

        printf("Network Topology Map:\n");
        for (i = 0; i < num_hosts; i++) {
                printf("  Host: %s (%s)\n", hosts[i]->name, inet_ntoa(hosts[i]->addr));
                for (j = 0; j < num_ports; j++) {
                        if (ports[j]->open) {
                                printf("    Port: %d (open)\n", ports[j]->port);
                        }
                }
                printf("\n");
        }
}

int main()
{
        FILE *fp;
        char line[1024];
        char *host, *port;
        int i;

        fp = fopen("hosts.txt", "r");
        if (fp == NULL) {
                perror("fopen");
                exit(1);
        }

        while (fgets(line, sizeof(line), fp)) {
                host = strtok(line, ":");
                port = strtok(NULL, ":");
                if (host && port) {
                        hosts[num_hosts] = malloc(sizeof(struct host));
                        hosts[num_hosts]->name = strdup(host);
                        hosts[num_hosts]->addr.s_addr = inet_addr(host);
                        hosts[num_hosts]->port = atoi(port);
                        num_hosts++;
                }
        }

        fclose(fp);

        fp = fopen("ports.txt", "r");
        if (fp == NULL) {
                perror("fopen");
                exit(1);
        }

        while (fgets(line, sizeof(line), fp)) {
                port = strtok(line, "\n");
                if (port) {
                        ports[num_ports] = malloc(sizeof(struct port));
                        ports[num_ports]->port = atoi(port);
                        num_ports++;
                }
        }

        fclose(fp);

        for (i = 0; i < num_hosts; i++) {
                scan_host(hosts[i]);
        }

        print_results();

        return 0;
}