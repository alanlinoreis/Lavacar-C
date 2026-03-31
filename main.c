#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Tcarro{
  char modelo[30] ;
  char placa[30] ;
  char cor[30];
}Tcarro;

//Definição do escopo das funções para implementação
void fun_decre(int *);
void fun_incre(int *);
void flush_in ();
float calcValor (float preco, float qtd);
int fun_invalidos (float prEta, float prGas, float prAdit, float tFila);
int fun_escreva();
char Fun_Tcar();

int main (void) {

  //Quantidade de variáveis em excesso, algumas poderiam ser criadas apenas no escopo da função
	float  prEta, prGas, prAdit, qtdEta, qtdGas, qtdAdit, valRec;
  //Opção de melhoria, inserir manualmente a quantidade de combustivel ou possivel integração com um sistema de gerenciamento de quantidade

  float etaRestante = 200, gasRestante = 200, aditRestante = 200;
  int fila = 0, tFila = 1, relatorio, menu, cont = 0, cAtendido = 0;

  printf("---------------------------------------------------------------------------------------------------------\n");
  printf("Bem vindo ao programa de abastecimento do posto de gasolina! Nosso programa facilita o abastecimento para nossos clientes.\n\n                     \n");
  printf("---------------------------------------------------------------------------------------------------------\n");
  
  do {
    // dentro fun_invalidos deveria-se checar se a a atribuição de valores correspondentes ao seu tipo, já que dentro do loop já é checado se os valores são negativos ou válidos
    // deveria-se identificar os valores individualmente, para que não seja necessário digitar a mesma informação mais de uma vez mesmo que ela esteja correta
  fun_invalidos(prEta, prGas, prAdit, tFila);
    
	printf ("\nDigite o preço do etanol: ");
	scanf  ("%f", &prEta);
	  
	printf ("\nDigite o preço da gasolina: ");
	scanf  ("%f", &prGas);
	
	printf ("\nDigite o preço da gasolina aditivada: ");
	scanf  ("%f", &prAdit);
	
  printf("\nInforme o tamanho da fila que o estabelecimento suportará: ");
  scanf  ("%d", &tFila);
  
  }
  while (prEta < 0 || prGas < 0 || prAdit < 0 || tFila <= 0);

  Tcarro carros[tFila];
  do {

  menu = fun_escreva();
  
  switch (menu){
    case 1:
      system("clear");
      if (fila < tFila) {
        fun_incre(&fila);
        flush_in ();
        
        printf("\nDigite o modelo do carro:\n ");
        fgets(carros[cont].modelo,30,stdin);
              
        printf("\nDigite a cor do carro:\n ");
        fgets(carros[cont].cor,30,stdin);
              
        printf("\nDigite a placa do carro:\n ");
        fgets(carros[cont].placa,30,stdin);
      
        printf("\nModelo do carro: %s\nCor do carro: %s\nPlaca do carro: %s", carros[cont].modelo, carros[cont].cor, carros[cont].placa);
        cont++;
        
        printf("\nCarro adicionado\n");
        
        } else {
        printf("\nFila cheia\n");
        }
    break;
    
    // Opção para atualizações futuras, poder selecionar um tipo de combustivel por vez
    case 2:
      system("clear");

      if (fila > 0) {
        printf ("\nDigite a quantidade vendida do etanol: ");
      	scanf  ("%f", &qtdEta);
        etaRestante = etaRestante - qtdEta;
  
      	printf ("\nDigite a quantidade vendida da gasolina comum: ");
      	scanf  ("%f", &qtdGas);
      	gasRestante = gasRestante - qtdGas;
      
      	printf ("\nDigite a quantidade vendida da gasolina aditivada: ");
      	scanf  ("%f", &qtdAdit);
      	aditRestante = aditRestante - qtdAdit;
        
        cAtendido = cAtendido + 1;
        printf("\nCarros atendidos: %d\n", cAtendido);
        printf("Carro abastecido\n");
        fun_decre(&fila);
        } else {
        printf("A fila está vazia! Adicione um carro antes de abastecer.");
        }
    break;
    
    case 3:
      system("clear");
      if (fila > 0) {
      fila =  fila - 1;
      printf("Próximo cliente chamado");
        } else
        printf("A fila está vazia! Adicione um carro antes de abastecer.");
      break;
    
    case 4:
      do
      {
      printf("------------------------------------------------------------------\n");
      printf("1 - Quantidade de litros vendida (por tipo de combustível)\n 2 - Valor total arecadado com as vendas (por tipo de combustível)\n 3 - Quantidade de carros atendidos\n 4 - Quantidade de combustível restante em cada tanque\n 5 - Voltar ao menu anterior\n");
      printf("------------------------------------------------------------------\n");
      printf("Informe a opção: ");
      scanf("%d", &relatorio);
      switch (relatorio){
        case 1:
          system("clear");
          printf ("A quantidade de litros vendida foi: Etanol: %.2f\nGasolina Comum: %.2f \n Gasolina Aditivada: %.2f\n", qtdEta, qtdGas, qtdAdit);
          break;
        
        case 2:
          system("clear");
          valRec = calcValor(prEta, qtdEta) + calcValor(prGas, qtdGas) + calcValor(prAdit, qtdAdit);
          printf ("Valor total arrecadado com as vendas foi: %.2f\n", valRec);
          break;
        
        case 3:
          system("clear");system("clear");
          printf ("%d carros foram atendidos\n", cAtendido);
          break;
        
        case 4:
          system("clear");
          printf ("%.2f litros restante de Etanol\n %.2f litros restante de Gasolina Comum\n %.2f litros restante de Gasolina Aditivada", etaRestante, gasRestante, aditRestante);
          break;
        
        case 5:
          system("clear");
          break;

        default:
          printf("Opção inválida\n"); 
      }
        }while (relatorio != 5);
      break;
    
    case 5:
      system("clear");
      printf("\nPrograma encerrado");
      break;
    
    default:
      system("clear");
      printf("\nOpção inválida\n");
  }
  } while (menu != 5);
	
	return 0;
}

//IMPLEMENTAÇÃO DAS FUNÇÕES=======================

//calcula o valor do preço total da venda do combustível
float calcValor (float preco, float qtd) {
	return preco*qtd;
}

//função que checa se os valores de etanol, gasolina, gasolina aditivada e tamanho da fila estão válidos para o sistema funcionar
int fun_invalidos (float prEta, float prGas, float prAdit, float tFila) {
  if (prEta < 0) 
     printf("\nValor do preço do Etanol inválido!\nDigite o preço novamente\n");
  if (prGas < 0) 
     printf("\nValor do preço da Gasolina inválido!\nDigite o preço novamente\n");
  if (prAdit < 0)
     printf("\nValor do preço da Gasolina Aditivada inválido!\nDigite o preço novamente\n");
  if (tFila <= 0)
      return printf("\nInforme um número para a fila válido!\n");
  return 0;
}

//Menu principal do programa
int fun_escreva () {
  int opcao;
  printf("\nPrograma para melhor experência dos clientes do posto de gasolina\n");
  printf("------------------------------------------------------------------\n");
  printf("1 - Adicionar um carro na fila\n2 - Abastecimento\n3 - Chamar o próximo\n4 - Relatórios\n5 - Encerrar\n");
  printf("------------------------------------------------------------------\n");
  printf("Informe a opção: ");
  scanf("%u", &opcao);
  return opcao;
}

//função de limpeza do buffer para evitar lixo nas variáveis
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

//incrementa fila de carros
void fun_incre (int *fila){
  *fila = *fila + 1;
  printf ("Número de carros na fila: %d\n", *fila);
}

//decrementa fila de carros
void fun_decre (int *fila){
  *fila = *fila - 1;
  printf ("Número de carros na fila: %d\n", *fila);
 }
