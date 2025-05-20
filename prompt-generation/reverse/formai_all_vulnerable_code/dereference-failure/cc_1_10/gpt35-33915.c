//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAXPORT 65535
#define TIMEOUT 3

typedef struct {
    char *banner;
    int timeout;
} service_t;

char *banners[] = {"OpenSSH_", "Dropbear_", "Microsoft Windows", "Apache/", "nginx/", "MySQL"};
static service_t services[] = {
    {"OpenSSH", 2},
    {"Dropbear", 2},
    {"HTTP", TIMEOUT},
    {"MySQL", 3},
    {"SQL Server", 3},
    {"Oracle", 3},
};

int scan_port(char *ip, int port, int timeout)
{
    struct sockaddr_in addr;
    int sockfd, flags, err;
    fd_set fdset;
    struct timeval tv;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    flags = fcntl(sockfd, F_GETFL, 0);
    if(flags < 0) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    if(fcntl(sockfd, F_SETFL, flags|O_NONBLOCK) < 0) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);

    err = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if(err < 0 && errno != EINPROGRESS) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    if(err == 0) {
        close(sockfd);
        return port;
    }

    FD_ZERO(&fdset);
    FD_SET(sockfd, &fdset);
    
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    err = select(sockfd+1, NULL, &fdset, NULL, &tv);
    if(err > 0) {
        int so_error;
        socklen_t len = sizeof(so_error);

        getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);

        if(so_error == 0) {
            close(sockfd);
            return port;
        }
    }

    close(sockfd);
    return -1;
}

int find_service(char *banner)
{
    int i;

    for(i = 0; i < sizeof(services)/sizeof(*services); i++) {
        if(strstr(banner, services[i].banner)) {
            return services[i].timeout;
        }
    }

    return TIMEOUT;
}

int main(int argc, char *argv[])
{
    char *ip;
    int i, j, k, timeout = TIMEOUT, start = 0, end = MAXPORT, count = 0;

    if(argc < 2) {
        printf("Usage: ./portscanner ip_address [-s start_port] [-e end_port]\n");
        exit(EXIT_FAILURE);
    }

    ip = argv[1];

    for(i = 2; i < argc; i++) {
        if(!strcmp(argv[i], "-s")) {
            if(i + 1 < argc) {
                start = atoi(argv[i+1]);
                if(start < 0) {
                    start = 0;
                }
            }
        }
        if(!strcmp(argv[i], "-e")) {
            if(i + 1 < argc) {
                end = atoi(argv[i+1]);
                if(end > MAXPORT) {
                    end = MAXPORT;
                }
            }
        }
    }

    printf("Starting port scan on %s from %d to %d\n", ip, start, end);

    for(i = start; i <= end; i++) {
        timeout = find_service(banners[rand() % sizeof(banners)/sizeof(*banners)]);

        if((k = scan_port(ip, i, timeout)) >= 0) {
            printf("Port %d OPEN - ", i);

            for(j = 0; j < sizeof(services)/sizeof(*services); j++) {
                if(services[j].timeout == timeout) {
                    printf("%s service detected\n", services[j].banner);
                    break;
                }
            }

            count++;
        }
    }

    printf("Scan complete. %d open ports found.\n", count);

    return 0;
}