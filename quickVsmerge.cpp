#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int l,int h){

    int i=l,j=h-1;

    while(i<=j){

        if(arr[i]<arr[h]) i++;
        else if(arr[j]>arr[h]) j--;
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[i],arr[h]);
    
     return i;
}

void quick(vector<int>&arr,int l,int h){

    if(l<h){
    int pivot=partition(arr,l,h);
    quick(arr,l,pivot-1);
    quick(arr,pivot+1,h);
    }
}



void merge(vector<int>&arr,int l,int mid,int h){
    
    int i=l;
    int j=mid+1;
    vector<int>temp;
    
    while(i<=mid && j<=h){
        
        if(arr[i]>arr[j])   temp.push_back(arr[j++]);
        
        else if(arr[i]<arr[j])  temp.push_back(arr[i++]);
        
        else {
            temp.push_back(arr[i++]);
            j++;
        }
    }
    
    while(i<=mid)   temp.push_back(arr[i++]);
    
    
    while(j<=h) temp.push_back(arr[j++]);
    
    int k=0;
    
    
    
    for(int i=0;i<temp.size();i++) arr[l+i]=temp[i];
    
}


void mergeSort(vector<int>&arr,int l,int h){
    
    if(l==h) return ;
    
    int mid=l+(h-l)/2;
    
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    
    merge(arr,l,mid,h);
}


void QuickSortTime(vector<int>arr){
    
     float start,end;
     int n=arr.size();
    start=clock();
    mergeSort(arr,0,n-1);
    end=clock();
    
   

   cout<<endl;
    cout<<"Quick Sort Time = "<<(end-start)/CLOCKS_PER_SEC<<endl;
}

void MergeSortTime(vector<int>arr){
    
     float start,end;
     int n=arr.size();
    start=clock();
    mergeSort(arr,0,n-1);
    end=clock();
    
    cout<<"Merge Sort Time = "<<(end-start)/CLOCKS_PER_SEC<<endl;
}

int main(){

   
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
     vector<int>arr(n);
     

    for(int i=0;i<n;i++){
        int a=rand()%(INT_MAX);
        arr[i]=a;
        
    }
    
    MergeSortTime(arr);
    QuickSortTime(arr);
   
}


