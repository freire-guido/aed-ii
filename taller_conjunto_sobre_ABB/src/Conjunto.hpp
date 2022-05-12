
template <class T>
Conjunto<T>::Conjunto(): _raiz{nullptr} {}

template <class T>
Conjunto<T>::~Conjunto() {
    // delete _raiz;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* nodoActual = _raiz;
    while (nodoActual) {
        if (clave == nodoActual->valor) {
            return true;
        } else if (clave < nodoActual->valor) {
            nodoActual = nodoActual->izq;
        } else {
            nodoActual = nodoActual->der;
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!_raiz) {
        _raiz = new Nodo(clave);
    } else {
        Nodo* nodoActual = _raiz;
        while (clave != nodoActual->valor) {
            if (clave < nodoActual->valor) {
                if (!nodoActual->izq) {
                    nodoActual->izq = new Nodo(clave);
                }
                nodoActual = nodoActual->izq;
            } else {
                if (!nodoActual->der) {
                    nodoActual->der = new Nodo(clave);
                }
                nodoActual = nodoActual->der;
            }
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* nodoActual = _raiz;
    if (nodoActual && nodoActual->valor == clave) {
        delete nodoActual;
        _raiz = nullptr;
    }
    while (nodoActual) {
        if (clave < nodoActual->valor) {
            Nodo* hijoIzq = nodoActual->izq;
            if (hijoIzq && hijoIzq->valor == clave) {
                delete hijoIzq;
                nodoActual->izq = nullptr;
            }
            nodoActual = hijoIzq;
        } else {
            Nodo* hijoDer = nodoActual->der;
            if (hijoDer && hijoDer->valor == clave) {
                delete hijoDer;
                nodoActual->der = nullptr;
            }
            nodoActual = nodoActual->der;
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* nodoActual = _raiz;
    while (clave != nodoActual->valor) {
        if (clave < nodoActual->valor) {
            nodoActual = nodoActual->izq;
        } else {
            nodoActual = nodoActual->der;
        }
    }
    if (nodoActual->der) {
        return _minimo(nodoActual->der);
    } else {
        nodoActual = _raiz;
        Nodo* inStack[nodoActual->profundidad()];
        int i = 0;
        for (; clave != nodoActual->valor; i++) {
            inStack[i] = nodoActual;
            if (clave < nodoActual->valor) {
                nodoActual = nodoActual->izq;
            } else {
                nodoActual = nodoActual->der;
            }
        }
        while (inStack[--i]->valor < clave);
        return inStack[i]->valor;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* nodoActual = _raiz;
    while(nodoActual->izq) {
        nodoActual = nodoActual->izq;
    }
    return nodoActual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* nodoActual = _raiz;
    while(nodoActual->der) {
        nodoActual = nodoActual->der;
    }
    return nodoActual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _raiz ? _raiz->hijos() : 0;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream& os) const {

}

