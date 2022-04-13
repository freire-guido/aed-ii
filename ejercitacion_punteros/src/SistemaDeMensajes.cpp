#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes() : _conns() {}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if (registrado(id)) {
        delete _conns[id];
    }
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (registrado(id)) {
        delete _conns[id];
    }
    _conns[id] = NULL;
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != NULL;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    _proxies.push_back(new Proxy(&_conns[id]));
    return _proxies[_proxies.size() - 1];
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; i++) {
        delete _conns[i];
    }
    for (int i = 0; i < _proxies.size(); i++) {
        delete _proxies[i];
    }
}
