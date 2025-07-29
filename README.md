
O programa utiliza um arquivo chamado `pricetab.txt`, onde cada linha representa um produto com os dados no seguinte formato:

[CODIGO_BARRAS]|[DESCRICAO]|[PRECO]


Exemplo:

7891234567890|Sabonete Lux 90g|3.50
00012345|Shampoo Seda 350ml|8.90


> OBS: Linhas que começam com `0` são tratadas como possíveis EAN-8 com zeros à esquerda, que são removidos antes da comparação.

---

## 🚀 Funcionalidades

- Leitura de código de barras digitado pelo usuário.
- Diferenciação entre códigos **EAN-13** e **EAN-8**.
- Busca do produto correspondente no arquivo.
- Exibição de:
  - Código de barras
  - Descrição do produto
  - Preço formatado

---

## 🧪 Como Usar

### 1. Compile o programa:

```bash
g++ -o leitor leitor.cpp

    Substitua leitor.cpp pelo nome real do seu arquivo fonte, se diferente.

2. Execute:

./leitor

3. Digite um código de barras:

Digite o codigo de barras('qq' para sair): 7891234567890
Codigo de barras....: 7891234567890
Descricao do produto: Sabonete Lux 90g
Preco do produto....: R$ 3.50

4. Para sair:

Digite o codigo de barras('qq' para sair): qq

⚙️ Estrutura do Código

    buscacodigoean13(): Lê linhas que não começam com zero, buscando por códigos de 13 dígitos.

    buscacodigoean8(): Lê linhas que começam com zero, removendo zeros à esquerda e comparando com códigos de até 8 dígitos.

    main(): Loop principal onde o usuário interage com o programa.

⚠️ Avisos

    O arquivo pricetab.txt deve estar no mesmo diretório do executável.
