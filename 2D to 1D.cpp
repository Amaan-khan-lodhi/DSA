#include<iostream>

using namespace std;

int main(){
    int x=0;
    int arr [3][3]= {{1,2,6},{0,3,4},{9,4,5}};
    int arr_1D [9];

    for (int i=0; i<3; i++){
        for (int j=0; j<3;j++){
            arr_1D[x]=arr[j][i];
            x++;
        }
    }
        cout<<"[ ";
    for (int i=0;i<9; i++){
        cout<<arr_1D[i]<<" ";
    }
        cout<<" ]";
}