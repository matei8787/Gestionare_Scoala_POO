#include "util.hpp"
int main()
{
    Situatie s;
    Data d1 = {1, 1, 2001}, d2 = {2, 1, 2001};
    s.adauga_absenta(d1);
    s.adauga_absenta(d2);
    s.motiveaza_absenta(d1);
    set<Data> absen = s.get_absente();
    for ( Data abs : absen )
    {
        cout<<abs<<" ";
    }
}