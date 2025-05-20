//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_METADATA 50
#define MAX_LENGTH 100

typedef struct{
  char type[MAX_LENGTH];
  char value[MAX_LENGTH];
}metadata;

metadata extractMetadata(char *line){
  metadata result;

  char *pos = strchr(line, '@');
  if(pos == NULL){
    strcpy(result.type, "");
    strcpy(result.value, "");
  }else{
    strcpy(result.type, pos+1);
    result.type[strlen(result.type)-1] = '\0';
    int len = pos - line;
    strncpy(result.value, line, len);
    result.value[len] = '\0';
  }

  return result;
}

metadata *extractMetadataFromFile(char *filename, int *count){
  metadata *metadataArray = malloc(MAX_METADATA * sizeof(metadata));

  FILE *file = fopen(filename, "r");

  char line[MAX_LENGTH];
  int i = 0;
  while(fgets(line, MAX_LENGTH, file)){
    metadataArray[i] = extractMetadata(line);
    i++;
  }

  fclose(file);

  *count = i;
  return metadataArray;
}

int main(){
  int count;
  metadata *metadataArray = extractMetadataFromFile("example.txt", &count);

  printf("Metadata Found:\n");
  for(int i=0;i<count;i++){
    printf("Type: %s, Value: %s\n", metadataArray[i].type, metadataArray[i].value);
  }

  return 0;
}