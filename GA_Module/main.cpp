#include "GA.h"

void GA::CalcScore()
{
    std::string ans = "Hello, World!";
    for (int k = 0; k < BiontNumber; k++)
    {
        int ret = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (genome[k].Chromosome[i] == ans[i])ret++;

        }
        genome[k].score = ret;
    }
    return;
}

int main()
{
    GA HW(13, 100);
    HW.MakeFirstGenome();
    int generation = 0;

    while (true)
    {
        HW.CalcScore();
        HW.ScoreSortDec();
        if (HW.genome[0].Chromosome != HW.Newgenome[0].Chromosome)std::cout << HW.genome[0].Chromosome << " " << HW.genome[0].score  << std::endl;
        if (13 == HW.genome[0].score)break;
        HW.CreateNewGeneration(5, 90, 5);
        
        generation++;
    }
    std::cout << generation << " " << HW.genome[0].Chromosome << std::endl;
}