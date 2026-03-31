# Lavacar-C
Revisão de Código — Sistema Lava-Carros (C)
Integrantes
Hilário Canci Neto
Alan Lino Reis
Sobre o Projeto:

Este projeto consiste na análise e revisão de um sistema de gerenciamento de abastecimento de um posto de gasolina (lava-carros), desenvolvido em linguagem C.

O objetivo foi aplicar, na prática, técnicas de revisão de código utilizando a ferramenta Reviewable, destacando melhorias, problemas e boas práticas.

Ferramenta Utilizada
Reviewable

Descrição:
O Reviewable é uma ferramenta integrada ao GitHub que permite revisar código de forma organizada e colaborativa, facilitando a análise de Pull Requests.

Principais recursos:

Comentários por linha de código
Visualização clara de alterações (diff)
Controle de revisão
Integração direta com GitHub
Como acessar e configurar
1. Acessar a ferramenta
Acesse: https://reviewable.io
Clique em "Sign in with GitHub"
Autorize o acesso
2. Instalar no repositório
Acesse o repositório no GitHub
Vá em Settings > GitHub Apps
Procure por Reviewable
Clique em Install
Escolha os repositórios desejados
Passo a passo da revisão
1. Criar um Pull Request
git add .
git commit -m "Revisão do sistema lava-carros"
git push

Depois:

Clique em "Compare & Pull Request" no GitHub
2. Abrir no Reviewable
Dentro do Pull Request, clique no botão "Reviewable"
3. Revisar o código

Na interface do Reviewable:

Analise os arquivos modificados
Observe mudanças linha a linha
Identifique problemas e melhorias
4. Inserir comentários
Clique na linha desejada
Escreva sugestões ou correções

Exemplo:

Variável poderia ter escopo local para evitar uso desnecessário de memória.

5. Finalizar revisão
Clique em "Mark as reviewed"
Demonstração da revisão no código
1. Problema: excesso de variáveis

Código original:

float  prEta, prGas, prAdit, qtdEta, qtdGas, qtdAdit, valRec;

Comentário:
Muitas variáveis estão no escopo da função principal. Algumas poderiam ser declaradas apenas quando necessárias.

Sugestão:

float prEta, prGas, prAdit;
2. Problema: função fun_invalidos

Código:

fun_invalidos(prEta, prGas, prAdit, tFila);

Comentário:
A função é chamada antes da leitura dos valores, podendo utilizar dados não inicializados.

Sugestão:
Mover a validação para depois do scanf.

3. Problema: uso de system("clear")

Comentário:
O uso de system("clear") não é portátil e pode não funcionar em todos os sistemas operacionais.

4. Problema: uso de fgets

Comentário:
Pode haver problemas com buffer dependendo da entrada anterior. É necessário garantir o uso correto da função de limpeza de buffer.

5. Problema: organização do código

Comentário:
O código pode ser melhor estruturado dividindo responsabilidades em funções menores, melhorando a legibilidade e manutenção.

Observações sobre a ferramenta
Pontos positivos
Interface clara e organizada
Boa integração com GitHub
Facilita a revisão colaborativa
Comentários bem estruturados
Pontos negativos
Curva de aprendizado inicial
Interface pode parecer complexa no início
Experiência do grupo

A ferramenta se mostrou útil para organizar a revisão de código, permitindo identificar problemas com mais clareza e registrar sugestões diretamente no código.

Após o uso inicial, a navegação se tornou mais intuitiva.

Conclusão

O uso do Reviewable permitiu:

Melhor organização da revisão
Identificação clara de problemas
Sugestões estruturadas de melhoria

Esse processo contribui para aumentar a qualidade do código e facilitar o trabalho em equipe.

Reprodutibilidade

Seguindo este manual, outro aluno consegue:

Configurar o Reviewable
Criar um Pull Request
Revisar código
Inserir comentários
Finalizar a revisão
