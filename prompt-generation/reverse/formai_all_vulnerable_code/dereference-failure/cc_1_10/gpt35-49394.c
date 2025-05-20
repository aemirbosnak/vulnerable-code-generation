//FormAI DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PORTS 65535
#define SCAN_DELAY 1 // Delay in seconds between scans
#define MAX_WAIT_TIME 1 // Max wait time for response in seconds

int open_socket(const char* addr, int port);
void scan_port(const char* addr, int port);
void *scan_range(void* arg);

struct scan_info
{
    char* addr;
    int start;
    int end;
};

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* addr = argv[1];

    printf("Scanning %s...\n", addr);

    pthread_t threads[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        struct scan_info* info = malloc(sizeof(struct scan_info));
        info->addr = addr;
        info->start = i * (MAX_PORTS / 10);
        info->end = info->start + (MAX_PORTS / 10) - 1;
        pthread_create(&threads[i], NULL, scan_range, info);
    }

    for (i = 0; i < 10; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete!\n");

    return 0;
}

int open_socket(const char* addr, int port)
{
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(addr);
    sa.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket() failed");
        return -1;
    }

    struct timeval tv;
    tv.tv_sec = MAX_WAIT_TIME;
    tv.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0)
    {
        perror("setsockopt() failed");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&sa, sizeof(sa)) < 0)
    {
        if (errno == EINPROGRESS)
        {
            printf("Port %d on %s is open (delayed response)\n", port, addr);
            sleep(SCAN_DELAY);
            return 1;
        }
        else
        {
            // perror("connect() failed");
            return 0;
        }
    }

    printf("Port %d on %s is open\n", port, addr);
    close(sock);
    return 1;
}

void scan_port(const char* addr, int port)
{
    if (open_socket(addr, port) < 0)
    {
        printf("Failed to open socket\n");
    }
}

void *scan_range(void* arg)
{
    struct scan_info* info = (struct scan_info*)arg;
    char* addr = info->addr;
    int start = info->start;
    int end = info->end;

    int i;
    for (i = start; i <= end; i++)
    {
        scan_port(addr, i);
    }

    free(arg);
    pthread_exit(NULL);
}