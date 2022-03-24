#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                s.erase(s.begin() + j);
                j--;
            }
        }
    }
    return s;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> conj(s.begin(), s.end());
    return vector<int>(conj.begin(), conj.end());
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    return quitar_repetidos_v2(a) == quitar_repetidos_v2(b);
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return quitar_repetidos_v2(a) == quitar_repetidos_v2(b);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) { // reimplementar con res.find() - devuelve iterador
    map<int, int> res;
    for (int i = 0; i < s.size(); i++) {
        if (res.count(s[i]) == 0) {
            res[s[i]] = 1;
        } else {
            res[s[i]]++;
        }
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    for (int i = 0; i < s.size(); i++) {
        bool repetido = false;
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                s.erase(s.begin() + j);
                j--;
                repetido = true;
            }
        }
        if (repetido) {
            s.erase(s.begin() + i);
            i--;
        }
    }
    return(s);
}

// Ejercicio 7
template <typename T>
set<T> interseccion(set<T> a, set<T> b) {
    set<T> res;
    for (T elem: a) { // buscar forma de iterar directamente sobre el menor de a, b
        if (b.find(elem) != b.end()) {
            res.insert(elem);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int i = 0; i < s.size(); i++) {
        res[s[i] % 10].insert(s[i]);
    }
    return(res);
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < tr.size(); j++) {
            if (tr[j].first == str[i]) {
                str[i] = tr[j].second;
                j = tr.size();
            }
        }
    }
    return str;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i].libretas() == s[j].libretas()) {
                s.erase(s.begin() + j);
                j--;
            } else if (interseccion(s[i].libretas(), s[j].libretas()) != set<LU>()){
                return true;
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  map<set<LU>, Mail> res;
  for (int i = 0; i < s.size(); i++) {
      if (s[i].adjunto() && (res.count(s[i].libretas()) == 0 || res[s[i].libretas()].fecha() < s[i].fecha())) {
          res[s[i].libretas()] = s[i];
      }
  }
  return res;
}
