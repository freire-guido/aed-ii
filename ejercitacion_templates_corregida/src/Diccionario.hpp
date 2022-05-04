#include <cassert>
#include <vector>

template<typename Clave, typename Valor>
class Diccionario {
public:
	Diccionario() {};
	void definir(Clave k, Valor v) {
        for (unsigned int i = 0; i < _asociaciones.size(); i++) {
            if (_asociaciones[i].clave == k) {
                _asociaciones[i].valor = v;
                return;
            }
        }
        _asociaciones.push_back(Asociacion(k, v));
    }
	bool def(Clave k) const {
        for (unsigned int i = 0; i < _asociaciones.size(); i++) {
            if (_asociaciones[i].clave == k) {
                return true;
            }
        }
        return false;
    }
	Valor obtener(Clave k) const {
        for (unsigned int i = 0; i < _asociaciones.size(); i++) {
            if (_asociaciones[i].clave == k) {
                return _asociaciones[i].valor;
            }
        }
        assert(false);
    }
    std::vector<Clave> claves() const {
        std::vector<Clave> claves;
        for (int i = 0; i < _asociaciones.size(); i++) {
            claves.push_back(_asociaciones[i].clave);
        }
        std::vector<Clave> claves_ord; // El enunciado pide este tipo de sort
        for (int i = 0; i < claves.size();) {
            Clave min = i;
            for (int j = i + 1; j < claves.size(); j++) {
                if (!(claves[min] <= claves[j])) { // No tengo operator>
                    min = j;
                }
            }
            claves_ord.push_back(claves[min]);
            claves.erase(claves.begin() + min);
        }
        return claves_ord;
    }
private:
	struct Asociacion {
		Asociacion(Clave k, Valor v): clave{k}, valor{v} {}
		Clave clave;
		Valor valor;
	};
	std::vector<Asociacion> _asociaciones;
};