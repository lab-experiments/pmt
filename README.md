# pmt
Program developed in C++ language similar to the Grep-GNU(https://www.gnu.org/software/grep/) 

******************************
      Guia de Execução
******************************

- Criar um executável

1- clone ou baixe esse o projeto desse repositório
2- acesse a pasta pmt/src/
3- abra seu terminal(Shell) e execute execute o comando cd afim de chagar ao diretório pmt/src/
4- na linha de comando em seu terminal execute o comando make

- Executar o programa

5- após a conclusão do passo 4, execute no terminal o comando ./pmt
6- para fins de compreensão dos parâmetros do programa execute ./pmt --help
7- adicione arquivos de texto em formato txt para iniciar seu execução do programa.


- Forma flexível de execução

1- após a criação do seu executável com os passos acima, você poderá copiar o mesmo em qualquer pasta afim de executar o programa.
2- é necessário que todas os arquivos estejam no mesmo diretório do executável para que o programa possa enxerga-lós


- Exemplo de uso

acesse via terminal a pasta onde se encontra o seu executável e os seus arquivos de texto ou de padrão e informe ./pmt e posteriormente o comando desejado.


******************************
          Comandos
******************************


***** Busca Padrão *****

$ pmt pattern textfile [textfile...]


    = pattern: uma string com o padrão para busca no texto.
    = textfile: arquivo com extensão txt, podendo ser um ou vários. Arquivos serão lidos pela ordem de inserção.

--------------------------------------------------
$ pmt --pattern patternfile textfile [textfile...]
    ou
$ pmt -p patternfile textfile [textfile...]


    = -p, --pattern: opção de argumento
    = patternfile: arquivo de texto com extensão txt, podendo conter um ou mais padrões por linha. Cada arquivo terá todos os padrões pesquisados por vez.
    = textfile: arquivo com extensão txt, podendo ser um ou vários. Arquivos serão lidos pela ordem de inserção.


Além dos comando acima é possível obter informações por meio dos comandos:

$pmt --help
    ou
$pmt -h

