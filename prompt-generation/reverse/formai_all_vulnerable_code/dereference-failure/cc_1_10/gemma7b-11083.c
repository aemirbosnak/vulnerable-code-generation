//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ routers 100

typedef struct Router {
    int id;
    struct Router* next;
    char* name;
    char* ip_address;
    char* mac_address;
} Router;

Router* create_router(int id, char* name, char* ip_address, char* mac_address) {
    Router* router = malloc(sizeof(Router));
    router->id = id;
    router->next = NULL;
    router->name = strdup(name);
    router->ip_address = strdup(ip_address);
    router->mac_address = strdup(mac_address);

    return router;
}

void add_router(Router* head, int id, char* name, char* ip_address, char* mac_address) {
    Router* router = create_router(id, name, ip_address, mac_address);
    if (head == NULL) {
        head = router;
    } else {
        router->next = head;
        head = router;
    }
}

void print_router(Router* head) {
    while (head) {
        printf("ID: %d, Name: %s, IP Address: %s, MAC Address: %s\n", head->id, head->name, head->ip_address, head->mac_address);
        head = head->next;
    }
}

int main() {
    Router* head = NULL;
    add_router(head, 1, "Router A", "192.168.1.1", "00:11:22:33:44:55");
    add_router(head, 2, "Router B", "192.168.1.2", "00:22:33:44:55:66");
    add_router(head, 3, "Router C", "192.168.1.3", "00:33:44:55:66:77");

    print_router(head);

    return 0;
}