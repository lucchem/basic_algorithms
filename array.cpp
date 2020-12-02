#include<iostream>
using namespace std;

int main() {
    int *p = NULL;
    int offset = 0;

    p = (int *)calloc(5,sizeof(int));

    offset = 3000;

    cout << *(p+offset) << endl;
    *(p+offset)=10101;

    p = NULL;
    cout << *(p+offset) << endl;



    return 0;
}
