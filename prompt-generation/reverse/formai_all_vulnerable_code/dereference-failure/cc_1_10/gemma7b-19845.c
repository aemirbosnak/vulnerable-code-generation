//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOSTS 255
#define MAX_LINKS 65535

typedef struct HOST {
    int host_id;
    char host_name[256];
    struct HOST *next;
} HOST;

typedef struct LINK {
    int src_id;
    int dst_id;
    struct LINK *next;
} LINK;

HOST *head_host = NULL;
LINK *head_link = NULL;

void add_host(int host_id, char *host_name) {
    HOST *new_host = (HOST *)malloc(sizeof(HOST));
    new_host->host_id = host_id;
    strcpy(new_host->host_name, host_name);
    new_host->next = NULL;

    if (head_host == NULL) {
        head_host = new_host;
    } else {
        head_host->next = new_host;
        head_host = new_host;
    }
}

void add_link(int src_id, int dst_id) {
    LINK *new_link = (LINK *)malloc(sizeof(LINK));
    new_link->src_id = src_id;
    new_link->dst_id = dst_id;
    new_link->next = NULL;

    if (head_link == NULL) {
        head_link = new_link;
    } else {
        head_link->next = new_link;
        head_link = new_link;
    }
}

void draw_topology(int num_hosts) {
    for (int i = 0; i < num_hosts; i++) {
        printf("%d (%s) ", head_host->host_id, head_host->host_name);
        printf("  ");
    }
    printf("\n");

    for (int i = 0; i < num_hosts; i++) {
        for (int j = 0; j < num_hosts; j++) {
            if (i != j) {
                LINK *link = head_link;
                while (link) {
                    if (link->src_id == i && link->dst_id == j) {
                        printf("%d-- ", head_host->host_id, head_host->host_name);
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    add_host(1, "localhost");
    add_host(2, "192.168.1.1");
    add_host(3, "192.168.1.2");
    add_link(1, 2);
    add_link(2, 3);

    draw_topology(3);

    return 0;
}