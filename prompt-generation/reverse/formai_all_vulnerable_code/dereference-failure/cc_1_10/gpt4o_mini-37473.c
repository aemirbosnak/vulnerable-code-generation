//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>

void dream_image(char *line) {
    char *dreams[] = {
        "Soft whispers of the digital sea.",
        "Fingers tap-dance on the keys of the void.",
        "Frostbitten program flung into starlit oblivion.",
        "Each process a soul wandering in the cosmic ether.",
        "Ghostly echoes of CPU cycles drift like smoke."
    };
    
    int index = rand() % 5; 
    printf("\n%s\n", dreams[index]);
}

void contemplate_process(char *pid, char *state, char *cmd) {
    printf("In the labyrinth of dreams, process %s, a brave knight in the realm of %s, wears a cloak woven from the threads of %s.\n", pid, state, cmd);
}

void wander_in_proc_files() {
    struct dirent *entry;
    DIR *directory = opendir("/proc");

    if (!directory) {
        perror("Failed to open /proc");
        return;
    }

    while ((entry = readdir(directory))) {
        if (isdigit(entry->d_name[0])) {
            char proc_path[256];
            snprintf(proc_path, sizeof(proc_path), "/proc/%s/stat", entry->d_name);
            FILE *proc_file = fopen(proc_path, "r");
            if (proc_file) {
                char buf[256];
                fgets(buf, sizeof(buf), proc_file);
                fclose(proc_file);

                char pid[10], comm[50], state[4];
                sscanf(buf, "%s %s %s", pid, comm, state);

                dream_image(comm);
                contemplate_process(pid, state, comm);
            }
        }
    }

    closedir(directory);
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Surrealist Process Viewer!\n");
    printf("The digital realm unfolds beneath your curious gaze...\n");

    while (1) {
        wander_in_proc_files();
        printf("\nAh, but the clock ticks on, dragging my thoughts through the web of time...\n");
        sleep(3); // The mind wanders for a moment, then returns to reality
    }

    return 0;
}