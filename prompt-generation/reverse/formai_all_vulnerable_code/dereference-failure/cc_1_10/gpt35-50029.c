//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 65535

typedef struct {
    char ip_address[16];
    char hostname[256];
} HostInfo;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(struct sockaddr_in));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    if (target_addr.sin_addr.s_addr == INADDR_NONE) {
        printf("Invalid IP address: %s\n", target_ip);
        exit(EXIT_FAILURE);
    }

    struct hostent *target_host = gethostbyaddr((char *) &target_addr.sin_addr,
                                            sizeof(target_addr.sin_addr), AF_INET);
    if (target_host == NULL) {
        printf("Unable to obtain host information for IP address: %s\n", target_ip);
        exit(EXIT_FAILURE);
    }

    char target_hostname[256];
    strncpy(target_hostname, target_host->h_name, sizeof(target_hostname));

    printf("Target IP: %s\n", target_ip);
    printf("Target hostname: %s\n", target_hostname);

    char command[MAX_BUFFER_SIZE];
    snprintf(command, MAX_BUFFER_SIZE, "traceroute -n %s", target_ip);
    FILE *trace_stream = popen(command, "r");
    if (trace_stream == NULL) {
        printf("Unable to open traceroute\n");
        exit(EXIT_FAILURE);
    }

    HostInfo hosts[MAX_BUFFER_SIZE];
    int num_hosts = 0;
    char trace_output[MAX_BUFFER_SIZE];
    while (fgets(trace_output, MAX_BUFFER_SIZE, trace_stream) != NULL) {
        char *ip_address = strtok(trace_output, " ");
        HostInfo host_info;

        if (inet_pton(AF_INET, ip_address, &(target_addr.sin_addr))) {
            struct hostent *host = gethostbyaddr((char *) &target_addr.sin_addr,
                                                sizeof(target_addr.sin_addr), AF_INET);
            if (host != NULL) {
                strncpy(host_info.ip_address, ip_address, sizeof(host_info.ip_address));
                strncpy(host_info.hostname, host->h_name, sizeof(host_info.hostname));
                hosts[num_hosts++] = host_info;
            }
        }
    }

    pclose(trace_stream);

    if (num_hosts > 0) {
        printf("\nNetwork Topology Map:\n");

        for (int i = 0; i < num_hosts; i++) {
            printf("%s -> %s\n", hosts[i].ip_address, hosts[i].hostname);
        }
    } else {
        printf("Unable to obtain network topology map\n");
    }

    exit(EXIT_SUCCESS);
}