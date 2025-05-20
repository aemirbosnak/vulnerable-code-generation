//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_TRY 3
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <website_url>\n", argv[0]);
        exit(1);
    }

    char *website = argv[1];
    int attempts = 0;
    int uptime = 0;

    printf("Contemplating the existence of %s...\n", website);

    while (attempts < MAX_TRY) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket creation error");
            attempts++;
            sleep(TIMEOUT);
            continue;
        }

        struct hostent *server = gethostbyname(website);
        if (!server) {
            fprintf(stderr, "Could not find server: %s\n", gai_strerror(h_errno));
            close(sockfd);
            attempts++;
            sleep(TIMEOUT);
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        addr.sin_addr = *((struct in_addr *)server->h_addr);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("connection error");
            close(sockfd);
            attempts++;
            sleep(TIMEOUT);
            continue;
        }

        char request[1024];
        snprintf(request, sizeof(request), "HEAD / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Uptime-Monitor\r\nConnection: close\r\n\r\n", website);
        send(sockfd, request, strlen(request), 0);

        char response[1024];
        int bytes_received = recv(sockfd, response, sizeof(response), 0);
        if (bytes_received > 0) {
            if (strstr(response, "HTTP/1.1 200 OK") || strstr(response, "HTTP/1.0 200 OK")) {
                uptime = get_uptime(website);
                printf("Ah, %s is alive. Uptime: %d days, %d hours, %d minutes, %d seconds.\n", website, uptime / (24 * 60 * 60), (uptime % (24 * 60 * 60)) / 60, (uptime % 60), (uptime % 60) % 60);
                close(sockfd);
                break;
            } else {
                close(sockfd);
                attempts++;
                sleep(TIMEOUT);
                continue;
            }
        } else {
            close(sockfd);
            attempts++;
            sleep(TIMEOUT);
            continue;
        }
    }

    if (attempts >= MAX_TRY) {
        printf("%s seems to be down...\n", website);
    }

    return 0;
}

int get_uptime(char *website) {
    FILE *file = fopen("/proc/uptime", "r");
    if (!file) {
        return 0;
    }

    char line[1024];
    int lines = fgets(line, sizeof(line), file);
    fclose(file);

    char *token = strtok(line, " ");
    long uptime_raw = strtoul(token, NULL, 10);

    FILE *file2 = popen("uptime", "r");
    char line2[128];
    int lines2 = fgets(line2, sizeof(line2), file2);
    pclose(file2);

    char *token2 = strtok(line2, ":");
    long uptime_current = strtoul(token2, NULL, 10);

    return (uptime_current - uptime_raw) / (60 * 60);
}