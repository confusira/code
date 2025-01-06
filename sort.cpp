#include<iostream>

using namespace std;

void bubblesort(int n,int* num){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i]<num[j]) swap(num[i],num[j]);
        }
    }
}

void selectionsort(int n,int *num){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(num[j]<num[min]) min=j;
        }
        swap(num[min],num[i]);
    }
}

int main(){

    int a[10]={1,4,5,3,9,7,2,8,10,6};

    selectionsort(10,a);

    for(int i=0;i<10;i++) cout << a[i] << endl;

    return 0;
}