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

void insertionsort(int n,int *num){
    for(int i=1;i<n;i++){
        int key=num[i];
        int j=i-1;
        while(num[j]>key && j>=0){
            num[j+1]=num[j];
            j--;
        }

        num[j+1]=key;
    }
}

int partition(int l,int r,int* num){
    int mid=num[l];

    while(l<r){
        while(l<r){
            if(num[r]<mid){
                num[l]=num[r];
                break;
            }
            r--;
        }
        while(l<r){
            if(num[l]>mid){
                num[r]=num[l];
                break;
            }
            l++;
        }
    }

    num[l]=mid;
    return l;
}

void quicksort(int l,int r,int *num){
    if(l>=r) return;

    int pivot=partition(l,r,num);
    quicksort(l,pivot-1,num);
    quicksort(pivot+1,r,num);
}


int HeapAdjust(int *num,int n,int index){
    int i=index;
    while(2*i+1<n){
        int j=2*i+1;
        if(j+1<n && num[j]<num[j+1]) j++;
        if(num[j]<=num[i]) break;
        swap(num[j],num[i]);
        i=j;
    }
    return 0;
}

int createheap(int *num,int n){
    for(int i=n/2-1;i>=0;i--){
        HeapAdjust(num,n,i);
    }
    return 0;
}

int heapsort(int *num,int n){
    createheap(num,n);

    for(int i=n;i>1;i--){
        swap(num[0],num[i-1]);

        HeapAdjust(num,i-1,0);
    }
}

int main(){

    int a[10]={1,4,5,3,9,7,2,8,10,6};

    heapsort(a,10);

    for(int i=0;i<10;i++) cout << a[i] << endl;

    return 0;
}