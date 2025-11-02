#include "header.h"

int main(){
    char **name, **surname, **second_name, **work, **phone_number, **email, **social_media;
    name = malloc(sizeof(char*) * SIZE_MASS);
    surname = malloc(sizeof(char*) * SIZE_MASS);
    second_name = malloc(sizeof(char*) * SIZE_MASS);
    work = malloc(sizeof(char*) * SIZE_MASS);
    phone_number = malloc(sizeof(char*) * SIZE_MASS);
    email = malloc(sizeof(char*) * SIZE_MASS);
    social_media = malloc(sizeof(char*) * SIZE_MASS);
    for (int i = 0; i < SIZE_MASS; i++){
        name[i] = malloc(sizeof(char) * 100);
        surname[i] = malloc(sizeof(char) * 100);
        second_name[i] = malloc(sizeof(char) * 100);
        work[i] = malloc(sizeof(char) * 100);
        phone_number[i] = malloc(sizeof(char) * 100);
        email[i] = malloc(sizeof(char) * 100);
        social_media[i] = malloc(sizeof(char) * 100);
    }
    int length = 0;
    int check_play = 1;
    char sym;
    printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
    while(check_play){
        while (!sym){
            scanf("%c", &sym);
        }
        switch (sym)
        {
        case '1':
            add(name, surname, second_name, work, phone_number, email, social_media, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '2':
            edit(name, surname, second_name, work, phone_number, email, social_media, &length);
            sym = 0;
            printf("What do you want to do?\n(enter 1 to add record, 2 to edit record, 3 to delete record, 4 to end the programm)\n");
            scanf("%c", &sym);
            while (!sym){
                printf("Incorrect action!\n");
                scanf("%c", &sym);
            }
            break;
        case '3':
            del(name, surname, second_name, work, phone_number, email, social_media, &length);
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
    free_func(name, surname, second_name, work, phone_number, email, social_media);
    name = NULL;
    surname = NULL;
    second_name = NULL;
    work = NULL;
    phone_number = NULL;
    email = NULL;
    social_media = NULL;
    return 0;
}