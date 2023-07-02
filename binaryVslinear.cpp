
#include<bits/stdc++.h>
using namespace std;

void binary_search(vector<int>arr,int key){

    int n=arr.size();
    int l=0;
    int h=n-1;


float start,end;
 start=clock();

    while(l<=h){

        int mid=l+(h-l)/2;

        if(arr[mid]==key) break;

        else if(key>arr[mid]) l=mid+1;
        else h=mid-1;
    }

    end=clock();
    cout<<endl<<"Time taken in binary search "<<((end-start)/CLOCKS_PER_SEC)<<" sec"<<endl;
}

void linear_search(vector<int>&arr,int key){

float start,end;
start=clock();
    for(int i=0;i<arr.size();i++){

        if(arr[i]==key) break;
    }

end=clock();

cout<<"Time taken in linear search "<<((end-start)/CLOCKS_PER_SEC)<<" sec"<<endl;

}

int main(){

int n;
int key;
cout<<"Enter the size\n";
cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
            int a=rand()%(INT_MAX);
        arr[i]=a;
    }

    sort(arr.begin(),arr.end());
    cout<<"Enter ele to be searched\n";
    cin>>key;

    binary_search(arr,key);
    linear_search(arr,key);

}
