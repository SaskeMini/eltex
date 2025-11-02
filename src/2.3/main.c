#include "header.h"

int main(){
    double res = 0;
    printf("Enter the number:\n");
    scanf("%lf", &res);
    getchar();
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
        double a;
        printf("Enter the number:\n");
        scanf("%lf", &a);
        char check_div = 1;
        double (*operation)(double, double); 
        if (action == '*'){
            operation = mult;
        }
        if (action == '+'){
            operation = sum;
        }
        if (action == '-'){
            operation = sub;
        }
        if (action == '/'){
            if (a == 0){
                printf("Division by zero!!!\n");
                check_div = 0;
            }
            operation = div;
        }
        if (check_div){
            res = operation(res, a);
            printf("Result:\n");
            printf("%lf\n", res);
        }
        getchar();
    }
}
