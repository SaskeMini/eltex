#include "dlinked_list_header.h"

int main(){
    struct Contact *head = NULL;
    int length = 0;
    int check_play = 1;
    char sym = 0;
    printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
    while(check_play){
        while (!sym){
            scanf("%c", &sym);
        }
        switch (sym)
        {
        case '1':
            head = add(head, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '2':
            head = edit(head, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '3':
            head = del(head, &length);
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
    deleteList(head);
    return 0;
}

