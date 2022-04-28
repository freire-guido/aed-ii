#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c) {
    auto min = c.cbegin();
    for (auto it = c.cbegin(); it != c.end(); it++) {
        if (*it < *min) {
            min = it;
        }
    }
    return *min;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c) {
    int tam = 1;
    typename Contenedor::value_type sum = *c.begin();
    for (auto it = ++c.cbegin(); it != c.end(); it++) {
        sum = sum + *it;
        tam++;
    }
    return sum / tam;
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta) {
    typename Iterator::value_type min = *desde;
    for (Iterator it = desde; it != hasta; it++) {
        if (*it < min) {
            min = *it;
        }
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta) {
    Iterator it = desde;
    int tam = 1;
    typename Iterator::value_type sum = *desde;
    for (it++; it != hasta; it++) {
        sum = sum + *it;
        tam++;
    }
    return sum / tam;
}

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem) {
    auto it = c.begin();
    while (it != c.end()) {
        if (*it == elem) {
            it = c.erase(it);
        } else {
            it++;
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c) {
    for (auto it = c.begin(); it != --c.end() && *it > *it++;)
    return it == --c.end();
     auto it = c.begin();
     while (it != --c.end()) {
         typename Contenedor::value_type pre = *it;
         it++;
         if (*it < pre) {
             return false;
         }
     }
     return true;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem) {
    std::pair<Contenedor, Contenedor> res;
    for (auto it = c.cbegin(); it != c.cend(); it++) {
        if (*it < elem) {
            res.first.insert(res.first.end(), *it);
        } else {
            res.second.insert(res.second.end(), *it);
        }
    }
    return res;
}

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res) {
    auto iter1 = c1.cbegin();
    auto iter2 = c2.cbegin();
    while (iter1 != c1.cend() && iter2 != c2.cend()) {
        if (*iter1 > *iter2) {
            res.insert(res.end(), *iter2);
            iter2++;
        } else {
            res.insert(res.end(), *iter1);
            iter1++;
        }
    }
    while (iter1 != c1.cend()) {
        res.insert(res.end(), *iter1);
        ++iter1;
    }
    while (iter2 != c2.cend()) {
        res.insert(res.end(), *iter2);
        ++iter2;
    }
}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H

