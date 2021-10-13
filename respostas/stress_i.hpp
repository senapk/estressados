#include <iostream>
#include <vector>

bool existe(const std::vector<int>& vet, int value) {
    for (auto elem : vet)
        if(elem == value)
            return true;
    return false;
}

int contar(const std::vector<int>& vet, int value) {
    int cont { 0 };
    for (auto elem : vet)
        if(elem == value)
            cont++;
    return cont;
}

int procurar_menor_valor_positivo(const std::vector<int>& vet) {
    int atual { -1 };
    for (int i = 0; i < (int) vet.size(); i++)
        if (vet[i] > 0 && (atual == -1 || vet[i] < vet[atual]))
            atual = i;
    return atual;
}

//retorna "primeira", "segunda" ou "empate"
std::string qual_metade_eh_mais_estressada(const std::vector<int>& vet) {
    int size { (int) vet.size() };
    int soma_primeira { 0 };
    int soma_segunda { 0 };
    int middle = size / 2;
    for (int i = 0; i < size; i++) {
        auto value { std::abs(vet[i]) };
        if (i < middle)
            soma_primeira += value;
        else if (size % 2 == 1 && i == middle)
            continue;
        else
            soma_segunda += value;
    }
    if (soma_primeira == soma_segunda)
        return "empate";
    return soma_primeira > soma_segunda ? "primeira" : "segunda";
}
