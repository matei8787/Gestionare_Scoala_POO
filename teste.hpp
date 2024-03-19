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
void testeaza()
{
    Scoala s("Liceul din mijloc");
    Admin a(Date_om::make_om("Bentley", "Bob", "50406184000000", Adrese_de_Contact::make_adresa("O iei in fata, faci dreapta, si te duci...", "serios@confident.smecher", "07noi2")), s);
    Elev marcel(Date_om::make_om("Ionescu", "Marcel", "1263748139", Adrese_de_Contact()));
    Elev mirel(Date_om::make_om("Marinescu", "Mirel-Mugurel-Mihnea", "5618391827", Adrese_de_Contact()));
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
        p.set_date(Date_om::make_om("Profu de", nume_disciplina[discipline[i]], "1690413", Adrese_de_Contact::make_adresa("Dupa colt", "blazeit69420@hotmail.xxx", "07n-am cartela")));
        a.angajeaza_profesor(p);
    }
    a.inmatriculeaza_copil(marcel, "VII B");
    a.inmatriculeaza_copil(mirel, "VII B");
    Clasa cla = a.get_scoala().get_clase()["VII B"];


    for ( int i = 0 ; i < discipline.size() ; i++ )
    {
        Profesor p = a.get_scoala().get_profesor("Profu de", nume_disciplina[discipline[i]], discipline[i]);
        a.inregistreaza_prof_la_clasa(p, cla);
        if ( discipline[i] == SPORT )
        {
            p.adauga_nota(marcel, 5);
            p.adauga_nota(mirel, 10);
        }
        else
        {
            p.adauga_nota(marcel, 10);
            p.adauga_nota(mirel, 5);
        }
    }
    a.muta_elev(mirel, cla, a.get_scoala().get_clase()["VII C"]);
    Data d1 = {1, 1, 2024}, d2 = {2, 1, 2024}, d3 = {4, 1, 2024};
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).adauga_absenta(mirel, d1);
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).adauga_absenta(mirel, d2);
    a.get_scoala().get_profesor("Profu de", "Geografie", DISCIPLINE_POSIBILE::GEOGRAFIE).adauga_absenta(mirel, d3);
    for ( Situatie sit : mirel.get_situatii() )
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
    }
}

