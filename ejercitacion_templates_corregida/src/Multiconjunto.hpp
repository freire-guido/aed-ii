#include "Diccionario.hpp"

template<typename T>
class Multiconjunto {
public:
    Multiconjunto(): _apariciones{Diccionario<T, int>()} {}
    void agregar(T x) {
        if (_apariciones.def(x)) {
            _apariciones.definir(x, _apariciones.obtener(x) + 1);
        } else {
            _apariciones.definir(x, 1);
        }
//        _apariciones.definir(x, 1 + _apariciones.def(x) ? _apariciones.obtener(x) : 0); pq no funca??
    }
    int ocurrencias(T x) const {
        return _apariciones.def(x) ? _apariciones.obtener(x) : 0;
    }
    bool operator<=(Multiconjunto<T> otro) const {
        std::vector<T> claves_ord = _apariciones.claves();
        for (int i = 0; i < claves_ord.size(); i++) {
            if (!(this->ocurrencias(claves_ord[i]) <= otro.ocurrencias(claves_ord[i]))) {
                return false;
            }
        }
        return true;
    }
private:
    Diccionario<T, int> _apariciones;
};