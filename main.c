#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char *line);

int main() {
  char line[128] = "ls -a -l";
  char **args = parse_args(line);

  int i;

  execvp(args[0], args);

  return 0;
}

char ** parse_args(char *line) {
  char **args = calloc(5, sizeof(char *));

  args[0] = strsep(&line, " ");
  int i = 1;
  for (i = 1; i < 5; i++) {
    args[i] = strsep(&line, " ");
    if (args[i] == NULL) {
      break;
    }
  }

  return args;
}