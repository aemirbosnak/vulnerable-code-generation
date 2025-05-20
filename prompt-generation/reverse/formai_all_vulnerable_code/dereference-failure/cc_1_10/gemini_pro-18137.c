//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

struct client_stat {
    int num_requests;
    int num_responses;
    float avg_response_time;
    float max_response_time;
    float min_response_time;
};

struct server_stat {
    int num_connections;
    int num_requests;
    int num_responses;
    float avg_response_time;
    float max_response_time;
    float min_response_time;
};

void client_stat_init(struct client_stat *stat) {
    stat->num_requests = 0;
    stat->num_responses = 0;
    stat->avg_response_time = 0.0;
    stat->max_response_time = 0.0;
    stat->min_response_time = 0.0;
}

void client_stat_update(struct client_stat *stat, float response_time) {
    stat->num_responses++;
    stat->avg_response_time = ((stat->avg_response_time * (stat->num_responses - 1)) + response_time) / stat->num_responses;
    if (response_time > stat->max_response_time) {
        stat->max_response_time = response_time;
    }
    if (response_time < stat->min_response_time) {
        stat->min_response_time = response_time;
    }
}

void server_stat_init(struct server_stat *stat) {
    stat->num_connections = 0;
    stat->num_requests = 0;
    stat->num_responses = 0;
    stat->avg_response_time = 0.0;
    stat->max_response_time = 0.0;
    stat->min_response_time = 0.0;
}

void server_stat_update(struct server_stat *stat, float response_time) {
    stat->num_responses++;
    stat->avg_response_time = ((stat->avg_response_time * (stat->num_responses - 1)) + response_time) / stat->num_responses;
    if (response_time > stat->max_response_time) {
        stat->max_response_time = response_time;
    }
    if (response_time < stat->min_response_time) {
        stat->min_response_time = response_time;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    struct client_stat client_stat;
    client_stat_init(&client_stat);

    struct server_stat server_stat;
    server_stat_init(&server_stat);

    char buf[BUF_SIZE];
    while (1) {
        // Send request
        memset(buf, 0, sizeof(buf));
        int len = sprintf(buf, "request %d", client_stat.num_requests);
        if (send(sockfd, buf, len, 0) < 0) {
            perror("send");
            break;
        }
        client_stat.num_requests++;

        // Receive response
        memset(buf, 0, sizeof(buf));
        int n = recv(sockfd, buf, sizeof(buf), 0);
        if (n < 0) {
            perror("recv");
            break;
        } else if (n == 0) {
            printf("Server closed connection\n");
            break;
        }
        server_stat.num_requests++;
        float response_time = atof(buf);
        client_stat_update(&client_stat, response_time);
        server_stat_update(&server_stat, response_time);

        // Print statistics
        printf("Client statistics:\n");
        printf("  Number of requests: %d\n", client_stat.num_requests);
        printf("  Number of responses: %d\n", client_stat.num_responses);
        printf("  Average response time: %.2f ms\n", client_stat.avg_response_time);
        printf("  Maximum response time: %.2f ms\n", client_stat.max_response_time);
        printf("  Minimum response time: %.2f ms\n", client_stat.min_response_time);
        printf("\n");

        printf("Server statistics:\n");
        printf("  Number of connections: %d\n", server_stat.num_connections);
        printf("  Number of requests: %d\n", server_stat.num_requests);
        printf("  Number of responses: %d\n", server_stat.num_responses);
        printf("  Average response time: %.2f ms\n", server_stat.avg_response_time);
        printf("  Maximum response time: %.2f ms\n", server_stat.max_response_time);
        printf("  Minimum response time: %.2f ms\n", server_stat.min_response_time);
        printf("\n");
    }

    close(sockfd);

    return 0;
}