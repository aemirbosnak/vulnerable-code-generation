//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <time.h>
#include <string.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    // check for valid arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // get server address info
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // setup server address struct
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2])) ;

    // connect to server
    int connect_status = connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
    if (connect_status < 0) 
        error("ERROR connecting");

    // set up packet struct
    struct packet {
        unsigned long long timestamp; // timestamp of packet
        int payload_size; // size of payload
        char payload[256]; // string payload
    };

    // send packets to server
    printf("\nSending packets to server... \n\n");
    struct packet pkt;
    int total_bytes_sent = 0;
    int ans;
    while (1) {
        memset(pkt.payload, 0, sizeof(pkt.payload)); // clear packet payload
        time_t t = time(NULL); // get timestamp
        pkt.timestamp = (unsigned long long)t;
        pkt.payload_size = rand() % 256 + 1; // randomize payload size
        for (int i = 0; i < pkt.payload_size-1; i++) {
            pkt.payload[i] = 'a' + rand() % 26; // randomize payload characters
        }
        pkt.payload[pkt.payload_size-1] = '\0'; // add null terminator
        total_bytes_sent += pkt.payload_size+sizeof(pkt.timestamp)+sizeof(pkt.payload_size); // calculate total sent bytes
        printf("timestamp: %llu\n", pkt.timestamp);
        printf("payload_size: %d\n", pkt.payload_size);
        printf("payload: %s\n", pkt.payload);
        ans = write(sockfd, &pkt, sizeof(pkt)); // send packet
        if (ans < 0) {
            error("ERROR writing to socket");
        }
        sleep(1); // wait 1 second
    }

    // close socket
    close(sockfd);
    return 0;
}