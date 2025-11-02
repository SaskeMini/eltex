#pragma once
void free_func(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media){
    for (int i = 0; i < SIZE_MASS; i++){
        free(name[i]);
        free(surname[i]);
        free(second_name[i]);
        free(work[i]);
        free(phone_number[i]);
        free(email[i]);
        free(social_media[i]);
    }
    free(name);
    free(surname);
    free(second_name);
    free(work);
    free(phone_number);
    free(email);
    free(social_media);
}

void add(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media, int* length){
    char* input = malloc(sizeof(char) * 100);

    printf("Enter name:\n");
    getchar();
    fgets(input, sizeof(input), stdin);
    while (input[0] == '\0' || input[0] == '\n'){
        printf("Empty name! Please, enter the correct name.\n");
        fgets(input, sizeof(input), stdin);
    }
    del_enter(input);
    strcpy(name[*length], input);
    memset(input, 0, 100 * sizeof(char));

    printf("Enter surname:\n");
    fgets(input, sizeof(input), stdin);
    while (input[0] == '\0' || input[0] == '\n'){
        printf("Empty surname! Please, enter the correct surname.\n");
        fgets(input, sizeof(input), stdin);
    }
    del_enter(input);
    strcpy(surname[*length], input);
    memset(input, 0, 100 * sizeof(char));

    printf("Enter second name (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(second_name[*length], input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter work (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(work[*length], input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter phone number (you can skip this point, press enter):\n");
    printf("NO + IN PHONE NUMBER!!!!!!!!!!!!!!!\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input);
        if (check_phone(input)){
            strcpy(phone_number[*length], input);
        }
        else{
            printf("Incorrect phone number, please, edit it later...\n");
        }
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter email (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input); 
        if (check_email(input)){
            strcpy(email[*length], input);
        }
        else{
            printf("Incorrect email, please, edit it later...\n");
        }
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter social media (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(social_media[*length], input); }
    memset(input, 0, 100 * sizeof(char));

    free(input);
    input = NULL;

    *length = *length + 1;
}

void edit(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media, int* length){
    if (*length == 0){
        printf("Nothing to edit\n");
        getchar();
        return;
    }
    printf("What record do you want to edit?\n");
    for (int i = 0; i < *length; i++){
        printf("Number: %d, name: %s, surname: %s, second name: %s, work: %s, phone number: %s, email: %s, social media: %s\n",
             i + 1, name[i], surname[i], second_name[i][0] != '\0' ? second_name[i] : "-", work[i][0] != '\0' ? work[i] : "-", phone_number[i][0] != '\0' ? phone_number[i] : "-",
              email[i][0] != '\0' ? email[i] : "-", social_media[i][0] != '\0' ? social_media[i] : "-");
    }
    printf("ENTER THE NUMBER:\n");
    int n = 0;
    scanf("%d", &n);
    while (n <= 0 || n > *length){
        printf("Incorrect number\n");
        printf("ENTER THE NUMBER:\n");
        scanf("%d", &n);
    }
    getchar();
    n--;

    char* input = malloc(sizeof(char) * 100);

    printf("Enter name (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(name[n], input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter surname (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(surname[n], input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter second name (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(second_name[n], input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter work (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(work[n], input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter phone number (you can skip this point, press enter):\n");
    printf("NO + IN PHONE NUMBER!!!!!!!!!!!!!!!\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input);
        if (check_phone(input)){
            strcpy(phone_number[*length], input);
        }
        else{
            printf("Incorrect phone number, please, edit it later...\n");
        }
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter email (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input); 
        if (check_email(input)){
            strcpy(email[*length], input);
        }
        else{
            printf("Incorrect email, please, edit it later...\n");
        }
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter social media (you can skip this point, press enter):\n");
    fgets(input, sizeof(input), stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(social_media[n], input); }
    memset(input, 0, 100 * sizeof(char));

    free(input);
    input = NULL;
}

void del(char** name, char** surname, char** second_name, char** work, char** phone_number, char** email, char** social_media, int* length){
    if (*length == 0){
        printf("Nothing to delete\n");
        getchar();
        return;
    }
    printf("What record do you want to delete?\n");
    for (int i = 0; i < *length; i++){
        printf("Number: %d, name: %s, surname: %s, second name: %s, work: %s, phone number: %s, email: %s, social media: %s\n",
             i + 1, name[i], surname[i], second_name[i][0] != '\0' ? second_name[i] : "-", work[i][0] != '\0' ? work[i] : "-", phone_number[i][0] != '\0' ? phone_number[i] : "-",
              email[i][0] != '\0' ? email[i] : "-", social_media[i][0] != '\0' ? social_media[i] : "-");
    }
    printf("ENTER THE NUMBER (press 0 to cancel):\n");
    int n = 0;
    scanf("%d", &n);
    while (n < 0 || n > *length){
        printf("Incorrect number\n");
        printf("ENTER THE NUMBER:\n");
        scanf("%d", &n);
    }
    if (n == 0){
        getchar();
        printf("OK\n");
        return;
    }
    getchar();
    n--;
    for (int i = n; i < *length - 1; i++){
        strcpy(name[i], name[i + 1]);
        strcpy(surname[i], surname[i + 1]);
        strcpy(second_name[i], second_name[i + 1]);
        strcpy(work[i], work[i + 1]);
        strcpy(phone_number[i], phone_number[i + 1]);
        strcpy(email[i], email[i + 1]);
        strcpy(social_media[i], social_media[i + 1]);
    }
    *length = *length - 1;
    printf("*DELETE COMPLETED*\n");
}

void del_enter(char* mass){
    char* res = strchr(mass, '\n');
    mass[res - mass] = '\0';
}

char check_phone(char* phone){
    char res = 1;
    for (size_t i = 0; i < strlen(phone); i++){
        if (phone[i] > 57 || phone[i] < 48){
            res = 0;
            break;
        }
    }
    return res;
}

char check_email(char* email){
    char res = 0;
    for (size_t i = 0; i < strlen(email); i++){
        if (email[i] == '@' && i != 0 && i != strlen(email) - 1){
            res = 1;
            break;
        }
    }
    return res;
}