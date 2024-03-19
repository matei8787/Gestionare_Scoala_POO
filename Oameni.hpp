#pragma once

#include "util.hpp"

class Elev
{
private:
    vector<Situatie> situatii;
    Date_om date_personale;
public:
    Elev()
    {
        situatii.resize(DIMENSIUNE);
        for ( int i = 0 ; i < discipline.size() ; i++ )
        {
            situatii[i].set_disciplina(discipline[i]);
        }
        date_personale = Date_om();
    }
    Elev(Date_om date)
    {
        date_personale = date;
        situatii.resize(DIMENSIUNE);
        for ( int i = 0 ; i < discipline.size() ; i++ )
        {
            situatii[i].set_disciplina(discipline[i]);
        }
    }
    Date_om& get_date()
    {
        return this -> date_personale;
    }
    vector<Situatie>& get_situatii()
    {
        return this -> situatii;
    }
    Situatie& get_situatie(int i)
    {
        return situatii[i];
    }
    Situatie& get_situatie(DISCIPLINE_POSIBILE d)
    {
        for ( int i = 0 ; i < situatii.size() ; i++ )
        {
            if ( situatii[i]. get_disciplina() == d )
            {
                return situatii[i];
            }
        }
    }
    void set_date(Date_om d)
    {
        date_personale = d;
    }
    bool operator==(const Elev& e) const
    {
        return (this -> date_personale == e.date_personale);
    }
    friend ostream& operator<< (ostream& out, const Elev& e);
};
ostream& operator<< (ostream& out, const Elev& e)
{
    out<<e.date_personale.nume<<" "<<e.date_personale.prenume<<": \n";
    for (int i = 0 ; i < e.situatii.size() ; i++ )
    {
        cout<<e.situatii[i];
    }
}

class Clasa
{
private:
    int nr_sala, nr_clasa;
    vector<Elev> elevi;
public:
    Clasa()
    {
        nr_sala = 0;
        nr_clasa = -1;
    }
    Clasa(int sala)
    {
        nr_sala = sala;
        nr_clasa = -1;
    }
    Clasa(int sala, int clasa)
    {
        nr_sala = sala;
        nr_clasa = clasa;
    }
    Clasa(int sala, int clasa, vector<Elev> el)
    {
        nr_sala = sala;
        nr_clasa = clasa;
        elevi = el;
    }
    int get_sala()
    {
        return nr_sala;
    }
    int get_clasa()
    {
        return nr_clasa;
    }
    vector<Elev>& get_elevi()
    {
        return elevi;
    }
    void set_sala(int nr)
    {
        nr_sala = nr;
    }
    void set_clasa(int nr)
    {
        nr_clasa = nr;
    }
    void adauga_elev(Elev e)
    {
        elevi.push_back(e);
    }
    void sterge_elev(Elev e)
    {
        for ( int i = 0 ; i < elevi.size() ; i++ )
        {
            if ( elevi[i] == e )
            {
                elevi.erase(elevi.begin()+i);
                return;
            }
        }
        ///nu am gasit elevul
        return;
    }
    bool operator== (const Clasa& c) const
    {
        return (this -> nr_clasa == c.nr_clasa && this -> nr_sala == c.nr_sala);
    }
    bool operator!= (const Clasa& c) const
    {
        return !(this -> nr_clasa == c.nr_clasa && this -> nr_sala == c.nr_sala);
    }
};
Clasa NMK = Clasa(-1, -1);
class Profesor
{
private:
    DISCIPLINE_POSIBILE disciplina;
    Date_om date_personale;
    vector<Clasa> clase;
public:
    Profesor()
    {
        disciplina = NIMIC;
        date_personale = Date_om();
    }
    Profesor(DISCIPLINE_POSIBILE d)
    {
        disciplina = d;
        date_personale = Date_om();
    }
    DISCIPLINE_POSIBILE get_disciplina()
    {
        return disciplina;
    }
    Date_om& get_date()
    {
        return date_personale;
    }
    vector<Clasa>& get_clase()
    {
        return clase;
    }
    Clasa& get_clasa(Elev e)
    {
        for ( Clasa& c : clase )
        {
            for ( Elev& el : c.get_elevi() )
            {
                if ( e == el )
                    return c;
            }
        }
        return NMK;
    }
    void adauga_clasa(const Clasa& c)
    {
        clase.push_back(c);
    }
    void set_disciplina(DISCIPLINE_POSIBILE d)
    {
        disciplina = d;
    }
    void set_date(Date_om d)
    {
        date_personale = d;
    }
    void adauga_nota(Elev e, int nr)
    {
        if ( get_clasa(e) != NMK )
            e.get_situatie(disciplina).adauga_nota(nr);
        else
            cout<<"N-am elevul la clasa\n";
    }
    void adauga_absenta(Elev e, Data d)
    {
        e.get_situatie(disciplina).adauga_absenta(d);
    }
    void sterge_nota(Elev e, int nr)
    {
        e.get_situatie(disciplina).sterge_nota(nr);
    }
    void motiveaza_absenta(Elev e, Data d)
    {
        e.get_situatie(disciplina).motiveaza_absenta(d);
    }
    bool operator== (const Profesor& p) const
    {
        return (this -> date_personale == p.date_personale);
    }
};

class Scoala
{
private:
    string nume;
    vector<Profesor> profesori_angajati;
    map<string, Clasa> clase;
public:
    Scoala()
    {

    }
    Scoala(string nume)
    {
        this -> nume = nume;
    }
    Scoala(vector<Profesor> profesori)
    {
        profesori_angajati = profesori;
    }
    Scoala(map<string, Clasa> clase)
    {
        this -> clase = clase;
    }
    Scoala(string nume, vector<Profesor> profesori, map<string, Clasa> clase)
    {
        this -> nume = nume;
        profesori_angajati = profesori;
        this -> clase = clase;
    }
    vector<Profesor>& get_profesori()
    {
        return profesori_angajati;
    }
    Profesor* get_profesor(string nume, string prenume, DISCIPLINE_POSIBILE d)
    {
        for (Profesor p : profesori_angajati )
        {
            if ( p.get_date().nume == nume && p.get_date().prenume == prenume && p.get_disciplina() == d )
            {
                Profesor* profl = &p;
                return profl;
            }
        }
    }
    map<string, Clasa>& get_clase()
    {
        return clase;
    }
    string get_clasa(const Clasa& c)
    {
        for ( auto i = clase.begin() ; i != clase.end() ; i++ )
        {
            if ( i -> second == c )
                return i -> first;
        }
    }
    Clasa& get_clasa(Elev e)
    {
        for ( auto& i : clase )
        {
            for ( Elev& el : i.second.get_elevi() )
            {
                if ( e == el )
                    return i.second;
            }
        }
    }
};

class Admin
{
private:
    Date_om date_personale;
    Scoala scoala;
public:
    Admin()
    {
        date_personale = Date_om();
    }
    Admin(Date_om d)
    {
        date_personale = d;
    }
    Admin(Date_om om, Scoala s)
    {
        date_personale = om;
        scoala = s;
    }
    Date_om& get_date()
    {
        return this -> date_personale;
    }
    Scoala& get_scoala()
    {
        return this -> scoala;
    }
    void set_om(Date_om om)
    {
        date_personale = om;
    }
    void set_scoala(Scoala s)
    {
        scoala = s;
    }
    void angajeaza_profesor(Profesor p)
    {
        scoala.get_profesori().push_back(p);
    }
    void concediaza_profesor(Date_om p)
    {
        vector<Profesor> &profesori = scoala.get_profesori();
        for ( int i = 0 ; i < profesori.size() ; i++ )
        {
            if ( profesori[i].get_date() == p )
            {
                profesori.erase(profesori.begin() + i);
                i--;
            }
        }
    }
    void concediaza_profesor(Profesor p)
    {
        vector<Profesor>& profesori = scoala.get_profesori();
        for ( int i = 0 ; i < profesori.size() ; i++ )
        {
            if ( profesori[i] == p )
            {
                profesori.erase(profesori.begin() + i);
            }
        }
    }
    void adauga_clasa(string id, Clasa c)
    {
        scoala.get_clase()[id] = c;
    }
    void sterge_clasa(string id)
    {
        if ( scoala.get_clase().find(id) != scoala.get_clase().end() )
        {
            scoala.get_clase().erase(id);
        }
    }
    void sterge_clasa(Clasa c)
    {
        for ( auto i = scoala.get_clase().begin() ; i != scoala.get_clase().end() ; i++ )
        {
            if ( i -> second == c )
            {
                scoala.get_clase().erase(i);
                return;
            }
        }
    }
    void inmatriculeaza_copil(Elev e, string id_clasa)
    {
        scoala.get_clase()[id_clasa].adauga_elev(e);
    }
    void exmatriculeaza_elev(Elev e, string id_clasa)
    {
        scoala.get_clase()[id_clasa].sterge_elev(e);
    }
    void inmatriculeaza_copil(Elev e, Clasa& c)
    {
        c.adauga_elev(e);
    }
    void exmatriculeaza_elev(Elev e, Clasa& c)
    {
        for ( int i = 0 ; i < c.get_elevi().size() ; i++ )
        {
            if ( c.get_elevi()[i] == e )
            {
                c.get_elevi().erase(c.get_elevi().begin() + i);
                return;
            }
        }
    }
    void exmatriculeaza_elev(Elev e)
    {
        map<string, Clasa> clase = scoala.get_clase();
        for ( auto i = clase.begin() ; i != clase.end() ; i++ )
        {
                vector<Elev> el = i -> second.get_elevi();
                for ( int j = 0 ; j < el.size() ; j++ )
                {
                    if ( e == el[j] )
                    {
                        el.erase(el.begin() + j);
                    }
                }
        }
    }
    void inregistreaza_prof_la_clasa(Profesor* p, const Clasa& c)
    {
        vector<Clasa>& aux = p ->get_clase();
        aux.push_back(c);
    }
    void muta_elev(Elev e, Clasa& c1, Clasa& c2)
    {
        c1.sterge_elev(e);
        c2.adauga_elev(e);
    }
};
