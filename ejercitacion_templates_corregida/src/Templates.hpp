template<typename T>
T cuadrado(T t) {
    return t*t;
}

template<typename Contenedor, typename Elem>
bool contiene(Contenedor c, Elem e) {
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == e) {
            return true;
        }
    }
    return false;
}

template<typename Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() >= b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

template<typename Contenedor, typename Elem>
Elem maximo(Contenedor c) {
    Elem max = c[0]; // c tiene al menos un elem
    for (int i = 1; i < c.size(); i++) {
        if (max < c[i]) {
            max = c[i];
        }
    }
    return max;
}

