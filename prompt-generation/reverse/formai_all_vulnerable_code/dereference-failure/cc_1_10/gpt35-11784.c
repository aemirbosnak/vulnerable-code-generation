//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define MAX_DOMAIN_LENGTH 256
#define MAX_ADDR_LENGTH 16
#define MAX_PORT_LENGTH 10
#define BUFFER_SIZE 256
#define STAT_FILE_PATH "/var/log/website_monitor.log"

typedef struct {
    char domain[MAX_DOMAIN_LENGTH];
    char addr[MAX_ADDR_LENGTH];
    char port[MAX_PORT_LENGTH];
} Website;

Website websites[] = {
    {"www.google.com", "172.217.1.132", "80"},
    {"www.facebook.com", "31.13.71.36", "80"},
    {"www.twitter.com", "104.244.42.1", "80"},
};

int websites_count = sizeof(websites) / sizeof(Website);

void handle_response(int sock_fd, char* buffer, int buffer_len) {
    int bytes_recv;
    memset(buffer, 0, buffer_len);
    while ((bytes_recv = recv(sock_fd, buffer, buffer_len - 1, 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, buffer_len);
    }
}

void monitor_website(int website_idx) {
    int sock_fd, conn_err, addr_len, bytes_sent;
    char buffer[BUFFER_SIZE], request[BUFFER_SIZE];
    const char* http_request_format = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    struct sockaddr_in server_addr;
    struct hostent* host_info;
    Website website = websites[website_idx];
    signal(SIGPIPE, SIG_IGN);
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        fprintf(stderr, "[MONITOR] Failed to create socket for %s [%s]\n", website.domain, strerror(errno));
        return;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(website.port));
    host_info = gethostbyname(website.domain);
    if (host_info == NULL) {
        fprintf(stderr, "[MONITOR] Failed to resolve host %s [%s]\n", website.domain, hstrerror(h_errno));
        return;
    }
    memcpy(&server_addr.sin_addr, host_info->h_addr_list[0], host_info->h_length);
    addr_len = sizeof(server_addr);
    conn_err = connect(sock_fd, (struct sockaddr*)&server_addr, addr_len);
    if (conn_err == -1) {
        fprintf(stderr, "[MONITOR] Failed to establish connection to %s [%s]\n", website.domain, strerror(errno));
        return;
    }
    snprintf(request, BUFFER_SIZE, http_request_format, website.domain);
    bytes_sent = send(sock_fd, request, strlen(request), 0);
    if (bytes_sent == -1) {
        fprintf(stderr, "[MONITOR] Failed to send HTTP request to %s [%s]\n", website.domain, strerror(errno));
        return;
    }
    printf("[MONITOR] Monitoring %s [%s:%s]\n", website.domain, website.addr, website.port);
    handle_response(sock_fd, buffer, BUFFER_SIZE);
    close(sock_fd);
}

void monitor_all_websites() {
    int i;
    for (i = 0; i < websites_count; i++) {
        monitor_website(i);
    }
}

int main(int argc, char** argv) {
    int interval = 60; // default interval in seconds
    time_t start_time, now;
    bool first_run = true;
    int log_fd, log_err;
    struct tm* timestamp;
    char timestamp_str[BUFFER_SIZE], log_msg[BUFFER_SIZE];
    if (argc > 1) {
        interval = atoi(argv[1]);
    }
    start_time = time(NULL);
    printf("[MONITOR] Starting website monitoring every %d seconds\n", interval);
    while (1) {
        now = time(NULL);
        if (first_run || now - start_time >= interval) {
            first_run = false;
            monitor_all_websites();
            start_time = now;
        }
        // write current timestamp
        timestamp = localtime(&now);
        strftime(timestamp_str, BUFFER_SIZE, "%Y/%m/%d %H:%M:%S", timestamp);
        log_fd = open(STAT_FILE_PATH, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
        if (log_fd == -1) {
            fprintf(stderr, "[MONITOR] Failed to open log file: %s [%s]\n", STAT_FILE_PATH, strerror(errno));
        } else {
            snprintf(log_msg, BUFFER_SIZE, "%s - website monitoring status\n", timestamp_str);
            log_err = write(log_fd, log_msg, strlen(log_msg));
            if (log_err == -1) {
                fprintf(stderr, "[MONITOR] Failed to write to log file: %s [%s]\n", STAT_FILE_PATH, strerror(errno));
            }
            close(log_fd);
        }
        sleep(1);
    }
    return 0;
}