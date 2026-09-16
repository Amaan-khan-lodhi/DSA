#include<iostream>
using namespace std;

int linearsearch(int arr[], int s, int x){
    for(int i=0;i<s;i++){
        if(arr[i]==x)
            return i;
    }
        return -1;
}


int main(){
    int x,s,result;

    int arr[]={53,56,62,64,67,77,99};
    s=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Array : {53,56,62,64,67,77,99}"<<endl;
    cout<<"Enter Target Element: ";
    cin>>x;

    result= linearsearch(arr,s,x);

   if (result != -1) {
        cout << "Element found at index: " << result+1<< endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}