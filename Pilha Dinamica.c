#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct dataNode
{
    int id;
} DataNode;

typedef struct node
{
    DataNode data;
    struct node* next;

} Node;

typedef struct pilha
{
    int size;
    Node* topo;

} Pilha;

/* Cabeçalhos */
Pilha* createPilha();
void push (Pilha* pilha, DataNode data);

void printPilha(Pilha* pilha);
void pop(Pilha* pilha);

int isEmpty(Pilha* pilha);
Node* atPos(Pilha* pilha, int index);
int indexOf(Pilha* list, Node* node);
int size(Pilha * pilha);
int topo(Pilha* pilha);

/* Funções */
Pilha* createPilha()
{
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->size = 0;
    pilha->topo = NULL;

    return pilha;
}


void push (Pilha* pilha, DataNode data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = pilha->topo;
    pilha->topo = node;
    pilha->size++;
}

void printPilha(Pilha* pilha)
{

    if(isEmpty(pilha))
    {
        printf("Pilhaa vazia \n");
        return;
    }
    Node* pointer = pilha->topo;
    printf("\n[");
    while(pointer != NULL)
    {
        printf("%d ", pointer->data.id);
        pointer = pointer->next;

    }
    printf("]");

}

void pop(Pilha* pilha)
{
    if(!isEmpty(pilha))
    {
        Node* pointer = pilha->topo;
        pilha->topo = pointer->next;
        free(pointer);
        pilha->size--;
    }
}




int isEmpty(Pilha* pilha)
{
    printf("%d", pilha->size);
    return(pilha->size == 0);
}


Node* atPos(Pilha* pilha, int index)
{
    if(index >= 0 && index < pilha->size)
    {
        Node* node = pilha->topo;

        int i;
        for(i= 0; i <index; i++)
        {
            node = node->next;

        }
        return node;

    }
    printf("Índice inválido");
    return 0;


}


int indexOf(Pilha* pilha, Node* node)
{
    if(node !=NULL)
    {
        Node* pointer = pilha->topo;
        int index = 0;

        while(pointer!= node && pointer != NULL )
        {
            pointer = pointer->next;
            index++;
        }
        if(pointer != NULL)
        {
            return index;


        }
    }
    printf("Nó não pertencente a pilhaa \n");
    return -1;

}







int size(Pilha * pilha)
{
    return(pilha->size);
}


int topo(Pilha* pilha)
{
    if(isEmpty(pilha))
    {
        printf("Pilhaa vazia \n");
        return -1;
    }
    return(pilha->topo->data.id);


}
int main()
{
    Pilha* p = createPilha();
    DataNode data;
    Node* ax;
    int opcao, vazia;

    setlocale(LC_ALL, "Portuguese_Brazil");
/*
    data.id = 5;
    push(p, data);
    printPilha(p);

    data.id = 9;
    push(p, data);
    printPilha(p);

    data.id = 7;
    push(p, data);
    printPilha(p);

    data.id = 99;
    push(p, data);
    printPilha(p);
    printf("%d", topo(p));
*/
    do
    {
        printf("\n Escolha sua opção digitando o algarismo associado: \n");
        printf("1-Verificar se a pilha está vazia \n");
        printf("2-Obter o tamanho da pilha \n");
        printf("3-Obter o topo da pilha \n");
        printf("4-Adicionar um elemento à pilha \n");
        printf("5-Retirar um elemento da pilha \n");
        printf("6-Imprimir a pilha \n");
        printf("7-sair \n");
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 1:
            vazia = isEmpty(p);
            if(vazia == 0)
            {
                printf("\n A pilha não está vazia\n ");

            }
            else
            {
                printf("\n Pilha vazia \n");

                break;
            case 2:
                printf("\nO tamanho da lista é %d \n", size(p));

                break;
            case 3:
                if(topo(p)!= -1)
                {
                    printf("\n %d \n",topo(p));

                }else{
                    printf("\n a pilha está vazia não existe topo! \n");
                }
                break;
            case 4:
                printf("\n Digite o numero que deseja adicionar \n");
                scanf("%d", &data.id);
                push (p, data);
                break;
            case 5:
                if(isEmpty(p))
                {
                    printf("\nNão há o que retirar, a pilha está vazia \n");
                }
                else{
                    pop(p);
                    printf("\n O topo da lista foi removido\n");

                }


                break;
            case 6:
                    printf("\n ");
                    printPilha(p);
                    printf("\n ");
                    break;
                case 7:
                printf("\n Tchau \n");
                break;

            default:
                printf("\n Opção inválida! \n");

                break;

            }
        }
    }
    while(opcao!= 7);

}
