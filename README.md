# Projeto-1Bimestre-Sistema-Jogos
PROJETO 1° BIMESTRE: SISTEMA DE JOGOS
Comecei com um void limparBuffer para que evitar colisões com outros scans;utilizei o while para descartar caracteres.
Usei o void pausarTela em todos os inicios do menu para o usário interpretar melhor e melhorar a interface, o system clear foi usado para selecionar apenas a parte necessária do menu e não interferir com os outros jogos.

O do while nos jogos foi usado para repetir.

Implementei o jogo de pergunta e resposta; usei o char como comando principal e o for para aparecer uma pergunta/opção/resposta de cada vez.

O cobra na caixa, o menu foi montado na mesma lógica.No for o if (i != escolha1-1) garante que o nome já escolhido pelo Jogador 1 (armazenado em escolha1) não seja exibido novamente, depois os nomes restantes no formato: número) Nome.
Para fazer sorteios eu não sabia comandos e utilizei a inteligência artificial:
Eu:qual comando eu devo usar para sorteios na linguagem C?
IA:srand(time(NULL)) garante que os sorteios sejam diferentes em cada execução do programa.
E nessa mesma logica pesquisei na IA um comando para copiar o nome do jogador e foi recomendado o strcpy.

No Gousmas War, o typedef struct auxiliou nas variáveis; o for ajuda na verificação do excesso de fúria, faz com que ataques e divisões seja utilizadas só por gousmas ativas e na interface mostra apenas opções válidas para o jogador e o print e o scanf interage com o jogador.

No final usei o switch case para direcionar o jogador aonde ele deseja.
