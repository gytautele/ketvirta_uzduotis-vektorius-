#include "../headers/time.h"
void Time::Start_clock()
{
    pradzia_ = std::chrono::high_resolution_clock::now();
}
void Time::Stop_clock()
{
    pabaiga_ = std::chrono::high_resolution_clock::now();
}
void Time::Get_time(std::ofstream& lout, int &skaicius)
{
    skirtumas_ = pabaiga_ - pradzia_;
    lout<<skaicius<<" eiluciu failo apdorojimo laikas = "<<skirtumas_.count()<<" s."<<std::endl;
    skaicius*=10;
}