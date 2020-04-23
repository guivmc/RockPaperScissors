#include<stdio.h>
#include<string.h>

#define PAPEL 1
#define PEDRA 2
#define TESOURA 3
#define EXIT 9

//CRTL + F5 to run any selected file.

int main()
{
	int isRunning = 1;

	srand(time(0));

#pragma region Players
	struct player
	{
		char* name;
		int move;
		int wins;
	};

	//init
	struct player user, machine;

	user.wins = 0;
	user.name = (char*)malloc(50);
	user.move = 0;

	machine.wins = 0;
	machine.name = "Thalos";
	machine.move = 0;
#pragma endregion

	printf("Insira o seu nome de jogador: ");

	//Get Inputed name.
	fgets(user.name, 50, stdin);

	//Removes \n from the end of the inputed string.
	user.name[strcspn(user.name, "\n")] = 0;

	while (isRunning == 1)
	{
		printf("Escolha sua jogada (Papel - 1, Pedra - 2, Tesoura - 3), ou para sair digite 9: ");
		scanf_s("%d", &user.move);
		
		//Rand % 3 + 1
		machine.move = (rand() % TESOURA) + PAPEL;

		if (user.move != EXIT)
		{
			//Check moves
			if (user.move == PAPEL)
			{
				if (machine.move == TESOURA)
				{
					machine.wins++;
					printf("%s Venceu \0/", machine.name);
					printf(" Total de: %d \n", machine.wins);
					printf("%s Perdeu :c", user.name);
					printf(" Total de: %d \n", user.wins);
				}
				else if (machine.move == PEDRA)
				{
					user.wins++;
					printf("%s Venceu \0/ ", user.name);
					printf(" Total de: %d \n", user.wins);
					printf("%s Perdeu :c ", machine.name);
					printf(" Total de: %d \n", machine.wins);
				}
				else
				{
					printf("Empate! :O \n");
				}
			}
			else if (user.move == PEDRA)
			{
				if (machine.move == PAPEL)
				{
					machine.wins++;
					printf("%s Venceu \0/", machine.name);
					printf(" Total de: %d \n", machine.wins);
					printf("%s Perdeu :c", user.name);
					printf(" Total de: %d \n", user.wins);
				}
				else if (machine.move == TESOURA)
				{
					user.wins++;
					printf("%s Venceu \0/ ", user.name);
					printf(" Total de: %d \n", user.wins);
					printf("%s Perdeu :c ", machine.name);
					printf(" Total de: %d \n", machine.wins);
				}
				else
				{
					printf("Empate! :O \n");
				}
			}
			else if (user.move == TESOURA)
			{
				if (machine.move == PEDRA)
				{
					machine.wins++;
					printf("%s Venceu \0/", machine.name);
					printf(" Total de: %d \n", machine.wins);
					printf("%s Perdeu :c", user.name);
					printf(" Total de: %d \n", user.wins);
				}
				else if (machine.move == PAPEL)
				{
					user.wins++;
					printf("%s Venceu \0/ ", user.name);
					printf(" Total de: %d \n", user.wins);
					printf("%s Perdeu :c ", machine.name);
					printf(" Total de: %d \n", machine.wins);
				}
				else
				{
					printf("Empate! :O \n");
				}
			}
			else
			{
				printf("Comando nao entendido :/ \n");
			}
		}
		else if (user.move == EXIT)
		{
			printf("Finalizando jogo! Bye Bye");
			isRunning = 0;
		}
	}

	return 0;
}
