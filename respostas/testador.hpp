#pragma once

#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
std::string to_string(T value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

template <typename T, typename K>
void compare(const T& A, const K& B) {
    if (to_string(A) == to_string(B))
        std::cout << "\tok\n";
    else
        std::cout << '\t' << A << " != " << B << "\n";
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "{";
    for (int i = 0; i < (int) v.size(); i++)
        os << v[i] << (i + 1 < (int) v.size() ? ", " : "");
    os << "}";
    return os;
}
