#include <stdio.h>

void insert(int A[], int n){
    int i=n, temp;
    temp = A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i]=temp;
}

int delete(int A[], int n){
    int i,j,x,temp,val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1; j = i*2;
    while(j <= n-1)
    {
        if(j<n-1 && A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
    else
        break;
    }
    return val;
}

int main(){
    int H[]={8,15,21,46,37,27,23,92,93,45,116,42,87,34,66,111,98,95};
    int i;
    for(i=2;i<=17;i++)
        insert(H,i);

    for(i=17;i>1;i--)
    {
        delete(H,i);
    }
    for(i=0;i<=17;i++)
        printf("%d ",H[i]);
    printf("\n");

    return 0;
}