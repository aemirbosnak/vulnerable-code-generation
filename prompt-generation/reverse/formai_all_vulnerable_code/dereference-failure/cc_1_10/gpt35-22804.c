//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUF_SIZE 1024

void error(char *msg) {
    fprintf(stderr, "[ERROR] %s: %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "[USAGE] %s <ip_address>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to create socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(22);

    int res = inet_aton(ip_address, &server_addr.sin_addr);
    if (res <= 0) {
        error("Invalid IP address");
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Failed to connect to remote host");
    }

    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "nmap %s", ip_address);

    FILE *fp = popen(buf, "r");
    if (fp == NULL) {
        error("Failed to execute nmap command");
    }

    printf("IP Address\t\tHostname\t\tPort\n");

    while (fgets(buf, BUF_SIZE, fp))
    {
        if (strstr(buf, "open")) {
            char *ip_start_ptr = strchr(buf, '(');
            if (ip_start_ptr != NULL){
                ip_start_ptr++;
                char ip[16];
                memset(ip, 0, sizeof(ip));
                strncpy(ip, ip_start_ptr, strchr(ip_start_ptr, ')') - ip_start_ptr);

                char *hostname_start_ptr = strchr(buf, ' ');
                if (hostname_start_ptr != NULL) {
                    hostname_start_ptr++;
                    char *hostname_end_ptr = strchr(hostname_start_ptr, ' ');
                    if (hostname_end_ptr != NULL) {
                        *hostname_end_ptr = '\0';

                        char *port_start_ptr = strchr(buf, '/');
                        if (port_start_ptr != NULL) {
                            port_start_ptr++;
                            int port = atoi(port_start_ptr);

                            printf("%-15s\t%-15s\t%d\n", ip, hostname_start_ptr, port);
                        }
                    }
                }
            }
        }
    }

    pclose(fp);
    close(sockfd);
    return 0;
}