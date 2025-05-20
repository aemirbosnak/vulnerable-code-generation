//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>
#include <netdb.h>

#define IFNAMSIZ 100        // Interface name max length
#define RETRIES 3           // Maximum number of retries
#define ADDRESS "8.8.8.8"  // Google's DNS server address
#define PORT 53             // DNS server port number
#define TIMEOUT 1           // Timeout in seconds

volatile sig_atomic_t terminate = 0; // Termination flag

void *measure_signal_strength(void *arg);

/* Signal handler for termination signals */
void signal_handler(int signum) {
    (void)signum;
    terminate = 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    /* Install signal handlers */
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    /* Create thread for measuring the signal strength */
    pthread_t t;
    int ret = pthread_create(&t, NULL, measure_signal_strength, argv[1]);
    if (ret != 0) {
        fprintf(stderr, "Unable to create thread: %s\n", strerror(ret));
        return 1;
    }

    /* Main thread waits for termination signal */
    while (!terminate) {
        sleep(1);
    }

    /* Terminate the measurement thread */
    ret = pthread_cancel(t); // Ask the thread to terminate
    if (ret != 0) {
        fprintf(stderr, "Unable to cancel thread: %s\n", strerror(ret));
    }
    pthread_join(t, NULL); // Wait for the thread to terminate

    return 0;
}

/* Measures the signal strength of the given interface */
void *measure_signal_strength(void *arg) {
    /* Get the interface name */
    char ifname[IFNAMSIZ];
    strncpy(ifname, (char *)arg, IFNAMSIZ-1);
    ifname[IFNAMSIZ-1] = '\0';

    /* Create a socket for connecting to Google's DNS server */
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        fprintf(stderr, "Unable to create socket: %s\n", strerror(errno));
        return NULL;
    }

    /* Set the socket to non-blocking mode */
    int flags = fcntl(sock, F_GETFL, 0);
    if (flags < 0) {
        fprintf(stderr, "Unable to get socket flags: %s\n", strerror(errno));
        close(sock);
        return NULL;
    }
    if (fcntl(sock, F_SETFL, flags | O_NONBLOCK) < 0) {
        fprintf(stderr, "Unable to set socket to non-blocking mode: %s\n", strerror(errno));
        close(sock);
        return NULL;
    }

    /* Create the socket address structure for the DNS server */
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, ADDRESS, &addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid address: %s\n", ADDRESS);
        close(sock);
        return NULL;
    }
    addr.sin_port = htons(PORT);

    /* Create the DNS lookup request */
    char hostname[100];
    sprintf(hostname, "%d.%d.%d.%d.in-addr.arpa", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
    char packet[512];
    memset(packet, 0, sizeof(packet));
    packet[0] = rand() % 256; // Transaction ID
    packet[2] = 0b00000001; // Recursive query
    packet[5] = 1; // One question
    char *p = packet + 12;
    for (int i = 0; i < strlen(hostname); ++i) {
        if (hostname[i] == '.') {
            *p++ = i - 1; // Length byte
            p += sprintf(p, "%s", hostname + i - (p - packet));
        }
    }
    *p++ = strlen(hostname) - (p - packet) - 1; // Length byte
    p += sprintf(p, "%s", hostname + strlen(hostname) - (p - packet));

    /* Send the DNS lookup request */
    int retries = RETRIES;
    while (retries > 0 && !terminate) {
        if (sendto(sock, packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            fprintf(stderr, "Unable to send DNS query: %s\n", strerror(errno));
            retries--;
            continue;
        }
        struct timespec start, now;
        clock_gettime(CLOCK_MONOTONIC, &start);
        /* Wait for the response */
        while (1) {
            /* Check if timeout has been reached */
            clock_gettime(CLOCK_MONOTONIC, &now);
            if (now.tv_sec - start.tv_sec >= TIMEOUT) {
                break;
            }
            /* Check if data is available to be read */
            fd_set rfds;
            FD_ZERO(&rfds);
            FD_SET(sock, &rfds);
            if (select(sock + 1, &rfds, NULL, NULL, &(struct timeval){ .tv_sec = 0, .tv_usec = 100000}) == -1) {
                fprintf(stderr, "Unable to select: %s\n", strerror(errno));
                retries--;
                break;
            }
            if (FD_ISSET(sock, &rfds)) {
                /* Data is available, read it */
                char response[512];
                int nread = recv(sock, response, sizeof(response), 0);
                if (nread == -1) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        /* No data available yet, try again */
                        continue;
                    }
                    fprintf(stderr, "Unable to receive DNS response: %s\n", strerror(errno));
                    retries--;
                    break;
                }
                /* Check the response */
                if (response[0] != packet[0] || !(response[3] & 0b00001000)) {
                    fprintf(stderr, "Invalid DNS response received\n");
                    retries--;
                    break;
                }
                /* Extract the IP address */
                char *p = response + 12 /* fixed header length */ + strlen(hostname) + 6 /* question length */;
                int family = p[0];
                if (family != 1 /* IPv4 */) {
                    fprintf(stderr, "Unsupported address family %d\n", family);
                    retries--;
                    break;
                }
                if (p[1] != 4 /* IPv4 length */) {
                    fprintf(stderr, "Invalid IPv4 length %d\n", p[1]);
                    retries--;
                    break;
                }
                int strength = (int)*(p + 2); // Signal strength (TTL value)
                printf("Signal strength of interface %s: %d\n", ifname, strength);
                /* Short delay before next measurement */
                usleep(500000);
                break;
            }
        }
    }

    close(sock);
    return NULL;
}