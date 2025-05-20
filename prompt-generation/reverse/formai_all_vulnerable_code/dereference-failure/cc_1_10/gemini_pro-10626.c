//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The ethereal gateway to the SMTP kingdom
#define SMTP_PORT 25

// The ethereal vessel for our SMTP transmissions
struct ethereal_vessel {
    int socket;
    char *hostname;
    char *port;
};

// The grand ethereal vessel builder
struct ethereal_vessel *ethereal_vessel_build(char *hostname, char *port) {
    struct ethereal_vessel *vessel = malloc(sizeof(struct ethereal_vessel));
    vessel->hostname = strdup(hostname);
    vessel->port = strdup(port);
    return vessel;
}

// The ethereal vessel destroyer
void ethereal_vessel_destroy(struct ethereal_vessel *vessel) {
    free(vessel->hostname);
    free(vessel->port);
    free(vessel);
}

// The ethereal vessel navigator
int ethereal_vessel_navigate(struct ethereal_vessel *vessel) {
    struct sockaddr_in server_address;
    struct hostent *server = gethostbyname(vessel->hostname);
    if (server == NULL) {
        return -1;
    }

    vessel->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (vessel->socket == -1) {
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(vessel->port));
    server_address.sin_addr = *(struct in_addr *)server->h_addr;

    if (connect(vessel->socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        return -1;
    }

    return 0;
}

// The ethereal vessel communicator
int ethereal_vessel_communicate(struct ethereal_vessel *vessel, char *message) {
    int bytes_sent = send(vessel->socket, message, strlen(message), 0);
    if (bytes_sent == -1) {
        return -1;
    }

    return bytes_sent;
}

// The grand ethereal vessel orchestrator
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    struct ethereal_vessel *vessel = ethereal_vessel_build(argv[1], argv[2]);
    if (ethereal_vessel_navigate(vessel) == -1) {
        printf("Error connecting to server\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal greeting
    char *greeting = "HELO ethereal_vessel\r\n";
    if (ethereal_vessel_communicate(vessel, greeting) == -1) {
        printf("Error sending greeting\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal mail sender
    char *sender = "MAIL FROM: <sender@example.com>\r\n";
    if (ethereal_vessel_communicate(vessel, sender) == -1) {
        printf("Error sending sender\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal mail recipient
    char *recipient = "RCPT TO: <recipient@example.com>\r\n";
    if (ethereal_vessel_communicate(vessel, recipient) == -1) {
        printf("Error sending recipient\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal mail data
    char *data = "DATA\r\n";
    if (ethereal_vessel_communicate(vessel, data) == -1) {
        printf("Error sending data\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal mail message
    char *message = "Subject: Ethereal Message\r\n\r\nThis is an ethereal message.\r\n";
    if (ethereal_vessel_communicate(vessel, message) == -1) {
        printf("Error sending message\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal mail closure
    char *closure = ".\r\n";
    if (ethereal_vessel_communicate(vessel, closure) == -1) {
        printf("Error sending closure\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    // The ethereal farewell
    char *farewell = "QUIT\r\n";
    if (ethereal_vessel_communicate(vessel, farewell) == -1) {
        printf("Error sending farewell\n");
        ethereal_vessel_destroy(vessel);
        return 1;
    }

    ethereal_vessel_destroy(vessel);
    return 0;
}