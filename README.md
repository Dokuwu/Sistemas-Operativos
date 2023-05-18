## Sistemas-Operativos
# Parte 1) Implementação um conjunto de comandos para manipulação de ficheiros (10,5 vals)
Implemente os seguintes comandos através de funções de chamada ao sistema (system calls) (ver https://linux.die.net/man/). Estes comandos devem ser implementados em C (para Linux) e serão invocados através de um interpretador de comandos. Qualquer
mensagem de erro deverá ser apresentada no descritor stderr, não utilize programação shell, funções LibC (fopen, fread, etc…) ou comandos pré-existentes para executar a funcionalidade pretendida.
a) mostra ficheiro – Este comando deve apresentar no ecrã (todo) o conteúdo do ficheiro indicado como parâmetro. Caso o ficheiro não exista, o comando deve avisar o utilizador que o ficheiro não existe;
b) copia ficheiro – Este comando deve criar um novo ficheiro, cujo nome é “ficheiro.copia”, cujo conteúdo é uma cópia de (todo) o conteúdo do ficheiro passado como parâmetro no comando, com o nome ficheiro. Caso o ficheiro não exista, deve ser apresentado um aviso ao utilizador;
c) acrescenta origem destino – Este comando deve acrescentar (todo) o conteúdo da “origem” no final do “destino”. Caso algum dos ficheiros não exista, deve ser apresentado um aviso ao utilizador;
d) conta ficheiro – Este comando deve contar o número de linhas existentes num ficheiro. Se o ficheiro não existir, deverá ser indicado ao utilizador uma mensagem de erro;
e) apaga ficheiro – Este comando deve apagar o ficheiro com o nome indicado. No caso de o ficheiro indicado não existir, e apenas, deve ser apresentado um aviso ao utilizador;
f) informa ficheiro – Este comando apresenta apenas a informação do sistema de ficheiros em relação ao ficheiro indicado, tipo de ficheiro (normal, diretoria, link, etc.), i-node, utilizador dono em formato textual e datas de criação, leitura e modificação em formato textual;
g) lista [directoria] – Este comando deve apresentar uma lista de todas as pastas e ficheiros existentes na directoria indicada ou na diretoria atual se não especificada. Adicionalmente, deve distinguir ficheiros simples de diretorias através de uma indicação textual.

# Parte 2) Implementação de um interpretador de linha de comandos (5,5 vals)
No sentido de substituir o interpretador de comandos habitual, Bash shell, por um novo interpretador personalizado, deve ser implementada uma aplicação, de nome interpretador, cuja função será a leitura de uma sequência de caracteres da consola, e em seguida executar essa sequência como um comando e respetivos argumentos no
sistema. O programa deve mostrar o símbolo “%” como indicação de que está pronto para ler um novo comando do utilizador. O programa deve executar o comando através de primitivas de execução genérica de processos tendo como referência a funcionalidade da função system(3), mas sem fazer
uso da mesma. Cada comando escrito deve dar origem a um novo processo. Adicionalmente, pode considerar que a execução do interpretador deve ser suspensa até o comando indicado estar concluído. O interpretador deve indicar sempre se o comando concluiu com ou sem sucesso, através do seu código de erro/terminação. O programa deve permitir executar vários comandos sequencialmente, isto é, um a seguir
ao outro, até o utilizador indicar o comando especial “termina” que termina esta aplicação.

$ ./interpretador
% lista /home/user/Desktop
...
Terminou comando lista com código 0
% apaga /home/user/Desktop/file
...
Terminou comando apaga com código 1
% termina
$
