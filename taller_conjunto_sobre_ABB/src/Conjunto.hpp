
template <class T>
Conjunto<T>::Conjunto(): _raiz{nullptr} {}

template <class T>
Conjunto<T>::~Conjunto() {
    _destruir(_raiz);
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
    if (!_raiz) return;
    Nodo* padre = _raiz;
    Nodo* borrar = padre;
    bool eraRaiz = _raiz->valor == clave;
    bool esHijoIzq = padre->izq && clave == padre->izq->valor;;
    if (!eraRaiz) {
        // busco padre de z, guardo
        while (!esHijoIzq && (!padre->der || clave != padre->der->valor)) {
            if (clave < padre->valor && clave != padre->izq->valor) {
                padre = padre->izq;
            } else {
                padre = padre->der;
            }
            if (!padre) return;
            esHijoIzq = padre->izq && clave == padre->izq->valor;
        }
        // guardo z
        borrar = esHijoIzq ? padre->izq : padre->der;
    }
    Nodo* heredero = borrar->der;
    if (heredero) {
        // busco padre de y (menor en subarbol der. z), guardo padre
        if (heredero->izq) {
            Nodo* tutor = heredero;
            heredero = heredero->izq;
            while (heredero->izq) {
                tutor = heredero;
                heredero = heredero->izq;
            }
            tutor->izq = heredero->der;
            heredero->der = borrar->der;
        }
        if (!eraRaiz) {
            (esHijoIzq ? padre->izq : padre->der) = heredero;
        }
        heredero->izq = borrar->izq;
    } else {
        if (!eraRaiz) {
            (esHijoIzq ? padre->izq : padre->der) = borrar->izq;
        } else {
            heredero = borrar->izq;   
        }
    }
    if (eraRaiz) {
        _raiz = heredero;
    }
    delete borrar;
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

