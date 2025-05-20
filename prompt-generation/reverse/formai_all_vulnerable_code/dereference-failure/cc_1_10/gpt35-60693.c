//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>

#define MAX_PORTS 65535

struct scan_host {
    char ip_str[INET_ADDRSTRLEN];
    struct in_addr ip_addr;
    int open_ports[MAX_PORTS];
    int num_ports_open;
};

void clear_screen() {
    system("clear||cls"); //clear screen based on OS
}

int is_port_open(const char *ip_str, int port) {
    int sockfd, status;
    struct addrinfo hints;
    struct addrinfo *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    char port_str[6];
    snprintf(port_str, 6, "%d", port);

    if ((status = getaddrinfo(ip_str, port_str, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 0;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        } else {
            close(sockfd);
            freeaddrinfo(servinfo);
            return 1;
        }
    }

    freeaddrinfo(servinfo);
    return 0;
}

void scan_port_range(struct scan_host *host, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(host->ip_str, port)) {
            printf("Port %d is open\n", port);
            host->open_ports[host->num_ports_open] = port;
            host->num_ports_open++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./scan [ip_address]\n");
        exit(1);
    }

    struct scan_host host;

    strncpy(host.ip_str, argv[1], INET_ADDRSTRLEN);

    if (inet_pton(AF_INET, host.ip_str, &(host.ip_addr)) != 1) {
        perror("inet_pton");
        exit(1);
    }

    clear_screen();

    printf("Starting paranoid wireless network scan...\n");

    const int port_range1_start = 1;
    const int port_range1_end = 1023;
    const int port_range2_start = 1024;
    const int port_range2_end = MAX_PORTS;

    const int num_scans = 2;
    int scans_completed = 0;

    while (scans_completed < num_scans) {
        printf("Scanning ports %d to %d...\n", (scans_completed == 0) ? port_range1_start : port_range2_start,
            (scans_completed == 0) ? port_range1_end : port_range2_end);

        if (scans_completed == 0) {
            scan_port_range(&host, port_range1_start, port_range1_end);
        } else {
            scan_port_range(&host, port_range2_start, port_range2_end);
        }

        if (host.num_ports_open > 0) {
            printf("WARNING: %d open ports found!\n", host.num_ports_open);

            for(int i=0;i<host.num_ports_open;i++)
            {
                printf("Port open: %d\n", host.open_ports[i]);
            }

            char *suspicious_services[] = {"telnet", "netstat", "ftp", "ssh", "mysql", "http", "https", "smtp"};
            int num_suspicious_services = sizeof(suspicious_services) / sizeof(suspicious_services[0]);

            printf("Possible services running: ");

            for(int i=0;i<host.num_ports_open;i++)
            {
                for(int j=0;j<num_suspicious_services;j++)
                {
                    if(host.open_ports[i] == 21 && strcmp(suspicious_services[j], "ftp") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }

                    if(host.open_ports[i] == 22 && strcmp(suspicious_services[j], "ssh") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }

                    if(host.open_ports[i] == 23 && strcmp(suspicious_services[j], "telnet") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }

                    if(host.open_ports[i] == 25 && strcmp(suspicious_services[j], "smtp") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }

                    if(host.open_ports[i] == 80 && strcmp(suspicious_services[j], "http") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }

                    if(host.open_ports[i] == 443 && strcmp(suspicious_services[j], "https") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }

                    if(host.open_ports[i] == 3306 && strcmp(suspicious_services[j], "mysql") == 0)
                    {
                        printf("%s, ", suspicious_services[j]);
                    }
                }
            }

            printf("\nWARNING: Possible security breach detected!\n");
        } else {
            printf("No open ports found.\n");
        }

        scans_completed++;

        if (scans_completed < num_scans) {
            printf("Waiting 5 seconds before scanning again...\n");
            sleep(5);
        }
    }

    return 0;
}