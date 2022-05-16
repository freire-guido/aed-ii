
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
    bool esRaiz = false;
    Nodo* padre = _raiz;
    if (padre && padre->valor == clave) {
        padre = new Nodo(_raiz->valor + 1);
        padre->izq= _raiz;
        esRaiz = true;
    }
    // busco al padre del nodo a borrar
    bool esHijoIzq = padre->izq && padre->izq->valor == clave;
    while (!(esHijoIzq || (padre->der && padre->der->valor == clave))) {
        if (padre->izq && clave < padre->izq->valor) {
            padre = padre->izq;
        } else {
            padre = padre->der;
        }
        esHijoIzq = padre->izq && padre->izq->valor == clave;
    }
    if (padre) {
        // busco al siguiente del nodo a borrar.
        Nodo* borrar = esHijoIzq ? padre->izq : padre->der;
        if (borrar->der && borrar->der->izq) {
            Nodo* sucesor = borrar->der;
            while(sucesor->izq->izq) {
                sucesor = sucesor->izq;
            }
            borrar->der = sucesor->izq;
            sucesor->izq = borrar->der->der;
            borrar->der->der = sucesor;    
        }
        (esHijoIzq ? padre->izq : padre->der) = borrar->der;
        if (borrar->der) {
            borrar->der->izq = borrar->izq;
        }
        delete borrar;
    }
    if (esRaiz) {
        _raiz = padre->izq;
        delete padre;
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

