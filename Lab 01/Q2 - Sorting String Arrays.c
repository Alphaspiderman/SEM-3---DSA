#include <stdio.h>
#include <string.h>

// Sort an array of strings

void sort(int n, char ptr[][100]);
void main()
{
    // Start
    int i,n;
    printf("Enter number of names to sort - ");
    scanf("%d", &n);
    // Compilers hate this one trick
    char words[n][100];

    for(i = 0; i<n; i++){
        printf("Enter Name %d - ", i+1);
        scanf("%s", words[i]);
    }

    sort(n, words);
    printf("\nSorted Names - ");
    for(i = 0; i<n; i++){
        printf("\n%d - %s",i+1, words[i]);
    }
}

void sort(int n, char ptr[][100]){
    int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n-i-1; j++){
            if(strcmp(ptr[j], ptr[j+1])>0){
                char tmp[100];
                strcpy(tmp, ptr[j]);
                strcpy(ptr[j], ptr[j+1]);
                strcpy(ptr[j+1], tmp);
            }
        }
    }
}