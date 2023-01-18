#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "latticeview.h"
#include <stdlib.h>

using namespace std;

#define ImageWidth 1000
#define ImageHeight 1000

void queima(int L)
{
    ofstream dados("F100.dat");
    for(int i = 1; i <= 200; i++)
    {
        int matriz[L*L];
        double p = 0.005*i;
        //double p = 0.5;
        int vivas = 0;
        for(int n = 1; n <= 1000; n++)
        {

            //GERAR CONFIG INICIAL
            for(int linha = 0; linha < L; linha++)
                for(int coluna = 0; coluna < L; coluna++)
                {
                    if(drand48() < p)
                    {
                        matriz[linha*L+coluna] = 1;
                    }
                    else
                    {
                        matriz[linha*L+coluna] = 0;
                    }
                }
            //Print_lattice (matriz, L, L, ImageWidth, ImageHeight, "i065.ppm");

            for(int t = 1; t <= 200; t++)
            {
                int altera[L*L] = {0};
                for(int linha = 0; linha < L; linha++)
                    for(int coluna = 0; coluna < L; coluna++)
                    {
                        int soma = 0;
                        if(((coluna-1) >= 0))
                        {
                            soma += matriz[linha*L+(coluna-1)];
                            if((linha-1) >= 0)
                            {
                                soma += matriz[(linha-1)*L+(coluna-1)];
                            }
                            if((linha-1) < 0)
                            {
                                soma += matriz[(L-1)*L+(coluna-1)];
                            }
                            if((linha+1) < L)
                            {
                                soma += matriz[(linha+1)*L+(coluna-1)];
                            }
                            if((linha+1) == L)
                            {
                                soma += matriz[(0)*L+(coluna-1)];
                            }
                        }
                        if((coluna-1) < 0)
                        {
                            soma += matriz[linha*L+(L-1)];
                            if((linha-1) >= 0)
                            {
                                soma += matriz[(linha-1)*L+(L-1)];
                            }
                            if((linha-1) < 0)
                            {
                                soma += matriz[(L-1)*L+(L-1)];
                            }
                            if((linha+1) < L)
                            {
                                soma += matriz[(linha+1)*L+(L-1)];
                            }
                            if((linha+1) == L)
                            {
                                soma += matriz[(0)*L+(L-1)];
                            }
                        }
                        ////////////////////////////////
                        if((coluna+1) < L)
                        {
                            soma += matriz[linha*L+(coluna+1)];
                            if((linha-1) >= 0)
                            {
                                soma += matriz[(linha-1)*L+(coluna+1)];
                            }
                            if((linha-1) < 0)
                            {
                                soma += matriz[(L-1)*L+(coluna+1)];
                            }
                            if((linha+1) < L)
                            {
                                soma += matriz[(linha+1)*L+(coluna+1)];
                            }
                            if((linha+1) == L)
                            {
                                soma += matriz[(0)*L+(coluna+1)];
                            }
                        }
                        if((coluna+1) == L)
                        {
                            soma += matriz[linha*L+0];
                            if((linha-1) >= 0)
                            {
                                soma += matriz[(linha-1)*L+(0)];
                            }
                            if((linha-1) < 0)
                            {
                                soma += matriz[(L-1)*L+(0)];
                            }
                            if((linha+1) < L)
                            {
                                soma += matriz[(linha+1)*L+(0)];
                            }
                            if((linha+1) == L)
                            {
                                soma += matriz[(0)*L+(0)];
                            }
                        }
                        ////////////////////////////////
                        if((linha-1) >= 0)
                        {
                            soma += matriz[(linha-1)*L+coluna];
                        }
                        if((linha-1) < 0)
                        {
                            soma += matriz[(L-1)*L+coluna];
                        }
                        ////////////////////////////////
                        if((linha+1) < L)
                        {
                            soma += matriz[(linha+1)*L+coluna];
                        }
                        if((linha+1) == L)
                        {
                            soma += matriz[(0)*L+coluna];
                        }
                        

                        if(matriz[linha*L+coluna] == 1)
                        {
                            if(soma < 2 || soma > 3)
                            {
                                altera[linha*L+coluna] = 0;
                            }
                            if(soma == 2 || soma == 3)
                            {
                                altera[linha*L+coluna] = 1;
                            }
                        }
                            
                        
                        
                        if(matriz[linha*L+coluna] == 0)
                        {
                            if(soma == 3)
                            {
                                altera[linha*L+coluna] = 1;
                            }
                            if(soma != 3)
                            {
                                altera[linha*L+coluna] = 0;
                            }
                        }
                    }

                /*
                int vivas = 0;
                for(int i=0; i<L*L; i++)
                {
                    if(matriz[i] == 1)
                    {
                        vivas += 1;
                    }
                }
                dados << t << "\t" <<  vivas <<endl;
                */
                for(int i = 0; i < L*L; i++)
                {
                    matriz[i] = altera[i];
                }

            }

            for(int i=0; i<L*L; i++)
            {
                if(matriz[i] == 1)
                {
                    vivas += 1;
                }
            }

            
        }
        vivas /= 1000;
        dados << p << "\t" << vivas <<endl;
    }
    dados.close();
    
}



int main()
{
    queima(100);
}