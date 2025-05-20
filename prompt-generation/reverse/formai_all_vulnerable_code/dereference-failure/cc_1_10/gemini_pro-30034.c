//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A macro for error checking
#define CHECK(expr, msg) do { \
        if (!(expr)) { \
                perror(msg); \
                exit(EXIT_FAILURE); \
        } \
} while (0)

// A struct to represent a network device
typedef struct device {
        char *name;
        char *ip_address;
        int port;
        struct device *next;
} device;

// A struct to represent a network topology
typedef struct topology {
        device *head;
        device *tail;
} topology;

// A function to create a new device
device *create_device(char *name, char *ip_address, int port) {
        device *new_device = malloc(sizeof(device));
        CHECK(new_device != NULL, "malloc");

        new_device->name = strdup(name);
        CHECK(new_device->name != NULL, "strdup");

        new_device->ip_address = strdup(ip_address);
        CHECK(new_device->ip_address != NULL, "strdup");

        new_device->port = port;

        new_device->next = NULL;

        return new_device;
}

// A function to add a device to a topology
void add_device(topology *t, device *d) {
        if (t->head == NULL) {
                t->head = d;
                t->tail = d;
        } else {
                t->tail->next = d;
                t->tail = d;
        }
}

// A function to print a topology
void print_topology(topology *t) {
        device *d;

        for (d = t->head; d != NULL; d = d->next) {
                printf("%s: %s:%d\n", d->name, d->ip_address, d->port);
        }
}

// A function to free a topology
void free_topology(topology *t) {
        device *d;

        for (d = t->head; d != NULL; d = d->next) {
                free(d->name);
                free(d->ip_address);
                free(d);
        }

        free(t);
}

// A function to map a network topology
topology *map_topology(char *filename) {
        FILE *fp;
        char line[1024];
        topology *t;
        device *d;
        int port;

        fp = fopen(filename, "r");
        CHECK(fp != NULL, "fopen");

        t = malloc(sizeof(topology));
        CHECK(t != NULL, "malloc");

        t->head = NULL;
        t->tail = NULL;

        while (fgets(line, sizeof(line), fp) != NULL) {
                char *name, *ip_address;

                name = strtok(line, ":");
                if (name == NULL) {
                        continue;
                }

                ip_address = strtok(NULL, ":");
                if (ip_address == NULL) {
                        continue;
                }

                port = atoi(strtok(NULL, "\n"));

                d = create_device(name, ip_address, port);
                add_device(t, d);
        }

        fclose(fp);

        return t;
}

// The main function
int main(int argc, char *argv[]) {
        topology *t;

        if (argc != 2) {
                fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        t = map_topology(argv[1]);
        print_topology(t);
        free_topology(t);

        return EXIT_SUCCESS;
}