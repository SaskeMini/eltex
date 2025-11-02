#include "header.h"

int main(){
    char ipv[1000];
    char subnet_mask[1000];
    int N = 0;
    printf("Enter IP address:\n");
    scanf("%s", ipv);
    while (!check_ip_mask(ipv)){
        printf("Incorrect IP address!\n");
        printf("Enter IP address:\n");
        scanf("%s", ipv);
    }
    printf("Enter subnet mask:\n");
    scanf("%s", subnet_mask);
    while (!check_ip_mask(subnet_mask)){
        printf("Incorrect subnet mask!\n");
        printf("Enter subnet mask:\n");
        scanf("%s", ipv);
    }
    printf("Enter N:\n");
    scanf("%d", &N);
    while (N < 1){
        printf("Incorrect N!\n");
        printf("Enter N:\n");
        scanf("%d", &N);
    }
    generate_ip_and_check(ipv, subnet_mask, N);
}

