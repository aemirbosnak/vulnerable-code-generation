//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_THREADS 100
#define MAX_IPADDR_LEN 16
#define MAX_HOSTNAME_LEN 256
#define INTERVAL_TIME 30 // seconds

struct host_info
{
    char hostname[MAX_HOSTNAME_LEN];
    char ipaddr[MAX_IPADDR_LEN];
    bool is_up;
    pthread_t thread_id;
};

struct host_info hosts[MAX_THREADS];
int num_hosts = 0;

struct thread_args
{
    int host_idx;
};

void *ping_host(void *args)
{
    struct thread_args *t_args = (struct thread_args *)args;

    int host_idx = t_args->host_idx;

    struct host_info *host = &hosts[host_idx];

    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, host->ipaddr, &(sa.sin_addr));
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof sa) < 0)
    {
        host->is_up = false;
        printf("%s (%s) is down\n", host->hostname, host->ipaddr);
    }
    else
    {
        host->is_up = true;
        printf("%s (%s) is up\n", host->hostname, host->ipaddr);
    }

    close(sockfd);

    return NULL;
}

void *monitor_hosts(void *args)
{
    while (true)
    {
        for (int i = 0; i < num_hosts; ++i)
        {
            struct thread_args t_args = {i};
            pthread_create(&hosts[i].thread_id, NULL, ping_host, &t_args);
        }

        for (int i = 0; i < num_hosts; ++i)
        {
            pthread_join(hosts[i].thread_id, NULL);
        }

        sleep(INTERVAL_TIME);
    }

    return NULL;
}

void add_host(char *hostname)
{
    struct hostent *he;

    if ((he = gethostbyname(hostname)) == NULL)
    {
        herror("gethostbyname");
        return;
    }

    char ipaddr[MAX_IPADDR_LEN];
    inet_ntop(AF_INET, he->h_addr, ipaddr, sizeof ipaddr);

    struct host_info host = {0};
    strcpy(host.hostname, hostname);
    strcpy(host.ipaddr, ipaddr);
    host.is_up = false;
    hosts[num_hosts++] = host;

    printf("%s (%s) added to monitoring list\n", hostname, ipaddr);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <hostname1> [hostname2] ... [hostnameN]\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    for (int i = 1; i < argc; ++i)
    {
        add_host(argv[i]);
    }

    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor_hosts, NULL);

    pthread_join(monitor_thread, NULL);

    return EXIT_SUCCESS;
}