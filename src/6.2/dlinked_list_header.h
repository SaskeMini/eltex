#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct Contact {
    int id;
    char name[100], surname[100], second_name[100], work[100], phone_number[100], email[100], social_media[100];
    struct Contact* next;
    struct Contact* prev;
 }Contact;

#define SIZE_MASS 1000

typedef Contact* (*add)(struct Contact*, int*);
typedef Contact* (*del)(struct Contact*, int*);
typedef Contact* (*edit)(struct Contact*, int*);
typedef void (*deleteList)(struct Contact*);