//**************************************************************//
//  Exemplo de Uso da Biblioteca FSManager                      //
//  Autor: Cahu Silva                                           //
//  Data: 2024                                                  //
//**************************************************************//
//                                                              //
//  Este exemplo demonstra como utilizar a biblioteca FSManager //
//  para gerenciar arquivos no sistema de arquivos LittleFS     //
//  em placas ESP32. O código inclui operações básicas como     //
//  formatação do sistema de arquivos, criação, leitura,        //
//  escrita e exclusão de arquivos, além de exibir informações  //
//  sobre o sistema de arquivos.                                //
//                                                              //
//  Funcionalidades Demonstradas:                               //
//  - Formatar o sistema de arquivos                            //
//  - Montar e desmontar o sistema de arquivos                  //
//  - Criar e excluir arquivos                                  //
//  - Escrever e ler arquivos                                   //
//  - Listar informações do sistema de arquivos                 //
//                                                              //
//  Observação: Certifique-se de que a placa ESP32 esteja       //
//  corretamente configurada no Arduino IDE e que o LittleFS    //
//  esteja disponível.                                          //
//                                                              //
//**************************************************************//

#include <Arduino.h>
#include <FSManager.h>

FSManager fsManager;

char filename[] = "/log.txt";
char prefix[] = "LOG | ";

void createLogFile();

void writeLogFile();

void readLogFile();

void setup() {
    Serial.begin(115200);

    // Formata o sistema de arquivos (opcional)
    // fsManager.formatFS();

    // Monta o sistema de arquivos
    if (!fsManager.openFS()) {
        Serial.println("Falha ao inicializar o sistema de arquivos.");
        while (1);
    }

    // Cria um arquivo de log
    createLogFile();

    // Escreve no arquivo de log
    writeLogFile( "Inicializando o sistema de arquivos..." )

    // Lê o arquivo de log
    readLogFile()

    // Exibe informações do sistema de arquivos
    fsManager.listFSInfo();

    // Exemplo de exclusão de arquivo (opcional)
    // fsManager.deleteFile("/log.txt");
}

void loop() {
    // Seu código aqui
}

void createLogFile()
{
    fsManager.createFile( filename );
}

void writeLogFile(char* msg)
{
    fsManager.writeFile( filename , (String(prefix) + String("Inicializando o sistema de arquivos...")).c_str());
}

void readLogFile()
{
    fsManager.readFile( filename );
}