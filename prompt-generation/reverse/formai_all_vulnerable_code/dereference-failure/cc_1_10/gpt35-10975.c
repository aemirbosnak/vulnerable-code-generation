//FormAI DATASET v1.0 Category: Port Scanner ; Style: decentralized
/*
Decentralized Port Scanner
by Chatbot
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 256
#define TIMEOUT 3

void *scan_port(void *p);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <ip> <start port> <end port>\n", argv[0]);
        return 1;
    }

    const char *ip_string = argv[1];
    struct in_addr addr;
    if (inet_aton(ip_string, &addr) == 0)
    {
        printf("Invalid IP address.\n");
        return 1;
    }

    const int startport = atoi(argv[2]);
    const int endport = atoi(argv[3]);

    if (startport <= 0 || startport > 65535 || endport <= 0 || endport > 65535 || startport > endport)
    {
        printf("Invalid port range.\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int nthreads = 0;

    printf("Starting scan of %s from port %d to %d\n", inet_ntoa(addr), startport, endport);

    for (int port = startport; port <= endport; port++)
    {
        pthread_t t;
        int *p = malloc(sizeof(int));
        *p = port;
        if (pthread_create(&t, NULL, scan_port, p) == 0)
        {
            threads[nthreads++] = t;
            if (nthreads == MAX_THREADS)
            {
                for (int i = 0; i < MAX_THREADS; i++)
                {
                    pthread_join(threads[i], NULL);
                }
                nthreads = 0;
            }
        }
    }

    for (int i = 0; i < nthreads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete.\n");

    return 0;
}

void *scan_port(void *p)
{
    const int port = *((int *)p);
    free(p);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket() failed");
        return NULL;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(port);
    inet_aton("localhost", &remote_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0)
    {
        // Connection failed
        close(sock);
        return NULL;
    }

    // Connection succeeded
    printf("%d open\n", port);
    close(sock);
    return NULL;
}