#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    int id;
    char name[100], surname[100], second_name[100], work[100], phone_number[100], email[100], social_media[100];
    struct Contact* next;
    struct Contact* prev;
 }Contact;
typedef struct Info {
    char name[100], surname[100], second_name[100], work[100], phone_number[100], email[100], social_media[100];
} Info;

struct Contact *AddItem (int id, struct Contact* head, Info* all);
struct Contact *EditItem (int id, struct Contact* head, Info* all);
struct Contact *DeleteItem (int id, struct Contact* head);
void del_enter(char* mass);
char check_phone(char* phone);
char check_email(char* email);
void printList(struct Contact* head);