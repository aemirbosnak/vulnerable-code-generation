//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define MAX_BUFFER_SIZE 256

typedef struct Process {
    int pid;
    char comm[MAX_BUFFER_SIZE];
    char state;
    unsigned long int vm_size; // Virtual memory size
    unsigned long int vm_rss;  // Resident Set Size
} Process;

// Function prototypes
void list_processes();
Process* read_process_info(int pid);
void print_process_info(Process* p);
void free_process(Process* p);
void display_help();

int main(int argc, char *argv[]) {
    // Check for help flag
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        display_help();
        return 0;
    }
    
    // List all processes
    list_processes();
    return 0;
}

void display_help() {
    printf("Usage: process_viewer [options]\n");
    printf("Options:\n");
    printf("  --help   Show this help message\n");
    printf("\nThis program lists all current running processes along with their details.\n");
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(PROC_DIR)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-6s %-25s %-10s %-10s %-10s\n", "PID", "COMMAND", "STATE", "VM_SIZE", "RSS");
    printf("---------------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        // Check if entry is a digit (indicating a PID)
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            Process* p = read_process_info(pid);
            if (p) {
                print_process_info(p);
                free_process(p);
            }
        }
    }
    closedir(dir);
}

Process* read_process_info(int pid) {
    char path[MAX_BUFFER_SIZE];
    snprintf(path, sizeof(path), PROC_DIR "/%d/stat", pid);

    FILE *fp = fopen(path, "r");
    if (!fp) {
        return NULL; // Process may have exited or file is not accessible
    }

    Process* p = malloc(sizeof(Process));
    if (p == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read the process file
    fscanf(fp, "%d (%[^)]s) %c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu",
           &p->pid, p->comm, &p->state, &p->vm_size, &p->vm_rss);
    
    fclose(fp);
    return p;
}

void print_process_info(Process* p) {
    // Print process information in a formatted way
    printf("%-6d %-25s %-10c %-10lu %-10lu\n", 
           p->pid, p->comm, p->state, p->vm_size / 1024, p->vm_rss / 1024);
}

void free_process(Process* p) {
    free(p);
}