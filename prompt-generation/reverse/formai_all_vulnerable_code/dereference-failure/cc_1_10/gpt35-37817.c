//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTS 1024
#define MAX_PORTS 1024

typedef struct{
    int host_count;
    char hosts[MAX_HOSTS][64];
}HostList;

void usage(char *program_name){
    printf("Usage: %s [ip or host name]\n", program_name);
}

int get_socket(char *host_ip){

    int sockfd;
    struct sockaddr_in target_addr;

    /* create a socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("Could not create a socket\n");
        return -1;
    }

    /* set target address */
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(host_ip);
    target_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        printf("Could not connect to target\n");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

HostList get_host_list(char *target_ip){

    HostList host_list;
    host_list.host_count = 0;

    int sockfd, i;
    char buffer[64];
    struct sockaddr_in server_addr;
    struct hostent *server;
    fd_set set;
    struct timeval timeout;

    /* create a socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("Could not create a socket\n");
        return host_list;
    }

    /* resolve target address */
    if ((server = gethostbyname(target_ip)) == NULL) {
        printf("Could not resolve target address\n");
        close(sockfd);
        return host_list;
    }

    /*set server address*/
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    /* connect to server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not connect to %s\n", target_ip);
        close(sockfd);
        return host_list;
    }

    /*send request*/
    send(sockfd, "GET / HTTP/1.1\r\nHost: ", 25, 0);
    send(sockfd, target_ip, strlen(target_ip), 0);
    send(sockfd, "\r\nConnection: close\r\n\r\n", 25, 0);

    /* wait for response */
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    /* read response */
    while (select(sockfd + 1, &set, NULL, NULL, &timeout) > 0) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
            if (strstr(buffer, "http://") != NULL) {
                char *host_start = buffer + (strstr(buffer, "http://") - buffer) + 7;
                char *host_end = strchr(host_start, '/');
                if (host_end != NULL) {
                    int host_len = host_end - host_start;
                    strncpy(host_list.hosts[host_list.host_count], host_start, host_len);
                    host_list.hosts[host_list.host_count][host_len] = '\0';
                    host_list.host_count++;
                }
            }
        }
        else {
            break;
        }
    }

    close(sockfd);
    return host_list;
}

void port_scan(char *ip_address, HostList *host_list) {

    int sockfd, i, j;
    struct sockaddr_in target_addr;
    fd_set set;
    struct timeval timeout;

    for (i = 0; i < host_list->host_count; i++) {
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;

        if (inet_aton(host_list->hosts[i], &target_addr.sin_addr) == 0) {
            printf("Invalid IP address: %s\n", host_list->hosts[i]);
            continue;
        }

        for (j = 0; j <= MAX_PORTS; j++) {
            if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
                break;
            }

            fcntl(sockfd, F_SETFL, O_NONBLOCK);

            target_addr.sin_port = htons(j);
            connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

            FD_ZERO(&set);
            FD_SET(sockfd, &set);
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;

            if (select(sockfd + 1, NULL, &set, NULL, &timeout) == 1) {
                printf("%s:%d\topen\n", host_list->hosts[i], j);
            }

            close(sockfd);
        }
    }
}


int main(int argc, char **argv){

    if (argc < 2) {
        usage(argv[0]);
        exit(-1);
    }

    HostList host_list;
    host_list = get_host_list(argv[1]);
    port_scan(argv[1], &host_list);
    exit(0);
}