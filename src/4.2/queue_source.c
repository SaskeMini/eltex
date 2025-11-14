#pragma once

struct Queue *AddItem (int priority, struct Queue* first){
    struct Queue* item = malloc(sizeof(struct Queue));
    item->priority = priority;
    item->next = NULL;

    if (first == NULL) return item;

    if (priority > first->priority){
        item->next = first;
        return item;
    }
    if (first->next){
        if (priority > first->next->priority){
            item->next = first->next;
            first->next = item;
            return first;
        }
    }
    else{
        first->next = item;
        return first;
    }

    struct Queue* tmp = first;

    if(tmp->next->next == NULL){
        tmp->next->next = item;
        return first;
    }
    char check = 1;
    while(tmp->next->next != NULL){
        if (priority > tmp->next->next->priority){
            item->next = tmp->next->next;
            tmp->next->next = item;
            check = 0;
            break;
        }
        else tmp = tmp->next;
    }
    if (check){
        tmp->next->next = item;
    }
    return first;
}

struct Queue *ExtractionItem (int priority, struct Queue* first, int check_operation){
    struct Queue* tmp = first;
    char check = 1, check_to_op_3 = 1;
    if (first->priority == priority || check_operation == 1) {
        printf("Extraction of element with priority %d is completed\n", first->priority);
        struct Queue *item = first;
        first = first->next;
        free(item);
        return first;
    }
    if (first->priority == priority && check_operation == 2){
        printf("Extraction of element with priority %d is completed\n", priority);
        struct Queue *item = first;
        first = first->next;
        free(item);
        return first;
    }
    // if (first->priority >= priority && check_operation == 3){
    //     printf("Extraction of element with priority %d is completed\n", first->priority);
    //     struct Queue *item = first;
    //     first = first->next;
    //     free(item);
    //     return first;
    // }
    while(tmp->next != NULL){
        if (priority == tmp->next->priority && check_operation == 2){
            printf("Extraction of element with priority %d is completed\n", priority);
            struct Queue *item = tmp->next;
            tmp->next = tmp->next->next;
            free(item);
            check = 0;
            break;
        }
        else if (priority <= tmp->next->priority && check_operation == 3){
            if (tmp->next->next){
                if (priority <= tmp->next->next->priority){
                    tmp = tmp->next;
                }
                else{
                    printf("Extraction of element with priority %d is completed\n", tmp->next->priority);
                    struct Queue *item = tmp->next;
                    tmp->next = tmp->next->next;
                    free(item);
                    check = 0;
                    check_to_op_3 = 0;
                    break;
                }
            }
            else{
                printf("Extraction of element with priority %d is completed\n", tmp->next->priority);
                struct Queue *item = tmp->next;
                tmp->next = tmp->next->next;
                free(item);
                check = 0;
                check_to_op_3 = 0;
                break;
            }
        }
        else tmp = tmp->next;
    }
    tmp = first;
    if (check_to_op_3 && tmp->priority >= priority){
        printf("Extraction of element with priority %d is completed\n", tmp->priority);
        struct Queue *item = tmp->next;
        tmp->next = tmp->next->next;
        free(item);
        check = 0;
        check_to_op_3 = 0;
    }
    else if (check){
        printf("No elements with this priority.\n");
    }
    return first;
}

void deleteList(struct Queue* first) {
    for(struct Queue* item = first; item != NULL; item = first) {
        first = first->next;
        free(item);
    }
}

void printList(struct Queue* first) {
    for(struct Queue* item = first; item != NULL; item = item->next) {
        printf("%d ", item->priority);
    }
    printf("\n");
}