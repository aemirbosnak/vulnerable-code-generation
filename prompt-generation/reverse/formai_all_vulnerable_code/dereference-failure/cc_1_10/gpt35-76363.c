//FormAI DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 20
#define MAX_PORTS 65535

int threadsCompleted = 0;

void* scanPort(void* argument) {
  int port = *((int*) argument);
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr("127.0.0.1");
  target.sin_port = htons(port);
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (connect(sockfd, (struct sockaddr*)&target, sizeof(target)) == 0) {
    printf("Port %d open\n", port);
  }
  close(sockfd);
  threadsCompleted++;
  return NULL;
}

void usage(char* name) {
  printf("Usage: %s <startPort-endPort>\n", name);
  exit(EXIT_FAILURE);
}

bool isNumber(char* string) {
  for(int i = 0; i < strlen(string); i++) {
    if(string[i] < '0' || string[i] > '9') {
      return false;
    }
  }
  
  return true;
}

int main(int argc, char** argv) {
  if(argc != 2) {
    usage(argv[0]);
  }

  char* portRange = argv[1];
  char* hyphen = strchr(portRange, '-');
  
  if(!hyphen || hyphen == portRange || hyphen == portRange + strlen(portRange) - 1) {
    usage(argv[0]);
  }

  hyphen[0] = '\0';

  int startPort = isNumber(portRange) ? atoi(portRange) : -1;
  int endPort = isNumber(hyphen + 1) ? atoi(hyphen + 1) : -1;

  if(startPort < 0 || startPort > MAX_PORTS || endPort < 0 || endPort > MAX_PORTS || endPort < startPort) {
    usage(argv[0]);
  }

  pthread_t threads[MAX_THREADS];

  int numThreadsNeeded = endPort - startPort + 1;
  int numThreads = numThreadsNeeded > MAX_THREADS ? MAX_THREADS : numThreadsNeeded;

  int portsPerThread = numThreadsNeeded / numThreads;

  int numPortsAssigned = 0;

  for(int i = 0; i < numThreads; i++) {
    int numPortsForThread = portsPerThread + (i < numThreadsNeeded % numThreads ? 1 : 0);
    int* ports = (int*) malloc(numPortsForThread * sizeof(int));
    for(int j = 0; j < numPortsForThread; j++) {
      ports[j] = startPort + numPortsAssigned++;
    }
    pthread_create(&threads[i], NULL, &scanPort, &ports[0]);
  }

  while(threadsCompleted < numThreads) {
    sleep(1);
  }

  return EXIT_SUCCESS;
}