#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <time.h>


typedef struct
{
    //std::vector<char> Chromosome;
    std::string Chromosome;
    int score;
}Genome;

class GA
{
public:
    std::vector<Genome> genome;
    std::vector<Genome> Newgenome;
    int Length;
    int BiontNumber;
    GA(int, int);
    void MakeFirstGenome();

    virtual void CalcScore();

    void FormatScore();
    void ScoreSortAsc();
    void ScoreSortDec();

    void CreateNewGeneration(int, int, int);
};
