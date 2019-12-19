#include<stdio.h>
#define NUM_TENTATIVAS 5
// define é uma constante,isto é, não muda. É uma variavel que é invariavel.
int main(){
	int numsecreto=42, chute;
	
	printf("**********************************************\n");
	printf("*Bem vindo ao jogo da adivinhação. Boa sorte!*\n");
	printf("**********************************************\n");
	
	for( int i=1; i<=NUM_TENTATIVAS;i++){		
			// i é o contador de tentativas
			printf("Tentativa %d de %d\n",i,NUM_TENTATIVAS);
			printf("Qual é o seu chute?\n");
			scanf("%d",&chute);
			printf("Seu chute foi %d\n",chute);
			
			int acertou= (chute==numsecreto);
			int maior=(chute > numsecreto);
			int menor=(chute < numsecreto);
			
			if(chute<0){
				printf("Você não pode informar números negativos \n");
				i--;
				continue;
			}
		    else if(acertou){
			printf("Parabéns, você acertou! :)\n");
			printf("Você é um bom jogador\n");
			break;
			}
			
			else if(maior){
					printf("Infelizmente você errou :(\n");
					printf("Vou te ajudar um pouquinho...\n");
					printf("O número secreto é menor que %d\n",chute);
					printf("Não conta para ninguém que eu te ajudei :)\n");
				}
				
				else{
					printf("Infelizmente você errou :(\n");
					printf("Vou te ajudar um pouquinho...\n");
					printf("O número secreto é maior que %d\n",chute);
					printf("Não conta para ninguém que eu te ajudei :)\n");
				}
			}
	printf("Fim de Jogo!\n");
}