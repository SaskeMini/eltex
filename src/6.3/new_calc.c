#include "new_calc_header.h"

int main(){
    double res = 0;
    void *handle1, *handle2, *handle3, *handle4;
    handle1 = dlopen("libs/mult.so", RTLD_LAZY);
    if (!handle1){
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(1);
    }
    handle2 = dlopen("libs/sum.so", RTLD_LAZY);
    if (!handle2){
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(1);
    }
    handle3 = dlopen("libs/sub.so", RTLD_LAZY);
    if (!handle3){
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(1);
    }
    handle4 = dlopen("libs/div.so", RTLD_LAZY);
    if (!handle4){
        fprintf(stderr, "Error: %s\n", dlerror());
        exit(1);
    }
    operation_func mult, sum, sub, div;
    mult = (operation_func) dlsym(handle1, "mult");
    sum = (operation_func) dlsym(handle2, "sum");
    sub = (operation_func) dlsym(handle3, "sub");
    div = (operation_func) dlsym(handle4, "div");
    if (!mult || !sum || !sub || !div){
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle1);
        dlclose(handle2);
        dlclose(handle3);
        dlclose(handle4);
        exit(1);
    }
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
            dlclose(handle1);
            dlclose(handle2);
            dlclose(handle3);
            dlclose(handle4);
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
