#include <stdio.h>
#include <stdlib.h>

struct Telefone{
    char nome[50];
    char telefone[15];
};


struct Telefone* criar_telefone() {
   struct Telefone* pessoa = (struct Telefone*) malloc(sizeof(struct Telefone));
    
   if (pessoa == NULL) {
      printf("Erro ao alocar memória.\n");
      return NULL; // Retorna NULL se a alocação falhar
   }

   printf("Digite o nome da pessoa:\n");
    scanf("%s", pessoa->nome);
   printf("Digite o número da pessoa:\n");
    scanf("%s", pessoa->telefone);
    
   return pessoa;
}

int menu(){
    printf("Digite uma opção:\n\n 1 - Incluir contato \n 2 - Excluir contato \n 3 - Listar contatos \n 4 - Atualizar lista \n 5 - Sair\n");
    printf("\n");

    int x;
    scanf("%d", &x); 
    return x;
}

void adicionar_contatos(struct Telefone agenda[], int *num_de_contatos){
   struct Telefone* novo_contato = criar_telefone();
   if (novo_contato != NULL){
      agenda[*num_de_contatos] = *novo_contato;
      (*num_de_contatos)++;
      free(novo_contato);
   }
}

void excluir_contatos(struct Telefone agenda[], int *num_de_contatos){
   int opcao;
   int indicedonumero;

   printf("Contatos:\n");
   for (int i = 0; i < *num_de_contatos-1; i++){
      printf("%d - %s\n", i, agenda[i+1].nome);
   }

   printf("Deseja excluir um contato? 1 - sim / 2 - não\n");
   scanf("%d", &opcao);

   printf("Digite o índice do número a ser removido:\n");
   scanf("%d", &indicedonumero);

   if (indicedonumero < 0 || indicedonumero > *num_de_contatos){
      printf("Índice inválido. \n");
      return;
   }
   
   for (int i = indicedonumero; i <  *num_de_contatos - 1; i++){
      agenda[i] = agenda[i+1]; 
   }
   (*num_de_contatos)--;
}

void listar_contatos(struct Telefone agenda[], int num_de_contatos){
   printf("Lista de contatos:\n");
   for (int i = 0; i < num_de_contatos; i++){
      printf("%d - %s - %s\n", (i+1),  agenda[i].nome, agenda[i].telefone);
   }
   printf("\n");
}

void atualizar_contato(struct Telefone agenda[100], int num_de_contatos){
    int i = 0; 

    listar_contatos( agenda, num_de_contatos);

    printf("Digite o ID do contato a ser alterado:");
    scanf("%d", &i);
    i--;

    printf("Digite o novo número:\n");
    scanf("%s", agenda[i].telefone);
}
 
void sair(){
    printf("Finalizando o programa.\n");
}

int main() {
    struct Telefone agenda[100];
    int num_contatos;
    int valor = 0;

    int *num_de_contatos = &num_contatos;

    printf("Digite o número de contatos:\n ");
    scanf("%d", &num_contatos);

    for (int i = 0; i < num_contatos; i++) {
        printf("Digite o NOME do contato [%d]:\n", i + 1);
        scanf("%s", agenda[i].nome);

        printf("Digite o TELEFONE do contato [%d]:\n", i + 1);
        scanf("%s", agenda[i].telefone);
        printf("\n");
    }

    printf("\n");
    printf("Contatos:\n");

    for (int i = 0; i < num_contatos; i++) {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
    }
    printf("\n");

    while (valor != 5){
        valor = menu();

        switch(valor){
            case 1:
                adicionar_contatos(agenda, num_de_contatos);
                break;
            case 2:
                excluir_contatos(agenda, num_de_contatos);
                break;
            case 3:
                listar_contatos(agenda, num_contatos);
                break;
            case 4:
                atualizar_contato(agenda, num_contatos);
                break;
            case 5:
                sair();
                break;
        }
    }

     

    return 0;
}
