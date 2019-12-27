#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){
	srand(time(0));
	int numsecreto=rand() % 100, chute;
	
		printf("\n\n\n");
		printf("             **********************************************\n");
		printf("             *Bem vindo ao jogo da adivinhação. Boa sorte!*\n");
		printf("             **********************************************\n");



printf("	                              | >>>                                 \n");
printf("                                  |										\n");
printf("                    | >>> _ _ | _ _ >>>									\n");
printf("                    | |; | |; | |; | |									\n");
printf("                _ _ | _ _ \\. . / _ _ | _ __                            \n");
printf("               |; | _ |; | _ |; | \\ :. , / |; | _ |; | _ |; |			\n");
printf("               \\ .. / ||; . | \\. . /                                  \n");
printf("                \\. , / ||:. | \\:. /									\n");
printf("                 ||: | _ _ || _. _ _ _ ||: |							\n");
printf("                 ||:. ||| _ |; | _ |; | _ |; | _ |; | _ |; || :. |		\n");
printf("                 ||: ||. . . . ||:.										\n");
printf("                 ||:. || . . . . , ||: | \\, /							\n");
printf("                 ||: ||:, _______. ||:, | / `\\							\n");
printf("                 ||: || . / +++++++ \\. ||: |							\n");
printf("                 ||: ||. | +++++++ | . ||:. |							\n");
printf("              __ ||:. ||:, | +++++++ |. . _ || _ |						\n");
printf("     ____-- `~ '- ~~ __ |. | +++++ __ | ---- ~ ~ `---, _____            \n");
printf("- ~ - ~ ~ ---__ |, - ~ '~~ ----_____- ~' '~ ---- ~~                     \n");
printf("\n \n \n");
	
	int ganhou=0;
	int tentativas=1; 
	double pontos=1000;
	int nivel;
	double acertou;

	printf("Qual o nível de dificuldade?\n");
	printf("(1) para fácil,(2) para médio,(3) para díficil\n\n");
	printf("Escolha:");
	scanf("%d",&nivel);

	
	int numtentativas;
	
	switch(nivel){
		case 1:
			numtentativas=20;
			break;
		case 2:
			numtentativas=15;
			break;
		default:
			numtentativas=6;
			break;
	}


	for(int i=1;i<=numtentativas;i++){
			printf("Tentativa %d  \n",tentativas);

			printf("Qual é o seu chute?\n");
			scanf("%d",&chute);
			printf("Seu chute foi %d\n",chute);
			
			double acertou= (chute==numsecreto);
			double maior=(chute > numsecreto);
			
			if(chute<0){
				printf("Você não pode informar números negativos \n");
				continue;}
		
		    else if(acertou){
							
			printf("		________00000000000___________000000000000________\n");
			printf("		______00000000_____00000___000000_____0000000______\n");
			printf("		____0000000_____________000______________00000_____\n");
			printf("		___0000000_______________0_________________0000____\n");
			printf("		__000000____________________________________0000___\n");
			printf("		__00000_____________________________________ 0000__\n");
			printf("		_00000______________________________________00000__\n");
			printf("		_00000_____________________________________000000__\n");
			printf("		__000000_________________________________0000000___\n");
			printf("		___0000000______________________________0000000____\n");
			printf("		_____000000____________________________000000______\n");
			printf("		_______000000________________________000000________\n");
			printf("		__________00000_____________________0000___________\n");
			printf("		_____________0000_________________0000_____________\n");
			printf("		_______________0000_____________000________________\n");
			printf("		_________________000_________000___________________\n");
			printf("		_________________ __000_____00_____________________\n");
			printf("		______________________00__00_______________________\n");
			printf("		________________________00_________________________\n");
			printf("\n \n");

 		                                                                      
			
			printf("Parabéns, você acertou! :)\n");
			printf("Você é um bom jogador\n");
			printf("Você acertou em %d tentativas\n",tentativas);
			printf("Fim de Jogo!\n");

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
				tentativas++;
				double pontosperdidos = abs( chute - numsecreto ) / (double)2;
				pontos = pontos - pontosperdidos;
				// abs eh usado p fazer um número neg ficar posit, mas se o núm for posit ele cont posit.
			}
	printf("Seus pontos são %.1f\n",pontos);
	printf("Fim de Jogo!\n");
}