#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media, int* length);
void edit(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media, int* length);
void del(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media, int* length);
void free_func(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media);
void del_enter(char* mass);
char check_phone(char* phone);
char check_email(char* email);

#define SIZE_MASS 1000
#include "source.c"