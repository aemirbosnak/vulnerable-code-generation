//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

#define MAX_PATH 200
#define MAX_LEVEL 7

struct node
{
  char name[MAX_PATH];
  long long size;
  struct node* child[10000];
  int childcnt;
};

typedef struct node Node;

Node* create_node(char* name)
{
  Node* newnode = (Node*)malloc(sizeof(Node));
  strcpy(newnode->name,name);
  newnode->size = 0;
  newnode->childcnt = 0;
  return newnode;
}

int do_scan_dir(char* dirpath, Node* parent, int level)
{
  DIR *dir = opendir(dirpath);
  if(!dir)
  {
    printf("Cannot open directory '%s'\n",dirpath);
    return -1;
  }
  struct dirent *entry;
  while(entry = readdir(dir))
  {
    if(entry->d_type == DT_DIR && strcmp(entry->d_name,".") && strcmp(entry->d_name,".."))
    {
      char path[MAX_PATH];
      sprintf(path,"%s/%s",dirpath,entry->d_name);
      Node* node = create_node(entry->d_name);    

      int child_index = parent->childcnt++;
      parent->child[child_index] = node;
      int retcode = do_scan_dir(path,node,level+1);

      if(retcode<0) return -1;        
    }
    else if(entry->d_type == DT_REG)
    {
      parent->size += entry->d_reclen;
    }
  }
  closedir(dir);
  return 0;
}

void print_node(Node* node, int level, long long total_size)
{
  if(node==NULL)
    return;
  printf("%*s%25s%15lld",level," ",node->name,node->size);
  if(total_size!=0)
  {
    double percent = 100.0*node->size/total_size;
    printf(" (%.2f%%)",percent);
  }
  printf("\n");
  for(int i=0;i<node->childcnt;i++)
  {
    print_node(node->child[i],level+4,total_size);
  }
}

int main(int argc, char** argv)
{
  if(argc<2)
  {
    printf("Usage: %s path\n",argv[0]);
    return -1;
  }
  Node* root = create_node(argv[1]);

  int retcode = do_scan_dir(argv[1],root,0);
  if(retcode<0)
  {
    printf("Disk space analyzer failed.\n");
    return -1;
  }

  printf("%20s%15s %10s\n","Folder Name", "Size", "Percent");
  printf("%20s%15s %10s\n","-----------", "-----","-----");

  print_node(root,0,root->size);
  return 0;
}