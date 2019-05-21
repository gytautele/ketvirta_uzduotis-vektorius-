#include "../headers/main_header.h"
#include "../headers/time.h"

int main()
{
    generavimas2();

    char laikinas;
    std::ofstream out;
    out.open("benchmarking.txt", std::fstream::app);
    int skaicius = 10000;
    for (int i = 0; i < 4; i++)
    {
        vector <Studentas> studentai, silpni;
        Time laikas;
        laikas.Start_clock();
        studentai.reserve(skaicius);
        skaitymas(studentai, i,laikinas);
        int ilgiausias_vardas = 6, ilgiausia_pavarde = 7;
        ilgio_nustatymas(studentai, ilgiausias_vardas, ilgiausia_pavarde);
        atrinkimas_2(studentai, silpni);
        isvedimas(studentai, silpni, ilgiausias_vardas, ilgiausia_pavarde);
        silpni.clear();
        laikas.Stop_clock();
        laikas.Get_time(out, skaicius);
    }


    out.close();
}
