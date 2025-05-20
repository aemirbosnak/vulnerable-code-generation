//FormAI DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

// Function to get system process details
void getProcessDetails() {
    DIR* dir = opendir("/proc"); // Open directory containing all process info
    struct dirent* entry;
    FILE* file;
    char filename[64];
    char line[256];
    char name[100];
    int pid;
    int vsize;
    int pmem;
    int pcpu;
    int cpuTotal;
    int memTotal;

    // Print out table headers
    printf("%-10s%-25s%-10s%-10s%-10s\n", "PID", "Name", "VIRT", "CPU%", "MEM%");

    // Loop through each process folder in directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if directory entry is a process folder (i.e. a folder with all process info)
        if (isdigit(*entry->d_name)) {
            pid = atoi(entry->d_name); // Get process ID

            // Open and read file containing process name
            sprintf(filename, "/proc/%d/cmdline", pid);
            file = fopen(filename, "r");
            if(file != NULL) {
                fgets(name, sizeof(name), file); // Get first line of file
                fclose(file);
            }

            // Convert all null bytes in process name to spaces
            for(int i = 0; i < sizeof(name)/sizeof(name[0]); i++) {
                if(name[i] == '\0') {
                    name[i] = ' ';
                }
            }

            // Open and read file containing virtual size
            sprintf(filename, "/proc/%d/status", pid);
            file = fopen(filename, "r");
            if(file != NULL) {
                while(fgets(line, sizeof(line), file)) {
                    if(strncmp(line, "VmSize:", 7) == 0) { // Find line containing virtual size
                        sscanf(line, "%*s %d", &vsize); // Scan line for virtual size
                    } 
                }
                fclose(file);
            }

            // Open and read file containing CPU usage
            sprintf(filename, "/proc/%d/stat", pid);
            file = fopen(filename, "r");
            if(file != NULL) {
                fgets(line, sizeof(line), file); // Get first line of file
                fclose(file);

                int utime, stime, cutime, cstime;

                // Parse CPU times from first line of file
                sscanf(line, "%d (%[^)]", &pid, name);
                for(int i = strlen(name)-1; i > 0; i--) {
                    if(name[i] == ' ') {
                        name[i] = '\0';
                        break;
                    }
                }
                sscanf(line+(strlen(line)-32), "%d %d %d %d", &utime, &stime, &cutime, &cstime);

                // Calculate CPU usage
                cpuTotal = utime + stime + cutime + cstime;
                pcpu = cpuTotal/10;

                // Open and read file containing memory usage
                sprintf(filename, "/proc/%d/statm", pid);
                file = fopen(filename, "r");
                if(file != NULL) {
                    fgets(line, sizeof(line), file); // Get first line of file
                    fclose(file);
                    sscanf(line, "%d %d", &pmem, &memTotal);

                    // Calculate memory usage
                    pmem = pmem*(getpagesize()/1024);
                    int memPercent = (pmem*100)/memTotal;

                    // Print out process info
                    printf("%-10d%-25s%-10d%-10d%-10d\n", pid, name, vsize, pcpu, memPercent);
                }
            }
        }
    }

    closedir(dir); // Close directory
}

int main() {
    getProcessDetails(); // Call function to get process details
    return 0;
}