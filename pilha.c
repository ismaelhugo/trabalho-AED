#include <stdio.h>
#include <time.h>

#define CAP 1000000

struct pilha {
    int itens[CAP];
    int topo;
};

int iniciaPilha(struct pilha *stack) {
    stack->topo = -1; //Essa funcao inicia a pilha vazia
}

int pilhaEhVazia(struct pilha stack) {
    if (stack.topo == -1) return 1; // Varifica se a pilha eh vazia. Se sim, retorna 1. Se n retorna 0
    else return 0;
}

//Retorna o valor (index) do topo da pilha
int valorTopoPilha(struct pilha stack) {
    return stack.itens[stack.topo];
}

//Aqui a gente inicia a operacao de insercao
int inserir(struct pilha *stack, int valor_inserido) {
    if (stack->topo != (CAP - 1)) { //verifica se a pilha contem a capacidade total.
        stack->topo++;
        stack->itens[stack->topo] = valor_inserido; //adiciona no topo
        return 0;
    } else { //Se tiver a capacidade total...
        printf("Overflow");
        return -1;
    }
}

//funcao de remocao
int remover(struct pilha *stack) {
    int valor;
    if (stack->topo != -1) { //verifica se existe algo na pilha e remove do topo
        valor = stack->itens[stack->topo];
        stack->topo--;
        return valor; //se existir, remove
    } else {
        printf("Underflow!");
        return 0;
    }
}

//funcao de ordenacao
void ordenar(struct pilha *stack)
{
    int i = 0;
    int j = 0;

    for( i = 0; i < stack->topo; i++ )
    {
        for( j = i + 1; j < stack->topo; j++ )
        {
            if( stack->itens[i] > stack->itens[j] )
            {
                int aux = stack->itens[i];
                stack->itens[i] = stack->itens[j];
                stack->itens[j] = aux;
            }
        }
    }
}

int main() {
    int clock_inicial;
    int clock_final;

    struct pilha stack;

    iniciaPilha(&stack);
    int i;

    clock_inicial = clock();

    for(i = CAP; i > 0; i--){
        
        inserir(&stack, i);
    };

    clock_final = clock();
    
    printf("Tempo decorrido para inserir é: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    clock_inicial = clock();
    remover(&stack);
    clock_final = clock();
    printf("Tempo decorrido para remover é: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    clock_inicial = clock();
    ordenar(&stack);
    clock_final = clock();
    printf("Tempo decorrido para ordenar é: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    printf("O topo é %d\n", valorTopoPilha(stack));

    return 0;
}
