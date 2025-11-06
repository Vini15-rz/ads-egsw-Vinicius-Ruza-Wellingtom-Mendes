04/11/2025 -
Versão 1.0: o usuário irá escolher o nome, o nível e o tipo(fogo, água, planta) dos Pokémons participantes da batalha, em seguida serão mostrado os status de saúde, ataque, defesa e velocidade dos participantes baseados em seu nível e tipo e dará início a batalha, aquele que tiver a maior velocidade será o primeiro a atacar, dependendo do tipo do pokemon o seu ataque dará o dobro ou a metade de dano e o dano que será recebido será calculado com uma conta de subtração do ataque do atacante com a defesa do agredido, se a conta der um número menor ou igual a zero, o pokemon dará 3 de dano, após ambos atacarem, será o fim do turno e dará inicio ao próximo, a batalha terá o seu fim quando a vida de um dos dois chegar a zero.

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
