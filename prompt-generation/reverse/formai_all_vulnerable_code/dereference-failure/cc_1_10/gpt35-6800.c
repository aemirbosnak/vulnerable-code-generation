//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50

char *compress(char *input_string);

int main(void) {
  char input_string[MAX_LENGTH];
  printf("Enter a string to compress:\n");
  fgets(input_string,MAX_LENGTH,stdin);
  char *result = compress(input_string);
  printf("The compressed string is: %s\n",result);
  free(result);
  return 0;
}

char *compress(char *input_string) {
  int length = strlen(input_string);
  char *compressed_string = (char*) malloc(length*sizeof(char));
  int compressed_index = 0;
  char current_char = input_string[0];
  int current_count = 1;
  int i;
  for(i=1;i<length;i++) {
    if(input_string[i] == current_char) {
      current_count++;
    } else {
      compressed_string[compressed_index++] = current_char;
      char *count_str = (char*) malloc(sizeof(char)*MAX_LENGTH);
      sprintf(count_str,"%d",current_count);
      int j;
      for(j=0;j<strlen(count_str);j++) {
        compressed_string[compressed_index++] = count_str[j];
      }
      free(count_str);
      current_char = input_string[i];
      current_count = 1;
    }
  }
  compressed_string[compressed_index++] = current_char;
  char *count_str = (char*) malloc(sizeof(char)*MAX_LENGTH);
  sprintf(count_str,"%d",current_count);
  int j;
  for(j=0;j<strlen(count_str);j++) {
    compressed_string[compressed_index++] = count_str[j];
  }
  free(count_str);
  compressed_string[compressed_index] = '\0';
  return compressed_string;
}