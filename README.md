# FSManager
 Biblioteca Arduino para Gerenciamento de Sistema de Arquivos com LittleFS no ESP32

## Descrição
A biblioteca FSManager fornece uma interface simples e fácil de usar para gerenciar arquivos no sistema de arquivos LittleFS em placas ESP32. Ela inclui funções para:

- Formatar o sistema de arquivos
- Criar e excluir arquivos
- Ler e escrever em arquivos
- Montar e desmontar o sistema de arquivos
- Recuperar informações como espaço total e usado do sistema de arquivos

## Recursos
- Fácil integração com projetos Arduino em ESP32
- API simplificada para operações comuns de sistema de arquivos
- Exemplo prático incluso para demonstrar o uso da biblioteca
- Estrutura da Biblioteca

A biblioteca é composta pelos seguintes arquivos:

- src/FSManager.h - Arquivo de cabeçalho com a declaração da classe e descrições das funções.
- src/FSManager.cpp - Arquivo de implementação com as definições das funções.
- library.properties - Arquivo de metadados para o Arduino IDE.
- keywords.txt - (Opcional) Arquivo para destaque de sintaxe no IDE.
- examples/FSManager_Example/FSManager_Example.ino - Arquivo de exemplo demonstrativo.

Instalação
Para instalar a biblioteca, siga os passos abaixo:

Baixe ou clone este repositório.

Copie a pasta da biblioteca para o diretório de bibliotecas do Arduino:

Windows: Documentos\Arduino\libraries\FSManager
macOS: ~/Documentos/Arduino/libraries/FSManager
Linux: ~/Arduino/libraries/FSManager
Estrutura de Pastas da Biblioteca:

FSManager/                <-- Pasta raiz da biblioteca
├── examples/             <-- Pasta contendo os exemplos
│   └── FSManager_Example/    <-- Pasta do exemplo
│       └── FSManager_Example.ino  <-- Arquivo de exemplo
├── src/                  <-- Pasta contendo os arquivos fonte
│   ├── FSManager.h       <-- Arquivo de cabeçalho da biblioteca
│   └── FSManager.cpp     <-- Implementação da biblioteca
├── library.properties    <-- Arquivo de propriedades da biblioteca
└── keywords.txt          <-- (Opcional) Arquivo para destaque de sintaxe no IDE

## Uso
Após instalar a biblioteca, você pode utilizá-la em seus projetos Arduino. Siga o exemplo abaixo ou abra o arquivo de exemplo fornecido com a biblioteca.

## API
Construtor e Destrutor
FSManager() - Inicializa o sistema de arquivos ao criar o objeto.
~FSManager() - Fecha o sistema de arquivos ao destruir o objeto.

Operações do Sistema de Arquivos
bool formatFS() - Formata o sistema de arquivos LittleFS.
bool openFS(bool formatOnFail = true) - Monta o sistema de arquivos; formata se a montagem falhar e formatOnFail for true.
void closeFS() - Desmonta o sistema de arquivos.

Operações de Arquivo
bool createFile(const char* fileName) - Cria um novo arquivo se ele não existir.
bool deleteFile(const char* fileName) - Exclui um arquivo.
bool writeFile(const char* fileName, const String& message) - Adiciona uma mensagem a um arquivo.
bool readFile(const char* fileName) - Lê e imprime o conteúdo de um arquivo.

Informações do Sistema de Arquivos
void listFSInfo() - Imprime o espaço total e usado do sistema de arquivos.

## Detalhes:

FSManager/: Pasta principal da biblioteca.
examples/: Contém as pastas de exemplos. Cada exemplo deve estar em sua própria pasta.
examples/FSManager_Example/: Pasta do exemplo. O nome deve corresponder ao nome do arquivo .ino.
examples/FSManager_Example/FSManager_Example.ino: Arquivo de exemplo com o código demonstrativo.
src/: Contém os arquivos fonte da biblioteca.
src/FSManager.h e src/FSManager.cpp: Arquivos de cabeçalho e implementação da biblioteca.
library.properties: Arquivo com metadados da biblioteca.
keywords.txt: (Opcional) Usado para destacar as palavras-chave da biblioteca no Arduino IDE.
Licença
Este projeto está licenciado sob os termos da licença MIT. Consulte o arquivo LICENSE para obter mais detalhes.

## Contribuindo
Contribuições são bem-vindas! Se você encontrar bugs ou tiver sugestões de melhorias, sinta-se à vontade para abrir uma issue ou enviar um pull request.

Autor
Cahu Silva

Referências
Documentação do LittleFS
Sistema de Arquivos no ESP32