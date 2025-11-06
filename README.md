Simulação de batalha Pokémon em linguagem C. Você informa nome, nível e tipo de cada Pokémon; o programa calcula os status e executa a batalha por turnos até alguém vencer.

Como compilar e executar
Pré-requisitos: GCC instalado.

Windows (PowerShell):

gcc pokemon_game.c -lm -o batalha.exe

.\batalha.exe

Observação: a opção -lm liga a biblioteca matemática (uso de trunc).

Regras rápidas
Os tipos suportados são informados por número:

1 = Fogo 🔥

2 = Água 💧

3 = Planta 🌱

Ordem do turno: quem tem maior velocidade ataca primeiro.

Dano: ataque − defesa; se o resultado for menor ou igual a 0, causa 3 de dano.

Eficácia por tipo:

Super efetivo: dano x2
Não efetivo: dano /2
Fluxo de jogo
O programa pede: nome, nível e tipo (1/2/3) do seu Pokémon e do rival.
Mostra os status calculados de cada um.
Executa turnos até que a saúde de um chegue a 0.
Exibe mensagens sobre dano, eficácia e o vencedor.
Ordem dos turnos e dano
Ordem: quem tem maior velocidade ataca primeiro. Em empate de velocidade, o rival ataca primeiro (pela implementação atual).
Dano base: dano = ataque - defesa. Se o resultado for <= 0, aplica dano mínimo 3.
Modificadores de eficácia: depois do dano base, se for super efetivo multiplica por 2; se for não muito efetivo divide por 2.
Em resumo: dano_final = ajustaMinimo(max(3, ataque - defesa)) e então aplica x2 ou /2 conforme a vantagem de tipo.

Exemplo rápido (entrada/saída)
Entrada (exemplo):
Qual o nome do seu parceiro?

Charmander

Qual o nível do seu parceiro?

5

Seu parceiro é um pokemon do tipo: 1-Fogo 2-Água 3-Planta

1

Qual o nome do seu rival?

Squirtle

Qual o nível do seu rival?

5

Seu rival é um pokemon do tipo: 1-Fogo 2-Agua 3-Planta

2

Saída (trecho esperado):
Status do Charmander:

Saúde: 19
Ataque: 17
Defesa: 12
Velocidade: 16

Status do Squirtle:

Saúde: 22
Ataque: 14
Defesa: 15
Velocidade: 13

Que comece a batalha! ...

Estrutura do projeto
pokemon_game.c — Código-fonte do programa.
.gitignore — Ignora binários, objetos e pastas de build.
CHANGELOG.md — Histórico de versões e mudanças.
README.md — Este arquivo descritivo do projeto
Fluxo de trabalho (GCS)
Branch principal: main.
Para mudanças, crie uma branch: feature/<nome-da-feature> ou branch-<seu-nome>.
Commits com mensagens claras e descritivas.
Abra Pull Request (PR) para integrar na main.
Após merge, atualize CHANGELOG.md com a nova versão.
Créditos
Dupla: Vinícius Ruza e Wellington Mendes.

About
Esse projeto irá simular uma batalha Pokémon em que o usuário escolhe o nível, tipo e nome dos Pokémon participantes

Resources
 Readme
 Activity
Stars
 0 stars
Watchers
 0 watching
Forks
 0 forks
Releases
No releases published
Create a new release
Packages
No packages published
Publish your first package
Contributors
2
@Vini15-rz
Vini15-rz Vinicius Ruza
@wtomendes
wtomendes Tom Mendes
Languages
C
100.0%
Suggested workflows
Based on your tech stack
C/C++ with Make logo
C/C++ with Make
Build and test a C/C++ project using Make.
CMake based, multi-platform projects logo
CMake based, multi-platform projects
Build and test a CMake based project on multiple platforms.
CMake based, single-platform projects logo
CMake based, single-platform projects
Build and test a CMake based project on a single-platform.
More workflows
Footer


        }
    }
}
