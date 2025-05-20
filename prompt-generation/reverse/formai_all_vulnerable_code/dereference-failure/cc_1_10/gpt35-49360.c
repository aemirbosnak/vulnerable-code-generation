//FormAI DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dir {
    char name[50];
    struct dir* parent;
    struct dir* children[50];
    struct file* files[50];
    int num_children;
    int num_files;
};

struct file {
    char name[50];
    char content[100];
};

struct dir* root;

void init_fs() {
    root = (struct dir*) malloc(sizeof(struct dir));
    strcpy(root->name, "/");
    root->parent = NULL;
    root->num_children = 0;
    root->num_files = 0;
}

void print_prompt() {
    printf("fs> ");
}

void tokenize(char* input, char** tokens, int* num_tokens) {
    char* token = strtok(input, " ");
    *num_tokens = 0;
    while (token != NULL) {
        tokens[*num_tokens] = token;
        *num_tokens = *num_tokens + 1;
        token = strtok(NULL, " ");
    }
}

struct dir* find_dir(char* name, struct dir* current_dir) {
    if (strcmp(name, "..") == 0) {
        return current_dir->parent;
    }
    int i;
    for (i = 0; i < current_dir->num_children; i++) {
        struct dir* child_dir = current_dir->children[i];
        if (strcmp(name, child_dir->name) == 0) {
            return child_dir;
        }
    }
    return NULL;
}

struct file* find_file(char* name, struct dir* current_dir) {
    int i;
    for (i = 0; i < current_dir->num_files; i++) {
        struct file* f = current_dir->files[i];
        if (strcmp(name, f->name) == 0) {
            return f;
        }
    }
    return NULL;
}

void cd(char** tokens, int num_tokens, struct dir** current_dir) {
    if (num_tokens != 2) {
        printf("Usage: cd <dir>\n");
        return;
    }
    struct dir* dir_found = find_dir(tokens[1], *current_dir);
    if (dir_found == NULL) {
        printf("Directory not found.\n");
        return;
    }
    *current_dir = dir_found;
}

void mkdir(char** tokens, int num_tokens, struct dir* current_dir) {
    if (num_tokens != 2) {
        printf("Usage: mkdir <dir_name>\n");
        return;
    }
    if (current_dir->num_children >= 50) {
        printf("Maximum number of directories reached.\n");
        return;
    }
    struct dir* dir = (struct dir*) malloc(sizeof(struct dir));
    strcpy(dir->name, tokens[1]);
    dir->parent = current_dir;
    dir->num_children = 0;
    dir->num_files = 0;
    current_dir->children[current_dir->num_children] = dir;
    current_dir->num_children++;
}

void rmdir(char** tokens, int num_tokens, struct dir* current_dir) {
    if (num_tokens != 2) {
        printf("Usage: rmdir <dir_name>\n");
        return;
    }
    int i;
    int dir_found = 0;
    for (i = 0; i < current_dir->num_children; i++) {
        struct dir* child_dir = current_dir->children[i];
        if (strcmp(tokens[1], child_dir->name) == 0) {
            if (child_dir->num_children > 0 || child_dir->num_files > 0) {
                printf("Directory must be empty.\n");
                return;
            }
            int j;
            for (j = i; j < current_dir->num_children-1; j++) {
                current_dir->children[j] = current_dir->children[j+1];
            }
            current_dir->num_children--;
            free(child_dir);
            dir_found = 1;
            break;
        }
    }
    if (dir_found == 0) {
        printf("Directory not found.\n");
        return;
    }
}

void ls(struct dir* current_dir) {
    int i;
    for (i = 0; i < current_dir->num_children; i++) {
        struct dir* child_dir = current_dir->children[i];
        printf("%s/\n", child_dir->name);
    }
    for (i = 0; i < current_dir->num_files; i++) {
        struct file* f = current_dir->files[i];
        printf("%s\n", f->name);
    }
}

void touch(char** tokens, int num_tokens, struct dir* current_dir) {
    if (num_tokens != 2) {
        printf("Usage: touch <file_name>\n");
        return;
    }
    if (current_dir->num_files >= 50) {
        printf("Maximum number of files reached.\n");
        return;
    }
    struct file* f = (struct file*) malloc(sizeof(struct file));
    strcpy(f->name, tokens[1]);
    strcpy(f->content, "");
    current_dir->files[current_dir->num_files] = f;
    current_dir->num_files++;
}

void rm(char** tokens, int num_tokens, struct dir* current_dir) {
    if (num_tokens != 2) {
        printf("Usage: rm <file_name>\n");
        return;
    }
    int i;
    int file_found = 0;
    for (i = 0; i < current_dir->num_files; i++) {
        struct file* f = current_dir->files[i];
        if (strcmp(tokens[1], f->name) == 0) {
            int j;
            for (j = i; j < current_dir->num_files-1; j++) {
                current_dir->files[j] = current_dir->files[j+1];
            }
            current_dir->num_files--;
            free(f);
            file_found = 1;
            break;
        }
    }
    if (file_found == 0) {
        printf("File not found.\n");
        return;
    }
}

void cat(char** tokens, int num_tokens, struct dir* current_dir) {
    if (num_tokens != 2) {
        printf("Usage: cat <file_name>\n");
        return;
    }
    struct file* f = find_file(tokens[1], current_dir);
    if (f == NULL) {
        printf("File not found.\n");
        return;
    }
    printf("%s\n", f->content);
}

void write(char** tokens, int num_tokens, struct dir* current_dir) {
    if (num_tokens <= 2) {
        printf("Usage: write <file_name> <content>\n");
        return;
    }
    struct file* f = find_file(tokens[1], current_dir);
    if (f == NULL) {
        printf("File not found.\n");
        return;
    }
    int i;
    sprintf(f->content, "%s", tokens[2]);
    for (i = 3; i < num_tokens; i++) {
        sprintf(f->content, "%s %s", f->content, tokens[i]);
    }
}

int main() {
    init_fs();

    struct dir* current_dir = root;

    while (1) {
        char input[100];
        print_prompt();
        fgets(input, 100, stdin);
        int len = strlen(input) - 1;
        if (input[len] == '\n') {
            input[len] = '\0';
        }

        char* tokens[50];
        int num_tokens = 0;
        tokenize(input, tokens, &num_tokens);

        if (num_tokens == 0) {
            continue;
        }

        if (strcmp("pwd", tokens[0]) == 0) {
            printf("/%s\n", current_dir->name);
        } else if (strcmp("cd", tokens[0]) == 0) {
            cd(tokens, num_tokens, &current_dir);
        } else if (strcmp("mkdir", tokens[0]) == 0) {
            mkdir(tokens, num_tokens, current_dir);
        } else if (strcmp("rmdir", tokens[0]) == 0) {
            rmdir(tokens, num_tokens, current_dir);
        } else if (strcmp("ls", tokens[0]) == 0) {
            ls(current_dir);
        } else if (strcmp("touch", tokens[0]) == 0) {
            touch(tokens, num_tokens, current_dir);
        } else if (strcmp("rm", tokens[0]) == 0) {
            rm(tokens, num_tokens, current_dir);
        } else if (strcmp("cat", tokens[0]) == 0) {
            cat(tokens, num_tokens, current_dir);
        } else if (strcmp("write", tokens[0]) == 0) {
            write(tokens, num_tokens, current_dir);
        } else if (strcmp("exit", tokens[0]) == 0) {
            break;
        } else {
            printf("Command not recognized.\n");
        }
    }

    return 0;
}