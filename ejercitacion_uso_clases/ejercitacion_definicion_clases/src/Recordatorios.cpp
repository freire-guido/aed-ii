#include <iostream>
#include <list>;

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {
    if (12 < mes || mes < 0) throw invalid_argument("mes debe estar entre 1 y 12");
    if (dias_en_mes(dia) < dia || dia < 0) throw invalid_argument("dia debe estar entre 1 y no superar los dias del mes");
}

int Fecha::mes() {
    return(mes_);
}

int Fecha::dia() {
    return(dia_);
}

ostream& operator<<(ostream& os, Fecha f) { // Aca no extiendo ostream porque no modifico la definicion de ostream (ver siguiente funcion)
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha f) { // Aca extiendo fecha porque es algo interno
    return (mes_ == f.mes() && dia_ == f.dia());
}
#endif

void Fecha::incrementar_dia() {
    if (dia_ + 1 > dias_en_mes(mes_)) {
        dia_ = 1;
        mes_++;
    } else {
        dia_++;
    }
}

// Ejercicio 11, 12

class Horario {
    public:
        Horario(uint h, uint m);
        uint hora();
        uint min();
        bool operator==(Horario h);
        bool operator<(Horario h);

    private:
        uint hora_;
        uint min_;
};

Horario::Horario(uint h, uint m) : hora_(h), min_(m) {}

uint Horario::hora() {
    return(hora_);
}

uint Horario::min() {
    return(min_);
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return(os);
}

bool Horario::operator==(Horario h) {
    return(hora_ == h.hora() && min_ == h.min());
}

bool Horario::operator<(Horario h) {
    return(hora_ < h.hora() || (hora_ == h.hora() && min_ < h.min()));
}

// Ejercicio 13
class Recordatorio {
    public:
        Recordatorio(Fecha f, Horario h, string m);
        Fecha fecha();
        Horario horario();
        string mensaje();

    private:
        Fecha f_;
        Horario h_;
        string m_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string m) : f_(f), h_(h), m_(m) {}

Fecha Recordatorio::fecha() { return(f_); }
Horario Recordatorio::horario() { return(h_); }
string Recordatorio::mensaje() { return(m_); }

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return(os);
}

// Ejercicio 14

class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();

    private:
        Fecha f_;
        list<Recordatorio> recordatorios_;
};

Agenda::Agenda(Fecha fecha_inicial) : f_(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_.push_back(rec);
}

void Agenda::incrementar_dia() {
    f_.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> recHoy;
    for (Recordatorio r: recordatorios_) {
        if (r.fecha() == this->hoy()) {
            recHoy.push_back(r);
        }
    }
    return(recHoy);
}

Fecha Agenda::hoy() { return(f_); }

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy() << endl << "=====" << endl;
    list<Recordatorio> recordatorios = a.recordatorios_de_hoy();
    recordatorios.sort([](Recordatorio a, Recordatorio b){ return(a.horario() < b.horario()); });
    for (Recordatorio r: recordatorios) {
        os << r << endl;
    }
    return(os);
}
