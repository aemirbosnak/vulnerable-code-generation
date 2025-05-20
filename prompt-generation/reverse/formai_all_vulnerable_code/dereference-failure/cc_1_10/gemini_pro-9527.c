//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Romeo and Juliet
#include <stdio.h>
#include <pcap.h>
#include <string.h>
#include <stdlib.h>

// Romeo and Juliet Packet Capturer

typedef struct {
    char *name;
    pcap_t *handle;
} Connection;

void greet(Connection *romeo, Connection *juliet) {
    printf("Romeo: My dearest Juliet, I am here to listen to your tales of the network.\n");
    printf("Juliet: Oh, Romeo, my love, I shall share with thee my secrets, for I have much to tell.\n");
}

void capture(Connection *conn) {
    struct pcap_pkthdr *header;
    const u_char *packet;
    while (1) {
        int res = pcap_next_ex(conn->handle, &header, &packet);
        if (res == 1) {
            printf("%s: I have received a packet from the void.\n", conn->name);
            printf("Header: %d bytes\n", header->caplen);
            printf("Packet: %s\n", packet);
        } else if (res == -1) {
            printf("%s: Alas, I have lost my connection to the network.\n", conn->name);
            break;
        }
    }
}

void closeConnection(Connection *conn) {
    pcap_close(conn->handle);
    free(conn->name);
    free(conn);
}

int main() {
    printf("Romeo: My Juliet, I pray that thou art connected to the network.\n");
    printf("Juliet: Romeo, I am here, and I am ready to capture your love.\n");

    Connection *romeo = malloc(sizeof(Connection));
    romeo->name = "Romeo";
    romeo->handle = pcap_open_live("eth0", 65535, 1, 1000, NULL);

    Connection *juliet = malloc(sizeof(Connection));
    juliet->name = "Juliet";
    juliet->handle = pcap_open_live("eth1", 65535, 1, 1000, NULL);

    greet(romeo, juliet);
    capture(romeo);
    capture(juliet);

    closeConnection(romeo);
    closeConnection(juliet);

    return 0;
}