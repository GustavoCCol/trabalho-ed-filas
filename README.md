# Objetivo
"Gerenciamento de Fila com Múltiplos Atendentes"\
Descrição: Simula laboratório com fila única e múltiplos atendentes, inclui distribuição de atendimentos.

## Mudanças
  - Inicialmente pegamos o código do professor de fila/pilha e em cima dele, começamos a fazer as modificações do código próprias, adaptando para o problema. Fizemos duas filas, uma normal e uma preferêncial.
  - Mais tardar, Udson iniciou os trabalhos com João Paulo usando a ferramente RAYLIB para fazer a interface do guichê. Foi postado o arquivo raylib.h e visual.c.
  - Manoel terminou de criar a função "EscolherNomeDessaFuncaoDepois" colocando nela a opção de chamar os pacientes pro guichê, liberá-los dos guichês e mostrar os guichês. Também criou o vetor dos guichês, definiu seu tamanho e criou uma função de inicialização.
  - Udson junto do João Paulo terminaram a interface do raylib, agora aparecendo os guichês com atendentes, botão de criar paciente, opção de poder colocar o paciente mais "recente" em termos de ter chegado primeiro, para ser atendido.
  - Júlio fez mudanças no código Fila_laboratorio.c para resolver a meta da variável dado ter o nome dos pacientes, colocou as funções "sleep" e "clear screen" para melhorar a visualização e deixar mais limpo o terminal.
    
## Membros do grupo
Manoel Pedro  
Julio Pereira  
Gustavo Cavalcante  
Joao Paulo  
Udson Marçal  

## Problemas Encontrados
Conseguir fazer nomes compostos aparecerem no guichê. Quando você libera paciêntes, ele libera por ordem de guiche, ou seja, primeiro o guiche 1, dps o 2 e dps o 3, e não por ordem de chegada, e quando você escreve na Escolha do switch 2asosnadsn4, se tiver o alguma opção válida no 1o caractere, ele aceita a resposta, e se tu escolher a opção de adicionar paciente com 2asodasod, ele aceita e logo dps escreve o nome do paciente como asodasod, então falta só isso pra ajeitar.

## Metas Iniciais
Resolver os problemas encontrados.
