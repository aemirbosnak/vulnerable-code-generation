//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTS 100
#define CHECK_INTERVAL 60 // seconds
#define TIMEOUT 5 // seconds

struct host {
    char *name;
    int sock;
};

void check_hosts(struct host *hosts, int num_hosts) {
    for (int i = 0; i < num_hosts; i++) {
        if (hosts[i].sock!= -1) {
            char buf[1024];
            int len = recv(hosts[i].sock, buf, sizeof(buf), 0);
            if (len <= 0) {
                close(hosts[i].sock);
                hosts[i].sock = -1;
                printf("%s is down\n", hosts[i].name);
            }
        }
    }
}

void add_host(struct host *hosts, int num_hosts, char *name) {
    for (int i = 0; i < num_hosts; i++) {
        if (hosts[i].sock == -1) {
            hosts[i].name = strdup(name);
            hosts[i].sock = socket(AF_INET, SOCK_STREAM, 0);
            struct sockaddr_in addr;
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_port = htons(80);
            inet_pton(AF_INET, name, &addr.sin_addr);
            if (connect(hosts[i].sock, (struct sockaddr *)&addr, sizeof(addr))!= -1) {
                printf("%s is up\n", name);
            } else {
                close(hosts[i].sock);
                hosts[i].sock = -1;
                printf("%s is down\n", name);
            }
            break;
        }
    }
}

int main() {
    struct host hosts[MAX_HOSTS];
    int num_hosts = 0;

    while (1) {
        check_hosts(hosts, num_hosts);
        sleep(CHECK_INTERVAL);

        char input[1024];
        printf("Enter a host name (or leave blank to exit): ");
        fgets(input, sizeof(input), stdin);
        if (strlen(input) == 0) {
            break;
        }

        char *name = strtok(input, "\n");
        add_host(hosts, num_hosts, name);
        num_hosts++;
    }

    return 0;
}