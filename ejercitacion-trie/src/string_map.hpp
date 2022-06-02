template <typename T>
string_map<T>::string_map(): _raiz{new Nodo()}, _size{0} {}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    *this = d;
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    delete _raiz;
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& p) {
    Nodo* n = _raiz;
    for (const char& c: p.first) {
        if (n->siguientes) {
            n = n->siguientes[c];
        } else {
            n->siguientes = new Nodo*[256];
            n = n->siguientes[c];
        }
    }
    n->definicion = new T(p.second);
    _size++;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    bool nueva = false;
    Nodo* n = _raiz;
    for (const char& c: clave) {
        if (n->siguientes) {
            n = n->siguientes[c];
        } else {
            n->siguientes = new Nodo*[256];
            n = n->siguientes[c];
            nueva = true;
        }
    }
    if (nueva) {
        _size++;
    }
    return *n->definicion;
}


template <typename T>
int string_map<T>::count(const string& clave) const {
    Nodo* n = _raiz;
    for (const char& c: clave) {
        if (n->siguientes) {
            n = n->siguientes[c];
        } else {
            return 0;
        }
    }
    if (n->definicion) {
        return 1;
    } else {
        return 0;
    }
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* n = _raiz;
    for (const char& c: clave) {
        n = n->siguientes[c];
    }
    return *n->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* n = _raiz;
    for (const char& c: clave) {
        n = n->siguientes[c];
    }
    return *n->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* n = _raiz;
    Nodo* ultn = nullptr;
    int ulti = 0;
    for (int i = 0; i < clave.size(); i++) {
        if (n->definicion || n->hijos() > 1) {
            ultn = n;
            ulti = i;
        }
        n = n->siguientes[clave[i]];
    }
    if (ultn) {
        delete ultn->siguientes[clave[ulti]];
    } else {
        delete _raiz;
    }
    _size--;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}