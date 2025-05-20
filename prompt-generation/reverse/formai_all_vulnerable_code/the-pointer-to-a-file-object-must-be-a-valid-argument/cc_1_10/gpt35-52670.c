//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include<stdio.h> 

// function to check for stop words
int isStopWord(char *word) {
  char stop_words[10][10] = {"a", "an", "the", "but", "and", "or", "by", "of", "from", "with"};
  int i;
  
  for(i=0; i<10; i++) {
    if(strcmp(stop_words[i], word) == 0) {
      return 1;
    }
  }
  return 0;
}

// main function
int main() {
  FILE *fp;
  char sentence[1000], words[100][100];
  int i, j, len, n=0;
  
  // reading input from file
  fp = fopen("input.txt", "r");

  printf("Original text: \n");

  while(fgets(sentence, 1000, fp)) {
    printf("%s", sentence);
  }
  
  fclose(fp);

  // splitting text into words
  for(i=0; sentence[i] != '\0'; i++) {
    if(sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!') {
      n++;
    } else {
      words[n][i] = sentence[i];
    }
  }

  printf("\n\nSummary: \n");

  // printing summary
  for(i=0; i<n; i++) {
    len = strlen(words[i]);
    if(len > 5 && !isStopWord(words[i])) {
      for(j=0; j<len; j++) {
        printf("%c", words[i][j]);
      }
      printf(". ");
    }
  }

  return 0;
}