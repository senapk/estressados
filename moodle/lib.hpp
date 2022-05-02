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
void check(const T& A, const K& B) {
    if (to_string(A) == to_string(B)) {
        std::cout << " ✓";
    } else {
        std::cout << " ✗";
        std::cout << '\n' << A << " != " << B << "\n";
        exit(1);
    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (int i = 0; i < (int) v.size(); i++)
        os << (i != 0 ? "," : "") << v[i];
    os << "]";
    return os;
}

template <typename T>
T read(std::istream& is) {
    T value;
    is >> value;
    return value;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vet) {
    std::stringstream token(read<std::string>(is));
    while (token.good()) {
        char trash { 0 };
        T value;
        token >> trash >> value;
        if (token)
            vet.push_back(value);
    }
    return is;
}

template <typename T>
std::string fmt(std::vector<T> data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? ", " : "") << *it;
    ss << "]";
    return ss.str();
}

std::string fmt(bool value) {
    return value ? "true" : "false";
}

// parse a stream into a tuple of values
template <typename... Args>
auto parse(std::istream& is) {
    std::tuple<Args...> t;
    std::apply([&is](auto&&... args) {((is >> args), ...);}, t);
    return t;
}