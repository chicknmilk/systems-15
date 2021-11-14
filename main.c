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
  char **args = calloc(4, sizeof(char *));

  strsep(&line, " ");
  int i = 0;
  for (i = 0; i < 4; i++) {
    args[i] = strsep(&line, " ");
    if (args[i] == NULL) {
      break;
    }
  }

  return args;
}