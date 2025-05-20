//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/time.h>

#define DELTA_SEC 1

typedef struct {
    char *name;
    int id;
} process_t;

typedef struct {
    int num_processes;
    process_t *processes;
} process_list_t;

void add_process(process_list_t *list, const char *name) {
    process_t *process = (process_t *)malloc(sizeof(process_t));
    process->name = strdup(name);
    process->id = getpid();
    list->processes = realloc(list->processes, sizeof(process_t) * ++list->num_processes);
    list->processes[list->num_processes - 1] = *process;
}

void print_process_list(process_list_t *list) {
    printf("Process list:\n");
    for (int i = 0; i < list->num_processes; i++) {
        printf("%d: %s\n", list->processes[i].id, list->processes[i].name);
    }
}

void free_process_list(process_list_t *list) {
    for (int i = 0; i < list->num_processes; i++) {
        free(list->processes[i].name);
    }
    free(list->processes);
}

int main() {
    process_list_t process_list = {0};

    while (1) {
        add_process(&process_list, "main");
        sleep(DELTA_SEC);
    }

    free_process_list(&process_list);

    return 0;
}