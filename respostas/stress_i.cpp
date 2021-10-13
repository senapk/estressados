#include <iostream>
#include <vector>
#include "testador.hpp"
#include "stress_i.hpp"


void teste_existe() {
    std::cout << "existe\n";
    compare(existe({1, 2, 3}, 1), true);
    compare(existe({1, 2, 3}, 5), false);
}

void teste_contar() {
    std::cout << "contar\n";
    compare(contar({1, 2, 1, 1}, 1), 3);
    compare(contar({1, 2, 3}, 5), 0);
    compare(contar({-1, -50, -1 -99}, -1), 2);
    compare(contar({-1, -50, -1, -99}, 10), 0);
}

void teste_procurar_menor_valor_positivo() {
    std::cout << "procurar_menor_valor_positivo\n";
    auto& fn = procurar_menor_valor_positivo;
    compare(fn({1, 2, 3}), 0);
    compare(fn({-1, 2, 3}), 1);
    compare(fn({-1, -2, 3}), 2);
    compare(fn({-1, -2, -3}), -1);
}

void teste_qual_metade_eh_mais_estressada() {
    std::cout << "qual_metade_eh_mais_estressada\n";
    auto &fn = qual_metade_eh_mais_estressada;
    compare(fn({-7, 2, 3, 4}), "primeira");
    compare(fn({-1, -3, 2, 3}), "segunda");
    compare(fn({-1, -3, 3, 1}), "empate");
}

int main() {


    teste_existe();
    teste_contar();
    teste_procurar_menor_valor_positivo();
    teste_qual_metade_eh_mais_estressada();
}