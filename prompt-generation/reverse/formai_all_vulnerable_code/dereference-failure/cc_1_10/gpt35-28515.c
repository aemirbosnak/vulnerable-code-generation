//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>
#include <netdb.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/* Macros for printing output */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/* Structure for holding packet data */
struct packet {
    struct timeval timestamp;
    int len;
    u_char data[1500];
};

/* Global variables */
int sockfd = -1;
int packets_received = 0;
int total_bytes_received = 0;
int connections_counter = 0;
struct sockaddr_in saddr;
int packet_size = 0;
int timeout = 0;

/* Function prototypes */
void usage();
void sigint_handler(int sig);
int create_socket(char *ip_address, int port);
void print_header();
void print_packet(struct packet *pkt);
void process_packets();
void print_statistics();

/* Main function */
int main(int argc, char *argv[]) {
    int port = 0;
    char *ip_address = NULL;

    /* Check for correct number of arguments */
    if (argc < 4) {
        usage();
        return 1;
    }

    /* Parse arguments */
    ip_address = argv[1];
    port = atoi(argv[2]);
    packet_size = atoi(argv[3]);

    /* Set timeout to 5 seconds */
    timeout = 5;

    /* Register signal handler for SIGINT */
    signal(SIGINT, sigint_handler);

    /* Create socket */
    sockfd = create_socket(ip_address, port);
    if (sockfd == -1) {
        fprintf(stderr, RED "Socket creation error: %s\n" RESET, strerror(errno));
        return 1;
    }

    /* Print header */
    print_header();

    /* Process packets */
    process_packets();

    /* Print statistics */
    print_statistics();

    /* Close socket */
    close(sockfd);

    return 0;
}

/* Usage function */
void usage() {
    printf("Usage: qos_monitor <IP address> <port> <packet size>\n");
    printf("Example: qos_monitor 127.0.0.1 8080 1000\n");
}

/* Signal handler function */
void sigint_handler(int sig) {
    printf("\nReceived SIGINT. Exiting.\n");
    print_statistics();
    close(sockfd);
    exit(0);
}

/* Create socket function */
int create_socket(char *ip_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    inet_aton(ip_address, &saddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
        return -1;
    }

    return sockfd;
}

/* Print header function */
void print_header() {
    printf("----------------------------------------------------------\n");
    printf("| %9s | %9s | %8s | %10s |\n", "Timestamp", "Packet #", "Size", "Connections");
    printf("----------------------------------------------------------\n");
}

/* Print packet function */
void print_packet(struct packet *pkt) {
    printf("| %ld.%ld | %9d | %8d | %10d |\n", pkt->timestamp.tv_sec, pkt->timestamp.tv_usec, packets_received, pkt->len, connections_counter);
}

/* Process packets function */
void process_packets() {
    fd_set rfds;
    struct timeval tv;
    int retval;
    int num_bytes;
    struct packet *pkt = NULL;
    int max_fd = sockfd + 1;
    if (max_fd < 2) {
        max_fd = 2;
    }
    int data_fd = open("/dev/random", O_RDONLY);

    while (1) {
        /* Set up fd_set for select() */
        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);

        /* Set timeout */
        tv.tv_sec = timeout;
        tv.tv_usec = 0;

        /* Wait for packet */
        retval = select(max_fd, &rfds, NULL, NULL, &tv);
        if (retval == -1) {
            fprintf(stderr, RED "select() error: %s\n" RESET, strerror(errno));
            continue;
        } else if (retval == 0) {
            printf(YEL "Timeout - no packets received in last %d seconds\n" RESET, timeout);
            continue;
        }

        /* Allocate memory for packet */
        pkt = malloc(sizeof(struct packet) + packet_size);
        if (pkt == NULL) {
            fprintf(stderr, RED "Memory allocation error: %s\n" RESET, strerror(errno));
            continue;
        }

        /* Determine packet size */
        num_bytes = read(data_fd, pkt->data, packet_size);
        if (num_bytes < 0) {
            fprintf(stderr, RED "Error reading data: %s\n" RESET, strerror(errno));
            continue;
        }
        pkt->len = num_bytes;

        /* Record timestamp */
        gettimeofday(&pkt->timestamp, NULL);

        /* Send packet */
        if (send(sockfd, pkt->data, pkt->len, 0) == -1) {
            fprintf(stderr, RED "Error sending data: %s\n" RESET, strerror(errno));
            free(pkt);
            continue;
        }

        /* Receive response */
        num_bytes = recv(sockfd, pkt->data, packet_size, 0);
        if (num_bytes == -1) {
            fprintf(stderr, RED "Error receiving data: %s\n" RESET, strerror(errno));
            free(pkt);
            continue;
        } else if (num_bytes == 0) {
            printf(YEL "Connection closed by server\n" RESET);
            free(pkt);
            exit(1);
        }

        /* Record packet data */
        pkt->len = num_bytes;
        packets_received++;
        total_bytes_received += num_bytes;

        /* Print packet information */
        print_packet(pkt);

        free(pkt);
    }
}

/* Print statistics function */
void print_statistics() {
    printf("\n");
    printf("----------------------------------------------------------\n");
    printf("| Statistics              | Value                         |\n");
    printf("----------------------------------------------------------\n");
    printf("| Total packets received  | %30d |\n", packets_received);
    printf("| Total bytes received    | %30d |\n", total_bytes_received);
    printf("| Average packet size     | %30.2f | \n", (float)total_bytes_received/packets_received);
    printf("----------------------------------------------------------\n");
}