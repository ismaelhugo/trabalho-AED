#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int buscar(int *lista, int tamanho, int valor_buscado) {
   int i;

   for (i = 0; i < tamanho; i++) {
        if ( lista[i] == valor_buscado) {
	        return i;
	    }
   }

   if (i == tamanho) {
        return -1;
   }
}

int ordenar(int *lista, int tamanho){
    int i, j;
    for (i = 0; i < tamanho; i++) {
        for ( j = 0; j < tamanho - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int maior = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = maior;
            };
        };
    };
}

int inserir(int *lista, int tamanho, int capacidade, int valor_inserido) {
    if (tamanho < capacidade) {
        if (buscar(lista, tamanho, valor_inserido) == -1) {
                lista[tamanho + 1] = valor_inserido;
            tamanho = tamanho + 1;
        } else {
            // se o valor já existe na lista
            return -1;
        }
    } else {
        // erro = capacidade da lista atingida
        return -2;
    }
    // se obtiver sucesso na operação
    printf("valor inserido no indice %d \n", tamanho);
    return 0;
}

int remover (int *lista, int tamanho, int valor_inserido) {
   if(tamanho != 0)
   {
       int i;
       int indice = buscar(lista, tamanho, valor_inserido);
       if(indice > 0)
       {
           for(i = indice; i <= tamanho - 1; i++)
           {
               lista[i] = lista[i + 1];
           }
       }
   }
   return 0;
}

int main() {
    FILE *arq;
    clock_t clock_inicial, clock_final;
    int *lista;
    int contador, valor_a_inserir;
    long int numero;
    int menu;
    int r;

    // alocação para uma quantidade máxima de 1 milhão de ints na lista
    lista = malloc(1000000*sizeof(int));

    // leitura dos dados em disco (arquivo) para um vetor
    arq = fopen("lista.txt", "r");
    contador = 0;
    while (fscanf(arq, "%ld", &numero) > 0) {
        lista[contador] = numero;
	    contador++;
    }
    fclose(arq);
    // fecha o arquivo ao fim da leitura

    printf("Digite a opcao desejada \n");
    printf("1 - Inserir\n");
    printf("2 - Buscar\n");
    printf("3 - Remover\n");
    printf("4 - Ordenar\n");
    scanf("%d", &menu);

    switch(menu){
        case 1:
            printf("Digite um numero para inserir: ");
            scanf("%d", &valor_a_inserir);


            clock_inicial = clock();
            inserir(lista, contador, 1000000, valor_a_inserir);
            clock_final = clock();
            printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));
            break;
        case 2:
            printf("Digite um numero para inserir: ");
            scanf("%d", & valor_a_inserir);


            clock_inicial = clock();
            r = buscar(lista, contador, valor_a_inserir);
            printf("Valor encontrado em %d.\n", r + 1);
            clock_final = clock();
            printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));
            break;
        case 3:
            printf("Digite um numero para remover: ");
            scanf("%d", &valor_a_inserir);
            clock_inicial = clock();
            r = remover(lista, contador, valor_a_inserir);
            clock_final = clock();
            printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));
            break;
        case 4:
            clock_inicial = clock();
            r = ordenar(lista, contador);
            clock_final = clock();
            printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));
            break;
    }

    return 0;
}
