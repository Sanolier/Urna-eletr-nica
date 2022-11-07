#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int mestra, chapas;
int base = 0;

void config() {
	
	printf("\n\n\n\t\tDefina a chave mestra: ");
	scanf("%d", &mestra);
	printf("\n\n\n\t\tDefina o numero de chapas: ");
	scanf("%d", &chapas);
}

void menu() {

	system("color F0");
	printf("\t\tColegio estadual\n");
	printf("\t\t Augusto Meyer");
	printf("\n\n\n\t\t-Urna eleitoral-");
	printf("\n\n\n\n\tPressione qualquer tecla para continuar");
	getch();
	getch();
	
	if(base == 0){
		config();
		base = base+1;
	}	
}

void cadastro() {
	
	FILE *log;
	log = fopen("cadastros.txt", "a");
	
	system("cls");
	system("color E0"); // Definindo cor
	
	// Cadastro
	char nome[30];
	printf("\t\t\tCadastro:\n");
	printf("\n- Digite seu nome: ");
	gets(nome);
	int turma;
	printf("\n- Digite sua turma: ");
	scanf("%d", &turma);

	// Gerando o código do aluno
	int codigo = rand() % 999999 + rand() % 999 + 25;
	printf("\nSeu codigo de aluno e: %d", codigo);
	printf("\n\nAperte qualquer tecla para confirmar. ");
	getch();
	
	// Salvando cadastro
	fprintf(log, "\nNome: %s", nome);
	fprintf(log, "\nTurma: %d", turma);
	fprintf(log, "\nCodigo de aluno: %d \n", codigo);
	fclose(log);
	system("cls");	
}

int main () {
	
	// Chamando funçoes
	menu();
	cadastro();
	
	// Pegando votos do banco de dados
	int pedro, maria, luiz;	
	FILE *txt;
	txt = fopen("votos.txt", "r");
	fscanf(txt, "%d %d %d", &pedro, &maria, &luiz);
	
	int senha;
	while(senha != mestra){	 // Inicio do ciclo de votação
	
		// Votar
		int voto=0, total = 0;	
		while(total != chapas){  // Inicio do ciclo votar
		
			total++;
			printf("\nChapa %d:\n", total);
			printf("1 para Pedro\n");
			printf("2 para Maria\n");
			printf("3 para Luiz\n");
			printf("Seu voto: "); 
			scanf("%d", &voto);	
			system("cls");
			// Verficando se o voto é valido
			if(voto <1 || voto > 3){
				total = 0;
				printf("Voto invalido, digite novamente. \n");
			}
			// Guardando o voto
			if(voto == 1){
				pedro++;
			}
			if(voto == 2){
				maria++;
			}
			if(voto == 3){
				luiz++;
			}	
		}   // Final do ciclo votar
		
		// Finalizar votação
		char sn = 0;
		printf("Deseja finalizaqr votacao? S/N    ");
		scanf("%s", &sn);
		
		if(sn == 's' || sn == 'S'){	
			system("cls");
			printf("Digite a senha para finalizar: ");
			scanf("%d", &senha);
		
			if(senha == mestra){
				// Exibir votos 
				system("cls");
				printf("Votos: \n\n");
				printf("Pedro: %d\nMaria: %d\nLuiz: %d\n", pedro, maria, luiz);
			}
			else{
				printf("\nSenha incorreta, a votacao nao pode ser finalizada!\n");
			}
		}
	
		// Salvando votos no banco de dados
		txt = fopen("votos.txt", "w");
		fprintf(txt, "%d %d %d", pedro, maria, luiz);	
		fclose(txt);					
	}  // Final do ciclo de votação
}
