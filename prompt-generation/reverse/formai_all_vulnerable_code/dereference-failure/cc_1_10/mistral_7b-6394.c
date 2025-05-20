//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

typedef struct {
    char name[20];
    int key;
} Agent;

void encrypt(void *input, size_t length, Agent *agent) {
    int i;
    char *buf = (char *)input;

    for (i = 0; i < length; i++) {
        buf[i] = (buf[i] + agent->key) % 256;
    }
}

void decrypt(void *input, size_t length, Agent *agent) {
    int i;
    char *buf = (char *)input;

    for (i = 0; i < length; i++) {
        buf[i] = (buf[i] - agent->key < 0) ? buf[i] + 256 : buf[i] - agent->key;
    }
}

void generate_key(Agent *agent) {
    agent->key = 0;

    while (1) {
        agent->key += rand() % 128;
        if (agent->key % 3 == 0 && agent->key % 5 == 0) {
            break;
        }
    }

    sprintf(agent->name, "Agent %d", agent->key);
}

void save_agent(Agent *agent, int fd) {
    memcpy(mmap(NULL, sizeof(Agent), PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0), agent, sizeof(Agent));
}

int main() {
    srand(time(NULL));
    int fd = open("agents.dat", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    Agent *agents = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    int i;

    for (i = 0; i < 10; i++) {
        Agent agent;
        generate_key(&agent);
        encrypt("Secret message", 13, &agent);
        save_agent(&agent, fd);
    }

    for (i = 0; i < 10; i++) {
        lseek(fd, i * sizeof(Agent), SEEK_SET);
        Agent agent;
        memcpy(&agent, mmap(NULL, sizeof(Agent), PROT_READ, MAP_PRIVATE, fd, 0), sizeof(Agent));
        decrypt("Secret message", 13, &agent);
        printf("%s: %s\n", agent.name, "Secret message");
        munmap(&agent, sizeof(Agent));
    }

    munmap(agents, 4096);
    close(fd);

    return 0;
}