//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 5
#define STR_SIZE 100

// The kingdom’s court to store the list of allowed knights
char *allowedKnights[MAX_CONNECTIONS];
int knightCount = 0;

// The town's guard that governs the incoming connections
void acceptConnection(int socket, struct sockaddr_in *address) {
    socklen_t addr_len = sizeof(*address);
    int clientSocket = accept(socket, (struct sockaddr*)address, &addr_len);
    
    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &address->sin_addr, clientIP, INET_ADDRSTRLEN);

    printf("A suitor approaches from the land: %s\n", clientIP);

    // Inspecting the realm to determine if the knight is allowed
    for (int i = 0; i < knightCount; i++) {
        if (strcmp(clientIP, allowedKnights[i]) == 0) {
            printf("Hark! The knight from %s hath been granted passage.\n", clientIP);
            write(clientSocket, "Welcome, noble knight!\n", 23);
            close(clientSocket);
            return;
        }
    }
    printf("Alas! The knight from %s hath been denied entry!\n", clientIP);
    write(clientSocket, "Beware! Thou art banished from these lands!\n", 42);
    close(clientSocket);
}

// A noble function to add a knight to the realm
void addKnight(const char *ip) {
    if (knightCount < MAX_CONNECTIONS) {
        allowedKnights[knightCount] = strdup(ip);
        knightCount++;
        printf("A new knight hath joined the realm: %s\n", ip);
    } else {
        printf("The court is full! Cannot accept more knights.\n");
    }
}

// Speaks to the townsfolk to listen for incoming connections
void guardTheRealm(int port) {
    int socket_desc;
    struct sockaddr_in address;

    // Creating the socket of the realm's guards
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) {
        perror("Could not create the judge's throne!");
        exit(EXIT_FAILURE);
    }

    // Setting the details for the grand court
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Binding the socket to the throne of the port
    if (bind(socket_desc, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("The court cannot be established!");
        close(socket_desc);
        exit(EXIT_FAILURE);
    }

    // The guards shall now listen for approach
    listen(socket_desc, MAX_CONNECTIONS);
    printf("The guards are ready! Awaiting knights at port %d...\n", port);

    // The main vigil of the guards
    while (1) {
        acceptConnection(socket_desc, &address);
    }

    close(socket_desc);
}

// Proclaim the allowed knights as a decree
void declareKnights() {
    printf("The following knights are allowed in the court:\n");
    for (int i = 0; i < knightCount; i++) {
        printf("- %s\n", allowedKnights[i]);
    }
}

int main(int argc, char *argv[]) {
    // Command to declare the port
    int port = 8080;

    // Adding some knights (IPs) to the court
    addKnight("192.168.1.10");
    addKnight("192.168.1.20");
    addKnight("192.168.1.30");

    // Proclaim the knights of the realm
    declareKnights();

    // The guard shall take their station
    guardTheRealm(port);
    
    return 0;
}