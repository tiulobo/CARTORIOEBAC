#include <stdio.h>  //bibioteca de comunicação com o usário!
#include <stdlib.h> //biblioteca de alocação de espaço em memária!
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsavel por cuidar das string
int registro()// funsao responsavel por cadastrar os usuarios no sistema
 {
 	//inicio da criaçao de variaveis/strings
 	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criaçao de variavel/string
    
    printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuario 
    scanf("%s", cpf);//%s refere-se as string
    
    strcpy(arquivo, cpf); //respomsavel por copiar o valor das string
    
    FILE *file; // cria o arquivo no banco de dados 
    file = fopen(arquivo, "w");// cria o arquivo e o "W" significa escrever
    fprintf(file,cpf);// salvo o valor da variavel
    fclose(file);// fecho o arquivo
    
    file = fopen (arquivo, "a");
    fprintf(file, ",");   
    fclose(file);
    
    printf("digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen (arquivo, "a");
    fprintf(file, ",");   
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");   
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    file = fopen (arquivo, "a");
    fprintf(file, ",");   
    fclose(file);
    
    
    
 }

int consulta()
 {
    setlocale(LC_ALL, "Portuguese"); // defenindo a linguagem
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consutado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    	
    if(file == NULL)
	{
       printf("Não foi possivel abrir seu arquivo, Não foi localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
    
    system("pause");
    
 }

int deletar()
 {
  char cpf[40];
  printf("Digite o cpf do usuário a ser deletado");
  scanf("%s", cpf);
  
  remove(cpf);//o remover remove sem presisar ser escrito um aviso o
  
  FILE *file;//criando o arquivo no banco de dados 
  file = fopen(cpf,"r");//lendo o arquivo do banco de dados
  
  if(file == NULL)//dizendo que se o que for encontrado for nulo entao devemos enviar um texto
  {
  	printf("usuário não se encontra no sistema!.\n");
  	system("pause");//finalizar so depois do proximo botao ser apertado 
  	
  }
   }

int main()
{
    int opcao=0; // definindo as variaveis
    int x=1;
    
    
    for(x=1;x=1;)
	{
	       system("cls");//responsavel por limpar a tela 
           setlocale(LC_ALL, "Portuguese"); // defenindo a linguagem
    
           printf("### Cartório da EBAC ###\n\n"); //inicio do menu |o comando printf(" ") e responsavel por  permetir colocar conteudos na prograçao de linguem C
           printf("Escolha a opçao que deseja do menu:\n\n"); //o \n é responsavel pelos espaçamentos entre os textos
           printf("\t1 - Registrar nomes:\n");// \t e responsavel pelo espaçamento
           printf("\t2 - Consultar nomes:\n");
           printf("\t3 - Deletar nomes:\n\n");
           printf("\t4 - sair do sistema:\n\n");
           printf("Escolha a opcão:");
    
    scanf("%d", &opcao);//amarzenando a escolha do usuario
    
    system("cls");
    
    switch(opcao)//inicio da seleçao do menu 
	{
		 case 1:
		 registro();//chamada de funções
         break;
        
       
         case 2:
       	 consulta();
         break;
       
         case 3:
       	 deletar();
         break;
         
       	
         default://caso nada for encomtrado devemos por default para dizer algo que nao esta diponivel
         printf("esta opção não esta diponivel!\n");
         system("pause");
         break;
         
         case 4:
         printf("Obrigado por utilizar nosso sistema!\n");
         return 0;
         break;
  }
    
    
 
 }
}
  
