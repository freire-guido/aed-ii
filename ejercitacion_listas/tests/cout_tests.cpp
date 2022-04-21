#include "../src/Lista.h"
#include <iostream>

int main() {
    Lista l1;
    l1.agregarAdelante(1);
    l1.agregarAdelante(2);
    l1.agregarAdelante(3);
    l1.agregarAdelante(4);
    l1.agregarAdelante(5);
    std::cout << l1 << '\n';
    // Deberia decir [5, 4, 3, 2, 1]
    Lista l2;
    l2.agregarAdelante(1);
    std::cout << l2 << '\n';
    // Deberia decir [1]
    Lista l3;
    l3.agregarAdelante(1);
    l3.agregarAdelante(2);
    std::cout << l3 << '\n';
    // Deberia decir [2, 1]
}