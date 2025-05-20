//FormAI DATASET v1.0 Category: Database Indexing System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Index {
 char keyword[20];
 int index_pos;
};

int comparator(const void* p, const void* q) {
  return strcmp(((struct Index*)p)->keyword, ((struct Index*)q)->keyword);
}

int main() {
  FILE *fp, *fp_index;
  struct Index *index;
  int count=0, ch, i=0, flag=0, temp, index_count=0;
  char file_name[30], word[20], file_ch;

  printf("Enter the name of the file:");
  scanf("%s", file_name);
  
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("File not found.\n");
    return 0;
  }

  // Counting the total number of words in the file
  while ((file_ch = fgetc(fp)) != EOF) {
     if (file_ch == '\n') {
        count++;
     }
  }
  fclose(fp);

  // Allocating memory dynamically for storing the index
  index = malloc(count * sizeof(struct Index));

  fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("File not found.\n");
    return 0;
  }

  while ((ch = fgetc(fp)) != EOF) {
    if (isalnum(ch)) {
      word[i++] = ch;
    }
    else if ((ch == ' ' || ch == '\n') && i) {
      word[i] = '\0';
      flag = 0;
      for (int j = 0; j < index_count; j++) {
        if (strcmp(word, index[j].keyword) == 0) {
          index[j].index_pos = ftell(fp) - strlen(word) - 1;
          flag = 1;
          break;
        }
      }
      if (!flag) {
        strcpy(index[index_count].keyword, word);
        index[index_count].index_pos = ftell(fp) - strlen(word) - 1;
        index_count++;
      }
      i = 0;
    }
  }
  
  // Sorting the index in ascending order using quicksort
  qsort(index, index_count, sizeof(struct Index), comparator);

  // Writing the index to the file
  fp_index = fopen("index.txt", "w+");
  for (int j = 0; j < index_count; j++) {
    fprintf(fp_index, "%s %d\n", index[j].keyword, index[j].index_pos);
  }
  fclose(fp_index);
  printf("Index created successfully!\n");
  return 0;
}