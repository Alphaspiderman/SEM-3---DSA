#include <stdio.h>

// Reverse a number using recursion

int rev_num(int num, int sum);
void main(){
    int num, rev;
    printf("Enter a number - ");
    scanf("%d", &num);
    rev = rev_num(num, 0);
    printf("Number in reverse - %d", rev);
}

int rev_num(int num, int sum){
    if(num  == 0){
        return sum;
    }
    else{
        sum = (sum * 10) + (num % 10);
        return rev_num(num/10, sum);
    }
}
