//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>

// QoS Constants
#define MIN_THRESHOLD 10
#define MAX_THRESHOLD 100

// Global Variables
int sockfd; // socket file descriptor
struct sockaddr_in servaddr; // server address struct
int qos_threshold = MIN_THRESHOLD; // minimum threshold for QoS

// Function Prototypes
void send_request(void);
void receive_response(void);
void monitor_qos(void);
void close_socket(void);

// Function Definitions
void send_request(void) {
    int i;
    for (i = 0; i < 10; i++) {
        char message[] = "Hello World!";
        send(sockfd, message, strlen(message), 0);
        printf("Message Sent: %s\n", message);
        usleep(1000);
    }
}

void receive_response(void) {
    char response[1024];
    for (;;) {
        int n = recv(sockfd, response, sizeof(response), 0);
        if (n < 0) {
            perror("Error receiving data");
            exit(1);
        }
        printf("Response: %s\n", response);
    }
}

void monitor_qos(void) {
    int i;
    for (i = 0; i < 10; i++) {
        int packet_size = 1024;
        char packet[packet_size];
        struct timeval start, end;
        gettimeofday(&start, NULL);
        write(sockfd, "Hello World!", strlen("Hello World!"));
        gettimeofday(&end, NULL);
        double latency = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
        double bandwidth = (packet_size * 8) / latency;
        if (bandwidth > qos_threshold) {
            printf("QoS Alert! Bandwidth exceeds threshold (%d bytes/sec)\n", bandwidth);
        }
        else {
            printf("QoS: Bandwidth = %f bytes/sec\n", bandwidth);
        }
        sleep(1);
    }
}

void close_socket(void) {
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    qos_threshold = atoi(argv[1]);
    if (qos_threshold < MIN_THRESHOLD || qos_threshold > MAX_THRESHOLD) {
        fprintf(stderr, "Invalid QoS threshold: %d\n", qos_threshold);
        exit(1);
    }

    struct hostent *server;
    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: Cannot resolve server address\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(8888);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    send_request();
    receive_response();
    monitor_qos();
    close_socket();

    return 0;
}