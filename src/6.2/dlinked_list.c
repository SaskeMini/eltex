#include "dlinked_list_header.h"

int main(){
    struct Contact *head = NULL;
    int length = 0;
    int check_play = 1;
    char sym = 0;
    void *handle1;
    handle1 = dlopen("din_lib.so", RTLD_LAZY);
    if (!handle1){
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(1);
    }
    add addd;
    edit eddit;
    del dell;
    deleteList deleteListt;
    addd = (add) dlsym(handle1, "add");
    eddit = (edit) dlsym(handle1, "edit");
    dell = (del) dlsym(handle1, "del");
    deleteListt = (deleteList) dlsym(handle1, "deleteList");
    if (!addd || !eddit || !dell || !deleteListt){
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle1);
        exit(1);
    }
    printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
    while(check_play){
        while (!sym){
            scanf("%c", &sym);
        }
        switch (sym)
        {
        case '1':
            head = addd(head, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '2':
            head = eddit(head, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '3':
            head = dell(head, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '4':
            check_play = 0;
            break;
        default:
            printf("Incorrect action!\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        }
    }
    deleteListt(head);
    return 0;
}

