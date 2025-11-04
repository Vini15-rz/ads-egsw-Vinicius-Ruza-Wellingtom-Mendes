# Batalha Pokemon - Simulador em C

Simulador de combate Pokemon desenvolvido em C. O programa permite batalhas entre dois pokemons com sistema de tipos, calculo de dano e interface colorida no terminal.

## Versao 2.0 - Principais mudancas

- Sistema expandido com 9 tipos de pokemon
- Interface com cores ANSI diferentes para cada tipo
- Barra de HP visual que muda conforme a vida restante
- Sistema completo de vantagens e desvantagens entre tipos
- Correcao de bugs na logica de combate
- Tela limpa entre turnos
- Pausas para melhor acompanhamento

## Compilacao

Requisitos: GCC instalado

Windows:
```
gcc pokemon_game.c -lm -o pokemon.exe
.\pokemon.exe
```

Linux/Mac:
```
gcc pokemon_game.c -lm -o pokemon
./pokemon
```

A flag -lm eh necessaria para a biblioteca matematica (funcao trunc).

## Tipos disponiveis

Escolha por numero durante o jogo:

1. Fogo - Alto ataque e velocidade, defesa baixa
2. Agua - HP alto, defesa media, velocidade baixa  
3. Planta - Alta defesa, ataque baixo, HP medio-alto
4. Eletrico - Ataque e velocidade altissimos, HP baixo
5. Gelo - Ataque alto, stats balanceados
6. Lutador - Ataque altissimo, HP alto, velocidade media
7. Voador - Velocidade muito alta, defesa baixa
8. Psiquico - Stats altos e balanceados
9. Noturno - HP alto, defesa media-alta, velocidade alta

## Mecanicas de jogo

Ordem de ataque: Pokemon mais rapido ataca primeiro
Calculo de dano: ataque - defesa do oponente (minimo 3)
Modificadores: x2 se super efetivo, /2 se nao muito efetivo

## Tabela de vantagens entre tipos

Super efetivo (dano x2):
- Fogo > Planta, Gelo
- Agua > Fogo
- Planta > Agua
- Eletrico > Agua, Voador
- Gelo > Planta, Voador
- Lutador > Gelo, Noturno
- Voador > Planta, Lutador
- Psiquico > Lutador
- Noturno > Psiquico

Fraco (dano /2):
- Fogo < Agua, Gelo
- Agua < Planta, Eletrico
- Planta < Fogo, Gelo, Voador
- Eletrico < Planta
- Gelo < Fogo, Lutador
- Lutador < Voador, Psiquico
- Voador < Eletrico, Gelo
- Psiquico < Noturno
- Noturno < Lutador, Psiquico


## Como funciona

1. Programa solicita nome, nivel e tipo de cada pokemon
2. Calcula e exibe os stats baseados no nivel e tipo escolhido
3. Batalha ocorre em turnos ate um pokemon chegar a 0 HP
4. Exibe o vencedor ao final

## Detalhes tecnicos

Ordem de ataque determinada pela velocidade (mais rapido ataca primeiro)
Formula de dano: ataque_atacante - defesa_defensor (minimo de 3)
Modificadores aplicados apos calculo base (x2 ou /2 conforme matchup)


## Exemplo de uso

Entrada:
```
Nome do parceiro: Charmander
Nivel: 5
Tipo: 1 (Fogo)

Nome do rival: Squirtle  
Nivel: 5
Tipo: 2 (Agua)
```

Saida:
```
Status do Charmander:
HP: 19 | Ataque: 17 | Defesa: 12 | Velocidade: 16

Status do Squirtle:
HP: 22 | Ataque: 14 | Defesa: 15 | Velocidade: 13

Batalha iniciada...
```


## Arquivos do projeto

- pokemon_game.c - codigo fonte principal
- CHANGELOG.md - historico de versoes
- README.md - documentacao

## Workflow

Branch main para producao. Crie branches separadas para features (ex: branch-wellington).
Commits devem ser descritivos. Use pull requests para merge na main.
Atualize o CHANGELOG apos mudancas significativas.

---

Desenvolvido por Vinicius Ruza e Wellington Mendes
