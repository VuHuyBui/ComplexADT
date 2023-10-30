#include <iostream>
using namespace std;

int main ( void ){
    int n = 5;
    int array[n] = {2,4,6,8,10};

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += array[i];
    }
    cout << "sum = " << sum << endl;

    return 0;
}