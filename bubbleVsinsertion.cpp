// #include<iostream>     for i/p & o/p
// #include<vector>       for vector
// #include<time.h>     for clock
// #include<stdlib.h>   for INT_MAX


#include<bits/stdc++.h>

using namespace std;

void bubble(vector<int>arr){
    
    int n=arr.size();
    
double start,end;

start=clock();


    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]); 
              
        }
       
    }
}

end=clock();

cout<<endl<<"Time taken in bubble sort "<<((end-start)/CLOCKS_PER_SEC)<<" sec"<<endl;

}


void insertion(vector<int>arr){

    float start,end;
    start=clock();

    int i=1;

   for(int i=1;i<arr.size();i++){
            int j=i-1;
            int temp=arr[i];
            while(j>=0 && arr[j]>temp){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
   }

   end=clock();
   cout<<endl<<"Time taken in insertion sort "<<((end-start)/CLOCKS_PER_SEC)<<" sec"<<endl;
   


}
int main(){
    
    int n;
    cout<<"Enter the size of arr\n";
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        int a=rand()%(INT_MAX);
        arr[i]=a;
       
    }
    bubble(arr);
    insertion(arr);
}