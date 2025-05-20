//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_BUFFER 256

typedef struct {
    char username[50];
    char homedir[100];
    uid_t uid;
    gid_t gid;
    char shell[100];
    time_t last_login;
} UserInfo;

void get_user_info(UserInfo *user_info) {
    struct passwd *pw = getpwuid(user_info->uid);
    if (pw) {
        strcpy(user_info->username, pw->pw_name);
        strcpy(user_info->homedir, pw->pw_dir);
        user_info->gid = pw->pw_gid;
        user_info->last_login = time(NULL);
        strcpy(user_info->shell, pw->pw_shell);
    }
}

void print_user_info(UserInfo *user_info) {
    struct group *gr = getgrgid(user_info->gid);
    char formatted_time[30];
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", localtime(&user_info->last_login));
    
    printf("User: %s\n", user_info->username);
    printf("UID: %d\n", user_info->uid);
    printf("GID: %d (%s)\n", user_info->gid, gr ? gr->gr_name : "N/A");
    printf("Home Directory: %s\n", user_info->homedir);
    printf("Shell: %s\n", user_info->shell);
    printf("Last Login: %s\n", formatted_time);
}

void write_user_info_to_file(UserInfo *user_info) {
    FILE *file = fopen("user_info.log", "a+");
    if (file) {
        fprintf(file, "User: %s, UID: %d, GID: %d, Home: %s, Shell: %s, Last Login: %ld\n", 
            user_info->username, 
            user_info->uid, 
            user_info->gid, 
            user_info->homedir, 
            user_info->shell, 
            user_info->last_login);
        fclose(file);
    } else {
        perror("Failed to open log file");
    }
}

void display_all_users() {
    struct passwd *pw;
    printf("\nList of all users:\n");
    while ((pw = getpwent()) != NULL) {
        printf("Username: %s, UID: %d, GID: %d\n", pw->pw_name, pw->pw_uid, pw->pw_gid);
    }
    endpwent();
}

void get_user_statistics() {
    printf("\nGathering user statistics...\n");

    UserInfo users[MAX_USERS];
    int count = 0;

    struct passwd *pw;
    while ((pw = getpwent()) != NULL && count < MAX_USERS) {
        users[count].uid = pw->pw_uid;
        get_user_info(&users[count]);
        count++;
    }
    endpwent();

    for(int i = 0; i < count; i++) {
        print_user_info(&users[i]);
        write_user_info_to_file(&users[i]);
    }
}

void print_help() {
    printf("Usage: user_manager <command>\n");
    printf("Commands:\n");
    printf("  list            - List all users\n");
    printf("  stats           - Gather user statistics\n");
    printf("  help            - Display this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Invalid arguments.\n");
        print_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "list") == 0) {
        display_all_users();
    } else if (strcmp(argv[1], "stats") == 0) {
        get_user_statistics();
    } else if (strcmp(argv[1], "help") == 0) {
        print_help();
    } else {
        fprintf(stderr, "Error: Unknown command '%s'.\n", argv[1]);
        print_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}