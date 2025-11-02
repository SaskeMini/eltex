#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

char check_rights(char rights[]);
void convert_to_bin(char rights[]);
void print_rights(char rights[]);
void print_rights_to_argv(char rights[]);

#include "source.c"