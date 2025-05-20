//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define PACKET_SIZE 1024
#define TIMEOUT 500

/* Struct to hold information about packets */
struct packet
{
    int packet_number;
    int packet_size;
    char data[PACKET_SIZE];
};

/* Struct to hold information about a connection */
struct connection
{
    int socket_fd;
    struct sockaddr_in server_addr;
    pthread_t thread_id;
    int packet_count;
    int packet_size;
    int total_bytes_received;
    double packet_loss_rate;
};

/* Function to send packets */
void* send_packets(void* conn_ptr)
{
    struct connection* conn = (struct connection*) conn_ptr;
    struct packet p;
    int packet_number = 0;
    while (1)
    {
        /* Create packet */
        memset(&p, 0, sizeof(struct packet)); // Zero out packet
        p.packet_number = packet_number;
        int bytes_to_send = PACKET_SIZE;
        if ((conn->packet_size - conn->total_bytes_received) < PACKET_SIZE)
        {
            bytes_to_send = conn->packet_size - conn->total_bytes_received;
        }
        memcpy(p.data, (conn->packet_count % 2 == 0) ? "0" : "1", 1); // Alternate 0s and 1s for data
        memset(&p.data[1], 'X', bytes_to_send - 1);
        p.packet_size = bytes_to_send;
        
        /* Send packet */
        int bytes_sent = 0;
        while (bytes_sent < bytes_to_send)
        {
            int n = sendto(conn->socket_fd, (void*) &p, sizeof(struct packet), 0, (struct sockaddr*) &conn->server_addr, sizeof(struct sockaddr_in));
            if (n < 0)
            {
                printf("Error sending data: %s\n", strerror(errno));
            }
            bytes_sent += n;
        }
        conn->packet_count++;
        conn->total_bytes_received += bytes_to_send;
        if (conn->total_bytes_received == conn->packet_size)
        {
            break;
        }
        usleep(5000); // Wait between packets to simulate network delay
    }
    pthread_exit(NULL);
}

/* Function to receive packets */
void* receive_packets(void* conn_ptr)
{
    struct connection* conn = (struct connection*) conn_ptr;
    struct packet p;
    int packet_number = 0;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;
    setsockopt(conn->socket_fd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(struct timeval));
    while (1)
    {
        /* Receive packet */
        int len = sizeof(struct sockaddr_in);
        int n = recvfrom(conn->socket_fd, (void*) &p, sizeof(struct packet), 0, (struct sockaddr*) &conn->server_addr, &len);
        if (n < 0)
        {
            /* Check if timeout occurred */
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                break;
            }
            printf("Error receiving data: %s\n", strerror(errno));
        }
        else if (n == 0)
        {
            printf("Server closed connection\n");
            break;
        }
        else
        {
            /* Check if packet arrived in order */
            if (p.packet_number != packet_number)
            {
                conn->packet_loss_rate += 1.0;
            }
            packet_number++;
            conn->total_bytes_received += p.packet_size;
        }
    }
    conn->packet_loss_rate /= conn->packet_count;
    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <hostname> <port> <packet_count> <packet_size>\n", argv[0]);
        exit(1);
    }
    
    /* Parse arguments */
    char* hostname = argv[1];
    int port = atoi(argv[2]);
    int packet_count = atoi(argv[3]);
    int packet_size = atoi(argv[4]);
    
    /* Create socket */
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd < 0)
    {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }
    
    /* Get server address */
    struct hostent* server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr, "Error finding server: %s\n", strerror(errno));
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in)); // Zero out server address
    server_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);
    
    /* Connect to server */
    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in)) < 0)
    {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }
    
    /* Create connection struct */
    struct connection conn;
    conn.socket_fd = socket_fd;
    conn.server_addr = server_addr;
    conn.packet_count = 0;
    conn.packet_size = packet_size;
    conn.total_bytes_received = 0;
    conn.packet_loss_rate = 0.0;
    
    /* Start send and receive threads */
    pthread_create(&conn.thread_id, NULL, send_packets, (void*) &conn);
    receive_packets((void*) &conn);
    pthread_join(conn.thread_id, NULL);
    
    /* Compute QoS metrics */
    double throughput = (double) (8 * conn.total_bytes_received) / ((double) TIMEOUT * 1000.0);
    double avg_packet_loss_rate = 100.0 * conn.packet_loss_rate;
    
    /* Print QoS metrics */
    printf("QoS Metrics:\n");
    printf("Throughput: %.2f Mbps\n", throughput);
    printf("Average Packet Loss Rate: %.2f%%\n", avg_packet_loss_rate);
    
    /* Clean up */
    close(socket_fd);
    
    return 0;
}