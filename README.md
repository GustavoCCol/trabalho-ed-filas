# Objetivo
"Gerenciamento de Fila com Múltiplos Atendentes"\
Descrição: Simula laboratório com fila única e múltiplos atendentes, inclui distribuição de atendimentos.

# OBSERVAÇÃO
  OBSERVAÇÃO AO PROFESSOR! COMO O INTEGRANTE MANOEL E JOÃO PAULO NÃO POSSUEM UM COMPUTADOR, A COMUNICAÇÃO FICOU ESTRITA POR WHATSAPP, ENTÃO NÃO FIZEMOS OS COMMITS NO GITHUB À MEDIDA QUE FORAM FEITAS AS MODIFIÇÕES, ENTÃO O ALUNO JÚLIO FEZ OS COMMITS TODOS SEQUENCIAIS NO DIA 29/07, EXPLICANDO AS CONVERSAS NO WHATSAPP E DEBATES OCORRIDOS, BEM COMO AS MUDANÇAS E LANÇANDO OS CÓDIGOS QUE FORAM SENDO FEITOS E ATUALIZANDO ELES NO GITHUB, COM AS DEVIDAS OBSERVAÇÕES. PORTANTO, HAVERÃO MAIS DE 15 COMMITS NO MESMO DIA E HORÁRIO, MAS SÃO EXPLICADOS POR CONTA DISSO.

## Mudanças
  - Inicialmente pegamos o código do professor de fila/pilha e em cima dele, começamos a fazer as modificações do código próprias, adaptando para o problema. Fizemos duas filas, uma normal e uma preferêncial.
  - Mais tardar, Udson iniciou os trabalhos com João Paulo usando a ferramente RAYLIB para fazer a interface do guichê. Foi postado o arquivo raylib.h e visual.c.
  - Manoel terminou de criar a função "EscolherNomeDessaFuncaoDepois" colocando nela a opção de chamar os pacientes pro guichê, liberá-los dos guichês e mostrar os guichês. Também criou o vetor dos guichês, definiu seu tamanho e criou uma função de inicialização.
  - Udson junto do João Paulo terminaram a interface do raylib, agora aparecendo os guichês com atendentes, botão de criar paciente, opção de poder colocar o paciente mais "recente" em termos de ter chegado primeiro, para ser atendido.
  - Júlio fez mudanças no código Fila_laboratorio.c para resolver a meta da variável dado ter o nome dos pacientes, colocou as funções "sleep" e "clear screen" para melhorar a visualização e deixar mais limpo o terminal.
  - Manoel levantou uma boa sugestão para resolver o problema, usar getchar ou gets. Após alguns ajustes, Manoel e Júlio fizeram as devidas resoluções para os problemas encontrados. A solução para a questão da ordem de liberação foi fazer o guichê virar uma fila, ao invés de ser um vetor, como era antes, o que solucionava o fato pode um paciente entrar no guichê 2 e sair antes do paciente do guichê 3, mesmo tendo chegado antes.
  - Manoel fez os ajustes para resolver o problema do scanf. Anteriormente, achamos ter resolvido isso, mas não foi o caso. Ele mudou as variáveis de escolha para "getch" ao invés de "scanf" para evitar que o usuário escreva mais do que deveria. O switch case da função "Escolha _menu" agora chama funções, para deixar o código mais organizado.
  - Júlio postou o código atualizado com alguns ajustes e refinamentos finais. Ainda há dúvidas sobre as funções criar fila e terminar fila, uma vez que, como é um guichê fixo de laboratório, não há razão para se criar filas ou encerrar filas, se uma fila ficar vazia, não tem problema, mas é necessário que ela ao menos exista.
  - Foi decidido tirar as funções criar fila e encerrar fila, deixando o código mais enxuto e direto, com as funções de adicionar paciente, chamar paciente, remover paciente, mostrar guichê e encerrar sessão.
    
## Membros do grupo
- Manoel Pedro
- Júlio Pereira
- Gustavo Cavalcante
- João Paulo
- Udson Marçal  

## Problemas Encontrados
- Novamente, nosso problema ainda é a mescla do código com o arquivo raylib, mas dessa vez é o problema principal.

## Metas Iniciais
- Fazer a fusão do código em C com a interface no RAYLIB.
- Não é relacionado com o código, mas o objetivo agora é ajustar os slides para a apresentação do trabalho.
- Baseado no feedback do professor sobre as apresentações anteriores, estamos pensando em fazer o diagrama para melhor visualização do pensamento e progresso do código.
- Resolver os problemas encontrados.
