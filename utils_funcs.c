#include "file_manager.h"

void change_backslash(char *path) {
  for (int i = 0; i < strlen(path); i++) {
    if (path[i] == '\\') {
      path[i] = '/';
    }
  }
}

void remove_this_char(char *str, char character) {
  int i, j = 0;

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] != character) {
      str[j++] = str[i];
    }
  }

  str[j] = '\0';
}

void process_path(char *path) {
  change_backslash(path);
  remove_this_char(path, '"');
  remove_this_char(path, '\n');
}