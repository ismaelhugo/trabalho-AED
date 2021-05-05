#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMS_NEEDED 250000

int main()
{
    int sizeArray = 0;
    int i = 0, j = 0;
    int nums[NUMS_NEEDED];
    FILE *fp = NULL;

    srand( time( NULL ) );
    fp = fopen( "lista250k.txt", "w" );

    if( fp == NULL )
    {
        printf( "erro.\n" );
        return 1;
    }
    while( sizeArray < NUMS_NEEDED )
    {
        int numGenerated = 1 + rand()% 9999999;
        // Verifica se o número já existe
        for( i = 0 ; i < sizeArray ; ++i )
        {
            if( nums[i] == numGenerated )
            {
                break;
            }
        }
        if( i == sizeArray )
        {
            fprintf( fp, "%d\n", numGenerated );
            nums[++sizeArray] = numGenerated;
        }
    }

    fclose( fp );
    fp = NULL;
    return 0;
}

// algoritmo gerador de numeros aleatorios sem repetição
// copiado da internet <3
