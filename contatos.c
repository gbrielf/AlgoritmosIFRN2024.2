#include <stdio.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

int menu(){
    printf("Digite uma opção:\n 1 - Incluir contato \n 2 - Excluir contato \n 3 - Listar contatos \n 4 - Atualizar lista \n 5 - Sair");
    int x;
    scanf("%d", &x); 
    return x;
}

struct Contato* inserir_contato(char nome[50], char telefone[15]){
    struct Contato* contato = (struct Pessoa*) malloc(sizeof(struct Contato));

    strcpy(contato->nome, nome);
    strcpy(*contato->telefone = telefone);

    return contato;

}

struct Contato* excluir_contato(){

}

void listar_contato(Contato lista, int tamanho){
    for(int i = 0; i < tamanho; i++)
}
 
void sair(){
    printf("Finalizando o programa.");
}

int main() {
    struct Contato agenda[100];
    int num_contatos;
    int valor = 0;

    printf("Digite o número de contatos: ");
    scanf("%d", &num_contatos);

    for (int i = 0; i < num_contatos; i++) {
        printf("Digite o nome do contato %d: ", i + 1);
        scanf("%s", agenda[i].nome);

        printf("Digite o telefone do contato %d: ", i + 1);
        scanf("%s", agenda[i].telefone);
    }

    printf("Contatos:\n");

    for (int i = 0; i < num_contatos; i++) {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
    }

    while (valor != 5){
        valor = menu();

        switch(valor){
            case 1:
                inserir_contato(agenda->nome, agenda->telefone);
                break;
            case 2:
                excluir_contato(agenda);
                break;
            case 3:
                listar_contato(agenda[100]);
                break;
            case 4:
                atualizar_lista();
                break;
            case 5:
                sair();
                break;
        }
    }

     

    return 0;
}