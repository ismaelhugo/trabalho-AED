#include <stdio.h>
#include <time.h>

#define CAP 100000

struct pilha {
    int itens[CAP];
    int topo;
};

int iniciaPilha(struct pilha *stack) {
    stack->topo = -1;
}

int pilhaEhVazia(struct pilha stack) {
    if (stack.topo == -1) return 1;
    else return 0;
}

int valorTopoPilha(struct pilha stack) {
    return stack.itens[stack.topo];
}

int inserir(struct pilha *stack, int valor_inserido) {
    if (stack->topo != (CAP - 1)) {
        stack->topo++;
        stack->itens[stack->topo] = valor_inserido;
        return 0;
    } else {
        printf("Overflow!");
        return -1;
    }
}

int remover(struct pilha *stack) {
    int valor;
    if (stack->topo != -1) {
        valor = stack->itens[stack->topo];
        stack->topo--;
        return valor;
    } else {
        printf("Underflow!");
        return 0;
    }
}

void ordenar(struct pilha *stack)
{
    int i = 0;
    int j = 0;

    for( i = 0; i < stack->pilha; i++ )
    {
        for( j = i + 1; j < stack->pilha; j++ )
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
    

    remover(&stack);

    ordenar(&stack);

    printf("Tempo decorrido: %lfs. \n", ((float)(clock_final - clock_inicial) / CLOCKS_PER_SEC));

    printf("O topo é %d\n", valorTopoPilha(stack));

    return 0;
}
