//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_PORTS 100
#define BUFFER_SIZE 1024

struct host_port {
    char hostname[MAX_HOSTNAME];
    int port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address or hostname>\n", argv[0]);
        exit(1);
    }

    char *ip_or_hostname = argv[1];
    struct hostent *host;
    int i, num_hosts = 0;
    struct host_port hosts[MAX_HOSTNAME];

    if ((host = gethostbyname(ip_or_hostname)) == NULL) {
        printf("Error: %s is not a valid hostname or IP address.\n", ip_or_hostname);
        exit(1);
    }

    for (i = 0; host->h_addr_list[i]!= NULL; i++) {
        strcpy(hosts[num_hosts].hostname, inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
        hosts[num_hosts].port = 0;
        num_hosts++;
    }

    printf("Topology for %s:\n", ip_or_hostname);
    printf("---------------------\n");

    for (i = 0; i < num_hosts; i++) {
        char buffer[BUFFER_SIZE];
        int port = 0;
        int num_ports = 0;

        sprintf(buffer, "telnet %s 1", hosts[i].hostname);
        FILE *fp = popen(buffer, "r");

        while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
            if (strstr(buffer, "Escape character is '^]'.\n")!= NULL) {
                port = atoi(strtok(buffer, " "));
                break;
            }
        }

        pclose(fp);

        if (port == 0) {
            continue;
        }

        hosts[i].port = port;
        printf("%s:%d\n", hosts[i].hostname, hosts[i].port);
    }

    return 0;
}