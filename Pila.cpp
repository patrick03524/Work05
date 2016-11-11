#include <iostream>
#include <algorithm>
#include "Pila.h"
#include <iterator>
#include <queue>
#include <cassert>
#include <vector>

using namespace std;

Cola::Cola(int longMax):lMax(longMax+1)
{
    elementos = new int[longMax];
    assert(elementos!= 0);
    ant = 0;
    post = lMax -1;
};
Cola::Cola(const Cola &c):lMax(c.lMax)
    ant = c.ant;
    post = c.post;
    elementos = new int[lMax];
    assert(elementos != 0);
    for (int i = ant; i != post; i = (i + 1) % lMax)
       elementos[i] = c.elementos[i];
    elementos [post] = c.elementos[post];
};
bool Cola::vacia() const
{
    return ((post + 1) % lMax)==ant;
}
bool Cola::llena() const
{
    return ((post + 2) % lMax) == ant;
}
Cola::cabecera()
{
    return elementos[ant];
}
void Cola::insert(const &elem)
{
    assert(!llena());

    post = (post + 1) % lMax;
    elementos[post] = elem;
}
void Cola::quite()
{
    assert(!vacia());
    ant = (ant + 1 ) % LMax;
}
int Cola::numElementos() const
{
    if (vacia())
        return 0;
    if (post > ant)
        return post - ant + 1;
    else
        return (lMax - ant + 1) + (post + 1);
}
Cola::~Cola()
{
    delete[] elementos;
}
