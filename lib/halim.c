#include <stdio.h>
#include <stdlib.h>

void multiple_entries (){
    int a,b,c;

    scanf("%d %d", &a, &b);

    c = a + b;

    printf("%d", c);
}

void case_numbers_blank_lines(){
    int a, b, c, cont = 0;

    while(scanf("%d %d", &a, &b) != EOF){
        c = a + b;
        printf("Case %d: %d\n", ++cont, c);
    }
}

void variable_number_inputs(){
    int k, c = 0;
    while(scanf("%d", &k) != EOF){
        int acc = 0;
        int *v;
        v = (int*)malloc(sizeof(int) * k);
        if (v == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            exit(1);
        }
        for(int i = 0; i < k;i++){
            scanf("%d", &v[i]);
            acc += *(v+i);
        }
        c++;
        printf("Case %d: %d\n", c, acc);
    }
}

int main (){
    
    // multiple_entries();
    // case_numbers_blank_lines();
    variable_number_inputs();
}