//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define MAX_IP_LENGTH 20
#define INTERVAL 60

volatile sig_atomic_t stop;

void sigint_handler(int signum) {
    stop = 1;
}

void monitor(char *url) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(url, "80", &hints, &res);
    if (status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        return;
    }
    struct sockaddr_in *ipv4 = (struct sockaddr_in *) res->ai_addr;
    char ip[MAX_IP_LENGTH];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ip, MAX_IP_LENGTH);
    freeaddrinfo(res);
    
    printf("Monitoring %s (%s)\n", url, ip);
    
    while (!stop) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            return;
        }
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        if (inet_pton(AF_INET, ip, &(addr.sin_addr)) != 1) {
            perror("Error: ");
            return;
        }
        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
            printf("Error connecting to server: %s\n", strerror(errno));
            close(sock);
            sleep(INTERVAL);
            continue;
        }
        char *http_request = "HEAD / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
        char request[MAX_URL_LENGTH + strlen(http_request) - 3];
        sprintf(request, http_request, url);
        if (write(sock, request, strlen(request)) == -1) {
            printf("Error writing to socket: %s\n", strerror(errno));
            close(sock);
            sleep(INTERVAL);
            continue;
        }
        char buffer[1024];
        int bytes_received;
        if ((bytes_received = read(sock, buffer, sizeof(buffer))) == -1) {
            printf("Error reading from socket: %s\n", strerror(errno));
            close(sock);
            sleep(INTERVAL);
            continue;
        }
        close(sock);
        if (bytes_received == 0) {
            printf("Error: Empty response received\n");
            sleep(INTERVAL);
            continue;
        }
        char *response = strtok(buffer, "\r\n");
        if (strstr(response, " 200 OK") == NULL) {
            printf("Error: %s\n", response);
        } else {
            printf("Site is up and running\n");
        }
        sleep(INTERVAL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url(s)>\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        signal(SIGINT, sigint_handler);
        stop = 0;
        monitor(argv[i]);
    }
    return 0;
}