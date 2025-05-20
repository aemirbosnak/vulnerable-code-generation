//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256
#define MAX_ATTR_VALS 10
#define MAX_RULES 10

typedef struct {
  char *attr;
  char *val;
} attr_val_t;

typedef struct {
  attr_val_t *attrs;
  int num_attrs;
  int class;
} example_t;

typedef struct {
  attr_val_t *attrs;
  int num_attrs;
  int class;
  double entropy;
} rule_t;

int num_examples;
example_t *examples;
int num_rules;
rule_t *rules;

void read_examples() {
  FILE *fp = fopen("examples.txt", "r");
  if (fp == NULL) {
    perror("Error opening examples file");
    exit(1);
  }

  fscanf(fp, "%d", &num_examples);
  examples = malloc(num_examples * sizeof(example_t));
  for (int i = 0; i < num_examples; i++) {
    examples[i].attrs = malloc(MAX_ATTR_VALS * sizeof(attr_val_t));
    fscanf(fp, "%d", &examples[i].num_attrs);
    for (int j = 0; j < examples[i].num_attrs; j++) {
      examples[i].attrs[j].attr = malloc(MAX_STR_LEN * sizeof(char));
      examples[i].attrs[j].val = malloc(MAX_STR_LEN * sizeof(char));
      fscanf(fp, "%s %s", examples[i].attrs[j].attr, examples[i].attrs[j].val);
    }
    fscanf(fp, "%d", &examples[i].class);
  }

  fclose(fp);
}

void read_rules() {
  FILE *fp = fopen("rules.txt", "r");
  if (fp == NULL) {
    perror("Error opening rules file");
    exit(1);
  }

  fscanf(fp, "%d", &num_rules);
  rules = malloc(num_rules * sizeof(rule_t));
  for (int i = 0; i < num_rules; i++) {
    rules[i].attrs = malloc(MAX_ATTR_VALS * sizeof(attr_val_t));
    fscanf(fp, "%d", &rules[i].num_attrs);
    for (int j = 0; j < rules[i].num_attrs; j++) {
      rules[i].attrs[j].attr = malloc(MAX_STR_LEN * sizeof(char));
      rules[i].attrs[j].val = malloc(MAX_STR_LEN * sizeof(char));
      fscanf(fp, "%s %s", rules[i].attrs[j].attr, rules[i].attrs[j].val);
    }
    fscanf(fp, "%d", &rules[i].class);
  }

  fclose(fp);
}

double entropy(int *counts, int num_classes) {
  double entropy = 0;
  for (int i = 0; i < num_classes; i++) {
    if (counts[i] > 0) {
      entropy -= counts[i] * log2(counts[i]);
    }
  }
  return entropy;
}

double info_gain(example_t *examples, int num_examples, attr_val_t *attr_val, int num_classes) {
  int counts[num_classes];
  for (int i = 0; i < num_classes; i++) {
    counts[i] = 0;
  }

  for (int i = 0; i < num_examples; i++) {
    for (int j = 0; j < examples[i].num_attrs; j++) {
      if (strcmp(examples[i].attrs[j].attr, attr_val->attr) == 0 &&
          strcmp(examples[i].attrs[j].val, attr_val->val) == 0) {
        counts[examples[i].class]++;
        break;
      }
    }
  }

  double entropy_before = entropy(counts, num_classes);

  int counts_after[num_classes][num_classes];
  for (int i = 0; i < num_classes; i++) {
    for (int j = 0; j < num_classes; j++) {
      counts_after[i][j] = 0;
    }
  }

  for (int i = 0; i < num_examples; i++) {
    int class_before = examples[i].class;
    for (int j = 0; j < examples[i].num_attrs; j++) {
      if (strcmp(examples[i].attrs[j].attr, attr_val->attr) == 0 &&
          strcmp(examples[i].attrs[j].val, attr_val->val) == 0) {
        counts_after[class_before][examples[i].class]++;
        break;
      }
    }
  }

  double entropy_after = 0;
  for (int i = 0; i < num_classes; i++) {
    double entropy_after_i = 0;
    for (int j = 0; j < num_classes; j++) {
      if (counts_after[i][j] > 0) {
        entropy_after_i -= counts_after[i][j] * log2(counts_after[i][j]);
      }
    }
    entropy_after += entropy_after_i * counts[i] / num_examples;
  }

  return entropy_before - entropy_after;
}

void find_best_rule() {
  double best_info_gain = -1;
  rule_t best_rule;

  for (int i = 0; i < num_examples; i++) {
    for (int j = 0; j < examples[i].num_attrs; j++) {
      double info_gain_ij = info_gain(examples, num_examples, &examples[i].attrs[j], 2);
      if (info_gain_ij > best_info_gain) {
        best_info_gain = info_gain_ij;
        best_rule.attrs = &examples[i].attrs[j];
        best_rule.num_attrs = 1;
        best_rule.class = examples[i].class;
      }
    }
  }

  rules[num_rules] = best_rule;
  num_rules++;
}

void classify_example(example_t *example, rule_t *rules, int num_rules) {
  for (int i = 0; i < num_rules; i++) {
    int matches = 1;
    for (int j = 0; j < rules[i].num_attrs; j++) {
      int attr_found = 0;
      for (int k = 0; k < example->num_attrs; k++) {
        if (strcmp(example->attrs[k].attr, rules[i].attrs[j].attr) == 0 &&
            strcmp(example->attrs[k].val, rules[i].attrs[j].val) == 0) {
          attr_found = 1;
          break;
        }
      }
      if (!attr_found) {
        matches = 0;
        break;
      }
    }

    if (matches) {
      example->class = rules[i].class;
      break;
    }
  }
}

int main() {
  read_examples();
  read_rules();

  while (num_rules < MAX_RULES) {
    find_best_rule();
  }

  example_t example;
  example.attrs = malloc(MAX_ATTR_VALS * sizeof(attr_val_t));
  example.num_attrs = 2;
  example.attrs[0].attr = "outlook";
  example.attrs[0].val = "overcast";
  example.attrs[1].attr = "temperature";
  example.attrs[1].val = "cool";

  classify_example(&example, rules, num_rules);

  printf("Predicted class: %d\n", example.class);

  return 0;
}