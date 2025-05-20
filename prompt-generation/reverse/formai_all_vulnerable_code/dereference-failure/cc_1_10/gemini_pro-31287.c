//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 1024

typedef struct {
    int id;
    char* name;
} Candidate;

Candidate* candidates;
int num_candidates;

void init_candidates() {
    candidates = malloc(sizeof(Candidate) * 3);
    num_candidates = 3;

    candidates[0].id = 1;
    candidates[0].name = "John Doe";
    candidates[1].id = 2;
    candidates[1].name = "Jane Doe";
    candidates[2].id = 3;
    candidates[2].name = "Joe Schmo";
}

int vote(int candidate_id) {
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            return 1;
        }
    }
    return 0;
}

int main() {
    init_candidates();

    int server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_sock, 5) < 0) {
        perror("listen");
        return 1;
    }

    printf("Waiting for clients to connect...\n");

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected.\n");

        char buff[BUFF_SIZE];
        int num_bytes = recv(client_sock, buff, BUFF_SIZE, 0);
        if (num_bytes < 0) {
            perror("recv");
            close(client_sock);
            continue;
        }

        int candidate_id = atoi(buff);
        int result = vote(candidate_id);

        if (result == 1) {
            send(client_sock, "Vote successful.\n", strlen("Vote successful.\n") + 1, 0);
        } else {
            send(client_sock, "Invalid candidate ID.\n", strlen("Invalid candidate ID.\n") + 1, 0);
        }

        close(client_sock);
    }

    close(server_sock);

    return 0;
}