#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#define PROF


bool in(std::vector<int> vet, int x) {
#ifdef PROF
    for (auto elem : vet)
        if (elem == x) 
            return true;
    return false;
#else
    return false;
#endif
}

// Retorne "onde" aparece X na vet pela primeira vez.
// Para todas as buscas, se não houver resultado, retorne -1
int index_of(std::vector<int> vet, int x) {
#ifdef PROF
    for (int i = 0; i < (int) vet.size(); ++i)
        if (vet[i] == x) 
            return i;
    return -1;
#else
    return 0;
#endif
}


// Qual a posição do primeiro homem (primeiro valor maior que 0)?
int find_if(const std::vector<int>& vet) {
#ifdef PROF
    for (int i = 0; i < (int) vet.size(); ++i)
        if (vet[i] > 0)
            return i;
    return -1;
#else
    return 0;
#endif
}

// Qual a posição do menor valor da lista?
// ou -1 para lista vazia
int min_element(const std::vector<int>& vet) {
    int index = -1;
    for (int i = 0; i < (int) vet.size(); ++i)
        if (index == -1 || vet[i] < vet[index])
            index = i;
    return index;
}

// Qual a posição do HOMEM mais calmo (menor valor maior que 0)?
int find_min_if(const std::vector<int>& vet) {
    int index = -1;
    for (int i = 0; i < (int) vet.size(); ++i)
        if (vet[i] > 0 && //homem
            (index == -1 || vet[i] < vet[index])) //primeiro ou melhor
            index = i;
    return index;
}

// Quantas vezes o valor X apareceu?
int count(std::vector<int> vet, int x) {
    int count { 0 };
    for (auto elem : vet)
        if (elem == x) 
            count += 1;
    return count;
}

// Qual a média de stress?
double average(const std::vector<int>& vet) {
    double sum = 0.0;
    for (auto value : vet)
        sum += std::abs(value);
    return sum / vet.size();
}

// Existem mais homens ou mulheres?
// return "draw", "men" ou "women"
std::string more_men_or_women(const std::vector<int>& vet) {
    int men { 0 };
    int women { 0 };
    for (auto elem : vet)
        if (elem > 0)
            men += 1;
        else
            women += 1;

    return men == women ? "draw" : (men > women ? "men" : "women");
}


// Compare a soma dos stress da primeira metade com a segunda metade
// e informe qual metade é mais estressada. Se a quantidade de elementos for
// ímpar, ignore o elemento do meio
// Retornd "draw" para empate, "first" para primeira, "second" para segunda metade.
std::string half_compare(const std::vector<int>& vet) {
    int first { 0 };
    int second { 0 };
    int size = vet.size(); 
    int half = size / 2;
    for (int i = 0; i < size; i++) {
        auto value = std::abs(vet[i]);
        if (size % 2 == 1 &&  i == half)
            continue;
        else if (i < half)
            first += value;
        else
            second += value;
    }

    return first == second ? "draw" : (first > second ? "first" : "second");
}


// Compare a média de stress de homens e mulheres e informe quem é mais estressado.
// return "draw", "men" or "women"
std::string sex_battle(const std::vector<int>& vet) {
    int men { 0 };
    double men_sum { 0.0 };

    int women { 0 };
    double women_sum { 0.0 };

    for (auto elem : vet) {
        if (elem > 0) {
            men += 1;
            men_sum += std::abs(elem);
        } else {
            women += 1;
            women_sum += std::abs(elem);
        }
    }
    men_sum /= men;
    women_sum /= women;

    return men_sum == women_sum ? "draw" : (men_sum > women_sum ? "men" : "women");
}
