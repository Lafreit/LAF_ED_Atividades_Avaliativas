/*
 * Exercício para nota 01.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 28/09/2024
 */

#include <iostream>

#define TAMANHO_PILHA 10

using namespace std;

struct Carro {
    string  placa;
    int     ano;
};

struct Pilha {
    Carro   data[TAMANHO_PILHA];
    int     contador;
};
/* Protótipos das funções. Desenvolver a partir da linha 59 */
void inicializar(Pilha *);
void estacionar(Pilha *, string, int);
void estacionar(Pilha *, Carro);
Carro sair(Pilha *);
void imprime_pilha(Pilha *);
void imprime_tudo(Pilha *);
int quantidade_vagas(Pilha);


int main() {
    Pilha estacionamento;
    inicializar(&estacionamento);
    Carro carro_comum;

    estacionar(&estacionamento,"ABC1234", 1999);
    carro_comum.placa = "DOW5782";
    carro_comum.ano = 2004;
    estacionar(&estacionamento, carro_comum);
    cout << "\nQuantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    cout << "PILHA DE CARROS" << endl;
    cout << "=========================" << endl;
    imprime_pilha(&estacionamento);
    estacionar(&estacionamento,"XYZ3215", 2022);
    estacionar(&estacionamento,"WQT2245", 2020);
    estacionar(&estacionamento,"GIN3285", 2017);
    estacionar(&estacionamento,"HIX5215", 2008);
    cout << "\nPILHA DE CARROS" << endl;
    cout << "=========================" << endl;
    imprime_pilha(&estacionamento);

    carro_comum = sair(&estacionamento);
    cout << "\nSaiu o carro: " << carro_comum.placa << endl;
    cout << "PILHA DE CARROS" << endl;
    cout << "=========================" << endl;
    imprime_pilha(&estacionamento);
    cout << "\nQuantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_tudo(&estacionamento);

}

// Desenvolver as funções propostas a partir daqui
void inicializar(Pilha *estacionamento) {
    estacionamento->contador = 0;
    int x;
	for (x = TAMANHO_PILHA-1; x >= 0 ; x--){
		estacionamento->data[x].placa = "AAA0000" ;
        estacionamento->data[x].ano = 0 ;
    }
}

void estacionar(Pilha *estacionamento, string placa, int ano) {
    // Implementar a função para estacionar um novo carro na pilha
    // Adicionar um novo carro na pilha e incrementar o contador
    // Caso a pilha esteja cheia, imprimir uma mensagem de erro e não adicionar o carro
    if(estacionamento->contador < TAMANHO_PILHA){
        Carro novo_carro;
        novo_carro.placa = placa;
        novo_carro.ano = ano;
        estacionamento->data[estacionamento->contador] = novo_carro;
        estacionamento->contador++;
    }else{
        cout << "Pilha cheia! Não foi possível estacionar o carro." << endl;
    }
    
}

void estacionar(Pilha *estacionamento, Carro carro) {
    // Implementar a função para estacionar um novo carro na pilha
    // Adicionar um novo carro na pilha e incrementar o contador
    // Caso a pilha esteja cheia, imprimir uma mensagem de erro e não adicionar o carro
    if(estacionamento->contador < TAMANHO_PILHA){
        estacionamento->data[estacionamento->contador] = carro;
        estacionamento->contador++;
    }else{
        cout << "Pilha cheia! Não foi possível estacionar o carro." << endl;
    }
}

Carro sair(Pilha *estacionamento) {
    // Implementar a função para retirar um carro da pilha
    // Remover o carro do topo da pilha e decrementar o contador
    // Caso a pilha esteja vazia, imprimir uma mensagem de erro e retornar pilha vazia
    Carro carro_saiu;
    if(estacionamento->contador > 0){
        carro_saiu = estacionamento->data[estacionamento->contador-1];
        estacionamento->contador--;
        return carro_saiu;
    }else{
        cout << "Pilha vazia! Não há carro para retirar." << endl;
        carro_saiu.placa = "AAA0000";
        carro_saiu.ano = 0;
        return carro_saiu;
    }
}

void imprime_pilha(Pilha *estacionamento) {
    // Implementar a função para imprimir a pilha de estacionamento
    // Exibir a placa e ano de todos os carros na pilha
    
    for(int i = estacionamento->contador-1; i >= 0; i--){
        cout << "Placa: " << estacionamento->data[i].placa << ", Ano: " << estacionamento->data[i].ano << endl;
    }
}

void imprime_tudo(Pilha *estacionamento) {
    // Implementar a função para imprimir todos os carros da pilha de estacionamento
    // Exibir a placa, ano e quantidade de carros na pilha
    cout << "\nTODA A PILHA" << endl;
    cout << "=========================" << endl;
    imprime_pilha(estacionamento);
}

int quantidade_vagas(Pilha estacionamento) {
    // Implementar a função para calcular a quantidade de vagas disponíveis na pilha
    // Retornar a quantidade de vagas disponíveis
    // Considerar que a pilha tem TAMANHO_PILHA espaços
    // Caso a pilha esteja cheia, retornar 0 de vagas disponíveis
    // Caso a pilha esteja vazia, retornar o total de vagas (TAMANHO_PILHA)
    if(estacionamento.contador == TAMANHO_PILHA){
        return 0;
    }else{
        return TAMANHO_PILHA - estacionamento.contador;
    }
    
}
