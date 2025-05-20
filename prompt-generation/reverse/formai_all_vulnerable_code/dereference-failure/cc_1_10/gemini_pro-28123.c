//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

struct website {
    char *url;
    int port;
    bool is_up;
    time_t last_checked;
};

struct website *create_website(char *url, int port) {
    struct website *website = malloc(sizeof(struct website));
    website->url = strdup(url);
    website->port = port;
    website->is_up = false;
    website->last_checked = time(NULL);
    return website;
}

void destroy_website(struct website *website) {
    free(website->url);
    free(website);
}

int get_socket(struct website *website) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    struct hostent *host = gethostbyname(website->url);
    if (host == NULL) {
        close(sockfd);
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(website->port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

bool is_website_up(struct website *website) {
    int sockfd = get_socket(website);
    if (sockfd == -1) {
        return false;
    }

    close(sockfd);
    website->is_up = true;
    website->last_checked = time(NULL);
    return true;
}

void print_website_status(struct website *website) {
    printf("%s: %s since %ld seconds\n", website->url, website->is_up ? "Up" : "Down", time(NULL) - website->last_checked);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url> <port>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    int port = atoi(argv[2]);

    struct website *website = create_website(url, port);

    while (true) {
        if (is_website_up(website)) {
            print_website_status(website);
        } else {
            printf("%s: Down since %ld seconds\n", website->url, time(NULL) - website->last_checked);
        }

        sleep(5);
    }

    destroy_website(website);

    return 0;
}