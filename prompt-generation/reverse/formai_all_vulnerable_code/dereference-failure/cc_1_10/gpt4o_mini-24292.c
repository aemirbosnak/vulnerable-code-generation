//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// Forward declaration of our funny functions
void display_procedure(pid_t pid);
void mood_based_greeting(int num_procs);
void fun_fact();
const char* get_process_name(pid_t pid);
void display_process_list();

// A slight bit of spice
#define MAX_PROCESSES 1024

int main() {
    // Display welcome message
    printf("Welcome to the Ridiculously Amusing Process Viewer!\n");
    mood_based_greeting(0);

    while (1) {
        display_process_list();
        printf("Press 'q' to quit or 'r' to refresh the list (any other key to continue): ");
        
        char action = getchar();
        while (getchar() != '\n'); // clear input buffer

        if (action == 'q') {
            printf("Goodbye, brave adventurer of processes! Until we meet again!\n");
            break;
        } else if (action == 'r') {
            printf("Refreshed! Let's take another look at these mysterious processes!\n");
            continue;
        }
    }
    return 0;
}

void display_process_list() {
    DIR *dir;
    struct dirent *entry;

    // This is where we go digging
    dir = opendir("/proc");
    if (!dir) {
        perror("Could not open /proc directory!");
        exit(EXIT_FAILURE);
    }

    // Get a count of processes for mood indicator
    int num_procs = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = (pid_t)atoi(entry->d_name);
            num_procs++;
            display_procedure(pid);
        }
    }
    closedir(dir);
    mood_based_greeting(num_procs);
    fun_fact();
}

void display_procedure(pid_t pid) {
    char path[256], buffer[256];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    FILE *fp = fopen(path, "r");
    if (!fp) {
        return; // This storm has passed!
    }
    
    // Read process info
    int ppid;
    char name[256];
    fscanf(fp, "%d %s %*s %*s %d", &pid, name, &ppid);
    fclose(fp);

    // Clean up the name
    // Take '/' off the name since it comes with it in proc files
    memmove(name, name + 1, strlen(name)); // move left by one

    printf("Process ID: %d | Name: %s | Parent PID: %d\n", pid, name, ppid);
}

void mood_based_greeting(int num_procs) {
    if (num_procs == 0) {
        printf("Wow! A peaceful world with no processes! It's a utopia! 🌈\n");
    } else if (num_procs < 10) {
        printf("Aww, just a few processes—it's like a cozy hobbit hole! 🏠\n");
    } else if (num_procs < 50) {
        printf("There's a decent crowd here! Don't let your socks get lost in the shuffle! 🧦\n");
    } else if (num_procs < 100) {
        printf("Whoa! It’s starting to look like a circus in here! 🎪\n");
    } else {
        printf("Goodness gracious! It’s a chaotic bazaar of processes! Help—I'm lost! 🥳\n");
    }
}

void fun_fact() {
    printf("Fun Fact: Did you know that cats purr at a frequency of 25 to 150 Hertz?\n");
    printf("This frequency range is known to be medically therapeutic (but you still shouldn't code with a cat on your keyboard)🐱💻\n\n");
}

const char* get_process_name(pid_t pid) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/comm", pid); // get the command name
    FILE *file = fopen(path, "r");
    
    if (file) {
        static char process_name[256];
        fgets(process_name, sizeof(process_name), file);
        fclose(file);
        process_name[strcspn(process_name, "\n")] = 0; // Remove any newline character
        return process_name;
    }
    return "Unknown process!";
}