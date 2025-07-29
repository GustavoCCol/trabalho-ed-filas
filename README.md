# Objetivo
"Gerenciamento de Fila com Múltiplos Atendentes"\
Descrição: Simula laboratório com fila única e múltiplos atendentes, inclui distribuição de atendimentos.

## Mudanças
  - Inicialmente pegamos o código do professor de fila/pilha e em cima dele, começamos a fazer as modificações do código próprias, adaptando para o problema. Fizemos duas filas, uma normal e uma preferêncial.
  - Mais tardar, Udson iniciou os trabalhos com João Paulo usando a ferramente RAYLIB para fazer a interface do guichê. Foi postado o arquivo raylib.h e visual.c.
  - Manoel terminou de criar a função "EscolherNomeDessaFuncaoDepois" colocando nela a opção de chamar os pacientes pro guichê, liberá-los dos guichês e mostrar os guichês. Também criou o vetor dos guichês, definiu seu tamanho e criou uma função de inicialização.
  - Udson junto do João Paulo terminaram a interface do raylib, agora aparecendo os guichês com atendentes, botão de criar paciente, opção de poder colocar o paciente mais "recente" em termos de ter chegado primeiro, para ser atendido.
  - Júlio fez mudanças no código Fila_laboratorio.c para resolver a meta da variável dado ter o nome dos pacientes, colocou as funções "sleep" e "clear screen" para melhorar a visualização e deixar mais limpo o terminal.
  - Manoel levantou uma boa sugestão para resolver o problema, usar getchar ou gets. Após alguns ajustes, Manoel e Júlio fizeram as devidas resoluções para os problemas encontrados. A solução para a questão da ordem de liberação foi fazer o guichê virar uma fila, ao invés de ser um vetor, como era antes, o que solucionava o fato pode um paciente entrar no guichê 2 e sair antes do paciente do guichê 3, mesmo tendo chegado antes.
    
## Membros do grupo
Manoel Pedro  
Julio Pereira  
Gustavo Cavalcante  
Joao Paulo  
Udson Marçal  

## Problemas Encontrados
O novo problema agora foi, agora que o código está praticamente finalizado, fazer a mescla com a interface feito no raylib, uma fez que inicialmente fizemos a interface pensando em ser algo isolado para ilustração, e agora queremos que sejam algo único.

## Metas Iniciais
Fazer a fusão do código em C com a interface no RAYLIB.
