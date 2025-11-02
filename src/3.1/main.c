#include "header.h"

int main(int argc, char* argv[]){
    int command;
    if (argc != 1){
        if (argc != 3 || !(check_rights(argv[1]))){
            printf("Incorrect rigths!\n");
        }
        else{
            FILE* file = fopen(argv[2], "r");
            if (!file){
                printf("Incorrect file!\n");
            }
            else if (argv[1][1] <= 55 && argv[1][1] >= 48){
                print_rights(argv[1]);
            }
            else{
                print_rights_to_argv(argv[1]);
            }
        }
    }
    else{
        printf("If you want to give rigths to files - give the arguments to executable file\n");
        printf("Enter the command (1, 2):\n");
        scanf("%d", &command);
        while (command != 1 && command != 2){
            printf("Incorrect command!\n");
            printf("Enter the command (1, 2, 3):\n");
            scanf("%d", &command);
        }
        if (command == 1){
            char rights[100];
            printf("Enter the rights (for example -rwx or -777):\n");
            scanf("%s", rights);
            if (!check_rights(rights)){
                printf("Incorrect rights!\n");
                printf("Enter the rights (for example -rwx or -777):\n");
                scanf("%s", rights);
            }
            printf("Bin result:\n");
            convert_to_bin(rights);
        }
        else if (command == 2){
            struct stat buf;
            printf("Input file name:\n");
            char file_name[1000];
            scanf("%s", file_name);
            if (stat(file_name, &buf) != 0){
                printf("Incorrect file\n");
            }
            else{
                unsigned short mode_to_rights = buf.st_mode;
                char rights[5];
                rights[0] = '-';
                for (int i = 1; i < 4; i++){
                    rights[i] = mode_to_rights % 8 + 48;
                    mode_to_rights = mode_to_rights / 8;
                }
                char temp = rights[1];
                rights[1] = rights[3];
                rights[3] = temp;
                print_rights(rights);
            }

        }
    }
    return 0;
}

