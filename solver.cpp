#include <iostream>
#include <vector>
#include <algorithm>

bool existe(std::vector<int> vet, int valor) {
    for (int i = 0; i < vet.size(); i++)
        if(vet[i] == valor)
            return true;
    return false;
}

int procura(std::vector<int> vet, int valor) {
    for (int i = 0; i < vet.size(); i++)
        if(vet[i] == valor)
            return i;
    return -1;
}


int main() {
    std::cout << existe({1, 2, 3, 4, 5}, 5) << '\n';
    std::cout << existe({1, 2, 3, 4, 5}, 0) << '\n';
}
