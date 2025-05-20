//FormAI DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Directory {
   char *name;
   struct Node *first_child;
   struct Directory *parent;
};

struct File {
   char *name;
   char *content;
   int size;
   struct Directory *parent;
};

struct Node {
   union {
      struct Directory dir;
      struct File file;
   } u;
   int is_dir;
   struct Node *next_sibling;
};

struct Node *root = NULL;

void init_fs() {
   root = calloc(1, sizeof(struct Node));
   root->is_dir = 1;
   root->u.dir.name = "/";
}

struct Node *find_node(struct Directory *dir, char *name) {
   if (dir == NULL)
      return NULL;
   struct Node *p = dir->first_child;
   while (p != NULL) {
      if (strcmp(p->u.dir.name, name) == 0)
         return p;
      p = p->next_sibling;
   }
   return NULL;
}

void check_dir_exists(struct Directory *dir, char *name) {
   if (find_node(dir, name) != NULL) {
      printf("Directory '%s' already exists in '%s'\n", name, dir->name);
      exit(1);
   }
}

void check_file_exists(struct Directory *dir, char *name) {
   if (find_node(dir, name) != NULL) {
      printf("File '%s' already exists in '%s'\n", name, dir->name);
      exit(1);
   }
}

void create_dir(struct Directory *parent_dir, char *name) {
   check_dir_exists(parent_dir, name);
   struct Node *new_dir_node = calloc(1, sizeof(struct Node));
   new_dir_node->is_dir = 1;
   struct Directory *new_dir = &new_dir_node->u.dir;
   new_dir_node->next_sibling = parent_dir->first_child;
   parent_dir->first_child = new_dir_node;
   new_dir->parent = parent_dir;
   new_dir->name = strdup(name);
   printf("Created directory '%s' in '%s'\n", name, parent_dir->name);
}

void create_file(struct Directory *parent_dir, char *name) {
   check_file_exists(parent_dir, name);
   struct Node *new_file_node = calloc(1, sizeof(struct Node));
   new_file_node->is_dir = 0;
   struct File *new_file = &new_file_node->u.file;
   new_file_node->next_sibling = parent_dir->first_child;
   parent_dir->first_child = new_file_node;
   new_file->parent = parent_dir;
   new_file->name = strdup(name);
   new_file->content = calloc(MAX, sizeof(char));
   new_file->size = 0;
   printf("Created file '%s' in '%s'\n", name, parent_dir->name);
}

struct Node *parse_path(char *path) {
   if (path == NULL)
      return NULL;

   char *saveptr = NULL;
   char *token = strtok_r(path, "/", &saveptr);
   if (token == NULL)
      return NULL;

   struct Node *cur_node;
   if (path[0] == '/')
      cur_node = root;
   else
      cur_node = find_node(&cur_node->u.dir, ".");

   while (token != NULL) {
      if (strcmp(token, "") != 0) {
         cur_node = find_node(&cur_node->u.dir, token);
         if (cur_node == NULL)
            return NULL;
      }
      token = strtok_r(NULL, "/", &saveptr);
   }

   return cur_node;
}

void print_file(struct File *file) {
   printf("%s\n", file->name);
   printf("Content:\n%s", file->content);
   printf("Size: %d\n", file->size);
}

void print_dir(struct Directory *dir, int depth) {
   printf("%s\n", dir->name);

   struct Node *cur_node = dir->first_child;
   while (cur_node != NULL) {
      for (int i = 0; i < depth; i++)
         printf("  ");
      if (cur_node->is_dir)
         print_dir(&cur_node->u.dir, depth + 1);
      else
         print_file(&cur_node->u.file);
      cur_node = cur_node->next_sibling;
   }
}

int main() {
   init_fs();

   create_dir(&root->u.dir, "usr");
   create_file(&root->u.dir, "README");
   create_file(&root->u.dir, "license");

   struct Node *usr_dir_node = find_node(&root->u.dir, "usr");
   if (usr_dir_node == NULL)
      return 1;

   create_dir(&usr_dir_node->u.dir, "doc");
   create_file(&usr_dir_node->u.dir, "file1");
   create_file(&usr_dir_node->u.dir, "file2");

   struct Node *doc_dir_node = find_node(&usr_dir_node->u.dir, "doc");
   if (doc_dir_node == NULL)
      return 2;

   create_file(&doc_dir_node->u.dir, "doc1");

   print_dir(&root->u.dir, 0);

   return 0;
}