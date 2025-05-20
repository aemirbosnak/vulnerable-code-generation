//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

/*
 * This program provides a unique artistic style for system process viewer.
 * It displays the list of all running processes similar to a virtual art gallery, 
 * with each process represented as a work of art on the wall.
 * 
 * The art piece for each process is a rectangle with varying dimensions, 
 * depending on the amount of memory used by the process. The rectangles 
 * are randomly colored and positioned on the screen to create a unique and 
 * interesting display.
 */

#define WIDTH 80      // width of the art gallery screen
#define HEIGHT 24     // height of the art gallery screen
#define MAX_MEM 1024  // maximum memory used by any process in kilobytes

#define RED "\x1b[31m"    // ANSI color code for red
#define GREEN "\x1b[32m"  // ANSI color code for green
#define YELLOW "\x1b[33m" // ANSI color code for yellow
#define BLUE "\x1b[34m"   // ANSI color code for blue
#define MAGENTA "\x1b[35m"// ANSI color code for magenta
#define CYAN "\x1b[36m"   // ANSI color code for cyan
#define RESET "\x1b[0m"   // ANSI color code to reset color

// structure to hold details of a process
typedef struct process {
    int pid;             // process ID
    char name[50];       // process name
    int mem;             // memory usage (in kilobytes)
} process_t;

// function to get the list of all running processes
void get_process_list(process_t **processes, int *num_processes) {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        exit(1);
    }

    int count = 0;

    // read all the directories in /proc directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            // if the directory name is a number, it is a process ID
            int pid = atoi(entry->d_name);

            // read the process name from the process status file
            char fname[100];
            sprintf(fname, "/proc/%d/status", pid);
            FILE *f = fopen(fname, "r");
            if (f != NULL) {
                char line[100];
                char *name = NULL;
                while (fgets(line, sizeof(line), f) != NULL) {
                    if (strncmp(line, "Name:", 5) == 0) {
                        // found the Name line, extract the process name
                        name = strdup(line + 5);
                        char *p = strchr(name, '\n');
                        if (p != NULL) {
                            *p = '\0';
                        }
                        break;
                    }
                }
                fclose(f);
                if (name != NULL) {
                    // read the process memory usage from the statm file
                    sprintf(fname, "/proc/%d/statm", pid);
                    f = fopen(fname, "r");
                    if (f != NULL) {
                        unsigned long long size;
                        fscanf(f, "%llu", &size);
                        size *= getpagesize();
                        (*processes)[count].pid = pid;
                        strncpy((*processes)[count].name, name, sizeof((*processes)[count].name));
                        (*processes)[count].mem = size/1024;
                        count++;
                        free(name);
                        fclose(f);
                    }
                }
            }
        }
    }

    closedir(dir);

    *num_processes = count;
}

// function to draw the given process as a work of art
void draw_process(const process_t *process) {
    int x = rand() % (WIDTH - 20);
    int y = rand() % (HEIGHT - 10);
    int w = 10 + 30*process->mem/MAX_MEM;
    int h = 5 + 20*process->mem/MAX_MEM;

    // add some randomness to the position and size
    x += rand() % 5;
    y += rand() % 5;

    // select a random color for the artwork
    int color = rand() % 6;

    //set the ANSI color code for the selected color
    const char *ansi_color = NULL;
    switch (color) {
        case 0: ansi_color = RED; break;
        case 1: ansi_color = GREEN; break;
        case 2: ansi_color = YELLOW; break;
        case 3: ansi_color = BLUE; break;
        case 4: ansi_color = MAGENTA; break;
        default: ansi_color = CYAN; break;
    }

    // draw the artwork rectangle
    printf("\x1b[%d;%dH%s", y, x, ansi_color);
    for (int i = 0; i < h; i++) {
        printf("\x1b[%d;%dH", y+i, x);
        for (int j = 0; j < w; j++) {
            printf("*");
        }
    }
    printf(RESET);
}

int main() {
    // hide the cursor and clear the screen
    printf("\x1b[?25l\x1b[2J");

    // initialize the random number generator
    srand(time(NULL));

    // get the list of all running processes
    process_t *processes = malloc(1000 * sizeof(process_t));
    int num_processes = 0;
    get_process_list(&processes, &num_processes);
    printf("\x1b[1;1HTotal Processes: %d\n\n", num_processes);

    // draw each process as a work of art on the screen
    for (int i = 0; i < num_processes; i++) {
        draw_process(&processes[i]);
    }

    printf("\x1b[%d;%dH", HEIGHT+1, WIDTH+1);
    free(processes);
    return 0;
}