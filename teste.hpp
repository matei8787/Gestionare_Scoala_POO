#pragma once

///TODO testez chestii
#include "Oameni.hpp"



void make_admin()
{
}
void make_scoala()
{


}
void make_clase()
{

}
void baga_copii()
{

}
void pre()
{

}
void afiseaza_profi(Scoala s)
{
    for ( Profesor& p : s.get_profesori() )
    {
        cout<<p.get_date().nume<<" "<<p.get_date().prenume<<" preda la clasele ";
        for ( Clasa& c : p.get_clase() )
        {
            cout<<c.get_clasa()<<" ";
        }
        cout<<endl;
    }
}
void afiseaza_copii(Clasa c)
{
    for ( Elev e : c.get_elevi() )
    {
        cout<<e.get_date().nume<<" "<<e.get_date().prenume<<" invata la clasa "<<c.get_clasa()<<'\n';
    }
}
void testeaza()
{
    Scoala s("Liceul din mijloc");
    Admin a(make_om("Bentley", "Bob", "50406184000000", make_adresa("O iei in fata, faci dreapta, si te duci...", "serios@confident.smecher", "07noi2")), s);
    Elev marcel(
                make_om("Ionescu",
                                 "Marcel",
                                 "1263748139",
                                 Adrese_de_Contact()));
    Elev mirel(make_om("Marinescu", "Mirel-Mugurel-Mihnea", "5618391827", Adrese_de_Contact()));
    string litere = "ABC";
    string classe[] = {"V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};
    string idcls;
    for ( int i = 0 ; i < 8 ; i++ )
    {
        for ( int j = 0 ; j < litere.size() ; j++ )
        {
            idcls = classe[i] + " " + litere[j];
            Clasa c(i*8+j, i+5);
            int ceva = 5;
            a.adauga_clasa(idcls, c);
        }
    }
    for ( int i = 0 ; i < discipline.size() ; i++ )
    {
        Profesor p = Profesor(discipline[i]);
        p.set_date(make_om("Profu de", nume_disciplina[discipline[i]], "1690413", make_adresa("Dupa colt", "blazeit69420@hotmail.xxx", "07n-am cartela")));
        a.angajeaza_profesor(p);
    }
    a.inmatriculeaza_copil(marcel, "VII B");
    a.inmatriculeaza_copil(mirel, "VII B");
    Clasa cla = a.get_scoala().get_clase()["VII B"];
    for ( auto cl : a.get_scoala().get_clase() )
    {
        afiseaza_copii(cl.second);
    }
    for ( int i = 0 ; i < discipline.size() ; i++ )
    {
        Profesor* p = a.get_scoala().get_profesor("Profu de", nume_disciplina[discipline[i]], discipline[i]);
        a.inregistreaza_prof_la_clasa(p, cla);
        for ( Clasa c : p -> get_clase() )
        {
            cout<<c.get_sala()<<'\n';
        }
        for ( Profesor pr : a.get_scoala().get_profesori() )
        {
            if ( pr.get_disciplina() == p -> get_disciplina() )
            {
                if ( &pr == p )
                {
                    cout<<"E bine";
                }
                else
                {
                    cout<<"E prost";
                }
            }
        }
        if ( discipline[i] == SPORT )
        {
            p->adauga_nota(marcel, 5);
            p->adauga_nota(mirel, 10);
        }
        else
        {
            p->adauga_nota(marcel, 10);
            p->adauga_nota(mirel, 5);
        }
    }
    afiseaza_profi(a.get_scoala());
    /*a.muta_elev(mirel, cla, a.get_scoala().get_clase()["VII C"]);
    Data d1 = {1, 1, 2024}, d2 = {2, 1, 2024}, d3 = {4, 1, 2024};
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).adauga_absenta(mirel, d1);
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).adauga_absenta(mirel, d2);
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).adauga_absenta(mirel, d3);
    /*for ( Situatie sit : mirel.get_situatii() )
    {
        cout<<sit;
    }
    ///puterea spagii loading...
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).motiveaza_absenta(mirel, d3);
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).motiveaza_absenta(mirel, d2);
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).motiveaza_absenta(mirel, d1);
    ///puterea spagii done!
    cout<<"AM DAT SPAGA SI NIMENI NU MA POATE PRINDE";
    a.exmatriculeaza_elev(mirel);
    cout<<"AM FOST EXMATRICULAT DIN SCOALA OF, NU FACETI CA MINE COPII\n";
    auto clase = a.get_scoala().get_clase();
    for ( auto i = clase.begin() ; i != clase.end() ; i++ )
    {
        cout<<"Clasa "<<i -> first<<":\n";
        for ( Elev e : i -> second.get_elevi() )
        {
            cout<<e;
        }
    }*/
}

