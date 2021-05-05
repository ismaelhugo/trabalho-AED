#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACIDADE 1000000

struct fila
{
	int a[CAPACIDADE];
	int inicio;
	int fim;
};

int opcao;
int r;

//Função necessária para criar uma fila vazia consistente
// Por convenção fila vazia tem o início e fim
// como sendo iguais a -1
void inicia(struct fila *f)
{
	f->inicio = -1;
	f->fim = -1;
}

//Função que verifica se uma fila está vazia
int filaVazia(struct fila f)
{
	if (f.inicio == -1)
		return 1;
	else
		return 0;
}

//Função que retorna o elemento inicio da fila sem removê-lo
int inicioFila(struct fila f)
{
	return f.a[f.inicio];
}

//Função que retorna o elemento no fim da fila sem removê-lo
int fimFila(struct fila f)
{
	return f.a[f.fim];
}

//Função de inserção na fila
int inserir(struct fila *f, int x)
{
	// Posição onde o novo elemento será inserido
	// levando em consideração a circularidade da fila
	// e se a fila está vazia
	int prov = (f->fim + 1) % CAPACIDADE; //guarda o index do fim da fila +1
	if (prov != f->inicio)
	{					  // Verifica se a fila não está cheia
		f->fim = prov;	  // Atualiza o fim da fila
		f->a[f->fim] = x; // Insere o novo elemento no fim
		if (f->inicio == -1)
		{ // Ajuste caso a fila esteja inicialmente vazia
			f->inicio = 0;
		}
		return 0;
	}
	else
	{ // Capacidade da fila esgotada
		printf("Overflow!");
		return -1;
	}
}

//Função de remoção
int remover(struct fila *f)
{
	int valor; // Valor a ser recuperado e removido
	if (f->inicio != -1)
	{							 // Verifica se a fila já não está vazia
		valor = f->a[f->inicio]; // Recupera o valor do início da fila
		if (f->inicio == f->fim)
		{ // Ajuste caso a elemento removido for o último
			f->inicio = -1;
			f->fim = -1;
		}
		else
		{ // Ajusta levando em consideração a circularidade, caso contrário
			f->inicio = (f->inicio + 1) % CAPACIDADE;
		}
		return valor;
	}
	else
	{ // Fila está vazia
		printf("Underflow!");
		return 0;
	}
}

int main()
{
	struct fila queue;
	clock_t clock_inicial, clock_final;

	printf("Digite o valor referente a opcao\n");
	printf("1 - Inserir\n");
	printf("2 - Remover\n");
	scanf("%d", &opcao);
	inicia(&queue);

	switch (opcao)
	{
	case 1:
		clock_inicial = clock();
		for (int i = CAPACIDADE; i > 0; i--)
		{
			inserir(&queue, rand() % CAPACIDADE);
		}
		clock_final = clock();
		printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));
		break;
	case 2:

		printf("Inserindo... %d\n", r); //Insere para ter algo para remover
		for (int i = CAPACIDADE; i > 0; i--)
		{
			inserir(&queue, rand() % CAPACIDADE);
		}

		int size = fimFila(queue); //salva o tamanho da fila

		printf("Iniciando remocao. Aguarde... %d\n", r);

		clock_inicial = clock();
		for (int i = 0; i < size; i++)
		{
			remover(&queue);
		}
		clock_final = clock();

		printf("Tempo decorrido para remover: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));
		break;
	}

	printf("O inicio é %d\n", inicioFila(queue));

	return 0;
}
