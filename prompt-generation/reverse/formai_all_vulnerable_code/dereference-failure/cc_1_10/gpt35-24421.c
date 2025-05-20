//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 12345 // the port number for the monitor

typedef struct {
    float latency;
    float bandwidth;
    float packet_loss;
    float jitter;
} QoSData;

QoSData measure_qos() {
    // code to measure the QoS metrics
    QoSData data;
    // TODO: implement measurement code
    return data;
}

void send_qos(const char *hostname, QoSData data) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set up server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy((char *)&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // serialize QoS data
    char buf[1024];
    sprintf(buf, "%f %f %f %f\n", data.latency, data.bandwidth, data.packet_loss, data.jitter);

    // send QoS data to server
    n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (n < 0) {
        perror("ERROR in sendto");
        exit(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    QoSData data = measure_qos();
    send_qos("localhost", data);
    return 0;
}