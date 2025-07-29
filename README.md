# Objetivo
"Gerenciamento de Fila com Múltiplos Atendentes"\
Descrição: Simula laboratório com fila única e múltiplos atendentes, inclui distribuição de atendimentos.

  - Inicialmente pegamos o código do professor de fila/pilha e em cima dele, começamos a fazer as modificações do código próprias, adaptando para o problema. Fizemos duas filas, uma normal e uma preferêncial.
  - Mais tardar, Udson iniciou os trabalhos com João Paulo usando a ferramente RAYLIB para fazer a interface do guichê. Foi postado o arquivo raylib.h e visual.c.
  - Manoel terminou de criar a função "EscolherNomeDessaFuncaoDepois" colocando nela a opção de chamar os pacientes pro guichê, liberá-los dos guichês e mostrar os guichês. Também criou o vetor dos guichês, definiu seu tamanho e criou uma função de inicialização.
  - Udson junto do João Paulo terminaram a interface do raylib, agora aparecendo os guichês com atendentes, botão de criar paciente, opção de poder colocar o paciente mais "recente" em termos de ter chegado primeiro, para ser atendido.
    
## Membros do grupo
Manoel Pedro  
Julio Pereira  
Gustavo Cavalcante  
Joao Paulo  
Udson Marçal  

## Problemas Encontrados
Achar uma maneira de colocar o nome dos pacientes como dado da lista, colocar as funções "sleep" e "clear screen" para que a interface fique mais bonita. Não estamos conseguindo fazer a tela do terminal limpar e atrasar a resposta das novas chamadas de função.

## Metas Iniciais
Criar uma forma de na variável "dado" da fila ter o nome dos pacientes, ter uma forma de escolher alternadamente os pacientes da fila normal e preferencial e guardar o nome deles nos guichês, que serão um vetor com 3 espaços (essa última parte é bem fácil pq a função "Get" já retira o paciente da fila e retorna a variável "dado" que vai ser o nome do paciente).
