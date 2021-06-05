# Código utilizado para avaliação do aprendizado ao longo do bimestre, segue o que foi pedido:
## Fila de arquivos para impressora

Implemente um programa que implemente uma fila de impressão. 

Para cada arquivo a ser impresso devem ser armazenados: 
- id sequencial da impressão (começando em 1)
- nome do arquivo
- quantidade de folhas

Exceto o id sequencial, as outras informações devem ser digitadas pelo 
usuário.

O programa também deve realizar um controle 
da quantidade de papel disponível na impressora, permitindo que o usuário 
realize a “inserção” de mais papel. Antes de inserir um novo documento na 
fila, o programa deve verificar se há papel suficiente na impressora para 
realizar a impressão. Se não houver papel suficiente, o programa não deve 
aceitar a impressão. Desenvolva métodos que:

  1.	Permita inserir um arquivo na fila de impressão (retornar falso caso não haja papel);
  2.	Remova um arquivo da fila da impressão (imprimir);
  3.	Liste os arquivos da fila de impressão;
  4.	Permita inserir mais folhas na impressora;
  5.	Retorne o total de folhas disponíveis na impressora
