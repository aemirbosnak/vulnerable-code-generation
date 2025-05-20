//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_THREADS 10
#define MAX_PORTS 65535

struct scan_args {
    char *ip;
    int start_port;
    int end_port;
};

void *port_scan(void* arg) {

    struct scan_args *args = (struct scan_args *)arg;
    int fd, port;

    struct sockaddr_in sock;
    struct hostent *he;

    /* Get host details from hostname / IP address */
    he = gethostbyname(args->ip);
    if (he == NULL) {
        printf("Error: Cannot resolve %s\n", args->ip);
        return NULL;
    }

    /* Attempt connection to each specified port */
    for (port = args->start_port; port < args->end_port; port++) {
        fd = socket(AF_INET, SOCK_STREAM, 0); // TCP socket
        if (fd == -1) {
            perror("Error creating socket");
            return NULL;
        }

        sock.sin_family = AF_INET;
        sock.sin_port = htons(port);
        sock.sin_addr = *((struct in_addr *)he->h_addr);
        memset(&(sock.sin_zero), 0, 8);

        if (connect(fd, (struct sockaddr *)&sock, sizeof(struct sockaddr)) != -1) {
            printf("%s:%d is open\n", args->ip, port);
        }
        close(fd);
    }
    free(args);
    return NULL;
}

int main(int argc, char **argv) {
    
    if (argc != 2) {
        printf("Usage: ./scanner <ip>\n");
        return 0;
    }
    
    int num_threads = MAX_THREADS;
    pthread_t threads[num_threads];
    int count = 0;
    int i;
    
    for (i = 0; i < MAX_PORTS; i += MAX_PORTS/num_threads) {
        struct scan_args *args = malloc(sizeof(struct scan_args));
        args->ip = argv[1];
        args->start_port = i;
        args->end_port = i + MAX_PORTS/num_threads;
        
        if (pthread_create(&threads[count], NULL, port_scan, args)) {
            perror("Error creating thread");
            return 0;
        }
        
        count++;
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("Error joining thread");
            return 0;
        }
    }

    return 0;
}