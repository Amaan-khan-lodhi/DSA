#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(int arr[], int x){
    int low =0;
    int high=sizeof(arr)-1;
    

    for (int i=0; low<=high; i++){
        int mid= low + ((high-low)/2);

        if (arr[mid]== x)
                    return mid;
        if(arr[mid]<x)
                    low=mid+1;
        else if(arr[mid]>x)
                    high=mid-1;
    }
    return -1;
}

int main() {

    int arr[]= {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
	int x;

    cout<<"Array = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}"<<endl;
    cout<<"Enter target Value: ";
    cin>>x;

    int result = BinarySearch(arr, x);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 25077;
}

