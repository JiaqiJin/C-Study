#pragma once
#include<string>
class InfoType
{
public:
    enum Info
    {
        WARNING,
        ERROR,
        FATAL
    };
};

class Debug {
public:
    constexpr Debug(InfoType::Info inf, bool b = true) : hw(b), io(b), other(b), info(inf){
    }
    constexpr Debug(bool h, bool i, bool o, InfoType::Info inf) :
        hw(h), io(i), other(o) , info(inf){
    }

    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { hw = b; }
private:
    bool hw; // hardware errors other than IO errors
    bool io; // IO errors
    bool other; // other errors
    InfoType::Info info;
};
/*
static member functions are not bound to any object
Objects do not contain data associated with static data members.
*/
class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string onwer;
    double amount;
    static constexpr int period = 30;
    static double interestRate;
    static double initRate();
};

double Account::initRate()
{
    //int i = Account::period;
    interestRate ++;
    return interestRate;
}

void Account::rate(double vale)
{
    interestRate = vale;
}


/*
Los miembros de datos no est�ticos existen en cada objeto del tipo de clase.
Los miembros de datos est�ticos existen independientemente de cualquier objeto de esta clase.
Cada miembro de datos est�ticos es un objeto asociado con una clase, no asociado con un objeto de esa clase.
declaraci�n:
Agregue la palabra clave static antes de la declaraci�n.
utilizar:
Utilice el operador de alcance :: acceso directo a miembros est�ticos: r = Cuenta :: tasa ();
Tambi�n puede utilizar el acceso a objetos: r = ac.rate ();
definici�n:
No agregue est�tica al definir fuera de la clase.
inicializaci�n:
Por lo general, no se inicializa dentro de la clase, pero se inicializa cuando se define, como double Account :: interestRate = initRate ();
Si debe definirse dentro de la clase, debe ser un constexpr de un tipo constante literal.
*/
