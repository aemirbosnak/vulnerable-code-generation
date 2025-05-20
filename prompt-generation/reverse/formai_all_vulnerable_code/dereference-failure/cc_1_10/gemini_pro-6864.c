//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define DEFAULT_PORT 80
#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_TEST_TIME 10
#define NUM_CONNECTIONS 5
#define MAX_CONNECTIONS 10

struct connection_info {
    int sockfd;
    struct sockaddr_in addr;
    int connected;
};

struct test_results {
    double download_speed;
    double upload_speed;
    double latency;
};

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in create_address(const char *host, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) != 1) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    return addr;
}

int connect_to_server(struct connection_info *info, const char *host, int port) {
    info->addr = create_address(host, port);
    info->sockfd = create_socket();
    if (connect(info->sockfd, (struct sockaddr *)&info->addr, sizeof(info->addr)) == -1) {
        perror("connect");
        return -1;
    }
    info->connected = 1;
    return 0;
}

void disconnect_from_server(struct connection_info *info) {
    if (info->connected) {
        close(info->sockfd);
        info->connected = 0;
    }
}

int send_data(struct connection_info *info, const char *data, int len) {
    int bytes_sent = send(info->sockfd, data, len, 0);
    if (bytes_sent == -1) {
        perror("send");
        return -1;
    }
    return bytes_sent;
}

int receive_data(struct connection_info *info, char *data, int len) {
    int bytes_received = recv(info->sockfd, data, len, 0);
    if (bytes_received == -1) {
        perror("recv");
        return -1;
    }
    return bytes_received;
}

double calculate_download_speed(struct connection_info *info, int test_time) {
    int i;
    char *data = malloc(DEFAULT_BUFFER_SIZE);
    double total_bytes_received = 0;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    for (i = 0; i < test_time; i++) {
        int bytes_received = receive_data(info, data, DEFAULT_BUFFER_SIZE);
        if (bytes_received == -1) {
            perror("recv");
            break;
        }
        total_bytes_received += bytes_received;
    }
    gettimeofday(&end, NULL);

    free(data);

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    return total_bytes_received / elapsed_time;
}

double calculate_upload_speed(struct connection_info *info, int test_time) {
    int i;
    char *data = malloc(DEFAULT_BUFFER_SIZE);
    double total_bytes_sent = 0;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    for (i = 0; i < test_time; i++) {
        int bytes_sent = send_data(info, data, DEFAULT_BUFFER_SIZE);
        if (bytes_sent == -1) {
            perror("send");
            break;
        }
        total_bytes_sent += bytes_sent;
    }
    gettimeofday(&end, NULL);

    free(data);

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    return total_bytes_sent / elapsed_time;
}

double calculate_latency(struct connection_info *info) {
    struct timeval start, end;
    char data[1] = {0};

    gettimeofday(&start, NULL);
    send_data(info, data, 1);
    receive_data(info, data, 1);
    gettimeofday(&end, NULL);

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    return elapsed_time * 1000.0;
}

struct test_results run_test(const char *host, int port, int test_time) {
    struct connection_info info[NUM_CONNECTIONS];
    struct test_results results;
    int i;

    for (i = 0; i < NUM_CONNECTIONS; i++) {
        connect_to_server(&info[i], host, port);
    }

    results.download_speed = calculate_download_speed(&info[0], test_time);
    results.upload_speed = calculate_upload_speed(&info[1], test_time);
    results.latency = calculate_latency(&info[2]);

    for (i = 0; i < NUM_CONNECTIONS; i++) {
        disconnect_from_server(&info[i]);
    }

    return results;
}

void print_results(const struct test_results *results) {
    printf("Download speed: %.2f Mbps\n", results->download_speed / 1000000.0);
    printf("Upload speed: %.2f Mbps\n", results->upload_speed / 1000000.0);
    printf("Latency: %.2f ms\n", results->latency);
}

int main(int argc, char *argv[]) {
    const char *host = "google.com";
    int port = DEFAULT_PORT;
    int test_time = DEFAULT_TEST_TIME;

    if (argc > 1) {
        host = argv[1];
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    if (argc > 3) {
        test_time = atoi(argv[3]);
    }

    struct test_results results = run_test(host, port, test_time);

    print_results(&results);

    return 0;
}