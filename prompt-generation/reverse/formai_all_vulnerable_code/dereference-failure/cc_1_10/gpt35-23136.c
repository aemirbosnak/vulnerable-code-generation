//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define NUM_OF_NODES 3
#define BLOCK_SIZE 1024

typedef struct {
    char id[20];
    char ip[20];
    int port;
} node_t;

typedef struct {
    node_t nodes[NUM_OF_NODES];
} network_t;

/* networking variables */
char *my_id;
char *my_ip;
int my_port;
node_t *neighbors;
size_t num_neighbors;
node_t *all_nodes;
size_t num_all_nodes;
int sock_fd;
struct timeval timeout;

/* QoS monitoring variables */
double avg_delay[NUM_OF_NODES];
double avg_loss[NUM_OF_NODES];

/* function prototypes */
void parse_args(int argc, char **argv);
void init_network();
void init_qos_monitor();
void send_data(char *data, size_t data_len, node_t *dest);
size_t recv_data(char *data_buff, node_t *src);
void monitor_qos(node_t *src);

/* main function */
int main(int argc, char **argv) {
    /* parse command line arguments */
    parse_args(argc, argv);

    /* initialize the network */
    init_network();

    /* initialize the QoS monitor */
    init_qos_monitor();

    while (1) {
        /* receive data from any source */
        char data_buff[BLOCK_SIZE] = {0};
        node_t src;
        size_t data_len = recv_data(data_buff, &src);

        /* update QoS monitor statistics */
        monitor_qos(&src);

        /* forward data to all neighbors, except the sender */
        for (size_t i = 0; i < num_neighbors; i++) {
            if (strcmp(neighbors[i].id, src.id) != 0) {
                send_data(data_buff, data_len, &neighbors[i]);
            }
        }
    }

    return 0;
}

/* parse command line arguments */
void parse_args(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <my_id> [<my_ip> <my_port>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* set my_id */
    my_id = argv[1];

    /* set my_ip and my_port if provided */
    if (argc >= 4) {
        my_ip = argv[2];
        my_port = atoi(argv[3]);
    }
}

/* initialize the network */
void init_network() {
    /* set random seed */
    srand(time(0));

    /* set all node IDs and IPs */
    all_nodes = calloc(NUM_OF_NODES, sizeof(node_t));
    for (int i = 0; i < NUM_OF_NODES; i++) {
        sprintf(all_nodes[i].id, "node_%d", i + 1);
        sprintf(all_nodes[i].ip, "127.0.0.%d", i + 1);
        all_nodes[i].port = 20000 + i + 1;
    }

    /* set my_ip and my_port randomly if not provided */
    if (!my_ip && my_port <= 0) {
        int r = rand() % NUM_OF_NODES;
        my_ip = all_nodes[r].ip;
        my_port = all_nodes[r].port;
    }

    /* set neighbors */
    neighbors = calloc(NUM_OF_NODES - 1, sizeof(node_t));
    for (size_t i = 0, j = 0; i < NUM_OF_NODES; i++) {
        if (strcmp(my_id, all_nodes[i].id) != 0) {
            neighbors[j++] = all_nodes[i];
        }
    }
    num_neighbors = NUM_OF_NODES - 1;

    /* print network configuration */
    printf("My ID: %s, My IP: %s, My Port: %d\n", my_id, my_ip, my_port);
    printf("Number of Neighbors: %lu\n", num_neighbors);
    for (size_t i = 0; i < num_neighbors; i++) {
        printf("Neighbor %lu: ID: %s, IP: %s, Port: %d\n",
            i+1, neighbors[i].id, neighbors[i].ip, neighbors[i].port);
    }

    /* create a UDP socket */
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* set the socket options */
    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(struct sockaddr_in));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(my_port);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bind(sock_fd, (const struct sockaddr *)&my_addr, sizeof(struct sockaddr_in));

    /* set the receive timeout option */
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));
}

/* initialize the QoS monitor */
void init_qos_monitor() {
    /* initialize the QoS variables to zero */
    for (size_t i = 0; i < NUM_OF_NODES; i++) {
        avg_delay[i] = 0.0;
        avg_loss[i] = 0.0;
    }
}

/* send data to the destination node */
void send_data(char *data, size_t data_len, node_t *dest) {
    /* create a socket */
    int dest_fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* set the socket options */
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(dest->port);
    inet_pton(AF_INET, dest->ip, &dest_addr.sin_addr);

    /* send the data */
    sendto(dest_fd, data, data_len, 0, (const struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in));

    /* close the socket */
    close(dest_fd);
}

/* receive data from the source node */
size_t recv_data(char *data_buff, node_t *src) {
    /* receive the data */
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(struct sockaddr_in);
    ssize_t num_bytes = recvfrom(sock_fd, data_buff, BLOCK_SIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);

    /* extract the source node information */
    inet_ntop(AF_INET, &src_addr.sin_addr, src->ip, 20);
    src->port = ntohs(src_addr.sin_port);
    for (size_t i = 0; i < NUM_OF_NODES; i++) {
        if (strcmp(src->ip, all_nodes[i].ip) == 0 && src->port == all_nodes[i].port) {
            strcpy(src->id, all_nodes[i].id);
            break;
        }
    }

    return (size_t)(num_bytes);
}

/* monitor QoS for the received data */
void monitor_qos(node_t *src) {
    /* set the loss and delay rates randomly */
    double loss_rate = (double)(rand() % 11) / 100.0;
    double delay_rate = (double)(rand() % 11) / 100.0;

    /* update the QoS variables */
    for (size_t i = 0; i < NUM_OF_NODES; i++) {
        if (strcmp(src->id, all_nodes[i].id) == 0) {
            avg_loss[i] = (avg_loss[i] + loss_rate) / 2.0;
            avg_delay[i] = (avg_delay[i] + delay_rate) / 2.0;
            break;
        }
    }
}