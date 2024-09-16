#include<iostream>
using namespace std;
int main(){
int n = 50;
int oddsum = 0;
for(int i=1; i<=n; i++){
    if(i%2 != 0){
        oddsum += i;
    }
}
cout << "odd sum = " << oddsum << endl;
return 0;
}







