//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_URL_LEN 256
#define MAX_HOST_LEN 128
#define MAX_PORT_LEN 6
#define MAX_STATUS_LEN 64
#define MAX_RETRY_COUNT 3

struct website {
    char url[MAX_URL_LEN];
    time_t last_checked;
    int status;
    int retry_count;
};

struct website_list {
    struct website *websites;
    int count;
};

struct website_list *website_list_new() {
    struct website_list *list = malloc(sizeof(struct website_list));
    list->websites = NULL;
    list->count = 0;
    return list;
}

void website_list_free(struct website_list *list) {
    if (list) {
        if (list->websites) {
            free(list->websites);
        }
        free(list);
    }
}

int website_list_add(struct website_list *list, struct website *website) {
    if (!list || !website) {
        return -1;
    }
    list->websites = realloc(list->websites, (list->count + 1) * sizeof(struct website));
    if (!list->websites) {
        return -1;
    }
    list->websites[list->count] = *website;
    list->count++;
    return 0;
}

struct website *website_new(const char *url) {
    if (!url) {
        return NULL;
    }
    struct website *website = malloc(sizeof(struct website));
    if (!website) {
        return NULL;
    }
    strncpy(website->url, url, MAX_URL_LEN);
    website->last_checked = 0;
    website->status = 0;
    website->retry_count = 0;
    return website;
}

void website_free(struct website *website) {
    if (website) {
        free(website);
    }
}

int website_check(struct website *website) {
    if (!website) {
        return -1;
    }
    struct hostent *host = gethostbyname(website->url);
    if (!host) {
        return -1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sockfd);
        return -1;
    }
    close(sockfd);
    return 0;
}

int website_list_check(struct website_list *list) {
    if (!list) {
        return -1;
    }
    time_t now = time(NULL);
    for (int i = 0; i < list->count; i++) {
        if (now - list->websites[i].last_checked > 60) {
            list->websites[i].last_checked = now;
            int status = website_check(&list->websites[i]);
            if (status == 0) {
                list->websites[i].retry_count = 0;
                list->websites[i].status = 200;
            } else {
                list->websites[i].retry_count++;
                list->websites[i].status = 503;
            }
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url> [<url> ...]\n", argv[0]);
        return -1;
    }
    struct website_list *list = website_list_new();
    for (int i = 1; i < argc; i++) {
        struct website *website = website_new(argv[i]);
        if (!website) {
            fprintf(stderr, "Error: could not create website %s\n", argv[i]);
            return -1;
        }
        if (website_list_add(list, website) < 0) {
            fprintf(stderr, "Error: could not add website %s to list\n", argv[i]);
            website_free(website);
            website_list_free(list);
            return -1;
        }
    }
    while (1) {
        website_list_check(list);
        for (int i = 0; i < list->count; i++) {
            printf("%s: %s\n", list->websites[i].url, list->websites[i].status == 200 ? "OK" : "DOWN");
        }
        sleep(60);
    }
    return 0;
}