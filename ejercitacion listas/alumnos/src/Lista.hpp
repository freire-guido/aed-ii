#include "Lista.h"

Lista::Lista(): _pri{nullptr}, _ult{nullptr}, _lon{0} {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    Nodo* actual = _pri;
    if (_lon > 0) {
        while (actual->sig) {
            actual = actual->sig;
            delete actual->pre;
        }
        delete actual;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    this->~Lista();
    _lon = 0;
    if (aCopiar._lon > 0) {
        Nodo* actual = aCopiar._pri;
        while (actual->sig) {
            this->agregarAtras(actual->val);
            actual = actual->sig;
        }
        this->agregarAtras(actual->val);
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    _pri = new Nodo(elem, nullptr, _pri);
    if (_lon == 0) {
        _ult = _pri;
    }
    else if (_lon > 0) {
        _pri->sig->pre = _pri;
    }
    _lon++;
}

void Lista::agregarAtras(const int& elem) {
    _ult = new Nodo(elem, _ult, nullptr);
    if (_lon == 0) {
        _pri = _ult;
    }
    else if (_lon > 0) {
        _ult->pre->sig = _ult;
    }
    _lon++;
}

void Lista::eliminar(Nat i) {
    Nodo* iesimo = _pri;
    for (int n = 0; n < i; n++) {
        iesimo = iesimo->sig;
    }
    if (iesimo->pre) {
        iesimo->pre->sig = iesimo->sig;
    } else {
        _pri = iesimo->sig;
    }
    if (iesimo->sig) {
        iesimo->sig->pre = iesimo->pre;
    } else {
        _ult = iesimo->pre;
    }
    delete iesimo;
    _lon--;
}

int Lista::longitud() const {
    return _lon;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* iesimo = _pri;
    for (int n = 0; n < i; n++) {
        iesimo = iesimo->sig;
    }
    return iesimo->val;
}

int& Lista::iesimo(Nat i) {
    Nodo* iesimo = _pri;
    for (int n = 0; n < i; n++) {
        iesimo = iesimo->sig;
    }
    return iesimo->val;
}

void Lista::mostrar(ostream& o) {
    std::cout << "[";
    Nodo* actual = _pri;
    while (actual->sig) {
        std::cout << actual->val << ", ";
        actual = actual->sig;
    }
    std::cout << actual->val << "]";
}
