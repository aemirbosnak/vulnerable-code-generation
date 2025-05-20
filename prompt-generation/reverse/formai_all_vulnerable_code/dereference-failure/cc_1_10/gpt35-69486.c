//FormAI DATASET v1.0 Category: System process viewer ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<ctype.h>

#define MAX_PID_LEN 8
#define MAX_NAME_LEN 256

void print_process_info(char *pid, char *name, char *user, char *state, int mem, float cpu, char *cmdline) {
    printf("-----------------------------------------------------------\n");
    printf("PID:\t%s\n", pid);
    printf("Name:\t%s\n", name);
    printf("User:\t%s\n", user);
    printf("State:\t%s\n", state);
    printf("Mem:\t%d\n", mem);
    printf("CPU:\t%.2f%%\n", cpu);
    printf("Cmdline:\n%s\n", cmdline);
}

void read_uid_name(char *uid, char *name) {
    FILE *fp = fopen("/etc/passwd", "r");

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, ":");
        char *_name = strtok(NULL, ":");
        char *_uid = strtok(NULL, ":");

        if (strcmp(uid, _uid) == 0) {
            strcpy(name, _name);
            break;
        }
    }

    fclose(fp);
}

void read_process_cmdline(char *pid, char *cmdline) {
    char path[256];
    sprintf(path, "/proc/%s/cmdline", pid);

    FILE *fp = fopen(path, "r");
    if (fp != NULL) {
        fgets(cmdline, MAX_NAME_LEN, fp);
        fclose(fp);
    }
}

void read_process_stat(char *pid, char *name, char *state, int *utime, int *stime) {
    char path[256];
    sprintf(path, "/proc/%s/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp != NULL) {
        fscanf(fp, "%s %s %s %d %*s %*s %*s %*s %*s %*s %*s %d", pid, name, state, utime, stime);
        fclose(fp);
    }
}

void read_process_mem(char *pid, int *mem) {
    char path[256];
    sprintf(path, "/proc/%s/status", pid);

    FILE *fp = fopen(path, "r");
    if (fp != NULL) {
        char line[256];

        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "VmSize:")) {
                sscanf(line, "%*s %*s %d", mem);
                break;
            }
        }

        fclose(fp);
    }
}

int is_number(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i])) return 0;
    }

    return 1;
}

float get_cpu_percent(char *pid, int utime, int stime) {
    static int prev_utime = 0, prev_stime = 0;
    static float prev_cpu_percent = 0;

    if (prev_utime == 0 && prev_stime == 0) {
        prev_utime = utime;
        prev_stime = stime;

        return 0;
    }

    int curr_utime = 0, curr_stime = 0;
    char path[256];
    sprintf(path, "/proc/%s/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp != NULL) {
        fscanf(fp, "%*s %*s %*s %d %*s %*s %*s %*s %*s %*s %*s %d", &curr_utime, &curr_stime);
        fclose(fp);
    }

    float total_time = curr_utime + curr_stime - prev_utime - prev_stime;
    float percent = total_time / sysconf(_SC_CLK_TCK) * 100;

    prev_utime = curr_utime;
    prev_stime = curr_stime;

    return percent;
}

void read_process_info(char *pid) {
    char state[MAX_NAME_LEN] = {0};
    char name[MAX_NAME_LEN] = {0};
    char uid[MAX_NAME_LEN] = {0};
    int utime, stime, mem;
    float cpu_percent;
    char cmdline[MAX_NAME_LEN] = {0};
    char user[MAX_NAME_LEN] = {0};

    read_process_stat(pid, name, state, &utime, &stime);
    read_uid_name(uid, user);
    read_process_cmdline(pid, cmdline);
    read_process_mem(pid, &mem);
    cpu_percent = get_cpu_percent(pid, utime, stime);

    print_process_info(pid, name, user, state, mem, cpu_percent, cmdline);
}

void print_all_processes() {
    DIR *dirp;
    struct dirent *dp;

    dirp = opendir("/proc/");
    while ((dp = readdir(dirp)) != NULL) {
        if (is_number(dp->d_name)) {
            read_process_info(dp->d_name);
        }
    }

    closedir(dirp);
}

int main() {
    printf("C Process Viewer\n");
    print_all_processes();

    return 0;
}