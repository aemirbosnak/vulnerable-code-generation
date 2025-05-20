//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct _node
{
  char name[256];
  struct _node *next;
} node;

typedef struct _dir_info
{
  char path[256];
  struct _dir_info *next;
} dir_info;

node *head = NULL;
node *tail = NULL;

dir_info *dir_head = NULL;
dir_info *dir_tail = NULL;

int compare(const void *a, const void *b)
{
  return strcmp(((node *)a)->name, ((node *)b)->name);
}

void add_file(char *path)
{
  node *new_node = (node *)malloc(sizeof(node));
  strcpy(new_node->name, path);
  new_node->next = NULL;

  if (head == NULL)
  {
    head = new_node;
    tail = new_node;
  }
  else
  {
    tail->next = new_node;
    tail = new_node;
  }
}

void add_dir(char *path)
{
  dir_info *new_dir = (dir_info *)malloc(sizeof(dir_info));
  strcpy(new_dir->path, path);
  new_dir->next = NULL;

  if (dir_head == NULL)
  {
    dir_head = new_dir;
    dir_tail = new_dir;
  }
  else
  {
    dir_tail->next = new_dir;
    dir_tail = new_dir;
  }
}

void print_files()
{
  node *current = head;
  while (current != NULL)
  {
    printf("%s\n", current->name);
    current = current->next;
  }
}

void print_dirs()
{
  dir_info *current = dir_head;
  while (current != NULL)
  {
    printf("%s\n", current->path);
    current = current->next;
  }
}

int main()
{
  char path[256];
  getcwd(path, sizeof(path));

  DIR *dir = opendir(path);
  struct dirent *entry;

  while ((entry = readdir(dir)) != NULL)
  {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
    {
      continue;
    }

    char full_path[256];
    sprintf(full_path, "%s/%s", path, entry->d_name);

    struct stat statbuf;
    stat(full_path, &statbuf);

    if (S_ISREG(statbuf.st_mode))
    {
      add_file(full_path);
    }
    else if (S_ISDIR(statbuf.st_mode))
    {
      add_dir(full_path);
    }
  }
  closedir(dir);

  qsort(head, tail - head + 1, sizeof(node), compare);
  print_files();

  qsort(dir_head, dir_tail - dir_head + 1, sizeof(dir_info), compare);
  print_dirs();

  return 0;
}