## 04/11/2025 - Versão 2.0 (branch-wellington)

###  Novas Funcionalidades
- **9 tipos de Pokémon**: Adicionados Elétrico, Gelo, Lutador, Voador, Psíquico e Noturno
- **Interface colorida**: Cores ANSI por tipo (vermelho=Fogo, azul=Água, verde=Planta, etc.)
- **Barra de HP visual**: Barra progressiva com mudança de cor (verde→amarelo→vermelho)
- **Emojis e bordas**: Interface mais atrativa com ícones e bordas decorativas
- **Limpeza de tela**: Tela limpa entre turnos para melhor legibilidade
- **Sistema de pausas**: Pressione ENTER para continuar após cada turno

###  Melhorias
- **Stats balanceados**: Cada tipo possui características únicas (ex: Elétrico tem velocidade altíssima)
- **Sistema de tipos expandido**: Tabela completa de fraquezas e resistências
- **Mensagens aprimoradas**: Indicadores visuais para ataques super efetivos e não efetivos
- **Função getCor()**: Retorna a cor ANSI correspondente ao tipo
- **Função getNomeTipo()**: Retorna o nome legível do tipo
- **Função mostrarBarraHP()**: Exibe barra de HP com cores dinâmicas
- **Função limparTela()**: Compatível com Windows e Unix

### Correções de Bugs
- **Corrigido bug no else do combate**: Variáveis `danop` e `danor` eram usadas incorretamente
- **Corrigido cálculo de dano**: Agora o rival ataca corretamente quando é mais rápido
- **HP não fica negativo**: HP é zerado quando vai abaixo de 0
- **Bug de entrada inválida**: Programa não trava mais ao digitar letras no nível ou tipo
- **Validação de entrada**: Adicionada função lerInteiro() que valida entradas numéricas
- **Validação de range**: Nível limitado entre 1-100, tipo limitado entre 1-9
- **Caracteres UTF-8**: Removidos emojis e símbolos especiais que apareciam como ?? no terminal Windows

###  Balanceamento
- **Fogo**: Alto ataque (nivelp*2+7), velocidade alta, defesa baixa
- **Água**: HP alto (nivelp*2+12), defesa média, velocidade baixa
- **Planta**: Defesa alta (nivelp*2.5+5), ataque baixo
- **Elétrico**: Ataque e velocidade altíssimos, HP baixo, defesa muito baixa
- **Gelo**: Ataque alto, stats balanceados
- **Lutador**: Ataque altíssimo (nivelp*2+9), HP alto
- **Voador**: Velocidade muito alta (nivelp*2+8), defesa baixa
- **Psíquico**: Stats altos e balanceados
- **Noturno**: HP alto, defesa média-alta

---

## 04/11/2025 - Versão 1.0

### Versão Inicial
O usuário irá escolher o nome, o nível e o tipo (fogo, água, planta) dos Pokémons participantes da batalha. Em seguida serão mostrados os status de saúde, ataque, defesa e velocidade dos participantes baseados em seu nível e tipo, e dará início à batalha. Aquele que tiver a maior velocidade será o primeiro a atacar. Dependendo do tipo do pokémon, o seu ataque dará o dobro ou a metade de dano. O dano que será recebido será calculado com uma conta de subtração do ataque do atacante com a defesa do agredido. Se a conta der um número menor ou igual a zero, o pokémon dará 3 de dano. Após ambos atacarem, será o fim do turno e dará início ao próximo. A batalha terá o seu fim quando a vida de um dos dois chegar a zero.

Branch Vinicius Ruza:
feature/Mecânica de desempate de velocidade, sitema de crítico, calculo de experiência adquirida, adição de mensagem de quem está atacando
bugfix/Correção de erro de dano dobrado, correção de "ressistencia==0" para "resistencia==1" 
chores/Simplificação de funções fraqueza e resistencia, transformar o sistema de experiencia em função

Branch Wellington Mendes:


Pull Requests aceitos:
**Correção de erros**:correção do erro de que quando os 2 Pokémons tinham a mesma velocidade apenas um levava dano por meio de um desempate realizado por aleatoriedade.
**Mecanica de ataque crítico**: adição da chance de ambos os participantes terem a chance de 5% de dar um dano crítico.
**Correção de erros**: foi corrigido a parte de dano que o parceiro recebe quando o inimigo ataca primeiro, a saúde do parceiro estava sendo subtraída duas por turno, pois a variáveis usadas para fazer esta conta eram as mesmas para tirar vida do parceiro no turno do rival, parecendo que o rival atacasse 2 vezes. Para resolver o problema simplesmente troquei o nome das variáveis.
**Simplificação das funções**: as funções de fraqueza e tinham um total de 2 "else if", então troquei eles por um único "if" com 3 "||"(ou) que retornam um valor verdadeiro e um "else" que retorna um valor falso.
Adição de mensagem: logo antes a mensagem que informa quem atacou quem e quanto de dano deu, foi a adicionado a mensagem "Vez de %s atacar: " para deixar mais claro quem atacou de forma mais rápida.
**Sistema de experiência**: Após a vitória de um dos competidores, aparecerá uma mensagem informando que o vencedor ganhou uma quantidade de experiência. Essa quantidade será calculado dependendo do nível do vencer e a diferença de nível entre os dois, se o perdedor tiver um nível maior, o vencedor ganhará a quantidade de 5 vezes o seu nível, se forem de mesmo nível será 3 vezes o seu nível e se tiver um nível maior será 2 vezes o seu nível.
**Simplificação de função**: Foram retirados os 'else if' usados para calcular a experiência ganha pelo vencedor e substituídas por duas funções (uma para cada vencedor) que fazem esse calculo.
Expande sistema de 3 para 9 tipos de Pokemon
**Interface collorida**: Adiciona interface colorida no terminal com cores por tipo
**Barra de vida dinâmica**: Implementa barra de HP visual dinamica
**Prevenção de bugs**: Adiciona validacao robusta de entrada (previne bugs com letras)
**Correção de bugs**Corrige bugs de calculo de dano e logica de combate
Remove caracteres UTF-8 problematicos no Windows
