//FormAI DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_GROUPS 50

struct User {
    char *username;
    char *password;
    char *homedir;
    char *shell;
    int uid;
    int gid;
};

struct Group {
    char *groupname;
    int gid;
    struct User *users[MAX_USERS];
    int num_users;
};

struct User *users[MAX_USERS];
int num_users = 0;

struct Group *groups[MAX_GROUPS];
int num_groups = 0;

void add_user(struct User *u) 
{
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached!\n");
        return;
    }
    users[num_users] = u;
    num_users++;
}

void add_group(struct Group *g) 
{
    if (num_groups >= MAX_GROUPS) {
        printf("Error: Maximum number of groups reached!\n");
        return;
    }
    groups[num_groups] = g;
    num_groups++;
}

void add_user_to_group(struct User *u, struct Group *g) 
{
    if (g->num_users >= MAX_USERS) {
        printf("Error: Maximum number of users in group reached!\n");
        return;
    }
    g->users[g->num_users] = u;
    g->num_users++;
    u->gid = g->gid;
}

void print_users() 
{
    printf("Users:\n");
    for (int i=0; i<num_users; i++) {
        struct User *u = users[i];
        printf("%d\t%s\t%s\t%s\t%s\t%d\t%d\n", 
            u->uid, 
            u->username, 
            u->password, 
            u->homedir, 
            u->shell,
            u->gid,
            u->uid
        );
    }
}

void print_groups() 
{
    printf("Groups:\n");
    for (int i=0; i<num_groups; i++) {
        struct Group *g = groups[i];
        printf("%d\t%s\n", g->gid, g->groupname);
        for (int j=0; j<g->num_users; j++) {
            struct User *u = g->users[j];
            printf("\t%d\t%s\n", u->uid, u->username);
        }
    }
}

int main() 
{
    struct User *u1 = malloc(sizeof(struct User));
    u1->username = "jdoe";
    u1->password = "password";
    u1->homedir = "/home/jdoe";
    u1->shell = "/bin/bash";
    u1->uid = 1000;

    struct User *u2 = malloc(sizeof(struct User));
    u2->username = "ksmith";
    u2->password = "password123";
    u2->homedir = "/home/ksmith";
    u2->shell = "/bin/bash";
    u2->uid = 1001;

    add_user(u1);
    add_user(u2);

    struct Group *g1 = malloc(sizeof(struct Group));
    g1->groupname = "developers";
    g1->gid = 1000;

    struct Group *g2 = malloc(sizeof(struct Group));
    g2->groupname = "admins";
    g2->gid = 1001;

    add_group(g1);
    add_group(g2);

    add_user_to_group(u1, g1);
    add_user_to_group(u2, g1);
    add_user_to_group(u2, g2);

    print_users();
    print_groups();

    return 0;
}