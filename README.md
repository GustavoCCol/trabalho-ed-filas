# Objetivo
"Gerenciamento de Fila com Múltiplos Atendentes"\
Descrição: Simula laboratório com fila única e múltiplos atendentes, inclui distribuição de atendimentos.

  Inicialmente pegamos o código do professor de fila/pilha e em cima dele, começamos a fazer as modificações do código próprias, adaptando para o problema. Fizemos duas filas, uma normal e uma preferêncial.
  Mais tardar, Udson iniciou os trabalhos com João Paulo usando a ferramente RAYLIB para fazer a interface do guichê. Foi postado o arquivo raylib.h e visual.c.

## Membros do grupo
Manoel Pedro  
Julio Pereira  
Gustavo Cavalcante  
Joao Paulo  
Udson Marçal  

## Problemas Encontrados

## Metas Iniciais
próximo paciente /// checar se a fila prioridade está vazia , se estive puxar um paciente da fila normal
selecionar cache /// ao puxar um paciente se procura um cache vazio para ele

ideia geral
gerar tempo do cache /// definir se o tempo de atendimento é fixo por cache e se muda entre eles
gerar paciente // decidir se os pacientes serão criados com o tempo

Criar uma forma de na variável "dado" da fila ter o nome dos pacientes, ter uma forma de escolher alternadamente os pacientes da fila normal e preferencial e guardar o nome deles nos guichês, que serão um vetor com 3 espaços (essa última parte é bem fácil pq a função "Get" já retira o paciente da fila e retorna a variável "dado" que vai ser o nome do paciente)
