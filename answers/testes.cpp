#include <iostream>
#include <vector>
#include "testador.hpp"
#include "solver.hpp"


/*Busca */
void teste_existe() {
    std::cout << "\nexiste";
    auto &fn = estressados::existe;
    compare(fn({1, 2, 3}, 1), true);
    compare(fn({1, 2, 3}, 5), false);
}

void teste_contar() {
    std::cout << "\ncontar";
    auto &fn = estressados::contar;
    compare(fn({1, 2, 1, 1}, 1), 3);
    compare(fn({1, 2, 3}, 5), 0);
    compare(fn({-1, -50, -1, -99}, -1), 2);
    compare(fn({-1, -50, -1, -99}, 10), 0);
}

void teste_procurar() {
    std::cout << "\nprocurar";
    auto &fn = estressados::procurar;
    compare(fn({-1, -50, -1 -99}, -50), 1);
    compare(fn({-1, -50, -1, -99}, 10), -1);
    compare(fn({-1, -50, -1, -99}, -99), 3);
}

void teste_procurar_apartir() {
    std::cout << "\nprocurar_apartir";
    auto& fn{estressados::procurar_apartir};
    compare(fn({5, 3, -1, -50, -1, -99}, -1, 0), 2);
    compare(fn({5, 3, -1, -50, -1, -99}, -1, 3), 4);
    compare(fn({5, 3, -1, -50, -1, -99}, -1, 4), 4);
    compare(fn({5, 3, -1, -50, -1, -99}, 3, 2), -1);
}

/* Melhor caso */

void teste_procurar_menor_valor() {
    std::cout << "\nprocurar_menor_valor";
    auto& fn = estressados::procurar_menor_valor;
    compare(fn({5, 3, -1, -50, -1, -99}), -99);
    compare(fn({1, 2, 3}), 1);
    compare(fn({-1, -2, 3}), -2);
    compare(fn({-1, -2, -3}), -3);
}

void teste_procurar_pos_menor() {
    std::cout << "\nprocurar_pos_menor";
    auto& fn = estressados::procurar_pos_menor;
    compare(fn({5, 3, -1, -50, -1, -99}), 5);
    compare(fn({-99, 3, -1, -50, -1, 30}), 0);
}

void teste_procurar_pos_menor_apartir() {
    std::cout << "\nprocurar_pos_menor_apartir";
    auto& fn = estressados::procurar_pos_menor_apartir;
    compare(fn({5, 3, -1, -50, -1, 10}, 3), 3);
    compare(fn({-99, 3, -1, -50, -1, 30}, 0), 0);
    compare(fn({-99, 3, -1, -50, -1, 30}, 4), 4);
}

void teste_procurar_pos_melhor_se() {
    std::cout << "\nprocurar_pos_melhor_se";
    auto& fn = estressados::procurar_pos_melhor_se;
    compare(fn({5, 3, -1, -50, -1, -99}), 1);
    compare(fn({-1, -50, -1, -99}), -1);
}

/* Contagem */

void teste_calcular_stress_medio() {
    std::cout << "\ncalcular_stress_medio";
    auto& fn = estressados::calcular_stress_medio;
    compare(fn({1,2,3,4,5}), 3);
    compare(fn({20, -90, 30, -40, 15}), 39);
    compare(fn({15, 13, 12, 14, 28, 49}), 21.8333);
    compare(fn({}), 0);
}

void teste_mais_homens_ou_mulheres() {
    std::cout << "\nmais_homens_ou_mulheres";
    auto& fn = estressados::mais_homens_ou_mulheres;
    compare(fn({5, 3, -1, -50, -1, -99}), "mulheres");
    compare(fn({5, 3, 1, -50, -1, -99}), "empate");
    compare(fn({5, 3, 1, -50, -1, 99}), "homens");
}

void teste_qual_metade_eh_mais_estressada() {
    std::cout << "\nqual_metade_eh_mais_estressada";
    auto &fn = estressados::qual_metade_eh_mais_estressada;
    compare(fn({-7, 2, 3, 4}), "primeira");
    compare(fn({-1, -3, 2, 3}), "segunda");
    compare(fn({-1, -3, 3, 1}), "empate");
}

void teste_homens_sao_mais_estressados_que_mulheres() {
    std::cout << "\nhomens_sao_mais_estressados_que_mulheres";
    auto &fn = estressados::homens_sao_mais_estressados_que_mulheres;
    compare(fn({1,3,-10,20,-50}), false);
    compare(fn({-1,-3,10,-20,50}), true);
    compare(fn({1,2,3,4,5}), true);
    compare(fn({-1,-2,-3,-4,-5}), false);
    compare(fn({}), false);
}

/* Filtragem */

void teste_clonar() {
    std::cout << "\nclonar";
    auto &fn = estressados::clonar;
    compare(fn({1,3,-10,20,-50}), "{1, 3, -10, 20, -50}");
    compare(fn({-1,-3,10,-20,50}), "{-1, -3, 10, -20, 50}");
    compare(fn({1,2,3,4,5}), "{1, 2, 3, 4, 5}");
    compare(fn({-1,-2,-3,-4,-5}), "{-1, -2, -3, -4, -5}");
    compare(fn({}), "{}");
}

void teste_pegar_homens() {
    std::cout << "\npegar_homens";
    auto &fn = estressados::pegar_homens;
    compare(fn({1,3,-10,20,-50}), "{1, 3, 20}");
    compare(fn({-1,-3,10,-20,50}), "{10, 50}");
    compare(fn({1,2,3,4,5}), "{1, 2, 3, 4, 5}");
    compare(fn({-1,-2,-3,-4,-5}), "{}");
    compare(fn({}), "{}");
}

void teste_pegar_mulheres() {
    std::cout << "\npegar_mulheres";
    auto &fn = estressados::pegar_mulheres;
    compare(fn({1,3,-10,20,-50}), "{-10, -50}");
    compare(fn({-1,-3,10,-20,50}), "{-1, -3, -20}");
    compare(fn({1,2,3,4,5}), "{}");
    compare(fn({-1,-2,-3,-4,-5}), "{-1, -2, -3, -4, -5}");
    compare(fn({}), "{}");
}

void teste_pegar_calmos() {
    std::cout << "\npegar_calmos";
    auto &fn = estressados::pegar_calmos;
    compare(fn({1,3,-10,20,-50}), "{1, 3}");
    compare(fn({-1,-3,10,-20,50}), "{-1, -3}");
    compare(fn({-1,2,-3,4,-5}), "{-1, 2, -3, 4, -5}");
    compare(fn({}), "{}");
}

void teste_pegar_mulheres_calmas() {
    std::cout << "\npegar_mulheres_calmas";
    auto &fn = estressados::pegar_mulheres_calmas;
    compare(fn({1,3,-10,20,-50}), "{}");
    compare(fn({-1,-3,10,-20,50}), "{-1, -3}");
    compare(fn({-1,2,-3,4,-5}), "{-1, -3, -5}");
    compare(fn({}), "{}");
}

/* Acesso */

/* Conjuntos */

void teste_exclusivos() {
    std::cout << "\nexclusivos";
    auto &fn = estressados::exclusivos;
    compare(fn({1,3,4,3,-1,-2,-2}), "{1, 3, 4, -1, -2}");
    compare(fn({-1,-1,-1,-1,-1}), "{-1}");
    compare(fn({-5, 6, 1, -2, 3}), "{-5, 6, 1, -2, 3}");
    compare(fn({}), "{}");
}

void teste_diferentes() {
    std::cout << "\ndiferentes";
    auto &fn = estressados::diferentes;
    compare(fn({1,3,4,3,-1,-2,-2}), "{1, 3, 4, 2}");
    compare(fn({-1,-1,-1,-1,-1}), "{1}");
    compare(fn({-5, 6, 1, -2, 3}), "{5, 6, 1, 2, 3}");
    compare(fn({}), "{}");
}

void teste_abandonados() {
    std::cout << "\nabandonados";
    auto &fn = estressados::abandonados;
    compare(fn({1,3,4,3,-1,-2,-2}), "{3, -2}");
    compare(fn({-1,-1,-1,-1,-1}), "{-1, -1, -1, -1}");
    compare(fn({-5, 6, 1, -2, 3}), "{}");
    compare(fn({}), "{}");
}

/* Manipula��o */

void teste_sozinhos() {
    std::cout << "\nsozinhos";
    auto &fn = estressados::sozinhos;
    compare(fn({1,3,4,3,-1,-2,-2}), "{4}");
    compare(fn({-1,-1,-1,-1,-1}), "{}");
    compare(fn({-5, 6, 1, -2, 3}), "{-5, 6, 1, -2, 3}");
    compare(fn({}), "{}");
}

void teste_mais_ocorrencias() {
    std::cout << "\nmais_ocorrencias";
    auto &fn = estressados::mais_ocorrencias;
    compare(fn({1,3, 4, 3, -1, -2, -2}), "2");
    compare(fn({1, 3, 4, 5, -1, -5, -5}), "3");
    compare(fn({-5, 6, 1, -2, 3}), "1");
    compare(fn({}), "0");
}

void teste_mais_recorrentes() {
    std::cout << "\nmais_recorrentes";
    auto &fn = estressados::mais_recorrentes;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), "{1, 3, 2}");
    compare(fn({1, 3, 4, 5, -1, -5, -5, 3, -3}), "{3, 5}");
    compare(fn({-5, 6, 1, -2, 3}), "{5, 6, 1, 2, 3}");
    compare(fn({}), "{}");
}

/* Proximidade */

void teste_briga() {
    std::cout << "\nbriga";
    auto &fn = estressados::briga;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), "0");
    compare(fn({50, 98, 31, -51, 31, -99}), "2");
    compare(fn({-5, 50, 1, -2, 3}), "0");
    compare(fn({}), "0");
}

void teste_apaziguado() {
    std::cout << "\napaziguado";
    auto &fn = estressados::apaziguado;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), "{}");
    compare(fn({83, -4, 65, 8, -99, 12}), "{0, 4}");
    compare(fn({40, 81, 1, -2, 3}), "{1}");
    compare(fn({-5, 81, 40, -2, 3}), "{1}");
    compare(fn({}), "{}");
}

/* Sequ�ncias */

void teste_quantos_times() {
    std::cout << "\nquantos_times";
    auto &fn = estressados::quantos_times;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), 2);
    compare(fn({83, -4, 65, 8, -99, 12}), 1);
    compare(fn({40, 81, 1, -2, 3}), 1);
    compare(fn({1,1,2,2,3,3}), 1);
    compare(fn({}), 0);
}

void teste_maior_time() {
    std::cout << "\nmaior_time";
    auto &fn = estressados::maior_time;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), "{1, 3, 4, 3}");
    compare(fn({83, -4, 65, 8, -99, 12}), "{65, 8}");
    compare(fn({40, 81, 1, -2, 3}), "{40, 81, 1}");
    compare(fn({1,1,2,2,3,3}), "{1, 1, 2, 2, 3, 3}");
    compare(fn({-2,-3,-4,1,2}), "{-2, -3, -4}");
    compare(fn({}), "{}");
}

void teste_sem_time() {
    std::cout << "\nsem_time";
    auto &fn = estressados::sem_time;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), 0);
    compare(fn({83, -4, 65, 8, -99, 12}), 4);
    compare(fn({40, 81, 1, -2, 3}), 2);
    compare(fn({1,1,2,2,3,3}), 0);
    compare(fn({-2,-3,-4,1,2}), 0);
    compare(fn({}), 0);
}

/* Grupos */

void teste_casais() {
    std::cout << "\ncasais";
    auto &fn = estressados::casais;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), 1);
    compare(fn({83, -4, 65, 8, -99, 12}), 0);
    compare(fn({40, 81, 1, -2, 3}), 0);
    compare(fn({1,1,2,2,3,3}), 0);
    compare(fn({-2,-3,-4,-1,1,2}), 2);
    compare(fn({}), 0);
}

void teste_trios() {
    std::cout << "\ntrios";
    auto &fn = estressados::trios;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), 0);
    compare(fn({83, -4, 65, 8, -99, 12}), 0);
    compare(fn({40, 81, 1, -2, 3}), 0);
    compare(fn({1,1,2,2,3,3}), 0);
    compare(fn({-2,-3,-4,-1,1,2,1}), 1);
    compare(fn({2,-2,2,-99,-99,-99, 30, 50, 30, 40, -30}), 3);
    compare(fn({}), 0);
}

/* Altera��o */

void teste_remove() {
    std::cout << "\nremove";
    auto &fn = estressados::remove;
    compare(fn({1, 3, 4, 3, -1, -2, -2}, 3), "{1, 4, 3, -1, -2, -2}");
    compare(fn({83, -4, 65, 8, -99, 12}, 12), "{83, -4, 65, 8, -99}");
    compare(fn({83, -4, 65, 8, -99, 12}, 83), "{-4, 65, 8, -99, 12}");
    compare(fn({}, 0), "{}");
}

void teste_insert() {
    std::cout << "\ninsert";
    auto &fn = estressados::insert;
    compare(fn({1, 3, 4, 3, -1, -2, -2}, 3, 0), "{3, 1, 3, 4, 3, -1, -2, -2}");
    compare(fn({83, -4, 65, 8, -99, 12}, 5, 3), "{83, -4, 65, 5, 8, -99, 12}");
    compare(fn({40, 81, 1, -2, 3}, 100, 0), "{40, 81, 1, -2, 3}");
    compare(fn({1,1,2,2,3,3}, -1, 0) , "{-1, 1, 1, 2, 2, 3, 3}");
    compare(fn({}, 3, 5), "{}");
}

void teste_dance() {
    std::cout << "\ndance";
    auto &fn = estressados::dance;
    compare(fn({1, 3, 4, 3, -1, -2, -2}), "{1, 3, 4, 3, -1}");
    compare(fn({1,1,2,2,3,3}), "{}");
    compare(fn({-4,-3,-2,-1,1,2,1}), "{-4, -3, 1}");
    compare(fn({-4, 3, -3, 2, 4, -4, -2, 4}), "{}");
    compare(fn({}), "{}");
}

/* Fim dos testes */

void bloco1() {
    /* Busca */
    std::cout << "\n======Busca======\n";
    teste_existe();
    teste_contar();
    teste_procurar();
    teste_procurar_apartir();
    /* Melhor caso */
    std::cout << "\n\n======Melhor Caso======\n";
    teste_procurar_menor_valor();
    teste_procurar_pos_menor();
    teste_procurar_pos_menor_apartir();
    teste_procurar_pos_melhor_se();
    /* Contagem */
    std::cout << "\n\n======Contagem======\n";
    teste_calcular_stress_medio();
    teste_mais_homens_ou_mulheres();
    teste_qual_metade_eh_mais_estressada();
    teste_homens_sao_mais_estressados_que_mulheres();
}

void bloco2() {
    /* Filtragem */
    std::cout << "\n\n======Filter======\n";
    teste_clonar();
    teste_pegar_homens();
    //teste_pegar_mulheres();
    teste_pegar_calmos();
    teste_pegar_mulheres_calmas();
    /* Acesso */
    /* Conjuntos */
    teste_exclusivos();
    teste_diferentes();
    teste_abandonados();
}

void bloco3() {
    /* Manipula��o */
    teste_sozinhos();
    teste_mais_ocorrencias();
    teste_mais_recorrentes();
    /* Proximidade */
    teste_briga();
    teste_apaziguado();
    /* Sequ�ncias */
    teste_quantos_times();
    teste_maior_time();
    teste_sem_time();
    /* Grupos */
    teste_casais();
    teste_trios();
    /* Altera��o */
    teste_remove();
    teste_insert();
    teste_dance();
    std::cout << '\n';
}

int main() {
    bloco1();
    bloco2();
    bloco3();
}