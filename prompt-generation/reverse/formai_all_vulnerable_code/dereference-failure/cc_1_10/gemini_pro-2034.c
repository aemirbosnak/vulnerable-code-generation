//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
// Enchanting C Network QoS Monitor in the Spirit of Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>

// A Panoply of Constants, for Knuthian Elegance

#define KNUTH_MAGIC 0xDEADBEEF
#define POLL_INTERVAL 500000  // Microseconds
#define MAX_HISTORY 100

// A Tapestry of Data Structures, Woven with Care

typedef struct {
    long timestamp;
    double rtt;
    double loss;
} QoSMeasurement;

typedef struct {
    char hostname[256];
    int port;
    struct sockaddr_in addr;
    int sockfd;
    QoSMeasurement history[MAX_HISTORY];
    int head, tail;
    struct timeval last_poll;
} QoSMeter;

// A Symphony of Functions, Composed with Virtuosity

int create_socket(const char *hostname, int port) {
    struct sockaddr_in addr;
    struct hostent *host = gethostbyname(hostname);
    int sockfd;

    if (!host) {
        fprintf(stderr, "gethostbyname() failed\n");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket() failed\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "connect() failed\n");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

void send_ping(int sockfd) {
    uint32_t magic = KNUTH_MAGIC;
    ssize_t n;

    n = write(sockfd, &magic, sizeof(magic));
    if (n < 0) {
        fprintf(stderr, "write() failed\n");
    }
}

double measure_rtt(int sockfd) {
    uint32_t magic;
    struct timeval t1, t2;
    ssize_t n;

    gettimeofday(&t1, NULL);
    n = read(sockfd, &magic, sizeof(magic));
    gettimeofday(&t2, NULL);

    if (n < 0) {
        fprintf(stderr, "read() failed\n");
        return -1.0;
    }

    if (magic != KNUTH_MAGIC) {
        fprintf(stderr, "Invalid magic number\n");
        return -1.0;
    }

    return (t2.tv_sec - t1.tv_sec) * 1000000.0 + (t2.tv_usec - t1.tv_usec);
}

double measure_loss(int sockfd) {
    static int sent = 0, received = 0;
    uint32_t magic;
    ssize_t n;

    n = read(sockfd, &magic, sizeof(magic));
    if (n < 0) {
        fprintf(stderr, "read() failed\n");
        return -1.0;
    }

    if (magic != KNUTH_MAGIC) {
        fprintf(stderr, "Invalid magic number\n");
        return -1.0;
    }

    received++;
    return 1.0 - received / (double)sent;
}

void update_history(QoSMeter *meter) {
    struct timeval now;

    gettimeofday(&now, NULL);
    meter->history[meter->head].timestamp = (now.tv_sec - meter->last_poll.tv_sec) * 1000000 + (now.tv_usec - meter->last_poll.tv_usec);
    meter->head = (meter->head + 1) % MAX_HISTORY;
    if (meter->head == meter->tail) {
        meter->tail = (meter->tail + 1) % MAX_HISTORY;
    }
}

void print_history(QoSMeter *meter) {
    int i;

    for (i = meter->tail; i != meter->head; i = (i + 1) % MAX_HISTORY) {
        printf("%ld,%f,%f\n", meter->history[i].timestamp, meter->history[i].rtt, meter->history[i].loss);
    }
}

// A Grand Orchestration of the Program's Logic

int main(int argc, char **argv) {
    QoSMeter meter;
    struct timeval now;
    double rtt, loss;
    int sent = 0;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strcpy(meter.hostname, argv[1]);
    meter.port = atoi(argv[2]);
    meter.sockfd = create_socket(meter.hostname, meter.port);
    if (meter.sockfd < 0) {
        return EXIT_FAILURE;
    }

    gettimeofday(&now, NULL);
    meter.last_poll = now;

    while (1) {
        usleep(POLL_INTERVAL);
        gettimeofday(&now, NULL);

        if (now.tv_sec - meter.last_poll.tv_sec >= 1) {
            printf("=====================================================================\n");
            printf("QoS Report for %s:%d\n", meter.hostname, meter.port);
            printf("---------------------------------------------------------------------\n");
            printf("Timestamp (microseconds),RTT (microseconds),Loss Percentage\n");
            print_history(&meter);
            printf("=====================================================================\n");
            meter.last_poll = now;
        }

        send_ping(meter.sockfd);
        sent++;
        rtt = measure_rtt(meter.sockfd);
        if (rtt >= 0.0) {
            loss = measure_loss(meter.sockfd);
            if (loss >= 0.0) {
                update_history(&meter);
                meter.history[meter.head].rtt = rtt;
                meter.history[meter.head].loss = loss;
            }
        }
    }

    close(meter.sockfd);
    return EXIT_SUCCESS;
}