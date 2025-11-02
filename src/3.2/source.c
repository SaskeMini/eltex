#pragma once

void generate_ip_and_check(char ipv[], char subnet_mask[], int n){
    int numeric_ipv[5], numeric_mask[5], index_ipv = 0, index_mask = 0, temp_index = 0;
    char temp_str[5];
    for (size_t i = 0; i < strlen(ipv); i++){
        if (ipv[i] == '.'){
            numeric_ipv[index_ipv++] = atoi(temp_str);
            memset(temp_str, 0, 4);
            temp_index = 0;
        }
        else{
            temp_str[temp_index++] = ipv[i];
        }
    }
    for (size_t i = 0; i < strlen(subnet_mask); i++){
        if (subnet_mask[i] == '.'){
            numeric_mask[index_mask++] = atoi(temp_str);
            memset(temp_str, 0, 4);
            temp_index = 0;
        }
        else{
            temp_str[temp_index++] = subnet_mask[i];
        }
    } 
    int count_to_local = 0, count_to_other = 0;
    int ipv_0 = numeric_ipv[0] & numeric_mask[0], ipv_1 = numeric_ipv[1] & numeric_mask[1],
        ipv_2 = numeric_ipv[2] & numeric_mask[2], ipv_3 = numeric_ipv[3] & numeric_mask[3];
    for (int i = 0; i < n; i++){
        int new_ip[5] = {numeric_ipv[0], numeric_ipv[1], 0, 0};
        new_ip[2] = rand() % 256;
        new_ip[3] = rand() % 256;
        new_ip[0] = new_ip[0] & numeric_mask[0];
        new_ip[1] = new_ip[1] & numeric_mask[1];
        new_ip[2] = new_ip[2] & numeric_mask[2];
        new_ip[3] = new_ip[3] & numeric_mask[3];
        if ((new_ip[0] ^ ipv_0) == 0 && (new_ip[1] ^ ipv_1) == 0 &&
        (new_ip[2] ^ ipv_2) == 0 && (new_ip[3] ^ ipv_3) == 0){
            count_to_local++;
        }
        else{
            count_to_other++;
        }
    }
    double local_res = (double)count_to_local / (double)n * 100, other_res = (double)count_to_other / (double)n * 100;
    printf("To local:\n");
    printf("Packages: %d - Percent: %.1lf%%\n", count_to_local, local_res);
    printf("To other:\n");
    printf("Packages: %d - Percent: %.1lf%%\n", count_to_other, other_res);
}

char check_ip_mask(char ipv[]){
    char res = 1;
    int dot_check = 0, temp_index = 0;
    char temp_str[1000] = {0};
    for (size_t i = 0; i < strlen(ipv); i++){
        if (ipv[i] == '.'){
            dot_check++;
            int check_ip_part = atoi(temp_str);
            if (check_ip_part < 0 || check_ip_part > 255){
                res = 0;
                break;
            }
            memset(temp_str, 0, 1000);
            temp_index = 0;
        }
        else if (ipv[i] < 48 || ipv[i] > 57){
            res = 0;
            break;
        }
        else{
            temp_str[temp_index++] = ipv[i];
        }
    }
    if (dot_check != 3){
        res = 0;
    }
    return res;
}