//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_NODE_COUNT 1000
#define MAX_NODE_NAME_LENGTH 50
#define STRESS_TEST_MAX_REQUESTS 1000

int nodeCount = 0;
char nodeNames[MAX_NODE_COUNT][MAX_NODE_NAME_LENGTH];

void parseTopology(char* topology) {
    char* curNodeName = strtok(topology, ",");
    while (curNodeName != NULL) {
        strncpy(nodeNames[nodeCount++], curNodeName, MAX_NODE_NAME_LENGTH);
        if (nodeCount > MAX_NODE_COUNT) {
            printf("Error: Too many nodes in topology. Trimming to %d nodes.\n", MAX_NODE_COUNT);
            break;
        }
        curNodeName = strtok(NULL, ",");
    }
}

void sampleNode(char* name) {
    bool requestSucceeded = false;
    CURL* curl = curl_easy_init();
    if (curl) {
        char url[100];
        sprintf(url, "http://%s:8080/ping", name);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Node %s is not reachable.\n", name);
        } else {
            printf("Node %s is reachable.\n", name);
            requestSucceeded = true;
        }
        curl_easy_cleanup(curl);
    } else {
        printf("Error: Failed to initialize CURL library.\n");
    }
    if (!requestSucceeded) {
        printf("Error: Unable to reach node %s. Are you sure it's on the network?\n", name);
    }
}

void mapTopology() {
    char response[1000];
    FILE* topologyFile = fopen("network_topology.txt", "r");
    if (!topologyFile) {
        printf("Error: Could not open network topology file.\n");
        return;
    }
    char topology[1000];
    fgets(topology, 1000, topologyFile);
    fclose(topologyFile);
    parseTopology(topology);
    printf("Mapped network topology:\n");
    int i;
    for (i = 0; i < nodeCount; i++) {
        printf("%s\n", nodeNames[i]);
    }
    printf("Commencing stress test on topology...\n");
    for (i = 0; i < STRESS_TEST_MAX_REQUESTS; i++) {
        int index = rand() % nodeCount;
        sampleNode(nodeNames[index]);
        sleep(1);
    }
}

int main(int argc, char** argv) {
    mapTopology();
    return 0;
}