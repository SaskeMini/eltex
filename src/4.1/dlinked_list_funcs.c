#pragma once
struct Contact *add(struct Contact *head, int* length){
    char* input = malloc(sizeof(char) * 100);
    Info new_info;
    printf("Enter name:\n");
    getchar();
    fgets(input, 100, stdin);
    while (input[0] == '\0' || input[0] == '\n'){
        printf("Empty name! Please, enter the correct name.\n");
        fgets(input, 100, stdin);
    }
    del_enter(input);
    strcpy(new_info.name, input);
    memset(input, 0, 100 * sizeof(char));

    printf("Enter surname:\n");
    fgets(input, 100, stdin);
    while (input[0] == '\0' || input[0] == '\n'){
        printf("Empty surname! Please, enter the correct surname.\n");
        fgets(input, 100, stdin);
    }
    del_enter(input);
    strcpy(new_info.surname, input);
    memset(input, 0, 100 * sizeof(char));

    printf("Enter second name (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.second_name, input); }
    else{strcpy(new_info.second_name, "\0"); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter work (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.work, input); }
    else{strcpy(new_info.work, "\0"); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter phone number (you can skip this point, press enter):\n");
    printf("NO + IN PHONE NUMBER!!!!!!!!!!!!!!!\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input);
        if (check_phone(input)){
            strcpy(new_info.phone_number, input);
        }
        else{
            printf("Incorrect phone number, please, edit it later...\n");
            strcpy(new_info.phone_number, "\0");
        }
    }
    else{
        strcpy(new_info.phone_number, "\0");
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter email (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input); 
        if (check_email(input)){
            strcpy(new_info.email, input);
        }
        else{
            printf("Incorrect email, please, edit it later...\n");
            strcpy(new_info.email, "\0");
        }
    }
    else{
        strcpy(new_info.email, "\0");
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter social media (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.social_media, input); }
    else {strcpy(new_info.social_media, "\0");}
    memset(input, 0, 100 * sizeof(char));

    free(input);
    input = NULL;
    *length = *length + 1;
    head = AddItem(*length, head, &new_info);
    return head;
}

struct Contact *edit(struct Contact *head, int* length){
    if (*length == 0){
        printf("Nothing to edit\n");
        getchar();
        return head;
    }
    Info new_info;
    printf("What record do you want to edit?\n");
    printList(head);
    printf("ENTER THE NUMBER:\n");
    int n = 0;
    scanf("%d", &n);
    while (n <= 0 || n > *length){
        printf("Incorrect number\n");
        printf("ENTER THE NUMBER:\n");
        scanf("%d", &n);
    }
    getchar();

    char* input = malloc(sizeof(char) * 100);

    printf("Enter name (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.name, input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter surname (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.surname, input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter second name (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.second_name, input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter work (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.work, input); }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter phone number (you can skip this point, press enter):\n");
    printf("NO + IN PHONE NUMBER!!!!!!!!!!!!!!!\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        del_enter(input);
        if (check_phone(input)){
            strcpy(new_info.phone_number, input);
        }
        else{
            printf("Incorrect phone number, please, edit it later...\n");
            strcpy(new_info.phone_number, "\0");
        }
    }
    else{
        strcpy(new_info.phone_number, "\0");
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter email (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { 
        //del_enter(input); 
        if (check_email(input)){
            strcpy(new_info.email, input);
        }
        else{
            printf("Incorrect email, please, edit it later...\n");
            strcpy(new_info.email, "\0");
        }
    }
    else{
        strcpy(new_info.email, "\0");
    }
    memset(input, 0, 100 * sizeof(char));

    printf("Enter social media (you can skip this point, press enter):\n");
    fgets(input, 100, stdin);
    if (!(input[0] == '\0' || input[0] == '\n')) { del_enter(input); strcpy(new_info.social_media, input); }\
    else {strcpy(new_info.social_media, "\0");}
    memset(input, 0, 100 * sizeof(char));
    free(input);
    input = NULL;
    head = EditItem(n, head, &new_info);
    return head;
}

struct Contact *del(struct Contact *head, int* length){
    if (*length == 0){
        printf("Nothing to delete\n");
        getchar();
        return head;
    }
    printf("What record do you want to delete?\n");
    printList(head);
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
        return head;
    }
    getchar();
    head = DeleteItem(n, head);
    *length = *length - 1;
    printf("*DELETE COMPLETED*\n");
    return head;
}

void del_enter(char* mass){
    mass[strlen(mass) - 1] = '\0';
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
        if (email[i] == 64 && i != 0 && ((i + 1) < strlen(email))){
            res = 1;
            break;
        }
    }
    return res;
}

struct Contact *AddItem (int id, struct Contact* head, Info* all){
    struct Contact* item = malloc(sizeof(struct Contact));
    item->id = id;
    strcpy(item->name, all->name);
    strcpy(item->surname, all->surname);
    strcpy(item->second_name, all->second_name);
    strcpy(item->work, all->work);
    strcpy(item->phone_number, all->phone_number);
    strcpy(item->email, all->email);
    strcpy(item->social_media, all->social_media);
    item->next = NULL;

    struct Contact* tmp = head;
    if (head == NULL) return item;

    if (id < head->id){
        item->next = head;
        head->prev = item;
        return item;
    }

    while(tmp->next != NULL){
        if (id < tmp->next->id){
            item->next = tmp->next;
            tmp->next = item;
            break;
        }
        else tmp = tmp->next;
    }
    tmp->next = item;
    item->prev = tmp;
    return head;
}

struct Contact *EditItem (int id, struct Contact* head, Info* all){
    if (id == head->id){
        struct Contact* item = malloc(sizeof(struct Contact));
        item->id = id;
        item->next = head->next;
        if(all->name[0] != '\0') { strcpy(item->name, all->name); }
        else {strcpy(item->name, head->name);}
        if(all->surname[0] != '\0') { strcpy(item->surname, all->surname); }
        else {strcpy(item->surname, head->surname);}
        if(all->second_name[0] != '\0') { strcpy(item->second_name, all->second_name); }
        else {strcpy(item->second_name, head->second_name);}
        if(all->work[0] != '\0') { strcpy(item->work, all->work); }
        else {strcpy(item->work, head->work);}
        if(all->phone_number[0] != '\0') { strcpy(item->phone_number, all->phone_number); }
        else {strcpy(item->phone_number, head->phone_number);}
        if(all->email[0] != '\0') { strcpy(item->email, all->email); }
        else {strcpy(item->email, head->email);}
        if(all->social_media[0] != '\0') { strcpy(item->social_media, all->social_media); }
        else {strcpy(item->social_media, head->social_media);}
        free(head);
        return item;
    }
    struct Contact* item = malloc(sizeof(struct Contact));
    item->id = id;
    struct Contact* tmp = head;
    while(tmp->next != NULL){
        if (id == tmp->id){
            if(all->name[0] != '\0') { strcpy(item->name, all->name); }
            else {strcpy(item->name, tmp->name);}
            if(all->surname[0] != '\0') { strcpy(item->surname, all->surname); }
            else {strcpy(item->surname, tmp->surname);}
            if(all->second_name[0] != '\0') { strcpy(item->second_name, all->second_name); }
            else {strcpy(item->second_name, tmp->second_name);}
            if(all->work[0] != '\0') { strcpy(item->work, all->work); }
            else {strcpy(item->work, tmp->work);}
            if(all->phone_number[0] != '\0') { strcpy(item->phone_number, all->phone_number); }
            else {strcpy(item->phone_number, tmp->phone_number);}
            if(all->email[0] != '\0') { strcpy(item->email, all->email); }
            else {strcpy(item->email, tmp->email);}
            if(all->social_media[0] != '\0') { strcpy(item->social_media, all->social_media); }
            else {strcpy(item->social_media, tmp->social_media);}
            if (tmp->prev->next){
                tmp->prev->next = item;
            }
            if (tmp->next->prev){
                tmp->next->prev = item;
            }
            item->next = tmp->next;
            item->prev = tmp->prev;
            free(tmp);
            break;
        }
        else tmp = tmp->next;
    }
    return head;
}

struct Contact *DeleteItem (int id, struct Contact* head){
    struct Contact* tmp = head;
    if (head->id == id) {
        struct Contact *item = head;
        head = head->next;
        free(item);
        tmp = head;
        while(tmp != NULL){
            tmp->id = tmp->id - 1;
            tmp = tmp->next;
        }
        return head;
    }
    while(tmp->next != NULL){
        if (id == tmp->next->id){
            struct Contact *item = tmp->next;
            tmp->next = tmp->next->next;
            tmp->next->prev = tmp;
            free(item);
            break;
        }
        else tmp = tmp->next;
    }
    tmp = head->next;
    if (tmp == NULL) return head;
    if (tmp->next == NULL){
        tmp->id = tmp->id - 1;
        return head;
    }
    char check = 0;
    while(tmp->next != NULL){
        if (check){
            tmp->id = tmp->id - 1;
        }
        else if (tmp->prev->id != tmp->id - 1){
            tmp->id = tmp->id - 1;
            check = 1;
        }
        tmp = tmp->next;
    }
    return head;
}

void deleteList(struct  Contact* head) {
    for(struct Contact* item = head; item != NULL; item = head) {
        head = head->next;
        free(item);
    }
}

void printList(struct Contact* head) {
    for(struct Contact* item = head; item != NULL; item = item->next) {
        printf("Number: %d, name: %s, surname: %s, second name: %s, work: %s, phone number: %s, email: %s, social media: %s\n", item->id,
            item->name, item->surname, item->second_name[0] != '\0' ? item->second_name : "-", item->work[0] != '\0' ? item->work : "-", 
            item->phone_number[0] != '\0' ? item->phone_number : "-",
            item->email[0] != '\0' ? item->email : "-", item->social_media[0] != '\0' ? item->social_media : "-");
    }
    printf("\n");
}