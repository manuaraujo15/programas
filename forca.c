#define TAMANHO_PALAVRA 20
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#include"forca.h"

	// Variaveis globais
	char palavra [TAMANHO_PALAVRA];
	char chutes[26];
	int chutesdados=0;

// Cabeçalho do jogo: 
void abertura(){
	printf("********************************************************************************\n");
	printf("			*	JOGO DA FORCA	   *\n")	;			
	printf("********************************************************************************\n\n");

}

void adicionapalavra(){
	char quer;
	printf("Quer adicionar uma palavra nova no jogo?(S-N)");
	scanf(" %c",&quer);

	if(quer == 'S'){
	char novapalavra[TAMANHO_PALAVRA];
	printf("Qual a nova palavra?");
	scanf("%s",novapalavra);

	FILE* f;

	f = fopen("palavra.txt","r+");

	if(f == 0){
		printf("Desculpa, o banco de dados nao esta disponivel\n\n");
		exit(1);
	}

	int qtd;
	fprintf(f,"%d",qtd );
	qtd++;

	fseek(f,0,SEEK_SET);
	fprintf(f,"%d",qtd);

	fseek(f,0,SEEK_END);
	fprintf(f, "\n%s",novapalavra);
	fclose(f);
	}
}

//palavra da forca
void escolhepalavra(){
	FILE* f ;
	f = fopen("palavra.txt", "r");

	if(f == 0){
		printf("Desculpa, o banco de dados nao esta disponivel\n\n");
		exit(1);
	}

	int qtddepalavras;
	fscanf(f, "%d", &qtddepalavras);

	srand(time(0));
	int randomico = rand() % qtddepalavras;

	for(int i=0; i<=randomico; i++){

		fscanf(f, "%s",palavra);
	}
	
	fclose(f);
}


//Jogador informa seu chute
void chuta(){

	char chute;
	printf("Chuta uma letra!\n");
	scanf(" %c",&chute);

	chutes[chutesdados]=chute;
	chutesdados++;
	
}
//Verifica se o chute foi correto
int jachutou(char letra){
	int achou = 0;	
	for( int j = 0; j < chutesdados; j++){
		if(chutes[j] == letra){
			achou = 1;
		break;
		}
	}
	return achou;

}
int acertou(){
	for( int i = 0; i < strlen(palavra); i++){
		if(!jachutou(palavra[i])){
			return 0;
		}
	}
	return 1;
}
int chuteserrados(){
	int erros=0;
	for(int i = 0; i < chutesdados; i++){

		int existe = 0;

		for( int j = 0; j < strlen(palavra); j++){
			if (chutes[i] == palavra[j]){
				existe=1;
				break;
				
			}
		}

	 if(!existe) erros++;

	}

	return erros;

}

//Mostra os lugares de cada letra
void desenhodaforca(){
	int erros = chuteserrados();

	printf("  _______         \n");
    printf(" |/      |        \n");
    printf(" |      %c%c%c    \n",(erros>=1 ? '(' : ' '),(erros>=1 ?'_' : ' '),(erros>=1 ? ')' : ' ') );
    printf(" |      %c%c%c    \n",(erros>=3 ?'\\' : ' '),(erros>=2 ? '|' : ' '),(erros>=4 ? '/' : ' ') );
    printf(" |       %c       \n",(erros>=5 ? '|' : ' ') );
    printf(" |      %c %c     \n",(erros>=6 ?'/' : ' '),(erros>=7 ? '\\' : ' ') );
    printf(" |                \n");
    printf("_|___             \n");
    printf("\n\n");

	for( int i=0; i < strlen(palavra); i++)
	{

		int letracerta = jachutou(palavra[i]);
			
			if(letracerta){
				printf("%c",palavra[i]);
			}else{
    			printf("_ ");
    		}
	}	
		printf("\n");
		chuta();

}

int enforcou(){
	return chuteserrados() >=8;
}
	





int main(){	
	
	abertura();
	escolhepalavra();

	do {
		desenhodaforca();
	
		} while(! acertou() &&! enforcou());
	
	if(acertou()){
    printf("\nParabéns, você ganhou!\n\n");

    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");

	}else{
		printf("\nPuxa, você foi enforcado!\n");
    printf("A palavra era **%s**\n\n", palavra);

    printf("    _______________         \n");
    printf("   /               \\       \n"); 
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");

	}
	adicionapalavra();
}


