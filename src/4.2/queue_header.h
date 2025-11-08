#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    int priority;
    struct Queue* next;
 }Queue;

struct Queue *AddItem (int priority, struct Queue* first);
struct Queue *ExtractionItem (int priority, struct Queue* first, int check_operation);
void deleteList(struct Queue* first);
void printList(struct Queue* first);

#include "queue_source.c"