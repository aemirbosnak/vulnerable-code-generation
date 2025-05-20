//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<ctype.h>

#define BUFFER_SIZE 1024
#define LIMIT 100
#define TOKEN_DELIM " \t\r\n\a"

void type_prompt(){
  printf("> "); // custom prompt
}

char *read_input(){
  char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
  fgets(buffer, BUFFER_SIZE, stdin);
  return buffer;
}

char **split_input(char *input){
  int position = 0;
  char **tokens = malloc(LIMIT * sizeof(char *));
  char *token;
  
  if(!tokens){
    printf("Memory allocation error\n");
    exit(EXIT_FAILURE); // Exit with a failure status
  }
  
  token = strtok(input, TOKEN_DELIM); // Split input by delimiters
  while(token != NULL){
    tokens[position] = token;
    position++;
    
    if(position >= LIMIT){
      printf("Token limit exceeded\n");
      exit(EXIT_FAILURE);
    }
    
    token = strtok(NULL, TOKEN_DELIM);
  }
  tokens[position] = NULL; // Last token needs to be NULL
  return tokens;
}

int execute(char **args){
  pid_t pid, wpid;
  int status;

  pid = fork();
  if(pid == 0){ // Child process                              
    if(execvp(args[0], args) == -1){ // Execute command
      perror("Error executing command");
      exit(EXIT_FAILURE);
    }  
    // Exit child process with success
    exit(EXIT_SUCCESS);
  } else if(pid < 0){ // Error forking
    perror("Error forking");
  } else { // Parent process
    do{
      wpid = waitpid(pid, &status, WUNTRACED);
    }while(!WIFEXITED(status) && !WIFSIGNALED(status)); // Check if process exited normally
  }
  
  return 1; // Shell status code
}

int shell_loop(){
  char *input;    
  char **args;
  int status;

  do{
    type_prompt(); // Print prompt
    input = read_input(); // Read user input
    args = split_input(input); // Split input into tokens
    status = execute(args); // Execute command
    free(input);
    free(args);
  }while(status); // Keep looping until exit command entered
  
  return 0; // Exited shell successfully
}

int main(int argc, char **argv){
  system("clear"); // Clear console screen
  printf("Welcome to the Unix-like Shell!\n");
  printf("Enter 'exit' to quit the shell\n\n");

  // Run shell
  shell_loop();

  return EXIT_SUCCESS; // Exit with success status
}