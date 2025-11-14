#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Info {
    char name[100], surname[100], second_name[100], work[100], phone_number[100], email[100], social_media[100];
} Info;

typedef struct Contact {
    int id;
    char name[100], surname[100], second_name[100], work[100], phone_number[100], email[100], social_media[100];
    struct Contact* next;
    struct Contact* prev;
 }Contact;

struct Contact *AddItem (int id, struct Contact* head, Info* all);
struct Contact *EditItem (int id, struct Contact* head, Info* all);
struct Contact *DeleteItem (int id, struct Contact* head);
struct Contact *SortItems (struct Contact* head);
void deleteList(struct Contact* head);
void printList(struct Contact* head);
struct Contact *add(struct Contact *head, int* length);
struct Contact *edit(struct Contact *head, int* length);
struct Contact *del(struct Contact *head, int* length);
void del_enter(char* mass);
char check_phone(char* phone);
char check_email(char* email);

#define SIZE_MASS 1000

#include "dlinked_list_funcs.c"