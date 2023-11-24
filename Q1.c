#include <stdio.h>
void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    for(int i=0;i<n;i++){
        int val = arr[i];
        if(val + i>=n){
            printf("NO");
            return 0;
        }
        for(int j=i+1;j<=val+i;j++){
            arr[j]--;
            if(arr[j]==-1){
                printf("NO");
                return 0;
            }
        }
        sort(arr,n);
    }
    printf("YES");

    return 0;
}


