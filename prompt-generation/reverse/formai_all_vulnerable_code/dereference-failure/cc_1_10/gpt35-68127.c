//FormAI DATASET v1.0 Category: Data recovery tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to recover the lost data
void recover_data(char* file_name){
  // open the corrupted file
  FILE *file = fopen(file_name, "r");
  
  if(file == NULL){
    // unable to open the file
    printf("Unable to open the file '%s'", file_name);
    return;
  }
  
  // calculate the size of the file
  fseek(file, 0L, SEEK_END);
  long int file_size = ftell(file);
  fseek(file, 0L, SEEK_SET);
  
  // allocate memory for the file content
  char *file_content = malloc(file_size * sizeof(char));
  
  if(file_content == NULL){
    printf("Memory allocation failed!");
    return;
  }
  
  // read the file content
  size_t read_size = fread(file_content, 1, file_size, file);
  
  if(read_size != file_size){
    printf("Failed to read the file");
    return;
  }
  
  // close the file
  fclose(file);
  
  // scan for lost data
  char *search_string = "APOLLO_11";
  int search_string_length = strlen(search_string);
  int found = 0;
  
  for(int i=0; i<file_size; i++){
    if(file_content[i] == search_string[found]){
      found++;
      
      if(found == search_string_length){
        // found the lost data
        printf("Recovered data: %s", search_string);
        return;
      }
    }
    else{
      found = 0;
    }
  }
  
  // unable to recover the lost data
  printf("Unable to recover the lost data");
}

int main(){
  // prompt the user for the file name
  char file_name[256];
  printf("Enter the file name: ");
  scanf("%s", file_name);
  
  recover_data(file_name);
  
  return 0;
}