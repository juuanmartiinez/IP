#include <iostream>

using namespace std;

int main(){

    int n;
    cout << "Introduce el numero sobre el que se incia la sucesión de Collatz: ";
    cin >> n;
    
    cout << n << " ";
    while(n != 1){
        
        if(n % 2 == 0){
            n = n / 2;    
        }else{
        n = (n * 3) + 1;
        }
        cout << n << " ";
    }
}
