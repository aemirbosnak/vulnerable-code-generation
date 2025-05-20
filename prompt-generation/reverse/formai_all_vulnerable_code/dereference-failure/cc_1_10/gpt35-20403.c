//FormAI DATASET v1.0 Category: System boot optimizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STARTUP_APPS 10
#define MAX_APP_NAME_LEN 20

typedef struct {
    char name[MAX_APP_NAME_LEN];
    int priority;
} StartupApp;

void optimize_boot(char* startup_apps_file) {
    StartupApp startup_apps[MAX_STARTUP_APPS];
    int num_apps = 0;
    
    // read startup apps from file
    FILE* file = fopen(startup_apps_file, "r");
    if (file == NULL) {
        printf("error: could not open file %s\n", startup_apps_file);
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* name = strtok(line, ",");
        char* priority_str = strtok(NULL, ",");
        int priority = atoi(priority_str);
        StartupApp new_app;
        strncpy(new_app.name, name, MAX_APP_NAME_LEN);
        new_app.priority = priority;
        startup_apps[num_apps++] = new_app;
    }
    fclose(file);
    
    // sort apps by priority
    for (int i = 0; i < num_apps; i++) {
        for (int j = i + 1; j < num_apps; j++) {
            if (startup_apps[j].priority > startup_apps[i].priority) {
                StartupApp temp = startup_apps[j];
                startup_apps[j] = startup_apps[i];
                startup_apps[i] = temp;
            }
        }
    }
    
    // execute apps in order
    for (int i = 0; i < num_apps; i++) {
        printf("Executing %s...\n", startup_apps[i].name);
        char command[50];
        sprintf(command, "/usr/bin/%s", startup_apps[i].name);
        system(command);
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: %s [startup_apps_file]\n", argv[0]);
        return 1;
    }
    
    char* startup_apps_file = argv[1];
    optimize_boot(startup_apps_file);
    
    return 0;
}