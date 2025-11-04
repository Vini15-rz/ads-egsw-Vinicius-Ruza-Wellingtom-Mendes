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

