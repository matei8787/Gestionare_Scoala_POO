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
enum DISCIPLINE_POSIBILE { NIMIC, ROMANA, MATEMATICA, INFORMATICA, GEOGRAFIE, ISTORIE, ECONOMIE, FILOZOFIE, ENGLEZA, FRANCEZA, FIZICA, SPORT, DIMENSIUNE };
vector<DISCIPLINE_POSIBILE> discipline = { ROMANA, MATEMATICA, INFORMATICA, GEOGRAFIE, ISTORIE, ECONOMIE, FILOZOFIE, ENGLEZA, FRANCEZA, FIZICA, SPORT };
map<DISCIPLINE_POSIBILE, string> nume_disciplina = {
    {NIMIC , "Nimic"}, {ROMANA, "Romana"}, {MATEMATICA, "Matematica"}, {INFORMATICA, "Informatica"}, {GEOGRAFIE, "Geografie"}, {ISTORIE, "Istorie"},
    {ECONOMIE, "Economie"}, {FILOZOFIE, "Filozofie"}, {ENGLEZA, "Engleza"}, {FRANCEZA, "Franceza"}, {FIZICA, "Fizica"}, {SPORT, "Sport"}
};

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
    out<<d.zi<<"-"<<d.luna<<"-"<<d.an;
    return out;
}
struct Adrese_de_Contact
{
    string locuinta, email, telefon;
    Adrese_de_Contact()
    {
        locuinta = email = telefon = "";
    }
    Adrese_de_Contact& operator=(Adrese_de_Contact ad)
    {
        locuinta = ad.locuinta;
        email = ad.email;
        telefon = ad.telefon;
        return *this;
    }
    bool operator== (const Adrese_de_Contact& ad) const
    {
        return (this -> locuinta == ad.locuinta && this -> email == ad.email && this -> telefon == ad.telefon);
    }
};
Adrese_de_Contact make_adresa(string loc, string mail, string tel)
{
        Adrese_de_Contact a;
        a.email = mail;
        a.locuinta = loc;
        a.telefon = tel;
        return a;
}
struct Date_om
{
    string nume, prenume, cnp;
    Adrese_de_Contact contact;
    Date_om()
    {
        nume = prenume = cnp = "";
        contact = Adrese_de_Contact();
    }
    Date_om& operator=(Date_om dp)
    {
        nume = dp.nume;
        prenume = dp.prenume;
        cnp = dp.cnp;
        contact = dp.contact;
        return *this;
    }
    Data get_data_nastere()
    {
        Data ans = {(cnp[5]-'0')*10+cnp[6]-'0',(cnp[3]-'0')*10+cnp[4]-'0',(cnp[1]-'0')*10+cnp[2]-'0'};
        return ans;
    }

    bool operator==(const Date_om& om) const
    {
        return (this -> nume == om.nume && this -> prenume == om.prenume && this -> cnp == om.cnp && this -> contact == om.contact);
    }
};
Date_om make_om(string nume, string prenume, string cnp, Adrese_de_Contact ad)
{
    Date_om d;
    d.nume = nume;
    d.prenume = prenume;
    d.cnp = cnp;
    d.contact = ad;
    return d;
}
class Situatie
{
private:

    DISCIPLINE_POSIBILE disciplina;
    vector<int> note;
    set<Data> absente;
public:
    Situatie()
    {
        note = vector<int>(11, 0);
        disciplina = NIMIC;
    }
    DISCIPLINE_POSIBILE get_disciplina()
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
    void set_disciplina(DISCIPLINE_POSIBILE d)
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
    friend ostream& operator<< (ostream& out, const Situatie& s);
};
ostream& operator<< (ostream& out, const Situatie& s)
{
    out<<s.disciplina<<"\nNote: ";
    for ( int i = 1 ; i <= 10 ; i++ )
    {
        int aux = s.note[i];
        while ( aux )
        {
            cout<<i<<", ";
            aux--;
        }
    }
    cout<<"\nAbsente: ";
    for ( Data i : s.absente )
    {
        cout<<i<<'\n';
    }
    cout<<"\n\n";
}
