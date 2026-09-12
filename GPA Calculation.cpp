#include<iostream>
using namespace std;

void GPA_Calc(int C_hrs,int T_course){

        float QP,GPA;

        float Arr[T_course];

        for (int i=0; i<T_course; i++){
            cout<<"Enter GPA of "<<i+1<<" Course"<<endl;
            cin>>Arr[i];

            QP+=(Arr[i]*3);
        }

        GPA= QP/C_hrs;

        cout<<" Your GPA is : "<<GPA<<endl;
}

int main(){

   GPA_Calc(15,5);

   return 25077;
}