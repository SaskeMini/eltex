#include "queue_header.h"

int main(){
    int operation;
    Queue* first = NULL;
    while (1){
        printf("Enter the number\n");
        printf("1 to add the element to queue, 2 to extract the element of queue, other number to quit the programm\n");
        scanf("%d", &operation);
        if (operation == 1){
            int priority = -1;
            printf("Enter the priority:\n");
            scanf("%d", &priority);
            while (priority < 0 || priority > 255){
                printf("Incorrect priority!\n");
                printf("Enter the priority:\n");
                scanf("%d", &priority);
            }
            first = AddItem(priority, first);
        }
        else if (operation == 2){
            if (first == NULL){
                printf("Nothing to extract!\n");
            }
            else{
                int check_operation = 0, priority = -1;
                printf("Enter the type of extract operation\n");
                printf("1 to extract first element,\n2 to extract element with some priority,\n3 to extract with a priority greater than the specified one\n");
                scanf("%d", &check_operation);
                while (check_operation != 1 && check_operation != 2 && check_operation != 3){
                    printf("Incorrect extract operation!\n");
                    printf("Enter the type of extract operation\n");
                    scanf("%d", &check_operation);
                }
                if (check_operation == 2 || check_operation == 3){
                    printf("Enter the priority:\n");
                    scanf("%d", &priority);
                    while (priority < 0 || priority > 255){
                        printf("Incorrect priority!\n");
                        printf("Enter the priority:\n");
                        scanf("%d", &priority);
                    }
                }
                first = ExtractionItem(priority, first, check_operation);
            }
        }
        else if (operation == 3){
            printList(first);
        }
        else{
            deleteList(first);
            return 0;
        }
    }
}

