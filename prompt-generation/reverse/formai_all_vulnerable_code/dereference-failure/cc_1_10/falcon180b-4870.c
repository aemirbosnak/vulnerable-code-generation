//Falcon-180B DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <syslog.h>
#include <time.h>
#include <pthread.h>

#define LOG_FACILITY LOG_LOCAL0
#define LOG_LEVEL LOG_INFO
#define LOG_IDENT "firewall"

int log_init(void);
void log_msg(int level, const char *fmt,...);

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd;
    int status;
    struct sockaddr_in listen_addr, conn_addr;

    if (argc!= 2) {
        log_msg(LOG_ERR, "Usage: %s <port>", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        log_msg(LOG_ERR, "socket() failed: %s", strerror(errno));
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        log_msg(LOG_ERR, "bind() failed: %s", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        log_msg(LOG_ERR, "listen() failed: %s", strerror(errno));
        exit(1);
    }

    log_msg(LOG_INFO, "Firewall listening on port %s", argv[1]);

    while (1) {
        socklen_t addr_len;
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addr_len);
        if (conn_fd == -1) {
            log_msg(LOG_ERR, "accept() failed: %s", strerror(errno));
            continue;
        }

        log_msg(LOG_INFO, "Connection from %s:%d", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        close(conn_fd);
    }

    return 0;
}

int log_init(void)
{
    openlog(LOG_IDENT, LOG_PID, LOG_LOCAL0);
    return 0;
}

void log_msg(int level, const char *fmt,...)
{
    va_list ap;
    char buf[1024];
    time_t now;
    struct tm tm;

    now = time(NULL);
    localtime_r(&now, &tm);

    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    syslog(level, "%04d/%02d/%02d %02d:%02d:%02d %s",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec, buf);
}