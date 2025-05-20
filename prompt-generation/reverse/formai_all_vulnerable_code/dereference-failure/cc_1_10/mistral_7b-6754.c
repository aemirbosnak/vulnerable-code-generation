//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOSTS 256
#define MAX_IPS 256

typedef struct {
    char host[MAX_HOSTS];
    char ip[INET_ADDRSTRLEN];
    int port;
    int state;
} host_t;

host_t hosts[MAX_HOSTS];

void scan_host(int index, char *hostname) {
    int sockfd, port, len;
    struct sockaddr_in serv_addr;

    if (index >= MAX_HOSTS) {
        printf("Max hosts reached\n");
        return;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("Invalid IP format");
        return;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket error");
        return;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connect error");
        close(sockfd);
        return;
    }

    if (send(sockfd, "GET / HTTP/1.0\r\nHost: ", 17, 0) < 0 ||
        send(sockfd, hostname, strlen(hostname), 0) < 0 ||
        send(sockfd, "\r\n", 2, 0) < 0) {
        perror("Send error");
        close(sockfd);
        return;
    }

    len = recv(sockfd, hosts[index].ip, MAX_IPS, 0);
    hosts[index].ip[len] = '\0';
    hosts[index].port = ntohs(serv_addr.sin_port);
    hosts[index].state = 1;

    close(sockfd);
    printf("Host: %s, IP: %s, Port: %d, State: Online\n", hosts[index].host, hosts[index].ip, hosts[index].port);
}

int main() {
    char *hosts_file = "hosts.txt";
    FILE *file;
    char line[MAX_HOSTS];
    int i = 0;

    file = fopen(hosts_file, "r");
    if (file == NULL) {
        perror("File error");
        return 1;
    }

    while (fgets(line, MAX_HOSTS, file) != NULL) {
        char *token = strtok(line, ":");
        if (token != NULL) {
            strcpy(hosts[i].host, token);
            scan_host(i, strtok(NULL, "\n"));
            i++;
        }
    }

    fclose(file);

    return 0;
}