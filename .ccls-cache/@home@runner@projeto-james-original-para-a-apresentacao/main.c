#include <stdio.h>
#include <string.h>

//#define COMPRIM_MAX_NOME_CIDADE 30
//#define MAX_VIAGENS 10

int main() {
  char COMPRIM_MAX_NOME_CIDADE = 30;
  int MAX_VIAGENS = 10;
  
  char CIDADES[MAX_VIAGENS][COMPRIM_MAX_NOME_CIDADE];
  char CIDADES2[MAX_VIAGENS][COMPRIM_MAX_NOME_CIDADE];
  int QTD[MAX_VIAGENS];

  int numviagens = 0;
  int opcao;
  int numPassagens;
  int indice_viagem = -1;
  int assentos_disponiveis = -1;


  char origin[COMPRIM_MAX_NOME_CIDADE];
  char destino[COMPRIM_MAX_NOME_CIDADE];
  char pesquisa_origem[COMPRIM_MAX_NOME_CIDADE];
  char destino_de_pesquisa[COMPRIM_MAX_NOME_CIDADE];





   printf("   ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦       \n");
   printf("   ▦    ◤                                         ◥      ▦       \n");
   printf("   ▦     BEM VINDO AO GERENCIADOR LINHA DE ONIBUS        ▦       \n");
   printf("   ▦    ◣                                         ◢      ▦       \n");
   printf("   ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦       \n");

  printf("   \n\n");
  do {
    printf("                     ⋘  MENU ⋙               ");
    printf("\n\n");
    printf("           🚌 1. CADRASTAR UMA VIAGEM  \n");
    printf("           🎫 2. VENDER PASSAGEM       \n");
    printf("           🏸 3. PESQUISAR VAGAS       \n");
    printf("           📃 4. LISTAR VIAGENS        \n");
    printf("           ❌ 5. SAIR                  \n");
    printf("           🧩 Escolha uma opção: ");
    scanf("%d%*c", &opcao);

    printf("\n\n");
    switch (opcao) {
    case 1:
      if (numviagens >= MAX_VIAGENS) {
        printf("  ⋙  Limite de viagens alcançado. \n");
        break;
      }

      printf("  ⋙  Digite o nome da cidade de origem: \n");
      fgets(CIDADES[numviagens], COMPRIM_MAX_NOME_CIDADE, stdin);
      CIDADES[numviagens][strcspn(CIDADES[numviagens], "\n")] = '\0';

      printf("  ⋙  Digite o nome da cidade de destino: \n");
      fgets(CIDADES2[numviagens], COMPRIM_MAX_NOME_CIDADE, stdin);
      CIDADES2[numviagens][strcspn(CIDADES2[numviagens], "\n")] = '\0';

      printf("  ⋙  Digite a quantidade de vagas disponíveis: \n");
      scanf("%d%*c", &QTD[numviagens]);

      numviagens++;
      break;
    case 2:
      if (numviagens == 0) {
        printf("  ⋙  Não há viagens cadastradas.\n");
        break;
      }


      printf("  ⋙  Digite a cidade de origem: \n");
      fgets(origin, COMPRIM_MAX_NOME_CIDADE, stdin);
      origin[strcspn(origin, "\n")] = '\0';

      printf("  ⋙  Digite a cidade de destino: \n");
      fgets(destino, COMPRIM_MAX_NOME_CIDADE, stdin);
      destino[strcspn(destino, "\n")] = '\0';

      printf("  ⋙  Digite a quantidade de passagens desejada: \n");
      scanf("%d%*c", &numPassagens);


      for (int i = 0; i < numviagens; i++) {
        if (strcmp(origin, CIDADES[i]) == 0 &&
            strcmp(destino, CIDADES2[i]) == 0) {
          indice_viagem = i;
          break;
        }
      }

      if (indice_viagem == -1) {
        printf("  ⋙  Viagem não encontrada.\n");
      } else if (QTD[indice_viagem] < numPassagens) {
        printf("  ⋙  Não há vagas disponíveis para essa viagem.\n");
      } else {
        printf("    ◉ Venda de %d passagens realizada com sucesso!\n",
               numPassagens);
        printf("    ◉ Cidade de origem: %s\n", origin);
        printf("    ◉ Cidade de destino: %s\n", destino);
        QTD[indice_viagem] -= numPassagens;
      }
      break;
    case 3:
      if (numviagens == 0) {
        printf("  ⋙  Não há viagens cadastradas.\n");
        break;
      }



      printf("  ⋙  Digite a cidade de origem: \n");
      fgets(pesquisa_origem, COMPRIM_MAX_NOME_CIDADE, stdin);
      pesquisa_origem[strcspn(pesquisa_origem, "\n")] = '\0';

      printf("  ⋙  Digite a cidade de destino: \n");
      fgets(destino_de_pesquisa, COMPRIM_MAX_NOME_CIDADE, stdin);
      destino_de_pesquisa[strcspn(destino_de_pesquisa, "\n")] = '\0';


      for (int i = 0; i < numviagens; i++) {
        if (strcmp(pesquisa_origem, CIDADES[i]) == 0 &&
            strcmp(destino_de_pesquisa, CIDADES2[i]) == 0) {
          assentos_disponiveis = QTD[i];
          break;
        }
      }

      if (assentos_disponiveis == -1) {
        printf("  ⋙  Viagem não encontrada.\n");
      } else {
        printf("    ◉ Quantidade de vagas disponíveis: %d\n",
               assentos_disponiveis);
      }
      break;
    case 4:
      if (numviagens == 0) {
        printf("    ◉ Não há viagens cadastradas.\n");
        break;
      }

      printf("  ⋙  Relação de viagens:\n");
      for (int i = 0; i < numviagens; i++) {
        printf("Viagem %d:\n", i + 1);
        printf("    ◉ Cidade de origem: %s\n", CIDADES[i]);
        printf("    ◉ Cidade de destino: %s\n", CIDADES2[i]);
        printf("    ◉ Vagas disponíveis: %d\n", QTD[i]);
      }
      break;
    case 5:
      printf("▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱\n");
      printf("▰   ENCERRANDO O PROGRAMA  ▰\n");
      printf("▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱▰▱");
      printf("\n\n");
      printf("░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░\n░░███████░░░░░░░░░░███▒▒▒▒▒▒▒▒███░░░░░░░\n░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███░░░░\n░░░█▒▒▒▒▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░\n░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███░\n░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██\n░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██\n░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██\n██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒▒██\n█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██\n██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░\n░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░░\n░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░\n░░████████████░░░█████████████████░░░░░░\n");
      break;
    default:
      printf("  ⋙  Opção inválida. Tente novamente.\n");
      break;
    }

    printf("\n");
  } while (opcao != 5);

  return 0;
}