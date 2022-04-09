#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    EXPECT_EQ(15 + 7, 22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    EXPECT_EQ(pow(10, 2), 100);
}

// Ejercicios 6..9
TEST(Aritmetica, potencia_general) {
    for(int i = 5; i <= 5; ++i) {
        EXPECT_EQ(pow(i, 2), i*i);
    }
}

TEST(Diccionario, obtener) {
    map<int, int> dicc;
    dicc[2] = 3;
    EXPECT_EQ(dicc[2], 3);
}

TEST(Diccionario, definir) {
    map<int, int> dicc;
    EXPECT_EQ(dicc.count(2), 0);
    dicc[2] = 10;
    EXPECT_EQ(dicc.count(2), 1);
}

TEST(Truco, inicio) {
    Truco tr;
    EXPECT_EQ(tr.puntaje_j1(), tr.puntaje_j2());
}

TEST(Truco, buenas) {
    Truco tr;
    EXPECT_FALSE(tr.buenas(1));
    for (int i = 0; i < 15; ++i) {
        tr.sumar_punto(1);
    }
    EXPECT_FALSE(tr.buenas(1));
    tr.sumar_punto(1);
    EXPECT_TRUE(tr.buenas(1));
    tr.sumar_punto(1); tr.sumar_punto(1);
    EXPECT_TRUE(tr.buenas(1));
}