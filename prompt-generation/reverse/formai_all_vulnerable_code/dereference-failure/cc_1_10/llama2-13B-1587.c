//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: protected
#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void html_beautify(char *input) {
  char *output = malloc(strlen(input) * 2);
  int indent = 0;
  int current_tag = 0;
  char tag_open[] = "<";
  char tag_close[] = "</";

  // Iterate through the input string
  for (int i = 0; i < strlen(input); i++) {
    // Check if the current character is a tag opening bracket
    if (input[i] == '<') {
      // If it is, increment the current tag counter
      current_tag++;

      // Check if the current tag is a self-closing tag
      if (input[i + 1] == '/') {
        // If it is, handle the self-closing tag
        i++;
        if (current_tag > 1) {
          output[indent] = ' ';
          for (int j = 0; j < current_tag; j++) {
            output[indent + j] = ' ';
          }
          output[indent + current_tag] = '>';
          indent += current_tag;
        } else {
          output[indent] = '>';
        }
        current_tag = 0;
      } else {
        // If it's not a self-closing tag, handle the start of a new tag
        output[indent] = ' ';
        for (int j = 0; j < current_tag; j++) {
          output[indent + j] = ' ';
        }
        output[indent + current_tag] = input[i + 1];
        current_tag++;
        i++;
      }
    } else if (input[i] == '>') {
      // If the current character is a tag closing bracket, handle it
      if (current_tag > 0) {
        output[indent] = ' ';
        for (int j = 0; j < current_tag; j++) {
          output[indent + j] = ' ';
        }
        output[indent + current_tag] = '>';
        current_tag = 0;
      }
    } else if (input[i] == ' ') {
      // If the current character is a space, handle it
      if (current_tag > 0) {
        output[indent] = ' ';
        for (int j = 0; j < current_tag; j++) {
          output[indent + j] = ' ';
        }
      }
    } else {
      // If the current character is anything else, add it to the output
      output[indent] = input[i];
    }
    indent++;
  }

  // Handle the end of the input string
  if (current_tag > 0) {
    output[indent] = '>';
  }

  // Replace the input string with the beautified output
  strcpy(input, output);
}

int main() {
  char input[] = "<html><body><p>This is a <b>beautiful</b> paragraph.</p><p>But it's not <i>really</i> beautiful, is it?</p></body></html>";
  html_beautify(input);
  return 0;
}