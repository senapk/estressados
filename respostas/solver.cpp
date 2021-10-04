#include <iostream>
#include <vector>
#include <algorithm>
#include "testador.hpp"
#include "testador.hpp"

bool existe(std::vector<int> vet, int valor) {
    for (int i = 0; i < (int) vet.size(); i++)
        if(vet[i] == valor)
            return true;
    return false;
}

int procurar_menor_valor_positivo(const std::vector<int>& vet) {
    int atual { -1 };
    for (int i = 0; i < (int) vet.size(); i++)
        if(vet[i] > 0 && (atual == -1 || vet[i] < vet[atual]))
            atual = i;
    return atual;
}

//retorna "primeira", "segunda" ou "empate"
std::string qual_metade_eh_mais_estressada(const std::vector<int>& vet) {
    int soma_primeira { 0 }, soma_segunda { 0 };
    for (int i = 0; i < (int) vet.size() / 2; i++)
        soma_primeira += vet[i] > 0 ? vet[i] : -vet[i];
    int inicio = (int) vet.size() / 2;
    if(vet.size() % 2 == 1)
        inicio += 1;
    for (int i = inicio; i < (int) vet.size(); i++)
        soma_segunda += std::abs(vet[i]);
    if(soma_primeira == soma_segunda)
        return "empate";
    return soma_primeira > soma_segunda ? "primeira" : "segunda";
}

void existe_teste() {
    std::cout << "existe_teste\n";
    testar(existe({1, 2, 3}, 1), true);
    testar(existe({1, 2, 3}, 5), false);
}

void procurar_menor_valor_positivo_teste() {
    std::cout << "procurar_menor_valor_positivo_teste\n";
    testar(procurar_menor_valor_positivo({1, 2, 3}), 0);
    testar(procurar_menor_valor_positivo({-1, 2, 3}), 1);
    testar(procurar_menor_valor_positivo({-1, -2, 3}), 2);
    testar(procurar_menor_valor_positivo({-1, -2, -3}), -1);
}

void qual_metade_eh_mais_estressada_teste() {
    std::cout << "qual_metade_eh_mais_estressada_teste\n";
    testar(qual_metade_eh_mais_estressada({-7, 2, 3, 4}), std::string("primeira"));
    testar(qual_metade_eh_mais_estressada({-1, -3, 2, 3}), std::string("segunda"));
    testar(qual_metade_eh_mais_estressada({-1, -3, 3, 1}), std::string("empate"));
}


int main() {
    existe_teste();
    procurar_menor_valor_positivo_teste();
    qual_metade_eh_mais_estressada_teste();
}
