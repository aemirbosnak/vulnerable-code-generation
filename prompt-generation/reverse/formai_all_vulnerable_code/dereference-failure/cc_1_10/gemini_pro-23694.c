//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTS 100
#define MAX_PORTS 10

struct host {
	char *name;
	struct sockaddr_in addr;
};

struct port {
	int number;
	int open;
};

struct topology {
	struct host hosts[MAX_HOSTS];
	struct port ports[MAX_PORTS];
	int num_hosts;
	int num_ports;
};

struct topology *
new_topology()
{
	struct topology *t;

	t = malloc(sizeof(struct topology));
	if (t == NULL)
		return NULL;

	t->num_hosts = 0;
	t->num_ports = 0;

	return t;
}

void
free_topology(struct topology *t)
{
	int i;

	for (i = 0; i < t->num_hosts; i++)
		free(t->hosts[i].name);

	free(t);
}

int
add_host(struct topology *t, char *name, char *addr)
{
	struct host *h;

	if (t->num_hosts >= MAX_HOSTS)
		return -1;

	h = &t->hosts[t->num_hosts++];

	h->name = strdup(name);
	if (h->name == NULL)
		return -1;

	if (inet_pton(AF_INET, addr, &h->addr.sin_addr) != 1)
		return -1;

	h->addr.sin_family = AF_INET;
	h->addr.sin_port = 0;

	return 0;
}

int
add_port(struct topology *t, int number)
{
	struct port *p;

	if (t->num_ports >= MAX_PORTS)
		return -1;

	p = &t->ports[t->num_ports++];

	p->number = number;
	p->open = 0;

	return 0;
}

int
scan_host(struct topology *t, struct host *h)
{
	int i, s;

	for (i = 0; i < t->num_ports; i++) {
		struct port *p = &t->ports[i];

		s = socket(AF_INET, SOCK_STREAM, 0);
		if (s == -1)
			continue;

		h->addr.sin_port = htons(p->number);
		if (connect(s, (struct sockaddr *)&h->addr, sizeof(h->addr)) == 0)
			p->open = 1;

		close(s);
	}

	return 0;
}

int
main(int argc, char **argv)
{
	struct topology *t;
	int i;

	t = new_topology();
	if (t == NULL) {
		fprintf(stderr, "failed to create topology\n");
		return 1;
	}

	if (argc < 2) {
		fprintf(stderr, "usage: %s <host> [<host> ...]\n", argv[0]);
		return 1;
	}

	for (i = 1; i < argc; i++) {
		if (add_host(t, argv[i], "127.0.0.1") == -1) {
			fprintf(stderr, "failed to add host %s\n", argv[i]);
			return 1;
		}
	}

	for (i = 0; i < t->num_hosts; i++)
		scan_host(t, &t->hosts[i]);

	for (i = 0; i < t->num_hosts; i++) {
		struct host *h = &t->hosts[i];
		printf("%s", h->name);
	}

	for (i = 0; i < t->num_ports; i++) {
		struct port *p = &t->ports[i];
		printf("%d", p->number);
	}

	free_topology(t);

	return 0;
}