#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

class Cola{
private:
    const int *elementos;
    const int lMax;
    int ant;
    int post;
    bool llena() const;
public:
    Cola(int longMax = 100);
    Cola(const Cola &c);
    bool vacia() const;
    int cabecera();
    void insert(const int &elem);
    void quite();
    int numElementos() const;
    ~Cola();
};

#endif // PILA_H_INCLUDED
