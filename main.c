#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausarTela() {
    printf("\nPressione Enter para continuar...");
    limparBuffer();
}


int menuPrincipal() {
    int opcao;
    system("cls || clear");
    printf("=================================\n");
    printf("          ARCADE DE JOGOS        \n");
    printf("=================================\n");
    printf("1: Pergunta e Resposta\n");
    printf("2: Cobra na Caixa!\n");
    printf("3: Gousmas War\n");
    printf("4: Sair\n");
    printf("=================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}


void perguntaResposta() {
    char jogarNovamente;
    setlocale(LC_ALL, "Portuguese");
    
    do {
        system("cls || clear");
        printf("=================================\n");
        printf("      PERGUNTA E RESPOSTA        \n");
        printf("=================================\n");
        printf("Responda corretamente as perguntas abaixo.\n");
        pausarTela();
        
        
        char *perguntas[5] = {
            "Qual foi o placar do jogo Brasil e Alemanha na Copa de 2014?",
            "Qual foi o papa anterior ao atual?",
            "Como é obrigado em francês?",
            "Em um ecossistema aquático com eutrofização, qual processo do ciclo do nitrogênio é mais diretamente afetado pelo excesso de nutrientes, levando à proliferação de algas e posterior zona morta?",
            "No contexto da Teoria das Cordas, qual destes elementos é fundamental para resolver a incompatibilidade entre a mecânica quântica e a relatividade geral?"
        };
        
        char *opcoes[5][4] = {
            {"A) 1 a 0", "B) 7 a 1", "C) 4 a 3", "D) 21 a 1"},
            {"A) Francisco", "B) Bento XVI", "C) João Paulo II", "D) Paulo VI"},
            {"A) Aurevoir", "B) Bonjour", "C) Merci", "D) Pardon"},
            {"A)Fixação biológica (por cianobactérias)", "B)Nitrificação (oxidação de NH4+ para NO3-)", "C)Assimilação (absorção de NO3- por plantas e algas)", "D)Desnitrificação (redução de NO3- para N2) "},
            {"A) Bóson de Higgs", "B) Dimensões extras", "C) Buracos negros primordiais", "D) Matéria escura fria"}
        };
        
        char respostas[5] = {'B', 'B', 'C', 'C', 'B'};
        int pontuacao = 0;
        int i,j;
        for (i = 0; i < 5; i++) {
            system("cls || clear");
            printf("Pergunta %d/%d:\n", i+1, 5);
            printf("%s\n", perguntas[i]);
            for (j = 0; j < 4; j++) {
                printf("%s\n", opcoes[i][j]);
            }
            
            char resposta;
            printf("\nSua resposta (A/B/C/D): ");
            scanf(" %c", &resposta);
            limparBuffer();
            
            resposta = toupper(resposta);
            if (resposta == respostas[i]) {
                printf("\nResposta correta!\n");
                pontuacao++;
            } else {
                printf("\nResposta incorreta! A correta era %c.\n", respostas[i]);
            }
            pausarTela();
        }
        
        system("cls || clear");
        printf("=================================\n");
        printf("        FIM DO JOGO             \n");
        printf("=================================\n");
        printf("Voce acertou %d de 5 perguntas!\n", pontuacao);
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
        jogarNovamente = toupper(jogarNovamente);
        
    } while (jogarNovamente == 'S');
}


void cobraNaCaixa() {
    char jogarNovamente;
    setlocale(LC_ALL, "Portuguese");
    
    do {
        system("cls || clear");
        printf("=================================\n");
        printf("         COBRA NA CAIXA!        \n");
        printf("=================================\n");
        printf("Você está em uma tumba egípcia com 5 caixas.\n");
        printf("Uma caixa tem o botão para abrir a porta.\n");
        printf("Outra tem uma cobra mortal. As outras estao vazias.\n");
        pausarTela();
        
        
        char *nomes[7] = {
            "Marcelo", "Jaderson", "Alcino", 
            "Ytalo", "Pedro", 
            "Antonio", "Evaristo"
        };
        
       
        char jogador1[50], jogador2[50];
        int escolha1, escolha2;
        int i;
        system("cls || clear");
        printf("Escolha o nome do Jogador 1:\n");
        for (i = 0; i < 7; i++) {
            printf("%d) %s\n", i+1, nomes[i]);
        }
        printf("Digite o numero do nome: ");
        scanf("%d", &escolha1);
        limparBuffer();
        strcpy(jogador1, nomes[escolha1-1]);
        
        system("cls || clear");
        printf("Escolha o nome do Jogador 2:\n");
        for (i = 0; i < 7; i++) {
            if (i != escolha1-1) {
                printf("%d) %s\n", i+1, nomes[i]);
            }
        }
        printf("Digite o numero do nome: ");
        scanf("%d", &escolha2);
        limparBuffer();
        strcpy(jogador2, nomes[escolha2-1]);
        
       
        srand(time(NULL));
        int vez = rand() % 2;
        char *jogadorAtual = vez == 0 ? jogador1 : jogador2;
        
        system("cls || clear");
        printf("O jogador %s comeca!\n", jogadorAtual);
        pausarTela();
        
        int jogoAtivo = 1;
        int botao, cobra;
        
        do {
            
            do {
                botao = rand() % 5 + 1;
                cobra = rand() % 5 + 1;
            } while (botao == cobra);
            
            system("cls || clear");
            printf("Rodada do jogador %s\n", jogadorAtual);
            printf("Escolha uma caixa (1-5): ");
            int caixa;
            scanf("%d", &caixa);
            limparBuffer();
            
            if (caixa == botao) {
                printf("Parabens! Voce encontrou o botao e abriu a porta!\n");
                printf("%s venceu!\n", jogadorAtual);
                jogoAtivo = 0;
            } else if (caixa == cobra) {
                printf("Oh nao! A cobra mortal estava nesta caixa!\n");
                printf("%s perdeu!\n", jogadorAtual);
                jogoAtivo = 0;
            } else {
                printf("Esta caixa esta vazia.\n");
               
                jogadorAtual = (strcmp(jogadorAtual, jogador1) == 0) ? jogador2 : jogador1;
                printf("Agora e a vez de %s.\n", jogadorAtual);
                pausarTela();
            }
        } while (jogoAtivo);
        
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
        jogarNovamente = toupper(jogarNovamente);
        
    } while (jogarNovamente == 'S');
}


void gousmasWar() {
    char jogarNovamente;
    
    do {
        system("cls || clear");
        printf("=================================\n");
        printf("         GOUSMAS WAR            \n");
        printf("=================================\n");
        printf("REGRAS:\n");
        printf("- Cada jogador comeca com 2 Gousmas (furia 1 cada)\n");
        printf("- Ataque: escolhe uma Gousma ATACANTE e uma INIMIGA\n");
        printf("- A Gousma atacante TRANSFERE toda sua furia para a inimiga\n");
        printf("- A Gousma atacante MANTEM sua furia (apos transferir)\n");
        printf("- Gousma explode se furia > 5 (6 ou mais)\n");
        printf("- Divisao: cria nova Gousma com metade da furia (max 2 Gousmas/jogador)\n");
        printf("- Objetivo: eliminar todas Gousmas do oponente\n");
        pausarTela();
        
        typedef struct {
            int furia;
            int ativa; 
        } Gousma;
        
       
	    Gousma jogador1[2] = {{1, 1}, {1, 1}};
        Gousma jogador2[2] = {{1, 1}, {1, 1}};
        int qtdJogador1 = 2, qtdJogador2 = 2;
        int vez = 0; 
        
        int jogoAtivo = 1;
        int i;
        
        while (jogoAtivo) {
            system("cls || clear");
            printf("=================================\n");
            printf("          GOUSMAS WAR            \n");
            printf("=================================\n");
            
           
            printf("Jogador 1 Gousmas: ");
            int gousmasAtivas1 = 0;
            for (i = 0; i < 2; i++) {
                if (jogador1[i].ativa) {
                    printf("[%d] ", jogador1[i].furia);
                    gousmasAtivas1++;
                }
            }
            printf("\n");
            
            
            printf("Jogador 2 Gousmas: ");
            int gousmasAtivas2 = 0;
            for (i = 0; i < 2; i++) {
                if (jogador2[i].ativa) {
                    printf("[%d] ", jogador2[i].furia);
                    gousmasAtivas2++;
                }
            }
            printf("\n\n");
            
            printf("Vez do Jogador %d\n", vez + 1);
            printf("1) Atacar\n");
            printf("2) Dividir Gousma\n");
            printf("Escolha uma acao: ");
            int acao;
            scanf("%d", &acao);
            limparBuffer();
            
            if (acao == 1) { 
                if (vez == 0) { 
                    if (gousmasAtivas1 == 0) {
                        printf("Voce nao tem Gousmas para atacar!\n");
                        pausarTela();
                        continue;
                    }
                    
                    
                    printf("Suas Gousmas ativas:\n");
                    int indicesAtivas1[2], count1 = 0;
                    for (i = 0; i < 2; i++) {
                        if (jogador1[i].ativa) {
                            printf("%d) [%d] ", count1+1, jogador1[i].furia);
                            indicesAtivas1[count1] = i;
                            count1++;
                        }
                    }
                    
                    printf("\nEscolha sua Gousma atacante (1-%d): ", count1);
                    int escolhaAtacante;
                    scanf("%d", &escolhaAtacante);
                    limparBuffer();
                    escolhaAtacante--;
                    int idxAtacante = indicesAtivas1[escolhaAtacante];
                    int furiaAtacante = jogador1[idxAtacante].furia;
                    
                   
                    printf("Gousmas inimigas ativas:\n");
                    int indicesAtivas2[2], count2 = 0;
                    for (i = 0; i < 2; i++) {
                        if (jogador2[i].ativa) {
                            printf("%d) [%d] ", count2+1, jogador2[i].furia);
                            indicesAtivas2[count2] = i;
                            count2++;
                        }
                    }
                    
                    printf("\nEscolha a Gousma inimiga para atacar (1-%d): ", count2);
                    int escolhaAlvo;
                    scanf("%d", &escolhaAlvo);
                    limparBuffer();
                    escolhaAlvo--;
                    int idxAlvo = indicesAtivas2[escolhaAlvo];
                    
                    
                    jogador2[idxAlvo].furia += furiaAtacante;
                    
                    
                    if (jogador2[idxAlvo].furia > 5) {
                        printf("\nA Gousma inimiga explodiu com %d de furia!\n", jogador2[idxAlvo].furia);
                        jogador2[idxAlvo].ativa = 0; 
                        qtdJogador2--;
                    }
                } 
                else { 
                    if (gousmasAtivas2 == 0) {
                        printf("Voce nao tem Gousmas para atacar!\n");
                        pausarTela();
                        continue;
                    }
                    
                    
                    printf("Suas Gousmas ativas:\n");
                    int indicesAtivas2[2], count2 = 0;
                    for (i = 0; i < 2; i++) {
                        if (jogador2[i].ativa) {
                            printf("%d) [%d] ", count2+1, jogador2[i].furia);
                            indicesAtivas2[count2] = i;
                            count2++;
                        }
                    }
                    
                    printf("\nEscolha sua Gousma atacante (1-%d): ", count2);
                    int escolhaAtacante;
                    scanf("%d", &escolhaAtacante);
                    limparBuffer();
                    escolhaAtacante--;
                    int idxAtacante = indicesAtivas2[escolhaAtacante];
                    int furiaAtacante = jogador2[idxAtacante].furia;
                    
                    
                    printf("Gousmas inimigas ativas:\n");
                    int indicesAtivas1[2], count1 = 0;
                    for (i = 0; i < 2; i++) {
                        if (jogador1[i].ativa) {
                            printf("%d) [%d] ", count1+1, jogador1[i].furia);
                            indicesAtivas1[count1] = i;
                            count1++;
                        }
                    }
                    
                    printf("\nEscolha a Gousma inimiga para atacar (1-%d): ", count1);
                    int escolhaAlvo;
                    scanf("%d", &escolhaAlvo);
                    limparBuffer();
                    escolhaAlvo--;
                    int idxAlvo = indicesAtivas1[escolhaAlvo];
                    
                    
                    jogador1[idxAlvo].furia += furiaAtacante;
                    
                    
                    if (jogador1[idxAlvo].furia > 5) {
                        printf("\nA Gousma inimiga explodiu com %d de furia!\n", jogador1[idxAlvo].furia);
                        jogador1[idxAlvo].ativa = 0; 
                        qtdJogador1--;
                    }
                }
            } 
            else if (acao == 2) { 
                if (vez == 0) { 
                    if (gousmasAtivas1 >= 2) {
                        printf("Voce ja tem o maximo de Gousmas!\n");
                        pausarTela();
                        continue;
                    }
                    
                    
                    int idxDividir = -1;
                    for (i = 0; i < 2; i++) {
                        if (jogador1[i].ativa) {
                            idxDividir = i;
                            break;
                        }
                    }
                    
                    if (jogador1[idxDividir].furia < 2) {
                        printf("Esta Gousma nao tem furia suficiente para dividir!\n");
                        pausarTela();
                        continue;
                    }
                    
                    
                    int idxNova = -1;
                    for (i = 0; i < 2; i++) {
                        if (!jogador1[i].ativa) {
                            idxNova = i;
                            break;
                        }
                    }
                    
                    
                    int novaFuria = jogador1[idxDividir].furia / 2;
                    jogador1[idxDividir].furia -= novaFuria;
                    jogador1[idxNova].furia = novaFuria;
                    jogador1[idxNova].ativa = 1;
                    qtdJogador1++;
                } 
                else { 
                    if (gousmasAtivas2 >= 2) {
                        printf("Voce ja tem o maximo de Gousmas!\n");
                        pausarTela();
                        continue;
                    }
                    
                    int idxDividir = -1;
                    for (i = 0; i < 2; i++) {
                        if (jogador2[i].ativa) {
                            idxDividir = i;
                            break;
                        }
                    }
                    
                    if (jogador2[idxDividir].furia < 2) {
                        printf("Esta Gousma nao tem furia suficiente para dividir!\n");
                        pausarTela();
                        continue;
                    }
                    
                   
                    int idxNova = -1;
                    for (i = 0; i < 2; i++) {
                        if (!jogador2[i].ativa) {
                            idxNova = i;
                            break;
                        }
                    }
                    
                    
                    int novaFuria = jogador2[idxDividir].furia / 2;
                    jogador2[idxDividir].furia -= novaFuria;
                    jogador2[idxNova].furia = novaFuria;
                    jogador2[idxNova].ativa = 1;
                    qtdJogador2++;
                }
            }
            
            
            if (qtdJogador1 == 0) {
                printf("\nJogador 2 venceu!\n");
                jogoAtivo = 0;
            } else if (qtdJogador2 == 0) {
                printf("\nJogador 1 venceu!\n");
                jogoAtivo = 0;
            } else {
                vez = (vez == 0) ? 1 : 0; 
            }
            
            pausarTela();
        }
        
        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &jogarNovamente);
        limparBuffer();
        jogarNovamente = toupper(jogarNovamente);
        
    } while (jogarNovamente == 'S');
}
int main() {
    srand(time(NULL)); 
    
    int opcao;
    do {
        opcao = menuPrincipal();
        
        switch (opcao) {
            case 1:
                perguntaResposta();
                break;
            case 2:
                cobraNaCaixa();
                break;
            case 3:
                gousmasWar();
                break;
            case 4:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausarTela();
                break;
        }
    } while (opcao != 4);
    
    return 0;
}
