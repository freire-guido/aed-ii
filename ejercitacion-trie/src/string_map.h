#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    string_map();

    /**
    CONSTRUCTOR POR COPIA
    * Construye un diccionario por copia.
    **/
    string_map(const string_map<T>& aCopiar);

    /**
    OPERADOR ASIGNACION
     */
    string_map& operator=(const string_map& d);

    /**
    DESTRUCTOR
    **/
    ~string_map();

    /**
    INSERT 
    * Inserta un par clave, valor en el diccionario
    **/
    void insert(const pair<string, T>&);

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(const string &key) const;

    /**
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    -- Versión modificable y no modificable
    **/
    const T& at(const string& key) const;
    T& at(const string& key);

    /**
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    **/
    void erase(const string& key);

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    /**
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
    bool empty() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
    T &operator[](const string &key);

private:

    struct Nodo {
        const unsigned int sz = 256;
        Nodo** siguientes;
        T* definicion;
        Nodo(): siguientes{new Nodo*[256]()}, definicion{nullptr} {}
        Nodo(T* def): siguientes{new Nodo*[256]()}, definicion{def} {}
        ~Nodo() {
            delete definicion;
            for (int i = 0; i < 256; i++) {
                if (siguientes[i]) {
                    delete siguientes[i];
                }
            }
            delete[] siguientes;
        }
        Nodo(const Nodo& n):  siguientes{new Nodo*[256]()}, definicion{n.definicion ? new T(*n.definicion) : nullptr} {
            for (int i = 0; i < 256; i++) {
                if (n.siguientes[i]) {
                    siguientes[i] = new Nodo(*n.siguientes[i]);
                }
            }
        }

        unsigned int hijos() {
            unsigned int res = 0;
            for (int i = 0; i < 256; i++) {
                if (siguientes[i]) {
                    res++;
                }
            }
            return res;
        }
    };

    Nodo* _raiz;
    int _size;
    // void _destruir(Nodo* n) {
    //     delete n->definicion;
    //     for (int i = 0; i < 256; i++) {
    //         if (n->siguientes[i]) {
    //             _destruir(n->siguientes[i]);
    //         }
    //     }
    //     delete[] n->siguientes;
    //     delete n;
    // }
};

#include "string_map.hpp"

#endif // STRING_MAP_H_
