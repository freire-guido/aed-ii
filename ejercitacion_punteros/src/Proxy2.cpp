#include "Proxy2.h"

#include <utility>

Proxy::Proxy(ConexionJugador** conn) : _conn(conn) {}

void Proxy::enviarMensaje(string msg) {
    (*_conn)->enviarMensaje(std::move(msg));
}