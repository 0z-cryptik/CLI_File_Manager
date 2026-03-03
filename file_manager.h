#ifndef file_manager_h
#define file_manager_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATH_LEN 350

// changes '\\' to '/' for windows computers
void change_backslash(char *path);

// removes character from str
void remove_this_char(char *str, char character);

// strips away '"', '\n' and changes '\' to '/'
void process_path(char *path);

// performs the copy operation
void copy_handler(const char *path, const char *dest);

// performs the copy operation
void move_handler(const char *path, const char *dest);

// performs the copy operation
void rename_handler(const char *path, const char *new_name);

// performs the copy operation
void delete_handler(const char *path);
#endif