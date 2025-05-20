//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/* Define the maximum lengths of various strings */
#define MAX_CV_LENGTH 1000
#define MAX_KEYWORDS 20
#define MAX_THREADS 10

/* Define structs to hold data for CV and keyword parsing */
typedef struct {
  char* name;
  char* email;
  char* summary;
  char* education;
  char* work_experience;
  char* skills;
  char* projects;
} CV;

typedef struct {
  char** keywords;
  int num_keywords;
  int* keyword_counts;
} KeywordData;

/* Define a global array of CVs, an array of thread IDs, a count of active worker threads,
and a mutex to protect the CV array and thread count */
CV* cvs[MAX_THREADS];
pthread_t thread_ids[MAX_THREADS];
int num_threads = 0;
pthread_mutex_t cvs_mut = PTHREAD_MUTEX_INITIALIZER;

/* Define a function to parse a CV given its raw text */
CV* parseCV(const char* raw_text) {
  /* Allocate memory for the CV struct */
  CV* cv = malloc(sizeof(CV));
  if(cv == NULL) {
    perror("Failed to allocate memory for CV");
    exit(EXIT_FAILURE);
  }

  /* Tokenize the raw text into separate fields */
  char* name = strtok(raw_text, "\n");
  char* email = strtok(NULL, "\n");
  char* summary = strtok(NULL, "\n");
  char* education = strtok(NULL, "\n");
  char* work_experience = strtok(NULL, "\n");
  char* skills = strtok(NULL, "\n");
  char* projects = strtok(NULL, "\n");

  /* Copy the tokenized data into the CV struct */
  cv->name = strdup(name);
  cv->email = strdup(email);
  cv->summary = strdup(summary);
  cv->education = strdup(education);
  cv->work_experience = strdup(work_experience);
  cv->skills = strdup(skills);
  cv->projects = strdup(projects);

  /* Return the parsed CV */
  return cv;
}

/* Define a function to parse a set of keywords */
KeywordData* parseKeywords(const char* raw_keywords) {
  /* Allocate memory for the KeywordData struct */
  KeywordData* data = malloc(sizeof(KeywordData));
  if(data == NULL) {
    perror("Failed to allocate memory for KeywordData");
    exit(EXIT_FAILURE);
  }

  /* Tokenize the raw keywords string into separate keywords */
  char* keywords[MAX_KEYWORDS] = {NULL};
  char* keyword = strtok(raw_keywords, ",");
  int num_keywords = 0;
  while(keyword != NULL && num_keywords < MAX_KEYWORDS) {
    keywords[num_keywords++] = strdup(keyword);
    keyword = strtok(NULL, ",");
  }

  /* Copy the tokenized data into the KeywordData struct */
  data->keywords = keywords;
  data->num_keywords = num_keywords;
  data->keyword_counts = calloc(num_keywords, sizeof(int));
  if(data->keyword_counts == NULL) {
    perror("Failed to allocate memory for KeywordData keyword counts");
    exit(EXIT_FAILURE);
  }

  /* Return the parsed KeywordData */
  return data;
}

/* Define a thread function to parse a CV and count keyword occurrences */
void* parseCVThread(void* data) {
  /* Extract the parsed keyword data from the passed-in argument */
  KeywordData* keyword_data = (KeywordData*) data;

  /* Loop through the CV array, parsing each CV and updating the keyword counts */
  while(1) {
    /* Acquire the mutex lock before accessing the CV array */
    pthread_mutex_lock(&cvs_mut);

    /* If there are no more CVs to parse, exit the thread */
    if(num_threads == 0) {
      pthread_mutex_unlock(&cvs_mut);
      break;
    }

    /* Get the next CV to parse from the global CV array */
    CV* cv = cvs[--num_threads];
    cvs[num_threads] = NULL;

    /* Release the mutex lock after accessing the CV array */
    pthread_mutex_unlock(&cvs_mut);

    /* Loop through the CV fields, counting keyword occurrences */
    char* fields[] = {cv->name, cv->email, cv->summary, cv->education, cv->work_experience, cv->skills, cv->projects};
    int i;
    for(i = 0; i < 7; i++) {
      if(fields[i] == NULL) continue;
      char* token = strtok(fields[i], " ");
      while(token != NULL) {
        int j;
        for(j = 0; j < keyword_data->num_keywords; j++) {
          if(strcmp(token, keyword_data->keywords[j]) == 0) {
            keyword_data->keyword_counts[j]++;
            break;
          }
        }
        token = strtok(NULL, " ");
      }
    }
  }

  /* Exit the thread */
  pthread_exit(NULL);
}

/* Define the main function */
int main(int argc, char* argv[]) {
  /* Check that the correct number of command-line arguments were provided */
  if(argc != 3) {
    fprintf(stderr, "Usage: %s <CV file> <keyword file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  /* Open the CV file and read its contents into the global CV array */
  FILE* cv_file = fopen(argv[1], "r");
  if(cv_file == NULL) {
    perror("Failed to open CV file");
    return EXIT_FAILURE;
  }
  char raw_cv[MAX_CV_LENGTH] = {'\0'};
  while(fgets(raw_cv, MAX_CV_LENGTH, cv_file) != NULL) {
    /* Acquire the mutex lock before modifying the global CV array */
    pthread_mutex_lock(&cvs_mut);

    /* Allocate memory for the new CV and parse it */
    cvs[num_threads++] = parseCV(raw_cv);

    /* Create a new thread to parse the new CV and count keyword occurrences */
    if(num_threads <= MAX_THREADS) {
      KeywordData* keyword_data = parseKeywords(argv[2]);
      pthread_create(&thread_ids[num_threads - 1], NULL, parseCVThread, keyword_data);
    }

    /* Release the mutex lock after modifying the global CV array */
    pthread_mutex_unlock(&cvs_mut);
  }
  fclose(cv_file);

  /* Wait for all worker threads to finish */
  int i;
  for(i = 0; i < num_threads; i++) {
    pthread_join(thread_ids[i], NULL);
  }

  /* Print the final keyword counts */
  KeywordData* keyword_data = parseKeywords(argv[2]);
  printf("Keyword counts:\n");
  for(i = 0; i < keyword_data->num_keywords; i++) {
    printf("- %s: %d\n", keyword_data->keywords[i], keyword_data->keyword_counts[i]);
  }

  /* Free all allocated memory */
  for(i = 0; i < num_threads; i++) {
    free(cvs[i]);
  }
  pthread_mutex_destroy(&cvs_mut);
  free(keyword_data->keywords);
  free(keyword_data->keyword_counts);
  free(keyword_data);

  /* Exit the program */
  return EXIT_SUCCESS;
}