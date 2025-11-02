#pragma once
void print_rights(char rights[]){
    printf("Symbolic:\n");
    printf("-");
    for (int i = 1; i < 4; i++){
        if (rights[i] == '7'){
            printf("rwx");
        }
        else if (rights[i] == '6'){
            printf("rw-");
        }
        else if (rights[i] == '5'){
            printf("r-x");
        }
        else if (rights[i] == '4'){
            printf("r--");
        }
        else if (rights[i] == '3'){
            printf("-wx");
        }
        else if (rights[i] == '2'){
            printf("-w-");
        }
        else if (rights[i] == '1'){
            printf("--x");
        }
        else if (rights[i] == '0'){
            printf("---");
        }
    }
    printf("\n");
    printf("Numeric:\n");
    printf("-%c%c%c\n", rights[1], rights[2], rights[3]);
    printf("Binary:\n");
    convert_to_bin(rights);
}

void print_rights_to_argv(char rights[]){
    printf("Symbolic:\n");
    printf("%s\n", rights);
    printf("Numeric:\n");
    printf("-");
    char check_r = 0, check_w = 0, check_x = 0;
    int check_three = 0;
    for (size_t i = 1; i < strlen(rights); i++){
        if (rights[i] == 'r'){
            check_r = 1;
        }
        if (rights[i] == 'w'){
            check_w = 1;
        }
        if (rights[i] == 'x'){
            check_x = 1;
        }
        check_three++;
        if (check_three == 3){
            check_three = 0;
            int res = 0;
            check_r ? res += 4 : res;
            check_w ? res += 2 : res;
            check_x ? res += 1 : res;
            check_r = 0;
            check_w = 0;
            check_x = 0;
            printf("%d", res);
        }
    }
    if (check_three != 0){
        int res = 0;
        check_r ? res += 4 : res;
        check_w ? res += 2 : res;
        check_x ? res += 1 : res;
        printf("%d", res);
    }
    printf("\n");
    printf("Binary:\n");
    convert_to_bin(rights);
}

char check_rights(char rights[]){
    char res = 1, temp_res = 1;
    if (rights[0] != '-'){
        res = 0;
    }
    else if (strlen(rights) == 1){
        res = 0;
    }
    else if (strlen(rights) > 10){
        res = 0;
    }
    else{
        if (strlen(rights) > 4){
            temp_res = 0;
        }
        for (size_t i = 1; i < strlen(rights) && temp_res; i++){
            if (rights[i] > 55 || rights[i] < 48){
                temp_res = 0;
                break;
            }
        }
        if (!temp_res){
            for (size_t i = 1; i < strlen(rights); i++){
                if (rights[i] != 'r' && rights[i] != 'w' && rights[i] != 'x' && !(rights[i] == '-' && i > 1)){
                    res = 0;
                    break;
                }
            }
        }
    }
    return res;
}

void convert_to_bin(char rights[]){
    if (rights[1] <= 55 && rights[1] >= 48){
        for (size_t i = 1; i < strlen(rights); i++){
            unsigned int num_right = rights[i] - 48;
            int res[3];
            res[0] = num_right % 2;
            num_right = num_right / 2;
            res[1] = num_right % 2;
            num_right = num_right / 2;
            res[2] = num_right % 2;
            printf("%d%d%d ", res[2], res[1], res[0]);
        }
        printf("\n");
    }
    else{
        char check_r = 0, check_w = 0, check_x = 0;
        int check_three = 0;
        for (size_t i = 1; i < strlen(rights); i++){
            if (rights[i] == 'r'){
                check_r = 1;
            }
            if (rights[i] == 'w'){
                check_w = 1;
            }
            if (rights[i] == 'x'){
                check_x = 1;
            }
            check_three++;
            if (check_three == 3){
                check_three = 0;
                check_r ? printf("1") : printf("0");
                check_w ? printf("1") : printf("0");
                check_x ? printf("1") : printf("0");
                check_r = 0;
                check_w = 0;
                check_x = 0;
                printf(" ");
            }
        }
        if (check_three != 0){
            check_r ? printf("1") : printf("0");
            check_w ? printf("1") : printf("0");
            check_x ? printf("1") : printf("0");
        }
        printf("\n");
    }
}