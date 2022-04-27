#include <iostream>
#include <vector>

namespace estressados {
/* Busca */
bool existe(const std::vector<int>& vet, int value) {
    for (auto elem : vet)
        if(elem == value)
            return true;
    return false;
}

bool existe_apartir(const std::vector<int>& vet, int value, size_t pos) {
    for (size_t i{pos}; i < vet.size(); i++) {
        if (vet[i] == value)
            return true;
    }
    return false;
}

template <class... v_pack>
bool existe_algum_apartir(const std::vector<int>& vet, size_t pos, v_pack&& ...value) {
    std::vector<bool> flags;
    ((flags.push_back(existe_apartir(vet, value, pos))), ...);
    for (auto i : flags) {
        if (i) {
            return true;
        }
    }
    return false;
}

int contar(const std::vector<int>& vet, int value) {
    int cont { 0 };
    for (auto elem : vet)
        if(elem == value)
            cont++;
    return cont;
}

int procurar(const std::vector<int>& vet, int value) {
    for (size_t i{0}; i < vet.size(); i++)
        if (vet[i] == value)
            return i;
    constexpr int not_found{-1};
    return not_found;
}

int procurar_apartir(const std::vector<int>& vet, int value, size_t pos) {
    for (size_t i{pos}; i < vet.size(); i++)
        if (vet[i] == value)
            return i;
    constexpr int not_found{-1};
    return not_found;
}

/* Melhor caso */

int procurar_menor_valor(const std::vector<int>& vet) {
    int menor{vet[0]};
    for (size_t i{0}; i < vet.size(); i++) 
        if (vet[i] < menor)
            menor = vet[i];
    return menor;
}

int procurar_pos_menor(const std::vector<int>& vet) {
    int menor{0};
    for (size_t i{0}; i < vet.size(); i++)
        if (vet[i] < vet[menor])
            menor = i;
    return menor;
}

int procurar_pos_menor_apartir(const std::vector<int>& vet, size_t pos) {
    size_t menor{pos};
    for (size_t i{menor}; i < vet.size(); i++)
        if (vet[i] < vet[menor])
            menor = i;
    return menor;
}

int procurar_pos_melhor_se(const std::vector<int>& vet) {
    auto for_homem = [](int a){ return a < 0 ? false : true; };
    int calmo{-1};
    for (size_t i{0}; i < vet.size(); i++)
        if (for_homem(vet[i]) && (calmo == -1 || vet[i] < vet[calmo]))
            calmo = i;
    return calmo;
}

/* Contagem */

double calcular_stress_medio(const std::vector<int>& vet) {
    double media{0};
    for (size_t i{0}; i < vet.size(); i++) { // {1,3,-90,10}
        media += (vet[i] < 0) ? -vet[i] : vet[i];
    }
    return (vet.size() == 0) ? media : media / vet.size();
}

std::string mais_homens_ou_mulheres(const std::vector<int>& vet) {
    int homens{0};
    int mulheres{0};
    auto for_homem{[](int a){ return (a > 0) ? true : false;}};
    for (auto elem : vet)
        if (for_homem(elem))
            homens++;
        else
            mulheres++;
    if (homens > mulheres)
        return "homens";
    else if (mulheres > homens)
        return "mulheres";
    return "empate";
}

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

bool homens_sao_mais_estressados_que_mulheres(const std::vector<int>& vet) {
    double homens{0};
    double mulheres{0};
    int quantidade_homens{0};
    int quantidade_mulheres{0};
    auto for_homem = [](int a){ return a < 0 ? false : true; };
    for (auto elem : vet) {
        if (!for_homem(elem)) {
            mulheres += -elem;
            quantidade_mulheres++;
        } else {
            homens += elem;
            quantidade_homens++;
        }
    }
    if (quantidade_homens > 0) {
        homens /= quantidade_homens;
    }
    if (quantidade_mulheres > 0) {
        mulheres /= quantidade_mulheres;
    }
    return (homens > mulheres) ? true : false;
}

/* Filtragem */

std::vector<int> clonar(const std::vector<int>& vet) {
    std::vector<int> novo_vetor;
    for (auto i : vet) {
        novo_vetor.push_back(i);
    }
    return novo_vetor;
}

std::vector<int> pegar_homens(const std::vector<int>& vet) {
    std::vector<int> homens;
    auto for_homem = [](int a){ return a < 0 ? false : true; };
    for (auto i : vet)
        if (for_homem(i))
            homens.push_back(i);
    return homens;
}

std::vector<int> pegar_mulheres(const std::vector<int>& vet) {
    std::vector<int> mulheres;
    auto for_mulher = [](int a){ return a > 0 ? false : true; };
    for (auto i : vet)
        if (for_mulher(i))
            mulheres.push_back(i);
    return mulheres;
}

std::vector<int> pegar_calmos(const std::vector<int>& vet) {
    std::vector<int> calmos;
    constexpr int estresse_aceitavel{9};
    for (auto i : vet)
        if (int elem = (i < 0) ? -i : i; elem <= estresse_aceitavel)
            calmos.push_back(i);
    return calmos;
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int>& vet) {
    std::vector<int> calmas;
    constexpr int estresse_aceitavel{-9};
    for (auto i : pegar_mulheres(vet))
        if (i >= estresse_aceitavel)
            calmas.push_back(i);
    return calmas;
}

/* Acesso */

std::vector<int> inverter_com_copia(const std::vector<int>& vet) {
    std::vector<int> array_reverso;
    for (auto i{vet.rbegin()}; i < vet.rend(); i++) {
        array_reverso.push_back(*i);
    }
    return array_reverso;
}

void inverter_inplace(std::vector<int>& vet) {
    for (size_t i{0}, j{vet.size() - 1}; i < vet.size()/2; i++, j--) {
        int aux{vet[i]};
        vet[i] = vet[j];
        vet[j] = aux;
    }
}

int sortear(std::vector<int>& vet) {
    srand(time(NULL));
    return vet[rand() % (vet.size() - 1) ];
}

void embaralhar(std::vector<int>& vet) {
    srand(time(NULL));
    for (size_t i{0}; i < vet.size(); i++) {
        size_t random{rand() % (vet.size() - 1)};
        int aux{vet[i]};
        vet[i] = vet[random];
        vet[random] = aux;
    }
}

void ordenar(std::vector<int>& vet) {
    for (size_t i{0}; i < vet.size(); i++) {
        size_t indice_menor{i};
        for (size_t j{i+1}; j < vet.size(); ++j) {
            if (vet[j] < vet[indice_menor]) {
                indice_menor = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[indice_menor];
        vet[indice_menor] = aux;
    }
}

/* Conjuntos */

std::vector<int> exclusivos(const std::vector<int>& vet) {
    std::vector<int> unicos;
    for (auto i : vet) {
        if(!existe(unicos, i)) {
            unicos.push_back(i);
        }
    }
    return unicos;
}

std::vector<int> diferentes(const std::vector<int>& vet) {
    std::vector<int> niveis;
    for (auto i : vet) {
        i = std::abs(i);
        if (!existe(niveis, i)) {
            niveis.push_back(i);
        }
    }
    return niveis;
}

std::vector<int> abandonados(const std::vector<int>& vet) {
    std::vector<int> orfaos{vet};
    for (auto i : exclusivos(orfaos)) {
        if(int indice{procurar(orfaos,i)}; indice != -1) {
            orfaos.erase(orfaos.begin() + indice);
        }
    }
    return orfaos;
}

/* Manipulação */

std::vector<int> sozinhos(const std::vector<int>& vet) {
    std::vector<int> sadboys;
    std::vector<int> seforam;

    for (size_t i{0}; i < vet.size(); i++) {
        int elem{(vet[i] < 0) ? -vet[i] : vet[i]};
        if (!existe(seforam, elem)) {
            if (!existe_algum_apartir(vet, i+1, elem, -elem)) {
                sadboys.push_back(vet[i]);
            }
            seforam.push_back(elem);   
        }
    }
    return sadboys;
}

int mais_ocorrencias(const std::vector<int>& vet) {
    int maior_ocorrencia{0};

    for (size_t i{0}; i < vet.size(); i++) {
        int elem = (vet[i] < 0) ? -vet[i] : vet[i];
        int occur{1};

        for (size_t j{i+1}; j < vet.size(); j++) {
            int elem2 = (vet[j] < 0) ? -vet[j] : vet[j];
            if (elem == elem2) {
                occur += 1;
            }
        }
        if (occur > maior_ocorrencia) {
            maior_ocorrencia = occur;
        }
    }
    return maior_ocorrencia;
}

std::vector<int> mais_recorrentes(const std::vector<int>& vet) {
    int maior_ocorrencia{mais_ocorrencias(vet)};
    std::vector<int> recorrentes;
    for (size_t i{0}; i < vet.size(); i++) {
        int elem = (vet[i] < 0) ? -vet[i] : vet[i];
        int occur{1};
        for (size_t j{i+1}; j < vet.size(); j++) {
            int elem2 = (vet[j] < 0) ? -vet[j] : vet[j];
            if (elem == elem2) {
                occur += 1;
            }
        }
        if (occur == maior_ocorrencia) {
            recorrentes.push_back(elem);
        }
    }
    return recorrentes;
}

/* Proximidade */

int briga(const std::vector<int>& vet) {
    if (vet.empty()) {
        return 0;
    }
    int brigas{0};

    for (size_t i{1}; i < vet.size() - 1; i++) {
        int elem{std::abs(vet[i])};
        int elem_esquerda{std::abs(vet[i - 1])};
        int elem_direita{std::abs(vet[i + 1])};
        if (elem > 50 && elem_esquerda > 30 && elem_direita > 30) {
            brigas += 1;
        }
    }
    return brigas;
}

std::vector<size_t> apaziguado(const std::vector<int> &vet) {
    if (vet.empty()) {
        return {};
    }
    std::vector<size_t> apaziguados;

    for (size_t i{0}; i < vet.size(); i++) {
        int elem{std::abs(vet[i])};
        if (elem > 80) {
            if (i > 0 && i < vet.size() - 1) {
                if (std::abs(vet[i - 1] < 10 || std::abs(vet[i + 1]) < 10)) {
                    apaziguados.push_back(i);
                }
            } else if (i == 0 && std::abs(vet[i + 1])) {
                apaziguados.push_back(i);
            } else if (std::abs(vet[i - 1] < 10)) {
                    apaziguados.push_back(i);
                }
            }
        }
    return apaziguados;
}

/* Sequ�ncias */

int _getSign(int num) {
    return num / std::abs(num);
}

std::vector<std::vector<int>> _getTimes(const std::vector<int> &vet) {
    int sign = _getSign(vet[0]), timesQtd = 0;
    std::vector<std::vector<int>> times(vet.size());

    size_t first_index = 0;
    size_t last_index = 0;
    for (size_t i = 1; i < vet.size(); i++) {
        if (_getSign(vet[i]) == sign) {
            last_index = i + 1;
        } else {
            for (size_t j = first_index; j < last_index; j++) {
                times[timesQtd].push_back(vet[j]);
            }
            first_index = i;
            last_index = i;
            timesQtd++;
            sign = _getSign(vet[i]);
        }
    }
    for (size_t j = first_index; j < last_index; j++) {
        times[timesQtd].push_back(vet[j]);
    }
    times.resize(timesQtd + 1);

    return times;
}

int quantos_times(const std::vector<int>& vet) {
    if (vet.empty()) {
        return 0;
    }
    auto times = _getTimes(vet);
    int cont = 0;

    for (auto time : times)
        if (time.size() >= 2)
            cont++;
    
    return cont;
}

std::vector<int> maior_time(const std::vector<int> &vet) {
    if (vet.empty()) {
        return {};
    }
    auto times = _getTimes(vet);
    int maior = 0;

    for (size_t i = 0; i < times.size(); i++) {
        if (times[i].size() > times[maior].size()) maior = i;
    }

    return times[maior];
}

int sem_time(const std::vector<int> &vet) {
    if (vet.empty()) {
        return {};
    }
    auto times = _getTimes(vet);
    int cont = 0;

    for (auto time : times) {
        if (time.size() == 0) cont++;
    }

    return cont;
}

/* Grupos */

std::vector<int> _getHomensQtd(const std::vector<int> &vet) {
    std::vector<int> res(100, 0);
    for (auto pessoa : vet) {
        if (pessoa > 0) res[pessoa]++;
    }

    return res;
}

std::vector<int> _getMulheresQtd(const std::vector<int> &vet) {
    std::vector<int> res(100, 0);
    for (auto pessoa : vet) {
        if (pessoa < 0) res[std::abs(pessoa)]++;
    }

    return res;
}

std::vector<int> _getQtd(const std::vector<int> &vet) {
    std::vector<int> res(100, 0);
    for (auto pessoa : vet) {
        res[std::abs(pessoa)]++;
    }

    return res;
}

int casais(const std::vector<int> &vet) {
    std::vector<int> homensQtd = _getHomensQtd(vet), mulheresQtd = _getMulheresQtd(vet);
    int casais = 0;

    for (size_t i = 1; i < homensQtd.size(); i++) {
        if (homensQtd[i] != 0 && mulheresQtd[i] != 0) {
            if (homensQtd[i] == mulheresQtd[i])
                casais += homensQtd[i];
            else
                casais += std::min(homensQtd[i], mulheresQtd[i]) % std::max(homensQtd[i], mulheresQtd[i]);
        }
    }

    return casais;
}

int trios(const std::vector<int> &vet) {
    if (vet.empty()) {
        return 0;
    }
    std::vector<int> qtd = _getQtd(vet);
    int trios = 0;
    for (auto pessoa : qtd) {
        if (pessoa % 3 == 0)
            trios += pessoa / 3;
    }

    return trios;
}

/* Altera��o */

std::vector<int> remove(const std::vector<int> vet, int pessoa) {
    if(vet.empty()) {
        return {};
    }
    std::vector<int> clone(vet);
    clone.erase(std::find(clone.begin(), clone.end(), pessoa));
    return clone;
}

std::vector<int> insert(const std::vector<int> vet, int pessoa, size_t pos) {
    if (pessoa > 99 || pessoa < -99 || pessoa == 0 || pos > vet.size()) {
        return vet;
    }
    std::vector<int> clone(vet);
    clone.insert(clone.begin() + pos, pessoa);
    return clone;
}

std::vector<int> dance(const std::vector<int> vet) {
    if (vet.empty()) {
        return vet;
    }
    std::vector<int> clone(vet);
    for (auto it = clone.begin(); it != clone.end() - 1; it++) {
        if (std::abs(*it) == std::abs(*(it + 1))) {
            clone.erase(it, it + 2);
            if(clone.empty()) {
                return clone;
            }
            it = clone.begin() - 1;
        }
    }

    return clone;
}

/* The End :) */
}