#include<stdio.h>

int main(){
	int numsecreto=42, chute;
	
	printf("**********************************************\n");
	printf("*Bem vindo ao jogo da adivinhação. Boa sorte!*\n");
	printf("**********************************************\n");
	
	int ganhou=0;
	int tentativas=1; 
	while(ganhou==0){		
			
			printf("Tentativa %d  \n",tentativas);
			printf("Qual é o seu chute?\n");
			scanf("%d",&chute);
			printf("Seu chute foi %d\n",chute);
			
			int acertou= (chute==numsecreto);
			int maior=(chute > numsecreto);
			
			if(chute<0){
				printf("Você não pode informar números negativos \n");
				continue;
			}
		    else if(acertou){
			printf("Parabéns, você acertou! :)\n");
			printf("Você é um bom jogador\n");
			ganhou=1;
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
				tentativas++;
			}
	printf("Fim de Jogo!\n");
	printf("Você acertou em %d tentativas\n",tentativas-1 );
}