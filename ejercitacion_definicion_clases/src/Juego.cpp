#include <utility>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

struct Pocion {
    Pocion(int m, int r, int t) : movimientos(m), restantes(r), turnos(t) {};
    int movimientos;
    int restantes;
    int turnos;
};

class Juego {
    using Pos = pair<int, int>;
    char IZQUIERDA = '^';
    char DERECHA = 'v';
    char ARRIBA = '<';
    char ABAJO = '>';
    public:
        Juego(uint casilleros, Pos pos_inicial);
        Pos posicion_jugador();
        uint turno_actual();
        void mover_jugador(char dir);
        void ingerir_pocion(uint movimientos, uint turnos);

    private:
        uint turno_;
        vector<Pocion> pociones_;
        uint casilleros_;
        Pos pos_;
};

Juego::Juego(uint casilleros, Pos pos_inicial) : casilleros_(casilleros), pos_(pos_inicial) {}

Pos Juego::posicion_jugador() { return(pos_); }
uint Juego::turno_actual() { return(turno_); }
void Juego::mover_jugador(char dir) {
    if (pos_.second < casilleros_ - 1 &&  dir == Juego::ARRIBA) {
        pos_.second++;
    }
    else if (pos_.second > 0 && dir == Juego::ABAJO) {
        pos_.second--;
    }
    else if (pos_.first < casilleros_ - 1 && dir == Juego::DERECHA) {
        pos_.first++;
    }
    else if (pos_.first > 0 && dir == Juego::IZQUIERDA) {
        pos_.first--;
    }
//    Se insiste con dejar al jugador hacer movimientos invalidos (y perder movimientos con ello)
//    else {
//        throw invalid_argument("mover_jugador(char) solo admite ^v<>");
//    }
    if (pociones_.empty()) {
        turno_++;
    } else {
        int i = 0;
        while (pociones_[i].restantes == 0) {
            i++;
        }
        if (i == pociones_.size() - 1 && pociones_[i].restantes == 1) {
            turno_++;
            for (int i = 0; i < pociones_.size(); i++) {
                pociones_[i].restantes = pociones_[i].movimientos;
                pociones_[i].turnos--;
                if (pociones_[i].turnos == 0) {
                    pociones_.erase(pociones_.begin() + i);
                    i--;
                }
            }
        } else {
            pociones_[i].restantes--;
        }
    }
}

void Juego::ingerir_pocion(uint movimientos, uint turnos) {
    pociones_.push_back(Pocion(movimientos, movimientos, turnos));
}
