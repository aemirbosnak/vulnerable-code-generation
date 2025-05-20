//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the Enigma machine
struct enigma {
    char rotor[3][26];
    char reflector[26];
    int notch[3];
    int position[3];
};

// Initialize the Enigma machine
void enigma_init(struct enigma *e) {
    // Set the rotor wirings
    strcpy(e->rotor[0], "EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    strcpy(e->rotor[1], "AJDKSIRUXBLHWTMCQGZNPYFVOE");
    strcpy(e->rotor[2], "BDFHJLCPRTXVZNYEIWGAKMUSQO");

    // Set the reflector wiring
    strcpy(e->reflector, "YRUHQSLDPXNGOKMIEBFZCWVJAT");

    // Set the notch positions
    e->notch[0] = 16;
    e->notch[1] = 5;
    e->notch[2] = 21;

    // Set the initial rotor positions
    e->position[0] = 0;
    e->position[1] = 0;
    e->position[2] = 0;
}

// Encrypt a character using the Enigma machine
char enigma_encrypt(struct enigma *e, char c) {
    // Rotate the rotors
    e->position[0]++;
    if (e->position[0] == e->notch[0]) {
        e->position[1]++;
    }
    if (e->position[1] == e->notch[1]) {
        e->position[2]++;
    }

    // Pass the character through the rotors
    c = e->rotor[0][c - 'A'];
    c = e->rotor[1][c - 'A'];
    c = e->rotor[2][c - 'A'];

    // Pass the character through the reflector
    c = e->reflector[c - 'A'];

    // Pass the character back through the rotors in reverse order
    c = e->rotor[2][c - 'A'];
    c = e->rotor[1][c - 'A'];
    c = e->rotor[0][c - 'A'];

    return c + 'A';
}

// Decrypt a character using the Enigma machine
char enigma_decrypt(struct enigma *e, char c) {
    // Pass the character through the rotors in reverse order
    c = e->rotor[0][c - 'A'];
    c = e->rotor[1][c - 'A'];
    c = e->rotor[2][c - 'A'];

    // Pass the character through the reflector
    c = e->reflector[c - 'A'];

    // Pass the character back through the rotors
    c = e->rotor[2][c - 'A'];
    c = e->rotor[1][c - 'A'];
    c = e->rotor[0][c - 'A'];

    return c + 'A';
}

// Create a TCP server socket
int create_server_socket(int port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

// Accept a client connection
int accept_client_connection(int server_sockfd) {
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;

    client_addr_len = sizeof(client_addr);
    client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("accept");
        exit(1);
    }

    return client_sockfd;
}

// Handle a client connection
void handle_client_connection(int client_sockfd) {
    char buffer[1024];
    struct enigma e;

    // Initialize the Enigma machine
    enigma_init(&e);

    // Read the message from the client
    int n = read(client_sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // Encrypt the message
    for (int i = 0; i < n; i++) {
        buffer[i] = enigma_encrypt(&e, buffer[i]);
    }

    // Write the encrypted message back to the client
    n = write(client_sockfd, buffer, n);
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Close the client connection
    close(client_sockfd);
}

int main(int argc, char **argv) {
    int server_sockfd;
    int client_sockfd;

    // Create a TCP server socket
    server_sockfd = create_server_socket(atoi(argv[1]));

    // Accept client connections
    while (1) {
        client_sockfd = accept_client_connection(server_sockfd);

        // Handle the client connection
        handle_client_connection(client_sockfd);
    }

    // Close the server socket
    close(server_sockfd);

    return 0;
}