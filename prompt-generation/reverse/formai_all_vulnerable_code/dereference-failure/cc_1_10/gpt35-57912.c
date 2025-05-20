//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

    // variables for socket connection
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // variables for QoS monitoring
    float avg_throughput = 0.0, avg_delay = 0.0, avg_jitter = 0.0;
    int num_packets = 0;

    // check command line arguments
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // convert port number from string to integer
    portno = atoi(argv[2]);

    // create socket connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // clear serv_addr and set values
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive packets and calculate QoS
    while (1) {
        char buffer[256];
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        if (n == 0) {
            break;
        }

        // retrieve QoS values from packet payload
        float throughput, delay, jitter;
        sscanf(buffer, "%f %f %f", &throughput, &delay, &jitter);

        // calculate running averages
        avg_throughput = ((num_packets * avg_throughput) + throughput) / (num_packets + 1);
        avg_delay = ((num_packets * avg_delay) + delay) / (num_packets + 1);
        avg_jitter = ((num_packets * avg_jitter) + jitter) / (num_packets + 1);

        // increment packet count
        num_packets++;
    }

    // close socket connection and print results
    close(sockfd);
    printf("Average Throughput: %.2f Mbps\n", avg_throughput);
    printf("Average Delay: %.2f ms\n", avg_delay);
    printf("Average Jitter: %.2f ms\n", avg_jitter);

    return 0;
}