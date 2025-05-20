//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535
#define TIMEOUT 1000

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int close(int fd);

void *scan_ports(void *args)
{
    int sockfd, port;
    struct sockaddr_in server_addr;
    char ip[16];
    int addrlen = sizeof(server_addr);

    strcpy(ip, (char *)args);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error creating socket\n");
        return NULL;
    }

    for (port = PORT_RANGE_MIN; port <= PORT_RANGE_MAX; port++)
    {
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server_addr.sin_addr);

        if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == 0)
        {
            printf("Open port: %d\n", port);
            close(sockfd);
            return NULL;
        }
        else if (errno!= ETIMEDOUT)
        {
            printf("Error connecting to %s:%d\n", ip, port);
            close(sockfd);
            return NULL;
        }
    }

    printf("No open ports found\n");
    close(sockfd);
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int i, num_threads = 0;

    for (i = 0; i < MAX_THREADS && num_threads < 100; i++)
    {
        pthread_create(&threads[num_threads], NULL, scan_ports, argv[1]);
        num_threads++;
    }

    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}