//Gemma-7B DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ firewall_size 1024

typedef struct firewall_rule {
  char *pattern;
  int action;
  struct firewall_rule *next;
} firewall_rule;

firewall_rule *firewall_rule_insert(firewall_rule *head, char *pattern, int action)
{
  firewall_rule *new_rule = malloc(sizeof(firewall_rule));
  new_rule->pattern = strdup(pattern);
  new_rule->action = action;
  new_rule->next = NULL;

  if (head == NULL)
  {
    head = new_rule;
  }
  else
  {
    head->next = new_rule;
  }

  return head;
}

int firewall_rule_match(firewall_rule *head, char *pattern)
{
  for (firewall_rule *rule = head; rule; rule = rule->next)
  {
    if (strcmp(rule->pattern, pattern) == 0)
    {
      return rule->action;
    }
  }

  return -1;
}

int main()
{
  firewall_rule *firewall = NULL;

  firewall = firewall_rule_insert(firewall, "192.168.1.1", 1);
  firewall = firewall_rule_insert(firewall, "192.168.1.2", 2);
  firewall = firewall_rule_insert(firewall, "192.168.1.3", 3);

  int action = firewall_rule_match(firewall, "192.168.1.2");

  switch (action)
  {
    case 1:
      printf("Allow\n");
      break;
    case 2:
      printf("Deny\n");
      break;
    case 3:
      printf("Block\n");
      break;
    default:
      printf("Error\n");
      break;
  }

  return 0;
}