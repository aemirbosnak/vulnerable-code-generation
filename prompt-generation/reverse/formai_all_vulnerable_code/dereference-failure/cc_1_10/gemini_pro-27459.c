//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define DEFAULT_PORT 80
#define DEFAULT_INTERVAL 60
#define MAX_URL_LENGTH 256

typedef struct {
    char *url;
    int port;
    int interval;
    time_t last_check;
    int status;
} website;

website *websites;
int num_websites;

int init_website(website *w, char *url, int port, int interval) {
    w->url = (char *)malloc(strlen(url) + 1);
    strcpy(w->url, url);
    w->port = port;
    w->interval = interval;
    w->last_check = 0;
    w->status = -1;
    return 0;
}

int get_hostname(char *url, char *hostname) {
    int i, j;
    for (i = 0; i < strlen(url); i++) {
        if (url[i] == ':') {
            break;
        }
    }
    for (j = 0; i < strlen(url); i++) {
        if (url[i] == '/') {
            break;
        }
        hostname[j++] = url[i];
    }
    hostname[j] = '\0';
    return 0;
}

int check_website(website *w) {
    int sockfd, status;
    struct hostent *host;
    struct sockaddr_in serv_addr;

    host = gethostbyname(w->url);
    if (host == NULL) {
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(w->port);
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (status < 0) {
        return -1;
    }

    close(sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    int i, interval;
    time_t now;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s URL [PORT] [INTERVAL]\n", argv[0]);
        return 1;
    }

    interval = DEFAULT_INTERVAL;
    if (argc >= 3) {
        interval = atoi(argv[2]);
    }

    websites = (website *)malloc(sizeof(website) * argc);
    num_websites = argc - 1;

    for (i = 0; i < num_websites; i++) {
        init_website(&websites[i], argv[i + 1], DEFAULT_PORT, interval);
    }

    while (1) {
        now = time(NULL);

        for (i = 0; i < num_websites; i++) {
            if (now - websites[i].last_check >= websites[i].interval) {
                websites[i].status = check_website(&websites[i]);
                websites[i].last_check = now;
            }
        }

        sleep(1);
    }

    return 0;
}