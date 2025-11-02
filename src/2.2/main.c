#include "header.h"

int main(){
    for(;;){
        printf("Enter the action (if you want to stop, enter 0):\n");
        char input_action[100];
        scanf("%s", input_action);
        char action = input_action[0];
        while (!((action == 42 || action == 43 || action == 45 || action == 47 || action == '0') && input_action[1] == '\0')){
            printf("Incorrect action!\n");
            printf("Enter the action:\n");
            scanf("%s", input_action);
            action = input_action[0];
        }
        if (action == '0'){
            return 0;
        }
        double a, b;
        printf("Enter the first number:\n");
        scanf("%lf", &a);
        printf("Enter the second number:\n");
        scanf("%lf", &b);
        switch (action)
        {
        case 42:
            printf("%lf\n", mult(a, b));
            break;
        case 43:
            printf("%lf\n", sum(a, b));
            break;
        case 45:
            printf("%lf\n", sub(a, b));
            break;
        case 47:
            if (b == 0){
                printf("Division by zero!!!\n");
                break;
            }
            printf("%lf\n", div(a, b));
            break;
        default:
            break;
        }
        getchar();
    }
}