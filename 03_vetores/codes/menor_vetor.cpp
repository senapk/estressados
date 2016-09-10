#include <iostream>
#include <vector>
using namespace std;

int main(){
    cout << "Digite valores inteiros e -1 para sair" << endl;
    int value = 0;
    vector<int> valores;
    while(true){
        cin >> value;
        if(value == -1)
            break;
        valores.push_back(value);
    }
    int menor = valores[0];
    for(auto valor : valores){
        if(valor < menor){
            menor = valor;
        }
    }
    cout << "O menor eh " << menor << endl;
    return 0;
}



            
