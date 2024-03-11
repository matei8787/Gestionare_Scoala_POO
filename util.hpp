#pragma once

#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class Elev;
class Profesor;
class Admin;

struct Data
{
    int zi, luna, an;
    friend ostream& operator << (ostream& out, const Data &d);
    bool operator< (const Data& d) const
    {
        if ( d.an == this -> an )
        {
            if ( d.luna == this -> luna )
                return this -> zi < d.zi;
            return this -> luna < d.luna;
        }
        return this -> an < d.an;
    }
    bool operator== (const Data& d) const
    {
        return (this -> an == d.an && this -> luna == d.luna && this -> zi == d.zi);
    }
    bool operator> (const Data& d) const
    {
        return !(*this == d || *this < d);
    }
};
ostream& operator << (ostream& out, const Data &d)
{
    out<<d.zi<<" "<<d.luna<<" "<<d.an;
    return out;
}

struct Adrese_de_Contact
{
    string locuinta, email, telefon;
};
class Situatie
{
private:

    string disciplina;
    vector<int> note;
    set<Data> absente;
public:
    Situatie()
    {
        note.resize(11);
    }
    string get_disciplina()
    {
        return disciplina;
    }
    vector<int> get_note()
    {
        return note;
    }
    set<Data> get_absente()
    {
        return absente;
    }
    void set_disciplina(string d)
    {
        disciplina = d;
    }
    void adauga_nota(int nota)
    {
        note[nota]++;
    }
    void sterge_nota(int nota)
    {
        if ( note[nota] > 0 )
            note[nota]--;
    }
    void adauga_absenta(Data d)
    {
        absente.insert(d);
    }
    void motiveaza_absenta(Data d)
    {
        if ( absente.find(d) != absente.end() )
            absente.erase(d);
    }
    int get_suma_note()
    {
        int ans = 0;
        for ( int i = 1 ; i <= 10 ; i++ )
            ans += i * note[i];
        return ans;
    }
    int get_cate_note()
    {
        return accumulate(note.begin(), note.end(), 0);
    }
    double get_media()
    {
        return 1.0*get_suma_note()/get_cate_note();
    }
};