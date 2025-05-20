//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct resume_data {
  char *name;
  char *email;
  char *phone;
  char *skills[10];
  int num_skills;
} resume_data;

typedef struct token {
  char *value;
  int type;
} token;

int is_delimiter(char c) {
  return isspace(c) || c == ',' || c == ';';
}

token *tokenize(char *str) {
  token *tokens = malloc(sizeof(token) * MAX_TOKENS);
  int num_tokens = 0;

  char *start = str;
  char *end = str;
  while (*end != '\0') {
    if (is_delimiter(*end)) {
      if (start != end) {
        tokens[num_tokens].value = strndup(start, end - start);
        tokens[num_tokens].type = 0;
        num_tokens++;
      }

      start = end + 1;
    }
    end++;
  }

  if (start != end) {
    tokens[num_tokens].value = strndup(start, end - start);
    tokens[num_tokens].type = 0;
    num_tokens++;
  }

  return tokens;
}

void free_tokens(token *tokens, int num_tokens) {
  for (int i = 0; i < num_tokens; i++) {
    free(tokens[i].value);
  }
  free(tokens);
}

resume_data *parse_resume(char *str) {
  token *tokens = tokenize(str);
  int num_tokens = 0;

  while (tokens[num_tokens].type != 0) {
    num_tokens++;
  }

  resume_data *data = malloc(sizeof(resume_data));
  data->name = NULL;
  data->email = NULL;
  data->phone = NULL;
  data->num_skills = 0;

  for (int i = 0; i < num_tokens; i++) {
    if (strcmp(tokens[i].value, "Name:") == 0) {
      data->name = strdup(tokens[i + 1].value);
    } else if (strcmp(tokens[i].value, "Email:") == 0) {
      data->email = strdup(tokens[i + 1].value);
    } else if (strcmp(tokens[i].value, "Phone:") == 0) {
      data->phone = strdup(tokens[i + 1].value);
    } else if (strcmp(tokens[i].value, "Skills:") == 0) {
      for (int j = i + 1; j < num_tokens; j++) {
        if (is_delimiter(tokens[j].value[0])) {
          break;
        }
        data->skills[data->num_skills++] = strdup(tokens[j].value);
      }
    }
  }

  free_tokens(tokens, num_tokens);
  return data;
}

void free_resume_data(resume_data *data) {
  free(data->name);
  free(data->email);
  free(data->phone);
  for (int i = 0; i < data->num_skills; i++) {
    free(data->skills[i]);
  }
  free(data);
}

int main() {
  char *resume_str =
    "Name: John Doe\n"
    "Email: john.doe@example.com\n"
    "Phone: 555-555-5555\n"
    "Skills: C, C++, Java, Python, JavaScript";

  resume_data *data = parse_resume(resume_str);

  printf("Name: %s\n", data->name);
  printf("Email: %s\n", data->email);
  printf("Phone: %s\n", data->phone);
  printf("Skills: ");
  for (int i = 0; i < data->num_skills; i++) {
    printf("%s ", data->skills[i]);
  }
  printf("\n");

  free_resume_data(data);

  return 0;
}