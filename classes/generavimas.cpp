#include"../headers/main_header.h"
//--------------------------------
void generavimas(std::ofstream& in, int skaicius)
{
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);

    for (int w = 0; w < skaicius; w++)
    {
        in << "Vardas" << w << "  Pavarde" << w << "  ";

        for (int w = 0; w < 10; w++)
        {
            in << uniform_dist(el) << " ";
        }
        in << uniform_dist(el) << endl;;
    }
}
//---------------------------------
void generavimas2()
{
    cout<<"Generuojami tekstiniai failai."<<endl;
    int skaicius = 10000;
    for (int i = 0; i < 4; i++)
    {
        std::ofstream out("test" + std::to_string(i + 1) + ".txt");
        generavimas(out, skaicius);
        out.close();
        skaicius *= 10;
    }
    cout<<"Tekstiniai failai sugeneruoti." <<endl;
}
