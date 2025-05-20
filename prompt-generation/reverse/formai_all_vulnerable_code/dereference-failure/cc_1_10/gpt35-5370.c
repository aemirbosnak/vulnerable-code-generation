//FormAI DATASET v1.0 Category: Text Summarizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

void remove_punctuation(char *line) {
   int len = strlen(line);
   for(int i = 0; i < len; i++) {
      if(ispunct(line[i]))
         line[i] = ' ';
   }
}

int count_words(char *line) {
   int count = 0;
   char *token = strtok(line, " ");
   while(token != NULL) {
      count++;
      token = strtok(NULL, " ");
   }
   return count;
}

int main(int argc, char *argv[]) {
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;

   if (argc != 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   fp = fopen(argv[1], "r");
   if (fp == NULL) {
      perror("File could not be opened.\n");
      exit(EXIT_FAILURE);
   }

   char *sentences[MAX_SENTENCES];
   int sentence_count = 0;
   char *words[MAX_WORDS];
   int word_count = 0;

   while ((read = getline(&line, &len, fp)) != -1) {
      remove_punctuation(line);
      char *token = strtok(line, ".?!");

      while(token != NULL) {
         sentences[sentence_count++] = strdup(token);
         token = strtok(NULL, ".?!");
      }

      token = strtok(line, " ");
      while(token != NULL) {
         words[word_count++] = strdup(token);
         token = strtok(NULL, " ");
      }
   }

   fclose(fp);
   if (line) free(line);

   float avg_sentence_length = (float)word_count / (float)sentence_count;
   printf("The average sentence length is %.2f words.\n", avg_sentence_length);

   int word_frequency[word_count][2];
   for(int i = 0; i < word_count; i++) {
      int count = 0;
      for(int j = 0; j < word_count; j++) {
         if(strcmp(words[i], words[j]) == 0) {
            count++;
         }
      }
      word_frequency[i][0] = count;
      word_frequency[i][1] = i;
   }

   printf("Words sorted by frequency:\n");
   for(int i = 0; i < word_count; i++) {
      for(int j = i + 1; j < word_count; j++) {
         if(word_frequency[i][0] < word_frequency[j][0]) {
            int temp_count = word_frequency[i][0];
            word_frequency[i][0] = word_frequency[j][0];
            word_frequency[j][0] = temp_count;

            int temp_index = word_frequency[i][1];
            word_frequency[i][1] = word_frequency[j][1];
            word_frequency[j][1] = temp_index;
         }
      }
   }

   for(int i = 0; i < word_count; i++) {
      printf("%s: %d\n", words[word_frequency[i][1]], word_frequency[i][0]);
   }

   for(int i = 0; i < sentence_count; i++) {
      printf("Sentence %d: %s\n", i+1, sentences[i]);
   }

   return 0;
}