#pragma once

#include <iostream>
#include <vector>

template <typename T>
void testar(const T& A, const T& B) {
    if (A == B)
        std::cout << "\tok\n";
    else
        std::cout << '\t' << A << " != " << B << "\n";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

bool operator==(const std::vector<int>& A, const std::vector<int>& B) {
    if (A.size() != B.size())
        return false;
    for (int i = 0; i < (int) A.size(); i++)
        if (A[i] != B[i])
            return false;
    return true;
}