#include<bits/stdc++.h>
using namespace std;
vector<int>factor(int num) {
    vector<int> factors;
    for (int i = 2; i <= num; i++) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }
    return factors;
}
void msp(int a,int b){
     double start,end;
    start=clock();
    vector<int>a1=factor(a);
    vector<int>a2=factor(b);
    int i=0;int j=0;int gcd=1;
    while(i<a1.size() && j<a2.size()){
        if(a1[i]==a2[j]){
            gcd*=a1[i];
            i++;j++;
        }
        else if(a1[i]<a2[j]){
            i++;
        }
        else{
            j++;
        }
    }
       end=clock();
    cout<<"time taken by the middle school algorithm is "<<((end-start)/CLOCKS_PER_SEC)<<endl;
    cout<<"gcd is" <<" "<<gcd<<endl;
}

void  eucdiv(int a, int b) {
    double start,end;
    start=clock();
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    end=clock();
    cout<<"time taken by the euclid division algorithm is "<<((end-start)/CLOCKS_PER_SEC)<<endl;
    cout<<"gcd is" <<" "<<a<<endl;
}


void eucsub(int a, int b) {
     double start,end;
    start=clock();
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    end=clock();
    cout<<"time taken by the euclid subtraction algorithm is "<<((end-start)/CLOCKS_PER_SEC)<<endl;
    cout<<"gcd is" <<" "<<a<<endl;
}


int main(){
    cout<<"enter the two number whose gcd you want";
    int m,n;
    cin>>m>>n;
    eucdiv(m,n);//m>n
    eucsub(m,n);
    msp(m,n);
  return 0; 
}
